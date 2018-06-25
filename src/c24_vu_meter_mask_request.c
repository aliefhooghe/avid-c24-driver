#include <string.h>

#include "c24_vu_meter_mask_request.h"
#include "c24_frame.h"

int c24_surface_update_vumeter_mask(struct c24_surface_t *surface)
{
	struct c24_frame frame;

	c24_frame_init(&frame);
	frame.header.frame_type = C24_FRAME_TYPE_VUMETER_MASK;
	frame.header.size = htons(100 + sizeof(struct c24_frame_header));
	frame.header.block_count = 1;
	frame.playload[0] = 0x04;
	frame.playload[1] = 0x64;
	frame.playload[2] = 0x25;
	frame.playload[3] = 0x00;
	memcpy(frame.playload + 4, surface->vumeter_mask, 96);

	return c24_frame_send(surface, &frame);
}

