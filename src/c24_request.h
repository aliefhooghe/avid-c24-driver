#ifndef C24_REQUEST_H_
#define C24_REQUEST_H_

#include <stdint.h>
#include "c24_frame.h"

struct c24_request
{

	enum
	{
		SLIDER_POS_REQUEST,
		DISPLAY_REQUEST,
		KNOB_LED_MASK_REQUEST,
		BUTTON_LED_REQUEST,
		COUNTER_SCREEN_MASK_REQUEST

	} type;

	union
	{
		struct
		{
			uint8_t track_id;
			uint16_t value;
		} slider_pos_request;

		struct
		{
			uint8_t track_id;
			uint8_t line;
			char text[7];
		} display_request;

		struct
		{
			uint8_t track_id;
			uint16_t mask;
		} knob_led_mask_request;

		struct
		{
			uint16_t button;
			uint8_t state;
		} button_led_request;

		struct
		{
			uint64_t digit_mask;
			uint8_t dot_mask;
		} counter_screen_mask_request;
	};
};

int c24_frame_add_request(
	struct c24_frame *req,
	const struct c24_request *ab_req);

#endif
