#include "c24_request.h"

#include <string.h>
#include "log.h"

static int add_slider_pos_request(
	struct c24_frame *frame,
	const uint8_t track_id,
	const uint16_t value)
{
	const uint8_t block[] =
	{
		0x00, 0x06, track_id, 0x00, value & 0x3 , value >> 2
	};
	return c24_frame_add_block(frame, block, sizeof(block));
}

static int add_display_request(
	struct c24_frame *frame,
	const uint8_t track_id,
	const uint8_t line,
	const char text[])
{
	uint8_t block[11] =
	{
		0x03, 0x0b, track_id, 0x10 + line
	};

	memcpy(block + 4, text, 7);
	return c24_frame_add_block(frame, block, sizeof(block));
}

static int add_knob_led_mask_request(
	struct c24_frame *frame,
	const uint8_t track_id,
	const uint16_t mask)
{
	const uint8_t block[] =
	{
		0x02, 0x06, track_id, 0x00,
		(mask & 0xff00) >> 8, mask & 0xff
	};
	return c24_frame_add_block(frame, block, sizeof(block));
}

static int add_button_led_request(
	struct c24_frame *frame,
	const uint16_t button,
	const uint8_t state)
{
	const uint8_t block[] =
	{
		0x01, 0x05, (button & 0xff00) >> 8,
		button & 0xff, state
	};
	return c24_frame_add_block(frame, block, sizeof(block));
}

static int add_counter_screen_mask_request(
	struct c24_frame *frame,
	const uint64_t digit_mask,
	const uint8_t dot_mask)
{
	const uint64_t m = htobe64(digit_mask);

	uint8_t block[13] =
	{
		0x06, 0x0d, 0x00, 0x00, dot_mask
	};


	memcpy(block + 5, &m, 8);
	return c24_frame_add_block(frame, block, sizeof(block));
}

int c24_frame_add_request(
	struct c24_frame *frame,
	const struct c24_request *req)
{

	switch (req->type)
	{

		case SLIDER_POS_REQUEST:
			return add_slider_pos_request(frame,
					req->slider_pos_request.track_id,
					req->slider_pos_request.value);

		case DISPLAY_REQUEST:
			return add_display_request(frame, req->display_request.track_id,
					req->display_request.line, req->display_request.text);

		case KNOB_LED_MASK_REQUEST:
			return add_knob_led_mask_request(frame,
					req->knob_led_mask_request.track_id,
					req->knob_led_mask_request.mask);

		case BUTTON_LED_REQUEST:
			return add_button_led_request(frame, req->button_led_request.button,
					req->button_led_request.state);

		case COUNTER_SCREEN_MASK_REQUEST:
			return add_counter_screen_mask_request(frame,
					req->counter_screen_mask_request.digit_mask,
					req->counter_screen_mask_request.dot_mask);

		default:
			DEBUG_PRINT("warning : Unknown abstract request type\n");
			return -1;

	}
}
