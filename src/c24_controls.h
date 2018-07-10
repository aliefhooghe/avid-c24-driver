#ifndef C24_CONTROLS_H_
#define C24_CONTROLS_H_

#include <stdint.h>

#define C24_TRACK_COUNT              24
#define C24_SLIDER_COUNT             C24_TRACK_COUNT
#define C24_BUTTON_COUNT             456
#define C24_KNOB_COUNT               25

#define C24_UNKNOWN_CONTROL          ((uint16_t)0xffff)   
#define C24_UNKNOWN_BUTTON           C24_UNKNOWN_CONTROL
#define C24_UNKNOWN_KNOB             C24_UNKNOWN_CONTROL 

const char *c24_surface_get_button_name(const uint16_t button);
const char *c24_surface_get_knob_name(const uint16_t knob);

int c24_button_is_slider(const uint16_t button);

uint8_t c24_button_track(const uint16_t button);
uint16_t c24_button_slider(const uint8_t track_id);
uint16_t c24_button_mute(const uint8_t track_id);
uint16_t c24_button_solo(const uint8_t track_id);
uint16_t c24_button_select(const uint8_t track_id);

int c24_knob_is_pan_knob(const uint16_t knob);

uint8_t c24_knob_track(const uint16_t knob);
uint16_t c24_pan_knob(const uint8_t track_id);

#define C24_PITCH_WHEEL         0x18

#define C24_BUTTON_REWIND       0x1aa
#define C24_BUTTON_FASTFORWARD  0x1ab
#define C24_BUTTON_STOP         0x1ac
#define C24_BUTTON_PLAY         0x1ad
#define C24_BUTTON_RECORD       0x1ae

#endif