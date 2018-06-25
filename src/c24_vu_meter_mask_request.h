#ifndef C24_VU_METER_MASK_REQUEST_H_
#define C24_VU_METER_MASK_REQUEST_H_

#include <stdint.h>

#include "c24_surface.h"

struct c24_vu_meter_mask_request
{
	uint8_t track_id;       //  [0, 23]
	uint8_t vumeter_id;    //  [0, 1]
	uint16_t mask;
};

int c24_surface_update_vumeter_mask(struct c24_surface_t *surface);

#endif
