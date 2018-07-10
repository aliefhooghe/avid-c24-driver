#include <sys/select.h>
#include <string.h>

#include "c24_error.h"
#include "c24_frame.h"
#include "c24_request.h"
#include "c24_vu_meter_mask_request.h"
#include "c24_handshake.h"
#include "c24_surface_private_definitions.h"
#include "utility.h"
#include "log.h"


#define MINIMUM_REQUEST_INTERVAL_USEC 5000	//  The minimum time that should elapse between 2 request
#define ACKNOWLEDGMENT_TIMEOUT_USEC 750000
#define MAXIMUM_BLOCK_COUNT_PER_FRAME 16
#define MAXIMUM_VUMETER_MASK_UPDATE_PER_FRAME 16
#define MAX_SEND_TRY_COUNT 3

static int c24_acknowledged_send_frame(
	struct c24_surface_t *surface,
	struct c24_frame *frame,
	const unsigned int usec_ack_timeout,
	const unsigned int max_try_count) // TODO add try count limit
{
	struct timeval timeout =
	{ .tv_sec = 0, .tv_usec = usec_ack_timeout };

	int ack_err;
	unsigned int try_count = 0;

	do
	{
		const int send_err = c24_frame_send(surface, frame);
		try_count++;

		if (send_err != SUCCESS)
			return send_err;

		ack_err = c24_acknowledgment_receive(surface, &timeout);
		if (ack_err == C24_TIMEOUT_REACHED) {
			LOG_PRINT("Warning : Acknowledgment timeout reached\n");

			if (try_count >= max_try_count) {
				LOG_PRINT("Warning : c24 surface was lost, trying to reconnect...\n");
				const int err = 
					c24_surface_find(surface, surface->reconnection_callback);
			}
		
			//	reset ack timeout
			timeout.tv_sec = 0;
			timeout.tv_usec = usec_ack_timeout;
		}


	} while (ack_err == C24_TIMEOUT_REACHED);

	return ack_err;
}

//////////////////////////////////////////////////////////////////

static int send_slider_pos_feedback(
	struct c24_surface_t *surface,
	const uint8_t track_id,
	const uint16_t value)
{
	struct c24_request req;
	struct c24_frame frame;

	req.type = SLIDER_POS_REQUEST;
	req.slider_pos_request.track_id = track_id;
	req.slider_pos_request.value = value;

	c24_frame_init(&frame);
	c24_frame_add_request(&frame, &req);

	return c24_acknowledged_send_frame(
		surface,
		&frame,
		ACKNOWLEDGMENT_TIMEOUT_USEC,
		MAX_SEND_TRY_COUNT);
}

static int handle_table_request_block(
	struct c24_surface_t *surface,
	const uint8_t *buffer,
	size_t *block_size)
{
	const uint16_t operation = ntohs(*(uint16_t*) buffer);

	switch (operation)
	{

		case C24_BLOCK_OPERATION_SLIDER_MOVE:
		{
			const uint8_t track_id = buffer[2];
			const uint16_t value = 4 * ((uint16_t)buffer[5]) + buffer[4];

			DEBUG_PRINT("BLOCK : Slider Move request TrackId = %u, value = %u\n",
					track_id, value);

			// Validate the slider move
			const int err = send_slider_pos_feedback(surface, track_id, value);

			if (err != SUCCESS)
				return err;

			if (surface->slider_callback != NULL && track_id < C24_TRACK_COUNT)
				surface->slider_callback(surface->user_data, track_id, value);

			*block_size = 6;
		}
		break;

		case C24_BLOCK_OPERATION_BUTTON_EVENT:
		{
			const uint16_t button = 
				c24_button_raw_id_to_id(
					ntohs(*(uint16_t*) (buffer + 2)));
			const uint8_t state = buffer[4];

			DEBUG_PRINT("BLOCK : Button Press request : button = %04x, state = %u\n",
					button, state);

			if (surface->button_callback != NULL && button < C24_BUTTON_COUNT)
				surface->button_callback(surface->user_data, button, state);

			*block_size = 5;
		}
		break;

		case C24_BLOCK_OPERATION_KNOB_ROTATE:
		{
			const uint16_t knob_id = 
				c24_knob_raw_id_to_id(ntohs(*(uint16_t*) (buffer + 2)));
			const uint8_t state = buffer[4];

			DEBUG_PRINT("BLOCK : Knob %04x rotate %u\n", knob_id, state);

			if (surface->knob_callback != NULL && knob_id < C24_KNOB_COUNT)
				surface->knob_callback(surface->user_data, knob_id, state);

			*block_size = 5;
		}
		break;

		default:
			DEBUG_PRINT("BLOCK : Unknown Block opcode : %x\n", operation);
			return C24_UNKNOW_REQUEST_BLOCK;
		break;
	}

	return SUCCESS;
}

static int handle_table_request(struct c24_surface_t *surface)
{
	struct c24_frame recv_frame;
	struct sockaddr_ll recv_addr;
	socklen_t recv_addr_len = sizeof(struct sockaddr_ll);

	//	Receive the request

	const int size = recvfrom(surface->sock, &recv_frame, sizeof(recv_frame), 0,
			(struct sockaddr*) &recv_addr, &recv_addr_len);

	if (size < 0)
		return errno;

	//	Ensure that packet was from the surface we are dealing with
	if (hw_adress_cmp(surface->address.sll_addr, recv_addr.sll_addr) != 0)
		return SUCCESS;	//	This is not an error

	//	Size check (ensure that packet is complete)

	if (size < ntohs(recv_frame.header.size))
		return C24_INCOMPLETE_FRAME;

	// Checksum check

	const uint16_t recv_checksum = recv_frame.header.blocks_checksum;
	c24_frame_compute_checksum(&recv_frame);

	if (recv_checksum != recv_frame.header.blocks_checksum)
		return C24_WRONG_CHECKSUM;


	if (recv_frame.header.frame_type == C24_FRAME_TYPE_ANNOUNCE)
	{
		LOG_PRINT("Try to reconnect\n");
		const int ret =  c24_surface_connect(surface);

		if (ret == SUCCESS) {
			LOG_PRINT("Reconnection Success !\n");
			if (surface->reconnection_callback != NULL)
				surface->reconnection_callback(surface->user_data);
		}

		return ret;
	}
	else if (recv_frame.header.frame_type == C24_FRAME_TYPE_REANNOUNCE)
	{
		DEBUG_PRINT("Reannounce received, pinging\n");
		return c24_surface_ping(surface, ACKNOWLEDGMENT_TIMEOUT_USEC);
	}
	else if(recv_frame.header.frame_type != C24_FRAME_TYPE_DEFAULT)
	{
		LOG_PRINT("Warning : Unable to do something with frame type %x\n",
				recv_frame.header.frame_type);
		return SUCCESS; // not an error
	}

	// Send acknowledgment (needed only for default frame

	c24_acknowledgment_send(surface, &recv_frame);

	// Handle blocks

	const unsigned int block_count = recv_frame.header.block_count;
	const unsigned int playload_size = ntohs(recv_frame.header.size)
			- sizeof(struct c24_frame_header);
	unsigned int offset = 0;

	DEBUG_PRINT("Received a %u block request frame, reading blocks..\n", block_count);

	for (unsigned int i = 0; i < block_count; i++)
	{
		size_t block_size;
		const int err = 
			handle_table_request_block(surface,
				recv_frame.playload + offset, &block_size);

		if (err == SUCCESS) {
			offset += block_size;
		}
		else if (err == C24_UNKNOW_REQUEST_BLOCK) {	//	not a fatal error
			break;
		}
		else {
			return err;
		}
	}

	// Check coherence
	if (offset != playload_size)	//	Not all blocks where matched
		LOG_PRINT("Warning : Some surface requests were not understood (%u bytes were not handled)\n", 
			playload_size - offset);

	return SUCCESS;
}

static int send_some_table_requests(
	struct c24_surface_t *surface,
	const unsigned int max_block_count,
	const unsigned int usec_ack_timeout)
{
	const unsigned int request_count = queue_get_element_count(
			surface->request_queue);

	if (request_count > 0)
	{

		const unsigned int send_count =
				request_count >= max_block_count ?
						max_block_count : request_count;

		struct c24_request request;
		struct c24_frame frame;

		// Build Frame

		c24_frame_init(&frame);

		for (unsigned int i = 0; i < send_count; i++)
		{
			queue_dequeue(surface->request_queue, &request);
			c24_frame_add_request(&frame, &request);
		}

		DEBUG_PRINT("Send a %u-block frame\n", send_count);
		// Send Frame
		return c24_acknowledged_send_frame(
				surface, 
				&frame, 
				usec_ack_timeout,
				MAX_SEND_TRY_COUNT);
	}
	// else ping ?

	return SUCCESS;
}

static int apply_some_vumeter_mask_requests(
	struct c24_surface_t *surface,
	const unsigned int max_vumeter_request)
{
	const size_t vumeter_request_count = queue_get_element_count(
			surface->vumeter_mask_queue);

	if (vumeter_request_count > 0)
	{

		const unsigned int send_count =
				vumeter_request_count >= max_vumeter_request ?
						max_vumeter_request : vumeter_request_count;

		unsigned int mask_change_count = 0;

		// Apply request on vumeter mask

		for (unsigned int i = 0; i < send_count; i++)
		{
			struct c24_vu_meter_mask_request request;
			uint16_t *target;

			queue_dequeue(surface->vumeter_mask_queue, &request);
			target = &(surface->vumeter_mask[request.track_id * 2
					+ request.vumeter_id]);

			const uint16_t request_mask = htons(request.mask);

			if (request_mask != *target)
			{
				*target = request_mask;
				mask_change_count++;
			}
		}

		if (mask_change_count > 0)
		{
			DEBUG_PRINT("Send a vumeter frame with %u modifications\n", send_count);
			return c24_surface_update_vumeter_mask(surface); // No Acknowledgment needed here
		}
	}

	return SUCCESS;
}

static void handle_error(
	struct c24_surface_t *surface,
	const int error)
{
	printf("Warning : %s\n", c24_strerror(error));

	switch (error)
	{
		case C24_TIMEOUT_REACHED:
			LOG_PRINT("Trying to reconnect...\n");
			c24_surface_find(surface, surface->reconnection_callback);
			break;

		case SUCCESS:
		case C24_WRONG_CHECKSUM:
		case C24_INCOMPLETE_FRAME:
		case C24_UNKNOW_REQUEST_BLOCK:
			break;	//	These are not fatal errors

		default:	
			LOG_PRINT("This was a Fatal Error\n");
			exit(1);
			break;
	}
}

void c24_surface_manager(struct c24_surface_t *surface)
{
	fd_set socket_fd;
	struct timeval socket_wait_timeout =
	{ .tv_sec = 0, .tv_usec =
	MINIMUM_REQUEST_INTERVAL_USEC };

	DEBUG_PRINT("Entering C24 Table Manager\n");

	while (surface->surface_manager_running)
	{

		//	Wait for the socket to be ready to be read,
		//	or the delay between two request to be reached

		FD_ZERO(&socket_fd);
		FD_SET(surface->sock, &socket_fd);

		const int select_ret = select(surface->sock + 1, &socket_fd, NULL, NULL,
				&socket_wait_timeout);

		if (select_ret < 0)
		{
			handle_error(surface, errno);
		}
		else if (select_ret == 0)
		{
			// Select timeout : dequeue and send requests

			int err = apply_some_vumeter_mask_requests(surface,
					MAXIMUM_VUMETER_MASK_UPDATE_PER_FRAME);

			if (err != SUCCESS)
				handle_error(surface, err);

			err = send_some_table_requests(surface,
				MAXIMUM_BLOCK_COUNT_PER_FRAME,
				ACKNOWLEDGMENT_TIMEOUT_USEC);

			if (err != SUCCESS)
				handle_error(surface, err);

			// Reset the timer
			socket_wait_timeout.tv_sec = 0;
			socket_wait_timeout.tv_usec = MINIMUM_REQUEST_INTERVAL_USEC;
		}
		else
		{
			// There is data to read on socket

			const int err = handle_table_request(surface);

			if (err != SUCCESS)
				handle_error(surface, err);
		}
	}
}

