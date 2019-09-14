#ifndef C24_FRAME_H_
#define C24_FRAME_H_

#include "c24_protocol.h"
#include "c24_surface_private_definitions.h"

#define C24_FRAME_MAX_PLAYLOAD_SIZE 512 

struct c24_frame_header
{
	uint16_t size;
	uint16_t blocks_checksum;
	uint16_t padd1;					//  unknown usage
	uint16_t sequence_number;
	uint16_t padd2;					//	unknown usage
	uint16_t acknowledgment_number; // 	Set only for acknowledgment frame
	uint16_t padd3;					//	unknown usage
	uint8_t frame_type;
	uint8_t block_count;
}__attribute__((__packed__));

struct c24_frame
{
	struct c24_frame_header header;
	uint8_t playload[C24_FRAME_MAX_PLAYLOAD_SIZE];
}__attribute__((__packed__));

void c24_frame_init(struct c24_frame *frame);

int c24_frame_add_block(
	struct c24_frame *frame,
	const void *block,
	const size_t block_size);

void c24_frame_compute_checksum(struct c24_frame *request);

int c24_frame_send(struct c24_surface_t *surface, struct c24_frame *frame);

int c24_frame_broadcast_send(
	struct c24_surface_t *surface,
	struct c24_frame *frame);

struct c24_request;
int c24_one_block_frame_send(
	struct c24_surface_t *surface,
	const struct c24_request *ab_req);

int c24_acknowledgment_receive(
	struct c24_surface_t *surface,
	struct timeval *timeout);

int c24_acknowledgment_send(
	struct c24_surface_t *surface,
	const struct c24_frame *received_frame);

int c24_surface_ping(
	struct c24_surface_t *surface,
	const unsigned int usec_aquitement_timeout);

#endif 
