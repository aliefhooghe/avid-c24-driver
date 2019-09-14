#ifndef DIGIDESIGN_SURFACE_H_
#define DIGIDESIGN_SURFACE_H_

#include <stdint.h>
#include "c24_controls.h"

struct c24_surface_t;

typedef void (*c24_button_callback_t)(void *user_data, const uint16_t button_id, const uint8_t state);
typedef void (*c24_slider_callback_t)(void *user_data, const uint8_t track_id, const uint16_t value);
typedef void (*c24_knob_callback_t)(void *user_data, const uint16_t knob, const uint8_t state);
typedef void (*c24_reconnection_callback_t)(void *user_data);

struct c24_surface_t * c24_surface_open(const unsigned int request_queue_size);
int c24_surface_close(struct c24_surface_t *surface);

void c24_surface_set_user_data(
	struct c24_surface_t *surface,
	void *user_data);

void c24_surface_set_button_callback(
	struct c24_surface_t *surface,
	c24_button_callback_t callback);

void c24_surface_set_slider_callback(
	struct c24_surface_t *surface,
	c24_slider_callback_t callback);

void c24_surface_set_knob_callback(
	struct c24_surface_t *surface,
	c24_knob_callback_t callback);

void c24_surface_set_reconnection_callback(
	struct c24_surface_t *surface,
	c24_reconnection_callback_t callback);

//	INFO

const char *c24_surface_get_version(struct c24_surface_t *surface);

//  SLIDER Control

int c24_surface_set_slider_pos(
	struct c24_surface_t *surface,
	const uint8_t track_id,
	const uint16_t value);

//  SCREEN Control

int c24_surface_display(
	struct c24_surface_t *surface,
	const char *str,
	const uint8_t track_id,
	const unsigned int line);

int c24_surface_print(
	struct c24_surface_t *surface,
	const char *str,
	const uint8_t track_id,
	const unsigned int line);

int c24_surface_display_float(
	struct c24_surface_t *surface,
	const float value,
	const uint8_t track_id,
	const unsigned int line);

//  LED control

int c24_surface_set_knob_led_mask(
	struct c24_surface_t *surface,
	const uint16_t knob,
	const uint16_t mask);

int c24_surface_set_button_led_state(
	struct c24_surface_t *surface,
	const uint16_t button,
	const uint8_t state);

// Main Counter Screen Control

int c24_surface_set_counter_screen_mask(
	struct c24_surface_t *surface,
	const uint64_t digit_mask,
	const uint8_t dot_mask);

// VUMETER control

int c24_surface_set_vumeter_mask(
	struct c24_surface_t *surface,
	const uint8_t track_id,
	const uint8_t vumeter_id,
	const uint16_t mask);


#endif
