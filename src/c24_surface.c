

#include <stdint.h>
#include <string.h>

#include <unistd.h>	// close

#include "log.h"
#include "c24_frame.h"
#include "c24_handshake.h"
#include "c24_request.h"
#include "c24_surface.h"

#include "c24_error.h"
#include "c24_surface_manager.h"
#include "c24_surface_private_definitions.h"
#include "utility.h"

#define VUMETER_MASK_QUEUE_SIZE 64

struct c24_surface_t * c24_surface_open(const unsigned int request_queue_size)
{
	struct c24_surface_t *surface =
		malloc(sizeof(struct c24_surface_t));

	if (surface == NULL)
		return NULL;

	bzero(surface, sizeof(struct c24_surface_t));

	// Open socket
	surface->sock = socket(PF_PACKET, SOCK_DGRAM, htons(C24_ETHER_TYPE));

	if (surface->sock < 0) {
		free(surface);
		return NULL;
	}

	//  Set callback and user_data
	surface->user_data = NULL;
	surface->button_callback = NULL;
	surface->slider_callback = NULL;
	surface->knob_callback = NULL;
	surface->reconnection_callback = NULL;

	//  Initialize sequence number
	surface->sequence_number = 1;

	// Connect to the c24 table
	if (c24_surface_find(surface, NULL) < 0) {
		free(surface);
		return NULL;
	}

	// Initialize request queue

	surface->request_queue = queue_new(request_queue_size,
			sizeof(struct c24_request));

	if (surface->request_queue == NULL) {
		close(surface->sock);
		free(surface);
		return NULL;
	}

	pthread_mutex_init(&(surface->request_queue_mutex), NULL);

	// Initialize vumeter mask, queue and mutex

	bzero(surface->vumeter_mask, 96);

	surface->vumeter_mask_queue = queue_new(VUMETER_MASK_QUEUE_SIZE,
			sizeof(struct c24_vu_meter_mask_request));

	if (surface->vumeter_mask_queue == NULL) {
		queue_delete(surface->request_queue);
		pthread_mutex_destroy(&(surface->request_queue_mutex));
		close(surface->sock);
		free(surface);
		return NULL;
	}

	pthread_mutex_init(&(surface->vumeter_mask_queue_mutex), NULL);

	// Create Table manager thread

	surface->surface_manager_running = 1;

	if (pthread_create(&(surface->surface_manager), NULL,
			(void *(*)(void*)) c24_surface_manager, surface) != 0) {
		queue_delete(surface->request_queue);
		pthread_mutex_destroy(&(surface->request_queue_mutex));
		queue_delete(surface->vumeter_mask_queue);
		pthread_mutex_destroy(&(surface->vumeter_mask_queue_mutex));
		close(surface->sock);
		free(surface);
		return NULL;
	}

	return surface;
}

int c24_surface_close(struct c24_surface_t *surface)
{

	if (surface != NULL) {

		// Stop surface manager thread

		surface->surface_manager_running = 0;
		pthread_join(surface->surface_manager, NULL);

		// Disconnect
		const int err = c24_surface_disconnect(surface, 500000); // TODO mieu
		
		if (err != SUCCESS)
			DEBUG_PRINT("Warning : disconnect error : %s\n", c24_strerror(err));

		close(surface->sock);

		pthread_mutex_destroy(&(surface->request_queue_mutex));
		pthread_mutex_destroy(&(surface->vumeter_mask_queue_mutex));

		queue_delete(surface->request_queue);
		queue_delete(surface->vumeter_mask_queue);

		free(surface);
	}

	return SUCCESS;
}

void c24_surface_set_user_data(
	struct c24_surface_t *surface,
	void *user_data)
{
	surface->user_data = user_data;
}

void c24_surface_set_button_callback(
	struct c24_surface_t *surface,
	c24_button_callback_t callback)
{
	surface->button_callback = callback;
}

void c24_surface_set_slider_callback(
	struct c24_surface_t *surface,
	c24_slider_callback_t callback)
{
	surface->slider_callback = callback;
}

void c24_surface_set_knob_callback(
	struct c24_surface_t *surface,
	c24_knob_callback_t callback)
{
	surface->knob_callback = callback;
}

void c24_surface_set_reconnection_callback(
	struct c24_surface_t *surface,
	c24_reconnection_callback_t callback)
{
	surface->reconnection_callback = callback;
}

/*
*
*/

const char *c24_surface_get_version(struct c24_surface_t *surface)
{
	return surface->version;
}


/*
 *
 */

static int c24_surface_request_enqueue(
	struct c24_surface_t *surface,
	const struct c24_request *req)
{
	pthread_mutex_lock(&(surface->request_queue_mutex));
	const int ret = queue_enqueue(surface->request_queue, req);
	pthread_mutex_unlock(&(surface->request_queue_mutex));

	if (ret < 0)
		return ENOBUFS;
	else
		return SUCCESS;
}

int c24_surface_set_slider_pos(
	struct c24_surface_t *surface,
	const uint8_t track_id,
	const uint16_t value)
{
	struct c24_request req;

	req.type = SLIDER_POS_REQUEST;
	req.slider_pos_request.track_id = track_id;
	req.slider_pos_request.value = value;

	return c24_surface_request_enqueue(surface, &req);
}

static int display_request_helper(
	struct c24_surface_t *surface,
	const char *str,
	const uint8_t track_id,
	const unsigned int line,
	const uint8_t size_limit)
{
	const size_t len = strlen(str);
	struct c24_request req;

	req.type = DISPLAY_REQUEST;
	req.display_request.track_id = track_id;
	req.display_request.line = line;

	memset(req.display_request.text, 0x20, 7);
	memcpy(req.display_request.text, str, len > size_limit ? size_limit : len);

	return c24_surface_request_enqueue(surface, &req);
}

int c24_surface_display(
	struct c24_surface_t *surface,
	const char *str,
	const uint8_t track_id,
	const unsigned int line)
{
	return display_request_helper(
		surface,
		str,
		track_id,
		line,
		6);
}

int c24_surface_print(
	struct c24_surface_t *surface,
	const char *str,
	const uint8_t track_id,
	const unsigned int line)
{
	unsigned int remain = strlen(str);
	uint8_t cur_track = track_id;

	while(remain > 0) {
		const unsigned int len = remain > 7 ? 7 : remain;
		const int err = display_request_helper(surface, str, cur_track, line, len);
		if (err < 0)
			return err;
		cur_track++;
		str += len;
		remain -= len;
	}

	return SUCCESS;
}

int c24_surface_display_float(
	struct c24_surface_t *surface,
	const float value,
	const uint8_t track_id,
	const unsigned int line)
{
	char str[16];
	sprintf(str, "%f", value);
	return c24_surface_display(surface, str, track_id, line);
}

int c24_surface_set_knob_led_mask(
	struct c24_surface_t *surface,
	const uint8_t track_id,
	const uint16_t mask)
{
	struct c24_request req;

	req.type = KNOB_LED_MASK_REQUEST;
	req.knob_led_mask_request.track_id = track_id;
	req.knob_led_mask_request.mask = mask;

	return c24_surface_request_enqueue(surface, &req);
}

int c24_surface_set_button_led_state(
	struct c24_surface_t *surface,
	const uint16_t button,
	const uint8_t state)
{
	struct c24_request req;

	req.type = BUTTON_LED_REQUEST;
	req.button_led_request.button = 
		c24_button_id_to_raw_id(button);
	req.button_led_request.state = state;

	return c24_surface_request_enqueue(surface, &req);
}

int c24_surface_set_counter_screen_mask(
	struct c24_surface_t *surface,
	const uint64_t digit_mask,
	const uint8_t dot_mask)
{
	struct c24_request req;

	req.type = COUNTER_SCREEN_MASK_REQUEST;
	req.counter_screen_mask_request.digit_mask = digit_mask;
	req.counter_screen_mask_request.dot_mask = dot_mask;

	return c24_surface_request_enqueue(surface, &req);
}

////

int c24_surface_set_vumeter_mask(
	struct c24_surface_t *surface,
	const uint8_t track_id,
	const uint8_t vumeter_id,
	const uint16_t mask)
{
	struct c24_vu_meter_mask_request req;

	req.track_id = track_id;
	req.vumeter_id = vumeter_id;
	req.mask = mask;

	pthread_mutex_lock(&(surface->vumeter_mask_queue_mutex));
	const int ret = queue_enqueue(surface->vumeter_mask_queue, &req);
	pthread_mutex_unlock(&(surface->vumeter_mask_queue_mutex));

	if (ret < 0)
		return ENOBUFS;
	else
		return SUCCESS;
}
