#ifndef C24_PRIVATE_DEFINITIONS_H_
#define C24_PRIVATE_DEFINITIONS_H_

#include <stdint.h>
#include <pthread.h>

#include "c24_vu_meter_mask_request.h"
#include "network.h"
#include "queue.h"

struct c24_surface_t
{
	int sock;
	struct sockaddr_ll address;

	uint16_t sequence_number;
	char version[64];

	pthread_t surface_manager;
	int surface_manager_running;

	pthread_mutex_t request_queue_mutex;
	struct queue *request_queue;

	uint16_t vumeter_mask[2 * C24_TRACK_COUNT];
	pthread_mutex_t vumeter_mask_queue_mutex;
	struct queue *vumeter_mask_queue;

	void *user_data;
	c24_button_callback_t button_callback;
	c24_slider_callback_t slider_callback;
	c24_knob_callback_t knob_callback;
	c24_reconnection_callback_t reconnection_callback;
};

#endif
