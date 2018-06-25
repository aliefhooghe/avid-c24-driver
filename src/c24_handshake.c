#include <string.h>
#include <stdint.h>

#include "log.h"
#include "network.h"
#include "c24_frame.h"
#include "c24_surface_private_definitions.h"
#include "utility.h"

int c24_surface_connect(struct c24_surface_t *surface)
{
	struct c24_frame frame;
	
	// Initialize and send broadcast TakeOver frame
	c24_frame_init(&frame);
	frame.header.frame_type = C24_FRAME_TYPE_BROADCAST_TAKEOVER;
	
	DEBUG_PRINT("Sending broadcast take over\n");
	c24_frame_broadcast_send(surface, &frame); // no acknowledgment (broadcast)
			
	// Initialize and send table TakeOver frame
	c24_frame_init(&frame);
	frame.header.frame_type = C24_FRAME_TYPE_SURFACE_TAKEOVER;
	
	DEBUG_PRINT("Sending surface take over\n");
	c24_frame_send(surface, &frame);
	
	return c24_acknowledgment_receive(surface, NULL); // unlimited timeout
}

static void read_announce_frame(
	struct c24_surface_t *surface,
	const struct c24_frame *announce_frame)
{
	const unsigned int playload_size = ntohs(announce_frame->header.size)
			- sizeof(struct c24_frame_header);
	memcpy(surface->version, announce_frame->playload + 14, playload_size - 14);
}

int c24_surface_find(
	struct c24_surface_t *surface,
	c24_reconnection_callback_t callback)
{
	socklen_t recv_addr_len = sizeof(struct sockaddr_ll);
	struct c24_frame recv_frame;
	
	LOG_PRINT("Searching Digidesign c24 table .....\n");

	while (1) {
		
		const int size = recvfrom(surface->sock, &recv_frame,
				sizeof(struct c24_frame), 0,
				(struct sockaddr*) &(surface->address), &recv_addr_len);
		
		if (size < 0)
			return size;
		
		if (recv_frame.header.frame_type == C24_FRAME_TYPE_ANNOUNCE) {
			DEBUG_PRINT("Received announce frame\n");
			read_announce_frame(surface, &recv_frame);
			
			const int ret = c24_surface_connect(surface);

			if (ret == 0 && callback != NULL)
				callback(surface->user_data);
		}
		else if (recv_frame.header.frame_type == C24_FRAME_TYPE_REANNOUNCE) {
			DEBUG_PRINT("Received ReAnnounce frame\n");
			read_announce_frame(surface, &recv_frame);
			return c24_surface_ping(surface, 1000000); // TODO mieux
		}
	}

	LOG_PRINT("Found Digidesign c24 table : \n\tversion = %s\n\thw_adress = ",
			surface->version);
	print_hw_address(surface->address.sll_addr);
	LOG_PRINT("\n");
}

int c24_surface_disconnect(
	struct c24_surface_t *surface,
	const unsigned int usec_timeout)
{
	struct c24_frame frame;
	struct timeval timeout = {.tv_sec =0, .tv_usec = usec_timeout};

	c24_frame_init(&frame);
	frame.header.frame_type = C24_FRAME_TYPE_DISCONECT;
	c24_frame_send(surface, &frame);

	return c24_acknowledgment_receive(surface, &timeout);
}

