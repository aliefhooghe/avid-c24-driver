
#include <stdint.h>
#include "c24_controls.h"

struct c24_control {
    uint16_t raw_id;		//	Used In Comunication Protocol
    const char *name;		//	Human Readable Name
};

static struct c24_control __c24_buttons__[C24_BUTTON_COUNT] =
{
    {.raw_id = 0x0, .name = "SliderTouch-1"},
	{.raw_id = 0x5, .name = "Source-HPF-1"},
	{.raw_id = 0xb, .name = "TrackAuto-1"},
	{.raw_id = 0xc, .name = "TrackEQ-1"},
	{.raw_id = 0xd, .name = "TrackDyn-1"},
	{.raw_id = 0xe, .name = "TrackInsert-1"},
	{.raw_id = 0xf, .name = "TrackSend-1"},
	{.raw_id = 0x13, .name = "Track-1"},
	{.raw_id = 0x14, .name = "TrackInput-1"},
	{.raw_id = 0x15, .name = "TrackRec-1"},
	{.raw_id = 0x16, .name = "Select-1"},
	{.raw_id = 0x17, .name = "Solo-1"},
	{.raw_id = 0x18, .name = "Mute-1"},
	{.raw_id = 0x100, .name = "SliderTouch-2"},
	{.raw_id = 0x105, .name = "Source-HPF-2"},
	{.raw_id = 0x10b, .name = "TrackAuto-2"},
	{.raw_id = 0x10c, .name = "TrackEQ-2"},
	{.raw_id = 0x10d, .name = "TrackDyn-2"},
	{.raw_id = 0x10e, .name = "TrackInsert-2"},
	{.raw_id = 0x10f, .name = "TrackSend-2"},
	{.raw_id = 0x113, .name = "Track-2"},
	{.raw_id = 0x114, .name = "TrackInput-2"},
	{.raw_id = 0x115, .name = "TrackRec-2"},
	{.raw_id = 0x116, .name = "Select-2"},
	{.raw_id = 0x117, .name = "Solo-2"},
	{.raw_id = 0x118, .name = "Mute-2"},
	{.raw_id = 0x200, .name = "SliderTouch-3"},
	{.raw_id = 0x205, .name = "Source-HPF-3"},
	{.raw_id = 0x20b, .name = "TrackAuto-3"},
	{.raw_id = 0x20c, .name = "TrackEQ-3"},
	{.raw_id = 0x20d, .name = "TrackDyn-3"},
	{.raw_id = 0x20e, .name = "TrackInsert-3"},
	{.raw_id = 0x20f, .name = "TrackSend-3"},
	{.raw_id = 0x213, .name = "Track-3"},
	{.raw_id = 0x214, .name = "TrackInput-3"},
	{.raw_id = 0x215, .name = "TrackRec-3"},
	{.raw_id = 0x216, .name = "Select-3"},
	{.raw_id = 0x217, .name = "Solo-3"},
	{.raw_id = 0x218, .name = "Mute-3"},
	{.raw_id = 0x300, .name = "SliderTouch-4"},
	{.raw_id = 0x305, .name = "Source-HPF-4"},
	{.raw_id = 0x30b, .name = "TrackAuto-4"},
	{.raw_id = 0x30c, .name = "TrackEQ-4"},
	{.raw_id = 0x30d, .name = "TrackDyn-4"},
	{.raw_id = 0x30e, .name = "TrackInsert-4"},
	{.raw_id = 0x30f, .name = "TrackSend-4"},
	{.raw_id = 0x313, .name = "Track-4"},
	{.raw_id = 0x314, .name = "TrackInput-4"},
	{.raw_id = 0x315, .name = "TrackRec-4"},
	{.raw_id = 0x316, .name = "Select-4"},
	{.raw_id = 0x317, .name = "Solo-4"},
	{.raw_id = 0x318, .name = "Mute-4"},
	{.raw_id = 0x400, .name = "SliderTouch-5"},
	{.raw_id = 0x405, .name = "Source-HPF-5"},
	{.raw_id = 0x40b, .name = "TrackAuto-5"},
	{.raw_id = 0x40c, .name = "TrackEQ-5"},
	{.raw_id = 0x40d, .name = "TrackDyn-5"},
	{.raw_id = 0x40e, .name = "TrackInsert-5"},
	{.raw_id = 0x40f, .name = "TrackSend-5"},
	{.raw_id = 0x413, .name = "Track-5"},
	{.raw_id = 0x414, .name = "TrackInput-5"},
	{.raw_id = 0x415, .name = "TrackRec-5"},
	{.raw_id = 0x416, .name = "Select-5"},
	{.raw_id = 0x417, .name = "Solo-5"},
	{.raw_id = 0x418, .name = "Mute-5"},
	{.raw_id = 0x500, .name = "SliderTouch-6"},
	{.raw_id = 0x505, .name = "Source-HPF-6"},
	{.raw_id = 0x50b, .name = "TrackAuto-6"},
	{.raw_id = 0x50c, .name = "TrackEQ-6"},
	{.raw_id = 0x50d, .name = "TrackDyn-6"},
	{.raw_id = 0x50e, .name = "TrackInsert-6"},
	{.raw_id = 0x50f, .name = "TrackSend-6"},
	{.raw_id = 0x513, .name = "Track-6"},
	{.raw_id = 0x514, .name = "TrackInput-6"},
	{.raw_id = 0x515, .name = "TrackRec-6"},
	{.raw_id = 0x516, .name = "Select-6"},
	{.raw_id = 0x517, .name = "Solo-6"},
	{.raw_id = 0x518, .name = "Mute-6"},
	{.raw_id = 0x600, .name = "SliderTouch-7"},
	{.raw_id = 0x605, .name = "Source-HPF-7"},
	{.raw_id = 0x60b, .name = "TrackAuto-7"},
	{.raw_id = 0x60c, .name = "TrackEQ-7"},
	{.raw_id = 0x60d, .name = "TrackDyn-7"},
	{.raw_id = 0x60e, .name = "TrackInsert-7"},
	{.raw_id = 0x60f, .name = "TrackSend-7"},
	{.raw_id = 0x613, .name = "Track-7"},
	{.raw_id = 0x614, .name = "TrackInput-7"},
	{.raw_id = 0x615, .name = "TrackRec-7"},
	{.raw_id = 0x616, .name = "Select-7"},
	{.raw_id = 0x617, .name = "Solo-7"},
	{.raw_id = 0x618, .name = "Mute-7"},
	{.raw_id = 0x700, .name = "SliderTouch-8"},
	{.raw_id = 0x705, .name = "Source-HPF-8"},
	{.raw_id = 0x70b, .name = "TrackAuto-8"},
	{.raw_id = 0x70c, .name = "TrackEQ-8"},
	{.raw_id = 0x70d, .name = "TrackDyn-8"},
	{.raw_id = 0x70e, .name = "TrackInsert-8"},
	{.raw_id = 0x70f, .name = "TrackSend-8"},
	{.raw_id = 0x713, .name = "Track-8"},
	{.raw_id = 0x714, .name = "TrackInput-8"},
	{.raw_id = 0x715, .name = "TrackRec-8"},
	{.raw_id = 0x716, .name = "Select-8"},
	{.raw_id = 0x717, .name = "Solo-8"},
	{.raw_id = 0x718, .name = "Mute-8"},
	{.raw_id = 0x800, .name = "SliderTouch-9"},
	{.raw_id = 0x805, .name = "Source-HPF-9"},
	{.raw_id = 0x80b, .name = "TrackAuto-9"},
	{.raw_id = 0x80c, .name = "TrackEQ-9"},
	{.raw_id = 0x80d, .name = "TrackDyn-9"},
	{.raw_id = 0x80e, .name = "TrackInsert-9"},
	{.raw_id = 0x80f, .name = "TrackSend-9"},
	{.raw_id = 0x813, .name = "Track-9"},
	{.raw_id = 0x814, .name = "TrackInput-9"},
	{.raw_id = 0x815, .name = "TrackRec-9"},
	{.raw_id = 0x816, .name = "Select-9"},
	{.raw_id = 0x817, .name = "Solo-9"},
	{.raw_id = 0x818, .name = "Mute-9"},
	{.raw_id = 0x900, .name = "SliderTouch-10"},
	{.raw_id = 0x905, .name = "Source-HPF-10"},
	{.raw_id = 0x90b, .name = "TrackAuto-10"},
	{.raw_id = 0x90c, .name = "TrackEQ-10"},
	{.raw_id = 0x90d, .name = "TrackDyn-10"},
	{.raw_id = 0x90e, .name = "TrackInsert-10"},
	{.raw_id = 0x90f, .name = "TrackSend-10"},
	{.raw_id = 0x913, .name = "Track-10"},
	{.raw_id = 0x914, .name = "TrackInput-10"},
	{.raw_id = 0x915, .name = "TrackRec-10"},
	{.raw_id = 0x916, .name = "Select-10"},
	{.raw_id = 0x917, .name = "Solo-10"},
	{.raw_id = 0x918, .name = "Mute-10"},
	{.raw_id = 0xa00, .name = "SliderTouch-11"},
	{.raw_id = 0xa05, .name = "Source-HPF-11"},
	{.raw_id = 0xa0b, .name = "TrackAuto-11"},
	{.raw_id = 0xa0c, .name = "TrackEQ-11"},
	{.raw_id = 0xa0d, .name = "TrackDyn-11"},
	{.raw_id = 0xa0e, .name = "TrackInsert-11"},
	{.raw_id = 0xa0f, .name = "TrackSend-11"},
	{.raw_id = 0xa13, .name = "Track-11"},
	{.raw_id = 0xa14, .name = "TrackInput-11"},
	{.raw_id = 0xa15, .name = "TrackRec-11"},
	{.raw_id = 0xa16, .name = "Select-11"},
	{.raw_id = 0xa17, .name = "Solo-11"},
	{.raw_id = 0xa18, .name = "Mute-11"},
	{.raw_id = 0xb00, .name = "SliderTouch-12"},
	{.raw_id = 0xb05, .name = "Source-HPF-12"},
	{.raw_id = 0xb0b, .name = "TrackAuto-12"},
	{.raw_id = 0xb0c, .name = "TrackEQ-12"},
	{.raw_id = 0xb0d, .name = "TrackDyn-12"},
	{.raw_id = 0xb0e, .name = "TrackInsert-12"},
	{.raw_id = 0xb0f, .name = "TrackSend-12"},
	{.raw_id = 0xb13, .name = "Track-12"},
	{.raw_id = 0xb14, .name = "TrackInput-12"},
	{.raw_id = 0xb15, .name = "TrackRec-12"},
	{.raw_id = 0xb16, .name = "Select-12"},
	{.raw_id = 0xb17, .name = "Solo-12"},
	{.raw_id = 0xb18, .name = "Mute-12"},
	{.raw_id = 0xc00, .name = "SliderTouch-13"},
	{.raw_id = 0xc05, .name = "Source-HPF-13"},
	{.raw_id = 0xc0b, .name = "TrackAuto-13"},
	{.raw_id = 0xc0c, .name = "TrackEQ-13"},
	{.raw_id = 0xc0d, .name = "TrackDyn-13"},
	{.raw_id = 0xc0e, .name = "TrackInsert-13"},
	{.raw_id = 0xc0f, .name = "TrackSend-13"},
	{.raw_id = 0xc13, .name = "Track-13"},
	{.raw_id = 0xc14, .name = "TrackInput-13"},
	{.raw_id = 0xc15, .name = "TrackRec-13"},
	{.raw_id = 0xc16, .name = "Select-13"},
	{.raw_id = 0xc17, .name = "Solo-13"},
	{.raw_id = 0xc18, .name = "Mute-13"},
	{.raw_id = 0xd00, .name = "SliderTouch-14"},
	{.raw_id = 0xd05, .name = "Source-HPF-14"},
	{.raw_id = 0xd0b, .name = "TrackAuto-14"},
	{.raw_id = 0xd0c, .name = "TrackEQ-14"},
	{.raw_id = 0xd0d, .name = "TrackDyn-14"},
	{.raw_id = 0xd0e, .name = "TrackInsert-14"},
	{.raw_id = 0xd0f, .name = "TrackSend-14"},
	{.raw_id = 0xd13, .name = "Track-14"},
	{.raw_id = 0xd14, .name = "TrackInput-14"},
	{.raw_id = 0xd15, .name = "TrackRec-14"},
	{.raw_id = 0xd16, .name = "Select-14"},
	{.raw_id = 0xd17, .name = "Solo-14"},
	{.raw_id = 0xd18, .name = "Mute-14"},
	{.raw_id = 0xe00, .name = "SliderTouch-15"},
	{.raw_id = 0xe05, .name = "Source-HPF-15"},
	{.raw_id = 0xe0b, .name = "TrackAuto-15"},
	{.raw_id = 0xe0c, .name = "TrackEQ-15"},
	{.raw_id = 0xe0d, .name = "TrackDyn-15"},
	{.raw_id = 0xe0e, .name = "TrackInsert-15"},
	{.raw_id = 0xe0f, .name = "TrackSend-15"},
	{.raw_id = 0xe13, .name = "Track-15"},
	{.raw_id = 0xe14, .name = "TrackInput-15"},
	{.raw_id = 0xe15, .name = "TrackRec-15"},
	{.raw_id = 0xe16, .name = "Select-15"},
	{.raw_id = 0xe17, .name = "Solo-15"},
	{.raw_id = 0xe18, .name = "Mute-15"},
	{.raw_id = 0xf00, .name = "SliderTouch-16"},
	{.raw_id = 0xf05, .name = "Source-HPF-16"},
	{.raw_id = 0xf0b, .name = "TrackAuto-16"},
	{.raw_id = 0xf0c, .name = "TrackEQ-16"},
	{.raw_id = 0xf0d, .name = "TrackDyn-16"},
	{.raw_id = 0xf0e, .name = "TrackInsert-16"},
	{.raw_id = 0xf0f, .name = "TrackSend-16"},
	{.raw_id = 0xf13, .name = "Track-16"},
	{.raw_id = 0xf14, .name = "TrackInput-16"},
	{.raw_id = 0xf15, .name = "TrackRec-16"},
	{.raw_id = 0xf16, .name = "Select-16"},
	{.raw_id = 0xf17, .name = "Solo-16"},
	{.raw_id = 0xf18, .name = "Mute-16"},
	{.raw_id = 0x1000, .name = "SliderTouch-17"},
	{.raw_id = 0x100b, .name = "TrackAuto-17"},
	{.raw_id = 0x100c, .name = "TrackEQ-17"},
	{.raw_id = 0x100d, .name = "TrackDyn-17"},
	{.raw_id = 0x100e, .name = "TrackInsert-17"},
	{.raw_id = 0x100f, .name = "TrackSend-17"},
	{.raw_id = 0x1013, .name = "Track-17"},
	{.raw_id = 0x1014, .name = "TrackInput-17"},
	{.raw_id = 0x1015, .name = "TrackRec-17"},
	{.raw_id = 0x1016, .name = "Select-17"},
	{.raw_id = 0x1017, .name = "Solo-17"},
	{.raw_id = 0x1018, .name = "Mute-17"},
	{.raw_id = 0x1100, .name = "SliderTouch-18"},
	{.raw_id = 0x110b, .name = "TrackAuto-18"},
	{.raw_id = 0x110c, .name = "TrackEQ-18"},
	{.raw_id = 0x110d, .name = "TrackDyn-18"},
	{.raw_id = 0x110e, .name = "TrackInsert-18"},
	{.raw_id = 0x110f, .name = "TrackSend-18"},
	{.raw_id = 0x1113, .name = "Track-18"},
	{.raw_id = 0x1114, .name = "TrackInput-18"},
	{.raw_id = 0x1115, .name = "TrackRec-18"},
	{.raw_id = 0x1116, .name = "Select-18"},
	{.raw_id = 0x1117, .name = "Solo-18"},
	{.raw_id = 0x1118, .name = "Mute-18"},
	{.raw_id = 0x1200, .name = "SliderTouch-19"},
	{.raw_id = 0x120b, .name = "TrackAuto-19"},
	{.raw_id = 0x120c, .name = "TrackEQ-19"},
	{.raw_id = 0x120d, .name = "TrackDyn-19"},
	{.raw_id = 0x120e, .name = "TrackInsert-19"},
	{.raw_id = 0x120f, .name = "TrackSend-19"},
	{.raw_id = 0x1213, .name = "Track-19"},
	{.raw_id = 0x1214, .name = "TrackInput-19"},
	{.raw_id = 0x1215, .name = "TrackRec-19"},
	{.raw_id = 0x1216, .name = "Select-19"},
	{.raw_id = 0x1217, .name = "Solo-19"},
	{.raw_id = 0x1218, .name = "Mute-19"},
	{.raw_id = 0x1300, .name = "SliderTouch-20"},
	{.raw_id = 0x130b, .name = "TrackAuto-20"},
	{.raw_id = 0x130c, .name = "TrackEQ-20"},
	{.raw_id = 0x130d, .name = "TrackDyn-20"},
	{.raw_id = 0x130e, .name = "TrackInsert-20"},
	{.raw_id = 0x130f, .name = "TrackSend-20"},
	{.raw_id = 0x1313, .name = "Track-20"},
	{.raw_id = 0x1314, .name = "TrackInput-20"},
	{.raw_id = 0x1315, .name = "TrackRec-20"},
	{.raw_id = 0x1316, .name = "Select-20"},
	{.raw_id = 0x1317, .name = "Solo-20"},
	{.raw_id = 0x1318, .name = "Mute-20"},
	{.raw_id = 0x1400, .name = "SliderTouch-21"},
	{.raw_id = 0x140b, .name = "TrackAuto-21"},
	{.raw_id = 0x140c, .name = "TrackEQ-21"},
	{.raw_id = 0x140d, .name = "TrackDyn-21"},
	{.raw_id = 0x140e, .name = "TrackInsert-21"},
	{.raw_id = 0x140f, .name = "TrackSend-21"},
	{.raw_id = 0x1413, .name = "Track-21"},
	{.raw_id = 0x1414, .name = "TrackInput-21"},
	{.raw_id = 0x1415, .name = "TrackRec-21"},
	{.raw_id = 0x1416, .name = "Select-21"},
	{.raw_id = 0x1417, .name = "Solo-21"},
	{.raw_id = 0x1418, .name = "Mute-21"},
	{.raw_id = 0x1500, .name = "SliderTouch-22"},
	{.raw_id = 0x150b, .name = "TrackAuto-22"},
	{.raw_id = 0x150c, .name = "TrackEQ-22"},
	{.raw_id = 0x150d, .name = "TrackDyn-22"},
	{.raw_id = 0x150e, .name = "TrackInsert-22"},
	{.raw_id = 0x150f, .name = "TrackSend-22"},
	{.raw_id = 0x1513, .name = "Track-22"},
	{.raw_id = 0x1514, .name = "TrackInput-22"},
	{.raw_id = 0x1515, .name = "TrackRec-22"},
	{.raw_id = 0x1516, .name = "Select-22"},
	{.raw_id = 0x1517, .name = "Solo-22"},
	{.raw_id = 0x1518, .name = "Mute-22"},
	{.raw_id = 0x1600, .name = "SliderTouch-23"},
	{.raw_id = 0x160b, .name = "TrackAuto-23"},
	{.raw_id = 0x160c, .name = "TrackEQ-23"},
	{.raw_id = 0x160d, .name = "TrackDyn-23"},
	{.raw_id = 0x160e, .name = "TrackInsert-23"},
	{.raw_id = 0x160f, .name = "TrackSend-23"},
	{.raw_id = 0x1613, .name = "Track-23"},
	{.raw_id = 0x1614, .name = "TrackInput-23"},
	{.raw_id = 0x1615, .name = "TrackRec-23"},
	{.raw_id = 0x1616, .name = "Select-23"},
	{.raw_id = 0x1617, .name = "Solo-23"},
	{.raw_id = 0x1618, .name = "Mute-23"},
	{.raw_id = 0x1700, .name = "SliderTouch-24"},
	{.raw_id = 0x170b, .name = "TrackAuto-24"},
	{.raw_id = 0x170c, .name = "TrackEQ-24"},
	{.raw_id = 0x170d, .name = "TrackDyn-24"},
	{.raw_id = 0x170e, .name = "TrackInsert-24"},
	{.raw_id = 0x170f, .name = "TrackSend-24"},
	{.raw_id = 0x1713, .name = "Track-24"},
	{.raw_id = 0x1714, .name = "TrackInput-24"},
	{.raw_id = 0x1715, .name = "TrackRec-24"},
	{.raw_id = 0x1716, .name = "Select-24"},
	{.raw_id = 0x1717, .name = "Solo-24"},
	{.raw_id = 0x1718, .name = "Mute-24"},
	{.raw_id = 0x1800, .name = "AutoEnVol"},
	{.raw_id = 0x1801, .name = "AutoEnSendLv1"},
	{.raw_id = 0x1802, .name = "AutoEnPan"},
	{.raw_id = 0x1803, .name = "AutoEnSendPan"},
	{.raw_id = 0x1804, .name = "AutoEnMute"},
	{.raw_id = 0x1805, .name = "AutoEnSendMute"},
	{.raw_id = 0x1806, .name = "AutoEnSuspend"},
	{.raw_id = 0x1807, .name = "AutoEnPlugin"},
	{.raw_id = 0x1808, .name = "Bypass"},
	{.raw_id = 0x1809, .name = "Bypass"},
	{.raw_id = 0x180a, .name = "DisplayMode"},
	{.raw_id = 0x180b, .name = "Select-Auto"},
	{.raw_id = 0x180c, .name = "Pre-Post"},
	{.raw_id = 0x180d, .name = "SendMute"},
	{.raw_id = 0x180e, .name = "AutoToAll"},
	{.raw_id = 0x180f, .name = "AutoToStart"},
	{.raw_id = 0x1810, .name = "AutoToEnd"},
	{.raw_id = 0x1811, .name = "AutoToPunch"},
	{.raw_id = 0x1812, .name = "AutoToNext"},
	{.raw_id = 0x1813, .name = "Auto-Write"},
	{.raw_id = 0x1814, .name = "Auto-Trim"},
	{.raw_id = 0x1815, .name = "Auto-Touch"},
	{.raw_id = 0x1816, .name = "Auto-Read"},
	{.raw_id = 0x1817, .name = "Auto-Latch"},
	{.raw_id = 0x1818, .name = "Auto-Off"},
	{.raw_id = 0x1819, .name = "DoToAll"},
	{.raw_id = 0x181a, .name = "DoToSelected"},
	{.raw_id = 0x181b, .name = "Default"},
	{.raw_id = 0x181c, .name = "SoloClear"},
	{.raw_id = 0x181d, .name = "PluginSafe"},
	{.raw_id = 0x181e, .name = "VelSens"},
	{.raw_id = 0x181f, .name = "InputMon"},
	{.raw_id = 0x1820, .name = "MasterRec"},
	{.raw_id = 0x1821, .name = "Masters"},
	{.raw_id = 0x1822, .name = "Flip"},
	{.raw_id = 0x1900, .name = "Shift(Add)"},
	{.raw_id = 0x1901, .name = "Opt-Alt"},
	{.raw_id = 0x1902, .name = "Ctrl-Win"},
	{.raw_id = 0x1903, .name = "Cmd-Ctrl"},
	{.raw_id = 0x1a00, .name = "+48v1-8"},
	{.raw_id = 0x1a01, .name = "+48v9-16"},
	{.raw_id = 0x1a02, .name = "ToMon"},
	{.raw_id = 0x1a03, .name = "TalkBack"},
	{.raw_id = 0x1a07, .name = "MonitorMode"},
	{.raw_id = 0x1a08, .name = "Monitor-L"},
	{.raw_id = 0x1a09, .name = "Monitor-C"},
	{.raw_id = 0x1a0a, .name = "Monitor-R"},
	{.raw_id = 0x1a0b, .name = "Monitor-Ls"},
	{.raw_id = 0x1a0c, .name = "Monitor-Rs"},
	{.raw_id = 0x1a0d, .name = "Monitor-LFE"},
	{.raw_id = 0x1a0e, .name = "Monitor-Solo"},
	{.raw_id = 0x1a10, .name = "AltMon"},
	{.raw_id = 0x1a11, .name = "FromCue"},
	{.raw_id = 0x1a12, .name = "On"},
	{.raw_id = 0x1a13, .name = "Main>Cue"},
	{.raw_id = 0x1a14, .name = "On"},
	{.raw_id = 0x1a15, .name = "MonitorMute"},
	{.raw_id = 0x1a16, .name = "MonitorDim"},
	{.raw_id = 0x1a17, .name = "MonitorMono"},
	{.raw_id = 0x1a18, .name = "MonitorMain"},
	{.raw_id = 0x1a19, .name = "MonitorAltSur"},
	{.raw_id = 0x1a1a, .name = "MonitorSt-1"},
	{.raw_id = 0x1a1b, .name = "MonitorSt-2"},
	{.raw_id = 0x1a1c, .name = "MonitorSum"},
	{.raw_id = 0x1b00, .name = "InsMastrByp"},
	{.raw_id = 0x1b01, .name = "InsCompare"},
	{.raw_id = 0x1b02, .name = "InsSafe"},
	{.raw_id = 0x1b03, .name = "InsParam"},
	{.raw_id = 0x1b04, .name = "Assign"},
	{.raw_id = 0x1b05, .name = "AssignInput"},
	{.raw_id = 0x1b06, .name = "AssignOutput"},
	{.raw_id = 0x1b07, .name = "AssignEscCancel"},
	{.raw_id = 0x1b0f, .name = "SoftKeys"},
	{.raw_id = 0x1b10, .name = "Send-F-J"},
	{.raw_id = 0x1b11, .name = "Send-A-F"},
	{.raw_id = 0x1b12, .name = "Send-B-G"},
	{.raw_id = 0x1b13, .name = "Send-C-H"},
	{.raw_id = 0x1b14, .name = "Send-D-I"},
	{.raw_id = 0x1b15, .name = "Send-E-J"},
	{.raw_id = 0x1b16, .name = "<ChannelBar"},
	{.raw_id = 0x1b17, .name = "ChannelBar>"},
	{.raw_id = 0x1c00, .name = "EditModeShuffle"},
	{.raw_id = 0x1c01, .name = "EditModeSpot"},
	{.raw_id = 0x1c02, .name = "EditModeSlip"},
	{.raw_id = 0x1c03, .name = "EditModeGrid"},
	{.raw_id = 0x1d00, .name = "ViewHome"},
	{.raw_id = 0x1d01, .name = "ViewFocus"},
	{.raw_id = 0x1d02, .name = "ViewMicPre"},
	{.raw_id = 0x1d03, .name = "Copy"},
	{.raw_id = 0x1d04, .name = "Paste"},
	{.raw_id = 0x1e01, .name = "Trim"},
	{.raw_id = 0x1e02, .name = "Select"},
	{.raw_id = 0x1e03, .name = "Grabber"},
	{.raw_id = 0x1e04, .name = "Pencil"},
	{.raw_id = 0x1e05, .name = "Smart"},
	{.raw_id = 0x1e06, .name = "LinkEdt-TL"},
	{.raw_id = 0x1e07, .name = "LinkEdt-Trk-Edt"},
	{.raw_id = 0x1f00, .name = "Unnamed"},
	{.raw_id = 0x1f01, .name = "WindowMix"},
	{.raw_id = 0x1f02, .name = "WindowEdit"},
	{.raw_id = 0x1f03, .name = "WindowPlugIn"},
	{.raw_id = 0x1f04, .name = "WindowPan"},
	{.raw_id = 0x1f05, .name = "WindowTransport"},
	{.raw_id = 0x1f06, .name = "WindowWinCfg"},
	{.raw_id = 0x1f07, .name = "WindowMemLock"},
	{.raw_id = 0x2000, .name = "Create"},
	{.raw_id = 0x2001, .name = "Enable"},
	{.raw_id = 0x2002, .name = "Modify"},
	{.raw_id = 0x2003, .name = "Delete"},
	{.raw_id = 0x2004, .name = "Suspend"},
	{.raw_id = 0x2100, .name = "Audition"},
	{.raw_id = 0x2101, .name = "RTZ-E"},
	{.raw_id = 0x2102, .name = "Trans="},
	{.raw_id = 0x2103, .name = "Online"},
	{.raw_id = 0x2104, .name = "PreRoll"},
	{.raw_id = 0x2105, .name = "MarkIn"},
	{.raw_id = 0x2106, .name = "MarkOut"},
	{.raw_id = 0x2107, .name = "PostRoll"},
	{.raw_id = 0x2108, .name = "DynTrans"},
	{.raw_id = 0x2109, .name = "LoopPlay"},
	{.raw_id = 0x210a, .name = "LoopRecord"},
	{.raw_id = 0x210b, .name = "QuickPunch"},
	{.raw_id = 0x210c, .name = "Rewind"},
	{.raw_id = 0x210d, .name = "FastForward"},
	{.raw_id = 0x210e, .name = "Stop"},
	{.raw_id = 0x210f, .name = "Play"},
	{.raw_id = 0x2110, .name = "Record"},
	{.raw_id = 0x2114, .name = "Scrub"},
	{.raw_id = 0x2115, .name = "Trim"},
	{.raw_id = 0x2116, .name = "Shuttle"},
	{.raw_id = 0x2200, .name = "Zoom1"},
	{.raw_id = 0x2201, .name = "Zoom2"},
	{.raw_id = 0x2202, .name = "Zoom3"},
	{.raw_id = 0x2203, .name = "Zoom4"},
	{.raw_id = 0x2204, .name = "Zoom5"},
	{.raw_id = 0x2205, .name = "Zoom"},
	{.raw_id = 0x2206, .name = "Navigate"},
	{.raw_id = 0x2207, .name = "UpArrow"},
	{.raw_id = 0x2208, .name = "DownArrow"},
	{.raw_id = 0x2209, .name = "LeftArrow"},
	{.raw_id = 0x220a, .name = "RightArrow"},
	{.raw_id = 0x2300, .name = "ClearClip"},
	{.raw_id = 0x2301, .name = "MetersPost"},
	{.raw_id = 0x2302, .name = "Counter"},
	{.raw_id = 0x2303, .name = "Undo"},
	{.raw_id = 0x2304, .name = "Redo"},
	{.raw_id = 0x2306, .name = "Enter"},
	{.raw_id = 0x2307, .name = "Esc-Cancel"},
	{.raw_id = 0x2308, .name = "Save"},
	{.raw_id = 0x2400, .name = "BankLeft"},
	{.raw_id = 0x2401, .name = "Nudge"},
	{.raw_id = 0x2402, .name = "BankRight"}
};

static struct c24_control __c24_knobs__[C24_KNOB_COUNT] = 
{
	{.raw_id = 0x0012, .name = "PanKnob-1"},
	{.raw_id = 0x0112, .name = "PanKnob-2"},
	{.raw_id = 0x0212, .name = "PanKnob-3"},
	{.raw_id = 0x0312, .name = "PanKnob-4"},
	{.raw_id = 0x0412, .name = "PanKnob-5"},
	{.raw_id = 0x0512, .name = "PanKnob-6"},
	{.raw_id = 0x0612, .name = "PanKnob-7"},
	{.raw_id = 0x0712, .name = "PanKnob-8"},
	{.raw_id = 0x0812, .name = "PanKnob-9"},
	{.raw_id = 0x0912, .name = "PanKnob-10"},
	{.raw_id = 0x0a12, .name = "PanKnob-11"},
	{.raw_id = 0x0b12, .name = "PanKnob-12"},
	{.raw_id = 0x0c12, .name = "PanKnob-13"},
	{.raw_id = 0x0d12, .name = "PanKnob-14"},
	{.raw_id = 0x0e12, .name = "PanKnob-15"},
	{.raw_id = 0x0f12, .name = "PanKnob-16"},
	{.raw_id = 0x1012, .name = "PanKnob-17"},
	{.raw_id = 0x1112, .name = "PanKnob-18"},
	{.raw_id = 0x1212, .name = "PanKnob-19"},
	{.raw_id = 0x1312, .name = "PanKnob-20"},
	{.raw_id = 0x1412, .name = "PanKnob-21"},
	{.raw_id = 0x1512, .name = "PanKnob-22"},
	{.raw_id = 0x1612, .name = "PanKnob-23"},
	{.raw_id = 0x1712, .name = "PanKnob-24"},
	{.raw_id = 0x2113, .name = "PitchWheelKnob"}
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

uint16_t c24_control_raw_id_to_id(
	const struct c24_control controls[],
	const unsigned int control_count,
	const uint16_t raw_id)
{
	// TODO mieu !!!!!!!!!!!
	for (unsigned int i = 0; i < control_count; i++)
		if (controls[i].raw_id == raw_id)
	 		return i;
	return C24_UNKNOWN_CONTROL;
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

