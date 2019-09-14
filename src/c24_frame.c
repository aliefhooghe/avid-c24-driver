#include <stdlib.h>
#include <string.h>

#include "c24_frame.h"
#include "c24_request.h"
#include "c24_error.h"
#include "log.h"

void c24_frame_init(struct c24_frame *frame)
{
	bzero(frame, sizeof(struct c24_frame));
	frame->header.size = htons(sizeof(struct c24_frame_header));
}

int c24_frame_add_block(
	struct c24_frame *frame,
	const void *block,
	const size_t block_size)
{
	const uint32_t request_size = ntohs(frame->header.size);
	const uint32_t playload_size = request_size
			- sizeof(struct c24_frame_header);

	if (playload_size + block_size > C24_FRAME_MAX_PLAYLOAD_SIZE)
		return ENOBUFS;

	memcpy(frame->playload + playload_size, block, block_size);

	frame->header.size = htons(request_size + block_size);
	frame->header.block_count++;

	return SUCCESS;
}

void c24_frame_compute_checksum(struct c24_frame *frame)
{
	const uint32_t playload_size = ntohs(frame->header.size)
			- sizeof(struct c24_frame_header);

	uint16_t checksum = 0;

	for (unsigned int i = 0; i < playload_size; i++)
		checksum += frame->playload[i];

	frame->header.blocks_checksum = htons(checksum);
}

static int c24_frame_send_to(
	struct c24_surface_t *surface,
	struct c24_frame *frame,
	const struct sockaddr_ll *addr)
{
	c24_frame_compute_checksum(frame);

	surface->sequence_number++;
	frame->header.sequence_number = htons(surface->sequence_number);

	const int err = sendto(surface->sock, frame, ntohs(frame->header.size), 0,
			(struct sockaddr*) addr, sizeof(struct sockaddr_ll));

	if (err < 0)
		return errno;
	else
		return SUCCESS;
}


int c24_frame_send(struct c24_surface_t *surface, struct c24_frame *frame)
{
	return c24_frame_send_to(surface, frame, &(surface->address));
}

int c24_frame_broadcast_send(
	struct c24_surface_t *surface,
	struct c24_frame *frame)
{
	struct sockaddr_ll broadcast_addr;

	// Initialize broadcast address
	memcpy(&broadcast_addr, &(surface->address), sizeof(struct sockaddr_ll)); //	retrieve if_index, protocol...
	memset(broadcast_addr.sll_addr, 0xff, 6);	//	broadcast

	return c24_frame_send_to(surface, frame, &broadcast_addr);
}

int c24_one_block_frame_send(
	struct c24_surface_t *surface,
	const struct c24_request *ab_req)
{
	struct c24_frame req;
	c24_frame_init(&req);
	c24_frame_add_request(&req, ab_req);
	return c24_frame_send(surface, &req);
}

int c24_acknowledgment_receive(
	struct c24_surface_t *surface,
	struct timeval *timeout)
{
	struct sockaddr_ll recv_addr;
	struct c24_frame frame;

	VERBOSE_PRINT("Waiting acknowledgment...\n");

	do {
		size_t size;
		int err = 
			recvfrom_with_timeout(surface->sock, &frame, sizeof(frame),
				&recv_addr, timeout, &size);

		if (err != SUCCESS)
			return err;

	} while (frame.header.frame_type != C24_FRAME_TYPE_ACKNOWLEDGMENT);

	const uint16_t acknowledgment_number =
			ntohs(frame.header.acknowledgment_number);

	if (surface->sequence_number == acknowledgment_number) {
		VERBOSE_PRINT("Acknowledgment Ok\n");
		return 0;
	}
	else {
		VERBOSE_PRINT("Acknowledgment error : bad acknowledgment number (%02x != %02x)\n",
				acknowledgment_number, surface->sequence_number);
		return C24_WRONG_CHECKSUM;
	}
}

int c24_acknowledgment_send(
	struct c24_surface_t *surface,
	const struct c24_frame *received_request)
{
	struct c24_frame frame;

	c24_frame_init(&frame);
	frame.header.frame_type = C24_FRAME_TYPE_ACKNOWLEDGMENT;
	frame.header.acknowledgment_number =
			received_request->header.sequence_number; // big endian

	return c24_frame_send(surface, &frame);
}

int c24_surface_ping(
	struct c24_surface_t *surface,
	const unsigned int usec_timeout)
{
	struct timeval timeout =
	{ .tv_sec = 0, .tv_usec = usec_timeout };
	struct c24_frame req;

	VERBOSE_PRINT("Pinging surface\n");

	c24_frame_init(&req);
	c24_frame_send(surface, &req);
	return c24_acknowledgment_receive(surface, &timeout);
}
