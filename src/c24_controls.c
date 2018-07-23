
#include <stdint.h>
#include "c24_controls.h"

struct c24_control {
	uint16_t raw_id;		//	Used In Comunication Protocol
    const char *name;		//	Human Readable Name
	uint8_t has_led;		//	1 if the button has a led
};	

static struct c24_control __c24_buttons__[C24_BUTTON_COUNT] =
{
    {.raw_id = 0x0, .name = "SliderTouch-1", 		.has_led = 0},
	{.raw_id = 0x5, .name = "Source-HPF-1", 		.has_led = 0},
	{.raw_id = 0xb, .name = "TrackAuto-1", 			.has_led = 0},
	{.raw_id = 0xc, .name = "TrackEQ-1", 			.has_led = 1},
	{.raw_id = 0xd, .name = "TrackDyn-1", 			.has_led = 1},
	{.raw_id = 0xe, .name = "TrackInsert-1", 		.has_led = 1},
	{.raw_id = 0xf, .name = "TrackSend-1", 			.has_led = 1},
	{.raw_id = 0x13, .name = "Track-1", 			.has_led = 1},
	{.raw_id = 0x14, .name = "TrackInput-1", 		.has_led = 1},
	{.raw_id = 0x15, .name = "TrackRec-1", 			.has_led = 1},
	{.raw_id = 0x16, .name = "Select-1", 			.has_led = 1},
	{.raw_id = 0x17, .name = "Solo-1", 				.has_led = 1},
	{.raw_id = 0x18, .name = "Mute-1", 				.has_led = 1},
	{.raw_id = 0x100, .name = "SliderTouch-2", 		.has_led = 0},
	{.raw_id = 0x105, .name = "Source-HPF-2", 		.has_led = 0},
	{.raw_id = 0x10b, .name = "TrackAuto-2", 		.has_led = 0},
	{.raw_id = 0x10c, .name = "TrackEQ-2", 			.has_led = 1},
	{.raw_id = 0x10d, .name = "TrackDyn-2", 		.has_led = 1},
	{.raw_id = 0x10e, .name = "TrackInsert-2", 		.has_led = 1},
	{.raw_id = 0x10f, .name = "TrackSend-2", 		.has_led = 1},
	{.raw_id = 0x113, .name = "Track-2", 			.has_led = 1},
	{.raw_id = 0x114, .name = "TrackInput-2", 		.has_led = 1},
	{.raw_id = 0x115, .name = "TrackRec-2", 		.has_led = 1},
	{.raw_id = 0x116, .name = "Select-2", 			.has_led = 1},
	{.raw_id = 0x117, .name = "Solo-2", 			.has_led = 1},
	{.raw_id = 0x118, .name = "Mute-2", 			.has_led = 1},
	{.raw_id = 0x200, .name = "SliderTouch-3", 		.has_led = 0},
	{.raw_id = 0x205, .name = "Source-HPF-3", 		.has_led = 0},
	{.raw_id = 0x20b, .name = "TrackAuto-3", 		.has_led = 0},
	{.raw_id = 0x20c, .name = "TrackEQ-3", 			.has_led = 1},
	{.raw_id = 0x20d, .name = "TrackDyn-3", 		.has_led = 1},
	{.raw_id = 0x20e, .name = "TrackInsert-3", 		.has_led = 1},
	{.raw_id = 0x20f, .name = "TrackSend-3", 		.has_led = 1},
	{.raw_id = 0x213, .name = "Track-3", 			.has_led = 1},
	{.raw_id = 0x214, .name = "TrackInput-3", 		.has_led = 1},
	{.raw_id = 0x215, .name = "TrackRec-3", 		.has_led = 1},
	{.raw_id = 0x216, .name = "Select-3", 			.has_led = 1},
	{.raw_id = 0x217, .name = "Solo-3", 			.has_led = 1},
	{.raw_id = 0x218, .name = "Mute-3", 			.has_led = 1},
	{.raw_id = 0x300, .name = "SliderTouch-4", 		.has_led = 0},
	{.raw_id = 0x305, .name = "Source-HPF-4", 		.has_led = 0},
	{.raw_id = 0x30b, .name = "TrackAuto-4", 		.has_led = 0},
	{.raw_id = 0x30c, .name = "TrackEQ-4", 			.has_led = 1},
	{.raw_id = 0x30d, .name = "TrackDyn-4", 		.has_led = 1},
	{.raw_id = 0x30e, .name = "TrackInsert-4", 		.has_led = 1},
	{.raw_id = 0x30f, .name = "TrackSend-4", 		.has_led = 1},
	{.raw_id = 0x313, .name = "Track-4", 			.has_led = 1},
	{.raw_id = 0x314, .name = "TrackInput-4", 		.has_led = 1},
	{.raw_id = 0x315, .name = "TrackRec-4", 		.has_led = 1},
	{.raw_id = 0x316, .name = "Select-4", 			.has_led = 1},
	{.raw_id = 0x317, .name = "Solo-4", 			.has_led = 1},
	{.raw_id = 0x318, .name = "Mute-4", 			.has_led = 1},
	{.raw_id = 0x400, .name = "SliderTouch-5", 		.has_led = 0},
	{.raw_id = 0x405, .name = "Source-HPF-5", 		.has_led = 0},
	{.raw_id = 0x40b, .name = "TrackAuto-5", 		.has_led = 0},
	{.raw_id = 0x40c, .name = "TrackEQ-5", 			.has_led = 1},
	{.raw_id = 0x40d, .name = "TrackDyn-5", 		.has_led = 1},
	{.raw_id = 0x40e, .name = "TrackInsert-5", 		.has_led = 1},
	{.raw_id = 0x40f, .name = "TrackSend-5", 		.has_led = 1},
	{.raw_id = 0x413, .name = "Track-5", 			.has_led = 1},
	{.raw_id = 0x414, .name = "TrackInput-5", 		.has_led = 1},
	{.raw_id = 0x415, .name = "TrackRec-5", 		.has_led = 1},
	{.raw_id = 0x416, .name = "Select-5", 			.has_led = 1},
	{.raw_id = 0x417, .name = "Solo-5", 			.has_led = 1},
	{.raw_id = 0x418, .name = "Mute-5", 			.has_led = 1},
	{.raw_id = 0x500, .name = "SliderTouch-6", 		.has_led = 0},
	{.raw_id = 0x505, .name = "Source-HPF-6", 		.has_led = 0},
	{.raw_id = 0x50b, .name = "TrackAuto-6", 		.has_led = 0},
	{.raw_id = 0x50c, .name = "TrackEQ-6", 			.has_led = 1},
	{.raw_id = 0x50d, .name = "TrackDyn-6", 		.has_led = 1},
	{.raw_id = 0x50e, .name = "TrackInsert-6", 		.has_led = 1},
	{.raw_id = 0x50f, .name = "TrackSend-6", 		.has_led = 1},
	{.raw_id = 0x513, .name = "Track-6", 			.has_led = 1},
	{.raw_id = 0x514, .name = "TrackInput-6", 		.has_led = 1},
	{.raw_id = 0x515, .name = "TrackRec-6", 		.has_led = 1},
	{.raw_id = 0x516, .name = "Select-6", 			.has_led = 1},
	{.raw_id = 0x517, .name = "Solo-6", 			.has_led = 1},
	{.raw_id = 0x518, .name = "Mute-6", 			.has_led = 1},
	{.raw_id = 0x600, .name = "SliderTouch-7", 		.has_led = 0},
	{.raw_id = 0x605, .name = "Source-HPF-7", 		.has_led = 0},
	{.raw_id = 0x60b, .name = "TrackAuto-7", 		.has_led = 0},
	{.raw_id = 0x60c, .name = "TrackEQ-7", 			.has_led = 1},
	{.raw_id = 0x60d, .name = "TrackDyn-7", 		.has_led = 1},
	{.raw_id = 0x60e, .name = "TrackInsert-7", 		.has_led = 1},
	{.raw_id = 0x60f, .name = "TrackSend-7", 		.has_led = 1},
	{.raw_id = 0x613, .name = "Track-7", 			.has_led = 1},
	{.raw_id = 0x614, .name = "TrackInput-7", 		.has_led = 1},
	{.raw_id = 0x615, .name = "TrackRec-7", 		.has_led = 1},
	{.raw_id = 0x616, .name = "Select-7", 			.has_led = 1},
	{.raw_id = 0x617, .name = "Solo-7", 			.has_led = 1},
	{.raw_id = 0x618, .name = "Mute-7", 			.has_led = 1},
	{.raw_id = 0x700, .name = "SliderTouch-8", 		.has_led = 0},
	{.raw_id = 0x705, .name = "Source-HPF-8", 		.has_led = 0},
	{.raw_id = 0x70b, .name = "TrackAuto-8", 		.has_led = 0},
	{.raw_id = 0x70c, .name = "TrackEQ-8", 			.has_led = 1},
	{.raw_id = 0x70d, .name = "TrackDyn-8", 		.has_led = 1},
	{.raw_id = 0x70e, .name = "TrackInsert-8", 		.has_led = 1},
	{.raw_id = 0x70f, .name = "TrackSend-8", 		.has_led = 1},
	{.raw_id = 0x713, .name = "Track-8", 			.has_led = 1},
	{.raw_id = 0x714, .name = "TrackInput-8", 		.has_led = 1},
	{.raw_id = 0x715, .name = "TrackRec-8", 		.has_led = 1},
	{.raw_id = 0x716, .name = "Select-8", 			.has_led = 1},
	{.raw_id = 0x717, .name = "Solo-8", 			.has_led = 1},
	{.raw_id = 0x718, .name = "Mute-8", 			.has_led = 1},
	{.raw_id = 0x800, .name = "SliderTouch-9", 		.has_led = 0},
	{.raw_id = 0x805, .name = "Source-HPF-9", 		.has_led = 0},
	{.raw_id = 0x80b, .name = "TrackAuto-9", 		.has_led = 0},
	{.raw_id = 0x80c, .name = "TrackEQ-9", 			.has_led = 1},
	{.raw_id = 0x80d, .name = "TrackDyn-9", 		.has_led = 1},
	{.raw_id = 0x80e, .name = "TrackInsert-9", 		.has_led = 1},
	{.raw_id = 0x80f, .name = "TrackSend-9", 		.has_led = 1},
	{.raw_id = 0x813, .name = "Track-9", 			.has_led = 1},
	{.raw_id = 0x814, .name = "TrackInput-9", 		.has_led = 1},
	{.raw_id = 0x815, .name = "TrackRec-9", 		.has_led = 1},
	{.raw_id = 0x816, .name = "Select-9", 			.has_led = 1},
	{.raw_id = 0x817, .name = "Solo-9", 			.has_led = 1},
	{.raw_id = 0x818, .name = "Mute-9", 			.has_led = 1},
	{.raw_id = 0x900, .name = "SliderTouch-10", 	.has_led = 0},
	{.raw_id = 0x905, .name = "Source-HPF-10", 		.has_led = 0},
	{.raw_id = 0x90b, .name = "TrackAuto-10", 		.has_led = 0},
	{.raw_id = 0x90c, .name = "TrackEQ-10", 		.has_led = 1},
	{.raw_id = 0x90d, .name = "TrackDyn-10", 		.has_led = 1},
	{.raw_id = 0x90e, .name = "TrackInsert-10", 	.has_led = 1},
	{.raw_id = 0x90f, .name = "TrackSend-10", 		.has_led = 1},
	{.raw_id = 0x913, .name = "Track-10", 			.has_led = 1},
	{.raw_id = 0x914, .name = "TrackInput-10", 		.has_led = 1},
	{.raw_id = 0x915, .name = "TrackRec-10", 		.has_led = 1},
	{.raw_id = 0x916, .name = "Select-10", 			.has_led = 1},
	{.raw_id = 0x917, .name = "Solo-10", 			.has_led = 1},
	{.raw_id = 0x918, .name = "Mute-10", 			.has_led = 1},
	{.raw_id = 0xa00, .name = "SliderTouch-11", 	.has_led = 0},
	{.raw_id = 0xa05, .name = "Source-HPF-11", 		.has_led = 0},
	{.raw_id = 0xa0b, .name = "TrackAuto-11", 		.has_led = 0},
	{.raw_id = 0xa0c, .name = "TrackEQ-11", 		.has_led = 1},
	{.raw_id = 0xa0d, .name = "TrackDyn-11", 		.has_led = 1},
	{.raw_id = 0xa0e, .name = "TrackInsert-11", 	.has_led = 1},
	{.raw_id = 0xa0f, .name = "TrackSend-11", 		.has_led = 1},
	{.raw_id = 0xa13, .name = "Track-11", 			.has_led = 1},
	{.raw_id = 0xa14, .name = "TrackInput-11", 		.has_led = 1},
	{.raw_id = 0xa15, .name = "TrackRec-11", 		.has_led = 1},
	{.raw_id = 0xa16, .name = "Select-11", 			.has_led = 1},
	{.raw_id = 0xa17, .name = "Solo-11", 			.has_led = 1},
	{.raw_id = 0xa18, .name = "Mute-11", 			.has_led = 1},
	{.raw_id = 0xb00, .name = "SliderTouch-12", 	.has_led = 0},
	{.raw_id = 0xb05, .name = "Source-HPF-12", 		.has_led = 0},
	{.raw_id = 0xb0b, .name = "TrackAuto-12", 		.has_led = 0},
	{.raw_id = 0xb0c, .name = "TrackEQ-12", 		.has_led = 1},
	{.raw_id = 0xb0d, .name = "TrackDyn-12", 		.has_led = 1},
	{.raw_id = 0xb0e, .name = "TrackInsert-12", 	.has_led = 1},
	{.raw_id = 0xb0f, .name = "TrackSend-12", 		.has_led = 1},
	{.raw_id = 0xb13, .name = "Track-12", 			.has_led = 1},
	{.raw_id = 0xb14, .name = "TrackInput-12", 		.has_led = 1},
	{.raw_id = 0xb15, .name = "TrackRec-12", 		.has_led = 1},
	{.raw_id = 0xb16, .name = "Select-12", 			.has_led = 1},
	{.raw_id = 0xb17, .name = "Solo-12", 			.has_led = 1},
	{.raw_id = 0xb18, .name = "Mute-12", 			.has_led = 1},
	{.raw_id = 0xc00, .name = "SliderTouch-13", 	.has_led = 0},
	{.raw_id = 0xc05, .name = "Source-HPF-13", 		.has_led = 0},
	{.raw_id = 0xc0b, .name = "TrackAuto-13", 		.has_led = 0},
	{.raw_id = 0xc0c, .name = "TrackEQ-13", 		.has_led = 1},
	{.raw_id = 0xc0d, .name = "TrackDyn-13", 		.has_led = 1},
	{.raw_id = 0xc0e, .name = "TrackInsert-13", 	.has_led = 1},
	{.raw_id = 0xc0f, .name = "TrackSend-13", 		.has_led = 1},
	{.raw_id = 0xc13, .name = "Track-13", 			.has_led = 1},
	{.raw_id = 0xc14, .name = "TrackInput-13", 		.has_led = 1},
	{.raw_id = 0xc15, .name = "TrackRec-13", 		.has_led = 1},
	{.raw_id = 0xc16, .name = "Select-13", 			.has_led = 1},
	{.raw_id = 0xc17, .name = "Solo-13", 			.has_led = 1},
	{.raw_id = 0xc18, .name = "Mute-13", 			.has_led = 1},
	{.raw_id = 0xd00, .name = "SliderTouch-14", 	.has_led = 0},
	{.raw_id = 0xd05, .name = "Source-HPF-14", 		.has_led = 0},
	{.raw_id = 0xd0b, .name = "TrackAuto-14", 		.has_led = 0},
	{.raw_id = 0xd0c, .name = "TrackEQ-14", 		.has_led = 1},
	{.raw_id = 0xd0d, .name = "TrackDyn-14", 		.has_led = 1},
	{.raw_id = 0xd0e, .name = "TrackInsert-14", 	.has_led = 1},
	{.raw_id = 0xd0f, .name = "TrackSend-14", 		.has_led = 1},
	{.raw_id = 0xd13, .name = "Track-14", 			.has_led = 1},
	{.raw_id = 0xd14, .name = "TrackInput-14", 		.has_led = 1},
	{.raw_id = 0xd15, .name = "TrackRec-14", 		.has_led = 1},
	{.raw_id = 0xd16, .name = "Select-14", 			.has_led = 1},
	{.raw_id = 0xd17, .name = "Solo-14", 			.has_led = 1},
	{.raw_id = 0xd18, .name = "Mute-14", 			.has_led = 1},
	{.raw_id = 0xe00, .name = "SliderTouch-15", 	.has_led = 0},
	{.raw_id = 0xe05, .name = "Source-HPF-15", 		.has_led = 0},
	{.raw_id = 0xe0b, .name = "TrackAuto-15", 		.has_led = 0},
	{.raw_id = 0xe0c, .name = "TrackEQ-15", 		.has_led = 1},
	{.raw_id = 0xe0d, .name = "TrackDyn-15", 		.has_led = 1},
	{.raw_id = 0xe0e, .name = "TrackInsert-15", 	.has_led = 1},
	{.raw_id = 0xe0f, .name = "TrackSend-15", 		.has_led = 1},
	{.raw_id = 0xe13, .name = "Track-15", 			.has_led = 1},
	{.raw_id = 0xe14, .name = "TrackInput-15", 		.has_led = 1},
	{.raw_id = 0xe15, .name = "TrackRec-15", 		.has_led = 1},
	{.raw_id = 0xe16, .name = "Select-15", 			.has_led = 1},
	{.raw_id = 0xe17, .name = "Solo-15", 			.has_led = 1},
	{.raw_id = 0xe18, .name = "Mute-15", 			.has_led = 1},
	{.raw_id = 0xf00, .name = "SliderTouch-16", 	.has_led = 0},
	{.raw_id = 0xf05, .name = "Source-HPF-16", 		.has_led = 0},
	{.raw_id = 0xf0b, .name = "TrackAuto-16", 		.has_led = 0},
	{.raw_id = 0xf0c, .name = "TrackEQ-16", 		.has_led = 1},
	{.raw_id = 0xf0d, .name = "TrackDyn-16", 		.has_led = 1},
	{.raw_id = 0xf0e, .name = "TrackInsert-16", 	.has_led = 1},
	{.raw_id = 0xf0f, .name = "TrackSend-16", 		.has_led = 1},
	{.raw_id = 0xf13, .name = "Track-16", 			.has_led = 1},
	{.raw_id = 0xf14, .name = "TrackInput-16", 		.has_led = 1},
	{.raw_id = 0xf15, .name = "TrackRec-16", 		.has_led = 1},
	{.raw_id = 0xf16, .name = "Select-16", 			.has_led = 1},
	{.raw_id = 0xf17, .name = "Solo-16", 			.has_led = 1},
	{.raw_id = 0xf18, .name = "Mute-16", 			.has_led = 1},
	{.raw_id = 0x1000, .name = "SliderTouch-17", 	.has_led = 0},
	{.raw_id = 0x100b, .name = "TrackAuto-17", 		.has_led = 0},
	{.raw_id = 0x100c, .name = "TrackEQ-17", 		.has_led = 1},
	{.raw_id = 0x100d, .name = "TrackDyn-17", 		.has_led = 1},
	{.raw_id = 0x100e, .name = "TrackInsert-17", 	.has_led = 1},
	{.raw_id = 0x100f, .name = "TrackSend-17", 		.has_led = 1},
	{.raw_id = 0x1013, .name = "Track-17", 			.has_led = 1},
	{.raw_id = 0x1014, .name = "TrackInput-17", 	.has_led = 1},
	{.raw_id = 0x1015, .name = "TrackRec-17", 		.has_led = 1},
	{.raw_id = 0x1016, .name = "Select-17", 		.has_led = 1},
	{.raw_id = 0x1017, .name = "Solo-17", 			.has_led = 1},
	{.raw_id = 0x1018, .name = "Mute-17", 			.has_led = 1},
	{.raw_id = 0x1100, .name = "SliderTouch-18", 	.has_led = 0},
	{.raw_id = 0x110b, .name = "TrackAuto-18", 		.has_led = 0},
	{.raw_id = 0x110c, .name = "TrackEQ-18", 		.has_led = 1},
	{.raw_id = 0x110d, .name = "TrackDyn-18", 		.has_led = 1},
	{.raw_id = 0x110e, .name = "TrackInsert-18", 	.has_led = 1},
	{.raw_id = 0x110f, .name = "TrackSend-18", 		.has_led = 1},
	{.raw_id = 0x1113, .name = "Track-18", 			.has_led = 1},
	{.raw_id = 0x1114, .name = "TrackInput-18", 	.has_led = 1},
	{.raw_id = 0x1115, .name = "TrackRec-18", 		.has_led = 1},
	{.raw_id = 0x1116, .name = "Select-18", 		.has_led = 1},
	{.raw_id = 0x1117, .name = "Solo-18", 			.has_led = 1},
	{.raw_id = 0x1118, .name = "Mute-18", 			.has_led = 1},
	{.raw_id = 0x1200, .name = "SliderTouch-19", 	.has_led = 0},
	{.raw_id = 0x120b, .name = "TrackAuto-19", 		.has_led = 0},
	{.raw_id = 0x120c, .name = "TrackEQ-19", 		.has_led = 1},
	{.raw_id = 0x120d, .name = "TrackDyn-19", 		.has_led = 1},
	{.raw_id = 0x120e, .name = "TrackInsert-19", 	.has_led = 1},
	{.raw_id = 0x120f, .name = "TrackSend-19", 		.has_led = 1},
	{.raw_id = 0x1213, .name = "Track-19", 			.has_led = 1},
	{.raw_id = 0x1214, .name = "TrackInput-19", 	.has_led = 1},
	{.raw_id = 0x1215, .name = "TrackRec-19", 		.has_led = 1},
	{.raw_id = 0x1216, .name = "Select-19", 		.has_led = 1},
	{.raw_id = 0x1217, .name = "Solo-19", 			.has_led = 1},
	{.raw_id = 0x1218, .name = "Mute-19", 			.has_led = 1},
	{.raw_id = 0x1300, .name = "SliderTouch-20", 	.has_led = 0},
	{.raw_id = 0x130b, .name = "TrackAuto-20", 		.has_led = 0},
	{.raw_id = 0x130c, .name = "TrackEQ-20", 		.has_led = 1},
	{.raw_id = 0x130d, .name = "TrackDyn-20", 		.has_led = 1},
	{.raw_id = 0x130e, .name = "TrackInsert-20", 	.has_led = 1},
	{.raw_id = 0x130f, .name = "TrackSend-20", 		.has_led = 1},
	{.raw_id = 0x1313, .name = "Track-20", 			.has_led = 1},
	{.raw_id = 0x1314, .name = "TrackInput-20", 	.has_led = 1},
	{.raw_id = 0x1315, .name = "TrackRec-20", 		.has_led = 1},
	{.raw_id = 0x1316, .name = "Select-20", 		.has_led = 1},
	{.raw_id = 0x1317, .name = "Solo-20", 			.has_led = 1},
	{.raw_id = 0x1318, .name = "Mute-20", 			.has_led = 1},
	{.raw_id = 0x1400, .name = "SliderTouch-21", 	.has_led = 0},
	{.raw_id = 0x140b, .name = "TrackAuto-21", 		.has_led = 0},
	{.raw_id = 0x140c, .name = "TrackEQ-21", 		.has_led = 1},
	{.raw_id = 0x140d, .name = "TrackDyn-21", 		.has_led = 1},
	{.raw_id = 0x140e, .name = "TrackInsert-21", 	.has_led = 1},
	{.raw_id = 0x140f, .name = "TrackSend-21", 		.has_led = 1},
	{.raw_id = 0x1413, .name = "Track-21", 			.has_led = 1},
	{.raw_id = 0x1414, .name = "TrackInput-21", 	.has_led = 1},
	{.raw_id = 0x1415, .name = "TrackRec-21", 		.has_led = 1},
	{.raw_id = 0x1416, .name = "Select-21", 		.has_led = 1},
	{.raw_id = 0x1417, .name = "Solo-21", 			.has_led = 1},
	{.raw_id = 0x1418, .name = "Mute-21", 			.has_led = 1},
	{.raw_id = 0x1500, .name = "SliderTouch-22", 	.has_led = 0},
	{.raw_id = 0x150b, .name = "TrackAuto-22", 		.has_led = 0},
	{.raw_id = 0x150c, .name = "TrackEQ-22", 		.has_led = 1},
	{.raw_id = 0x150d, .name = "TrackDyn-22", 		.has_led = 1},
	{.raw_id = 0x150e, .name = "TrackInsert-22", 	.has_led = 1},
	{.raw_id = 0x150f, .name = "TrackSend-22", 		.has_led = 1},
	{.raw_id = 0x1513, .name = "Track-22", 			.has_led = 1},
	{.raw_id = 0x1514, .name = "TrackInput-22", 	.has_led = 1},
	{.raw_id = 0x1515, .name = "TrackRec-22", 		.has_led = 1},
	{.raw_id = 0x1516, .name = "Select-22", 		.has_led = 1},
	{.raw_id = 0x1517, .name = "Solo-22", 			.has_led = 1},
	{.raw_id = 0x1518, .name = "Mute-22", 			.has_led = 1},
	{.raw_id = 0x1600, .name = "SliderTouch-23", 	.has_led = 0},
	{.raw_id = 0x160b, .name = "TrackAuto-23", 		.has_led = 0},
	{.raw_id = 0x160c, .name = "TrackEQ-23", 		.has_led = 1},
	{.raw_id = 0x160d, .name = "TrackDyn-23", 		.has_led = 1},
	{.raw_id = 0x160e, .name = "TrackInsert-23", 	.has_led = 1},
	{.raw_id = 0x160f, .name = "TrackSend-23", 		.has_led = 1},
	{.raw_id = 0x1613, .name = "Track-23", 			.has_led = 1},
	{.raw_id = 0x1614, .name = "TrackInput-23", 	.has_led = 1},
	{.raw_id = 0x1615, .name = "TrackRec-23", 		.has_led = 1},
	{.raw_id = 0x1616, .name = "Select-23", 		.has_led = 1},
	{.raw_id = 0x1617, .name = "Solo-23", 			.has_led = 1},
	{.raw_id = 0x1618, .name = "Mute-23", 			.has_led = 1},
	{.raw_id = 0x1700, .name = "SliderTouch-24", 	.has_led = 0},
	{.raw_id = 0x170b, .name = "TrackAuto-24", 		.has_led = 0},
	{.raw_id = 0x170c, .name = "TrackEQ-24", 		.has_led = 1},
	{.raw_id = 0x170d, .name = "TrackDyn-24", 		.has_led = 1},
	{.raw_id = 0x170e, .name = "TrackInsert-24", 	.has_led = 1},
	{.raw_id = 0x170f, .name = "TrackSend-24", 		.has_led = 1},
	{.raw_id = 0x1713, .name = "Track-24", 			.has_led = 1},
	{.raw_id = 0x1714, .name = "TrackInput-24", 	.has_led = 1},
	{.raw_id = 0x1715, .name = "TrackRec-24", 		.has_led = 1},
	{.raw_id = 0x1716, .name = "Select-24", 		.has_led = 1},
	{.raw_id = 0x1717, .name = "Solo-24", 			.has_led = 1},
	{.raw_id = 0x1718, .name = "Mute-24", 			.has_led = 1},
	{.raw_id = 0x1800, .name = "AutoEnVol", 		.has_led = 1},
	{.raw_id = 0x1801, .name = "AutoEnSendLv1", 	.has_led = 1},
	{.raw_id = 0x1802, .name = "AutoEnPan", 		.has_led = 1},
	{.raw_id = 0x1803, .name = "AutoEnSendPan", 	.has_led = 1},
	{.raw_id = 0x1804, .name = "AutoEnMute", 		.has_led = 1},
	{.raw_id = 0x1805, .name = "AutoEnSendMute", 	.has_led = 1},
	{.raw_id = 0x1806, .name = "AutoEnSuspend", 	.has_led = 1},
	{.raw_id = 0x1807, .name = "AutoEnPlugin", 		.has_led = 1},
	{.raw_id = 0x1808, .name = "Bypass", 			.has_led = 1},
	{.raw_id = 0x1809, .name = "Bypass", 			.has_led = 1},
	{.raw_id = 0x180a, .name = "DisplayMode", 		.has_led = 1},
	{.raw_id = 0x180b, .name = "Select-Auto", 		.has_led = 1},
	{.raw_id = 0x180c, .name = "Pre-Post", 			.has_led = 1},
	{.raw_id = 0x180d, .name = "SendMute", 			.has_led = 1},
	{.raw_id = 0x180e, .name = "AutoToAll", 		.has_led = 1},
	{.raw_id = 0x180f, .name = "AutoToStart", 		.has_led = 1},
	{.raw_id = 0x1810, .name = "AutoToEnd", 		.has_led = 1},
	{.raw_id = 0x1811, .name = "AutoToPunch", 		.has_led = 1},
	{.raw_id = 0x1812, .name = "AutoToNext", 		.has_led = 1},
	{.raw_id = 0x1813, .name = "Auto-Write", 		.has_led = 1},
	{.raw_id = 0x1814, .name = "Auto-Trim", 		.has_led = 1},
	{.raw_id = 0x1815, .name = "Auto-Touch", 		.has_led = 1},
	{.raw_id = 0x1816, .name = "Auto-Read", 		.has_led = 1},
	{.raw_id = 0x1817, .name = "Auto-Latch", 		.has_led = 1},
	{.raw_id = 0x1818, .name = "Auto-Off", 			.has_led = 1},
	{.raw_id = 0x1819, .name = "DoToAll", 			.has_led = 1},
	{.raw_id = 0x181a, .name = "DoToSelected", 		.has_led = 1},
	{.raw_id = 0x181b, .name = "Default", 			.has_led = 1},
	{.raw_id = 0x181c, .name = "SoloClear", 		.has_led = 1},
	{.raw_id = 0x181d, .name = "PluginSafe", 		.has_led = 1},
	{.raw_id = 0x181e, .name = "VelSens", 			.has_led = 1},
	{.raw_id = 0x181f, .name = "InputMon", 			.has_led = 1},
	{.raw_id = 0x1820, .name = "MasterRec", 		.has_led = 1},
	{.raw_id = 0x1821, .name = "Masters", 			.has_led = 1},
	{.raw_id = 0x1822, .name = "Flip", 				.has_led = 1},
	{.raw_id = 0x1900, .name = "Shift(Add)", 		.has_led = 0},
	{.raw_id = 0x1901, .name = "Opt-Alt", 			.has_led = 0},
	{.raw_id = 0x1902, .name = "Ctrl-Win", 			.has_led = 0},
	{.raw_id = 0x1903, .name = "Cmd-Ctrl", 			.has_led = 0},
	{.raw_id = 0x1a00, .name = "+48v1-8", 			.has_led = 1},
	{.raw_id = 0x1a01, .name = "+48v9-16", 			.has_led = 1},
	{.raw_id = 0x1a02, .name = "ToMon", 			.has_led = 1},
	{.raw_id = 0x1a03, .name = "TalkBack", 			.has_led = 1},
	{.raw_id = 0x1a07, .name = "MonitorMode", 		.has_led = 1},
	{.raw_id = 0x1a08, .name = "Monitor-L", 		.has_led = 1},
	{.raw_id = 0x1a09, .name = "Monitor-C", 		.has_led = 1},
	{.raw_id = 0x1a0a, .name = "Monitor-R", 		.has_led = 1},
	{.raw_id = 0x1a0b, .name = "Monitor-Ls", 		.has_led = 1},
	{.raw_id = 0x1a0c, .name = "Monitor-Rs", 		.has_led = 1},
	{.raw_id = 0x1a0d, .name = "Monitor-LFE", 		.has_led = 1},
	{.raw_id = 0x1a0e, .name = "Monitor-Solo", 		.has_led = 1},
	{.raw_id = 0x1a10, .name = "AltMon", 			.has_led = 1},
	{.raw_id = 0x1a11, .name = "FromCue", 			.has_led = 1},
	{.raw_id = 0x1a12, .name = "On", 				.has_led = 1},
	{.raw_id = 0x1a13, .name = "Main>Cue", 			.has_led = 1},
	{.raw_id = 0x1a14, .name = "On", 				.has_led = 1},
	{.raw_id = 0x1a15, .name = "MonitorMute", 		.has_led = 1},
	{.raw_id = 0x1a16, .name = "MonitorDim", 		.has_led = 1},
	{.raw_id = 0x1a17, .name = "MonitorMono", 		.has_led = 1},
	{.raw_id = 0x1a18, .name = "MonitorMain", 		.has_led = 1},
	{.raw_id = 0x1a19, .name = "MonitorAltSur", 	.has_led = 1},
	{.raw_id = 0x1a1a, .name = "MonitorSt-1", 		.has_led = 1},
	{.raw_id = 0x1a1b, .name = "MonitorSt-2", 		.has_led = 1},
	{.raw_id = 0x1a1c, .name = "MonitorSum", 		.has_led = 1},
	{.raw_id = 0x1b00, .name = "InsMastrByp", 		.has_led = 1},
	{.raw_id = 0x1b01, .name = "InsCompare", 		.has_led = 1},
	{.raw_id = 0x1b02, .name = "InsSafe", 			.has_led = 1},
	{.raw_id = 0x1b03, .name = "InsParam", 			.has_led = 1},
	{.raw_id = 0x1b04, .name = "Assign", 			.has_led = 1},
	{.raw_id = 0x1b05, .name = "AssignInput", 		.has_led = 1},
	{.raw_id = 0x1b06, .name = "AssignOutput", 		.has_led = 1},
	{.raw_id = 0x1b07, .name = "AssignEscCancel", 	.has_led = 1},
	{.raw_id = 0x1b0f, .name = "SoftKeys", 			.has_led = 1},
	{.raw_id = 0x1b10, .name = "Send-F-J", 			.has_led = 1},
	{.raw_id = 0x1b11, .name = "Send-A-F", 			.has_led = 1},
	{.raw_id = 0x1b12, .name = "Send-B-G", 			.has_led = 1},
	{.raw_id = 0x1b13, .name = "Send-C-H", 			.has_led = 1},
	{.raw_id = 0x1b14, .name = "Send-D-I", 			.has_led = 1},
	{.raw_id = 0x1b15, .name = "Send-E-J", 			.has_led = 1},
	{.raw_id = 0x1b16, .name = "<ChannelBar", 		.has_led = 1},
	{.raw_id = 0x1b17, .name = "ChannelBar>", 		.has_led = 1},
	{.raw_id = 0x1c00, .name = "EditModeShuffle", 	.has_led = 1},
	{.raw_id = 0x1c01, .name = "EditModeSpot", 		.has_led = 1},
	{.raw_id = 0x1c02, .name = "EditModeSlip", 		.has_led = 1},
	{.raw_id = 0x1c03, .name = "EditModeGrid", 		.has_led = 1},
	{.raw_id = 0x1d00, .name = "ViewHome", 			.has_led = 1},
	{.raw_id = 0x1d01, .name = "ViewFocus", 		.has_led = 1},
	{.raw_id = 0x1d02, .name = "ViewMicPre", 		.has_led = 1},
	{.raw_id = 0x1d03, .name = "Copy", 				.has_led = 1},
	{.raw_id = 0x1d04, .name = "Paste", 			.has_led = 1},
	{.raw_id = 0x1e01, .name = "Trim", 				.has_led = 1},
	{.raw_id = 0x1e02, .name = "Select", 			.has_led = 1},
	{.raw_id = 0x1e03, .name = "Grabber", 			.has_led = 1},
	{.raw_id = 0x1e04, .name = "Pencil", 			.has_led = 1},
	{.raw_id = 0x1e05, .name = "Smart", 			.has_led = 1},
	{.raw_id = 0x1e06, .name = "LinkEdt-TL", 		.has_led = 1},
	{.raw_id = 0x1e07, .name = "LinkEdt-Trk-Edt", 	.has_led = 1},
	{.raw_id = 0x1f00, .name = "Unnamed", 			.has_led = 1},
	{.raw_id = 0x1f01, .name = "WindowMix", 		.has_led = 1},
	{.raw_id = 0x1f02, .name = "WindowEdit", 		.has_led = 1},
	{.raw_id = 0x1f03, .name = "WindowPlugIn", 		.has_led = 1},
	{.raw_id = 0x1f04, .name = "WindowPan", 		.has_led = 1},
	{.raw_id = 0x1f05, .name = "WindowTransport", 	.has_led = 1},
	{.raw_id = 0x1f06, .name = "WindowWinCfg", 		.has_led = 1},
	{.raw_id = 0x1f07, .name = "WindowMemLock", 	.has_led = 1},
	{.raw_id = 0x2000, .name = "Create", 			.has_led = 1},
	{.raw_id = 0x2001, .name = "Enable", 			.has_led = 1},
	{.raw_id = 0x2002, .name = "Modify", 			.has_led = 1},
	{.raw_id = 0x2003, .name = "Delete", 			.has_led = 1},
	{.raw_id = 0x2004, .name = "Suspend", 			.has_led = 1},
	{.raw_id = 0x2100, .name = "Audition", 			.has_led = 1},
	{.raw_id = 0x2101, .name = "RTZ-E", 			.has_led = 1},
	{.raw_id = 0x2102, .name = "Trans=", 			.has_led = 1},
	{.raw_id = 0x2103, .name = "Online", 			.has_led = 1},
	{.raw_id = 0x2104, .name = "PreRoll", 			.has_led = 1},
	{.raw_id = 0x2105, .name = "MarkIn", 			.has_led = 1},
	{.raw_id = 0x2106, .name = "MarkOut", 			.has_led = 1},
	{.raw_id = 0x2107, .name = "PostRoll", 			.has_led = 1},
	{.raw_id = 0x2108, .name = "DynTrans", 			.has_led = 1},
	{.raw_id = 0x2109, .name = "LoopPlay", 			.has_led = 1},
	{.raw_id = 0x210a, .name = "LoopRecord", 		.has_led = 1},
	{.raw_id = 0x210b, .name = "QuickPunch", 		.has_led = 1},
	{.raw_id = 0x210c, .name = "Rewind", 			.has_led = 1},
	{.raw_id = 0x210d, .name = "FastForward", 		.has_led = 1},
	{.raw_id = 0x210e, .name = "Stop", 				.has_led = 1},
	{.raw_id = 0x210f, .name = "Play", 				.has_led = 1},
	{.raw_id = 0x2110, .name = "Record", 			.has_led = 1},
	{.raw_id = 0x2114, .name = "Scrub", 			.has_led = 1},
	{.raw_id = 0x2115, .name = "Trim", 				.has_led = 1},
	{.raw_id = 0x2116, .name = "Shuttle", 			.has_led = 1},
	{.raw_id = 0x2200, .name = "Zoom1", 			.has_led = 1},
	{.raw_id = 0x2201, .name = "Zoom2", 			.has_led = 1},
	{.raw_id = 0x2202, .name = "Zoom3", 			.has_led = 1},
	{.raw_id = 0x2203, .name = "Zoom4", 			.has_led = 1},
	{.raw_id = 0x2204, .name = "Zoom5", 			.has_led = 1},
	{.raw_id = 0x2205, .name = "Zoom", 				.has_led = 1},
	{.raw_id = 0x2206, .name = "Navigate", 			.has_led = 1},
	{.raw_id = 0x2207, .name = "UpArrow", 			.has_led = 0},
	{.raw_id = 0x2208, .name = "DownArrow", 		.has_led = 0},
	{.raw_id = 0x2209, .name = "LeftArrow", 		.has_led = 0},
	{.raw_id = 0x220a, .name = "RightArrow", 		.has_led = 0},
	{.raw_id = 0x2300, .name = "ClearClip", 		.has_led = 1},
	{.raw_id = 0x2301, .name = "MetersPost", 		.has_led = 1},
	{.raw_id = 0x2302, .name = "Counter", 			.has_led = 1},
	{.raw_id = 0x2303, .name = "Undo", 				.has_led = 1},
	{.raw_id = 0x2304, .name = "Redo", 				.has_led = 1},
	{.raw_id = 0x2306, .name = "Enter", 			.has_led = 1},
	{.raw_id = 0x2307, .name = "Esc-Cancel", 		.has_led = 1},
	{.raw_id = 0x2308, .name = "Save", 				.has_led = 1},
	{.raw_id = 0x2400, .name = "BankLeft", 			.has_led = 1},
	{.raw_id = 0x2401, .name = "Nudge", 			.has_led = 1},
	{.raw_id = 0x2402, .name = "BankRight"}
};

static struct c24_control __c24_knobs__[C24_KNOB_COUNT] = 
{
	{.raw_id = 0x0012, .name = "PanKnob-1"		, .has_led = 1},
	{.raw_id = 0x0112, .name = "PanKnob-2"		, .has_led = 1},
	{.raw_id = 0x0212, .name = "PanKnob-3"		, .has_led = 1},
	{.raw_id = 0x0312, .name = "PanKnob-4"		, .has_led = 1},
	{.raw_id = 0x0412, .name = "PanKnob-5"		, .has_led = 1},
	{.raw_id = 0x0512, .name = "PanKnob-6"		, .has_led = 1},
	{.raw_id = 0x0612, .name = "PanKnob-7"		, .has_led = 1},
	{.raw_id = 0x0712, .name = "PanKnob-8"		, .has_led = 1},
	{.raw_id = 0x0812, .name = "PanKnob-9"		, .has_led = 1},
	{.raw_id = 0x0912, .name = "PanKnob-10"		, .has_led = 1},
	{.raw_id = 0x0a12, .name = "PanKnob-11"		, .has_led = 1},
	{.raw_id = 0x0b12, .name = "PanKnob-12"		, .has_led = 1},
	{.raw_id = 0x0c12, .name = "PanKnob-13"		, .has_led = 1},
	{.raw_id = 0x0d12, .name = "PanKnob-14"		, .has_led = 1},
	{.raw_id = 0x0e12, .name = "PanKnob-15"		, .has_led = 1},
	{.raw_id = 0x0f12, .name = "PanKnob-16"		, .has_led = 1},
	{.raw_id = 0x1012, .name = "PanKnob-17"		, .has_led = 1},
	{.raw_id = 0x1112, .name = "PanKnob-18"		, .has_led = 1},
	{.raw_id = 0x1212, .name = "PanKnob-19"		, .has_led = 1},
	{.raw_id = 0x1312, .name = "PanKnob-20"		, .has_led = 1},
	{.raw_id = 0x1412, .name = "PanKnob-21"		, .has_led = 1},
	{.raw_id = 0x1512, .name = "PanKnob-22"		, .has_led = 1},
	{.raw_id = 0x1612, .name = "PanKnob-23"		, .has_led = 1},
	{.raw_id = 0x1712, .name = "PanKnob-24"		, .has_led = 1},
	{.raw_id = 0x2113, .name = "PitchWheelKnob"	, .has_led = 0}	
};

///------

const char *c24_surface_get_knob_name(const uint16_t knob)
{
	if (knob < C24_KNOB_COUNT)
		return __c24_knobs__[knob].name;
	else
		return "Unknown Knob";
}

const char *c24_surface_get_button_name(const uint16_t button)
{
	if (button < C24_BUTTON_COUNT)
		return __c24_buttons__[button].name;
	else
		return "Unknown Button";
}


///

uint16_t c24_control_id_to_raw_id(
	const struct c24_control controls[],
	const unsigned int control_count,
	const uint16_t id)
{
	if (id < control_count)
		return controls[id].raw_id;
	else
		return C24_UNKNOWN_CONTROL;
}


static uint16_t control_raw_id_to_id_aux(
	const struct c24_control controls[],
	const unsigned int start,
	const unsigned int end,
	const uint16_t raw_id)
{
	if (start == end) {
		const unsigned start_raw_id = 
			controls[start].raw_id;

		if (raw_id == start_raw_id)
			return start;
		else
			return C24_UNKNOWN_CONTROL;
	}
	else {
		const unsigned int center = 
			(start + end) / 2;

		const unsigned int center_raw_id = 
			controls[center].raw_id;

		if (raw_id < center_raw_id)
			return control_raw_id_to_id_aux(
				controls, start, center - 1, raw_id);
		else if (raw_id == center_raw_id)
			return center;
		else 
			return control_raw_id_to_id_aux(
				controls, center + 1, end, raw_id);
	} 
}

uint16_t c24_control_raw_id_to_id(
	const struct c24_control controls[],
	const unsigned int control_count,
	const uint16_t raw_id)
{
	return control_raw_id_to_id_aux(
		controls,
		0,
		control_count - 1,
		raw_id);
}


//------

uint16_t c24_button_id_to_raw_id(const uint16_t id)
{
	return 
		c24_control_id_to_raw_id(
			__c24_buttons__,
			C24_BUTTON_COUNT,
			id);
}

uint16_t c24_button_raw_id_to_id(const uint16_t raw_id)
{
	return 
		c24_control_raw_id_to_id(
			__c24_buttons__,
			C24_BUTTON_COUNT,
			raw_id);
}


uint16_t c24_knob_id_to_raw_id(const uint16_t id)
{
	return 
		c24_control_id_to_raw_id(
			__c24_knobs__,
			C24_KNOB_COUNT,
			id);
}

uint16_t c24_knob_raw_id_to_id(const uint16_t raw_id)
{
	return 
		c24_control_raw_id_to_id(
			__c24_knobs__,
			C24_KNOB_COUNT,
			raw_id);
}

//--

int c24_button_is_slider(const uint16_t button)
{
	if (button < 208) {
		return button % 13 == 0;
	}
	else if (button < 304) {
		return (button - 208) % 12 == 0;
	}
	else {
		return 0;
	}
}

int c24_button_has_led(const uint16_t button)
{
	if (button < C24_BUTTON_COUNT)
		return __c24_buttons__[button].has_led;
	else
		return 0;
}

uint8_t c24_button_track(const uint16_t button)
{
	if (button < 208) {
		return button / 13;
	}
	else {
		const unsigned int ret = 16 + 
			((button - 208) / 12);

		if (ret < C24_TRACK_COUNT)
			return ret;
		else
			return 0xff;
	}
}

uint16_t c24_button_slider(const uint8_t track_id)
{
	if (track_id < C24_TRACK_COUNT) {

		if (track_id < 16)
			return 13 * track_id;
		else
			return 208 + (track_id - 16) * 12;
	}
	else
		return C24_UNKNOWN_BUTTON;
}

uint16_t c24_button_mute(const uint8_t track_id)
{
	if (track_id < C24_TRACK_COUNT) {

		if (track_id < 16)
			return 13 * track_id + 12;
		else
			return 208 + (track_id - 16) * 12 + 11;
	}
	else
		return C24_UNKNOWN_BUTTON;
}

uint16_t c24_button_solo(const uint8_t track_id)
{
	if (track_id < C24_TRACK_COUNT) {

		if (track_id < 16)
			return 13 * track_id + 11;
		else
			return 208 + (track_id - 16) * 12 + 10;
	}
	else
		return C24_UNKNOWN_BUTTON;
}

uint16_t c24_button_select(const uint8_t track_id)
{
	if (track_id < C24_TRACK_COUNT) {

		if (track_id < 16)
			return 13 * track_id + 10;
		else
			return 208 + (track_id - 16) * 12 + 9;
	}
	else
		return C24_UNKNOWN_BUTTON;
}

int c24_knob_is_pan_knob(const uint16_t knob)
{
	return (knob < C24_TRACK_COUNT);
}

uint8_t c24_knob_track(const uint16_t knob)
{
	if (c24_knob_is_pan_knob(knob))
		return knob;
	else
		return 0xff;
}

uint16_t c24_pan_knob(const uint8_t track_id)
{
	if (track_id < C24_TRACK_COUNT)
		return track_id;
	else
		return C24_UNKNOWN_KNOB;
}

