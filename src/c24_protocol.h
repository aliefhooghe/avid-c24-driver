#ifndef C24_PROTOCOL__H_
#define C24_PROTOCOL_H_

#define C24_ETHER_TYPE	0x885fu

// Frame Types

#define C24_FRAME_TYPE_DEFAULT				0x00u
#define C24_FRAME_TYPE_VUMETER_MASK         0x02u
#define C24_FRAME_TYPE_ACKNOWLEDGMENT		0xa0u
#define C24_FRAME_TYPE_BROADCAST_TAKEOVER	0xb0u
#define C24_FRAME_TYPE_ANNOUNCE				0xe0u
#define C24_FRAME_TYPE_REANNOUNCE			0xe1u
#define C24_FRAME_TYPE_SURFACE_TAKEOVER		0xe2u
#define C24_FRAME_TYPE_DISCONECT			0xe3u

// Block Operation Identifiers  

#define C24_BLOCK_OPERATION_BUTTON_EVENT	0x0005u
#define C24_BLOCK_OPERATION_SLIDER_POS		0x0006u
#define C24_BLOCK_OPERATION_COUNTER_SCREEN	0x060du
#define C24_BLOCK_OPERATION_BUTTON_LED		0x0105u
#define C24_BLOCK_OPERATION_SLIDER_MOVE		0x0106u
#define C24_BLOCK_OPERATION_KNOB_ROTATE		0x0205u
#define C24_BLOCK_OPERATION_KNOB_LED_MASK	0x0206u
#define C24_BLOCK_OPERATION_DISPLAY			0x030bu





// Controls identifiers

#define C24_TRACK_COUNT              24

#define C24_PAN_KNOB_TRACK_ID(knob_id)          (uint8_t)((knob_id & 0xff00) >> 8)
#define C24_IS_PAN_KNOB(knob_id)                (((0xff & knob_id) == 0x12u) && (C24_PAN_KNOB_TRACK_ID(knob_id) < 24))

#define C24_PAN_KNOB(track_id)                  (uint16_t)((track_id << 8) | 0x12u)

#define C24_KNOB_BUTTON(track_id)               (uint16_t)((track_id << 8) | 0x13u)
#define C24_INPUT_BUTTON(track_id)              (uint16_t)((track_id << 8) | 0x14u)
#define C24_REC_BUTTON(track_id)                (uint16_t)((track_id << 8) | 0x15u)
#define C24_SELECT_BUTTON(track_id)             (uint16_t)((track_id << 8) | 0x16u)
#define C24_SOLO_BUTTON(track_id)               (uint16_t)((track_id << 8) | 0x17u)
#define C24_MUTE_BUTTON(track_id)               (uint16_t)((track_id << 8) | 0x18u)

#define C24_SLIDER_BUTTON(track_id)             (uint16_t)(track_id << 8)

#define C24_SLIDER_BUTTON_TRACK_ID(button_id)   (C24_PAN_KNOB_TRACK_ID(button_id))
#define C24_IS_SLIDER_BUTTON(button_id)         (((0xff & button_id) == 0u) && (C24_SLIDER_BUTTON_TRACK_ID(button) < 24))

#define C24_REWIND_BUTTON                       0x210cu
#define C24_FAST_FORWARD_BUTTON                 0x210du
#define C24_STOP_BUTTON                         0x210eu
#define C24_PLAY_BUTTON                         0x210fu
#define C24_RECORD_BUTTON                       0x2110u

#define C24_PITCH_WHEEL_KNOB                    0x2113u

#define C24_UP_ARROW_BUTTON                     0x2207u
#define C24_DOWN_ARROW_BUTTON                   0x2208u
#define C24_LEFT_ARROW_BUTTON                   0x2209u
#define C24_RIGHT_ARROW_BUTTON                  0x220au

// 7 segment

#endif  
