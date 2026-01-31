#ifndef PAD_H
#define PAD_H
#include <types.h>

#define PAD_BUTTON_DPAD_UP          0x1
#define PAD_BUTTON_DPAD_DOWN        0x2
#define PAD_BUTTON_DPAD_LEFT        0x4
#define PAD_BUTTON_DPAD_RIGHT       0x8
#define PAD_BUTTON_LANALOG_UP       0x10
#define PAD_BUTTON_LANALOG_DOWN     0x20
#define PAD_BUTTON_LANALOG_LEFT     0x40
#define PAD_BUTTON_LANALOG_RIGHT    0x80
#define PAD_BUTTON_RANALOG_UP       0x100
#define PAD_BUTTON_RANALOG_DOWN     0x200
#define PAD_BUTTON_RANALOG_LEFT     0x400
#define PAD_BUTTON_RANALOG_RIGHT    0x800
#define PAD_BUTTON_B                0x1000
#define PAD_BUTTON_A                0x2000
#define PAD_BUTTON_X                0x4000
#define PAD_BUTTON_Y                0x8000
#define PAD_BUTTON_L3               0x10000  // Unused in GC
#define PAD_BUTTON_R3               0x20000  // Unused in GC
#define PAD_BUTTON_START            0x40000
#define PAD_BUTTON_SELECT           0x80000  // Unused in GC
#define PAD_BUTTON_L                0x100000
#define PAD_BUTTON_L2               0x200000 // Unused in GC
#define PAD_BUTTON_R                0x400000
#define PAD_BUTTON_Z                0x800000

#define PAD_NUM_BUTTONS 24
#define PAD_NUM_PORTS 4

typedef struct EXPadActionMap {
    u32 ButtonBits;
    u32 ActionBits;
} EXPadActionMap;

typedef struct XGamePad {
    uint m_ButtonState[8];
    uint m_LastButtonState[8];
    uint m_ButtonEdgeDown[8];
    uint m_ButtonEdgeUp[8];
    //GC:
    //- 0, 1: Left stick
    //- 2, 3: Right stick
    //- 12: Left trigger
    //- 14: Right trigger
    float m_AnalogChan[8][16];
    uchar m_DeadZoneMode[8][2];
    uint m_ActionState[8];
    uint m_LastActionState[8];
    uint m_ActionEdgeDown[8];
    uint m_ActionEdgeUp[8];
    EXPadActionMap m_ActionMap[8][32];
    uchar m_ActionMapCount[8];
    uint m_RumbleTimeHi[8];
    uint m_RumbleTimeLo[8];
    uchar m_RumbleStrengthHi[8];
    uchar m_RumbleStrengthLo[8];
    char m_EnableRumble[8];
    char m_Inserted[8];
    void** __vtable;
} EXBaseGamePad;

/// @brief The global game pad instance.
extern EXBaseGamePad* gpGamePad;

/// @brief The global current pad index.
extern int g_PadNum;

// Check if a button is down.
bool pad_button_state(uint button, int pad_num);
// Check if a button was down last frame.
bool pad_last_button_state(uint button, int pad_num);
// Check if a button has just been pressed.
bool pad_button_edge_down(uint button, int pad_num);
// Check if a button has just been released.
bool pad_button_edge_up(uint button, int pad_num);
// Check if a button is down on the global pad.
bool g_pad_button_state(uint button);
// Check if a button was down last frame on the global pad.
bool g_pad_last_button_state(uint button);
// Check if a button has just been pressed on the global pad.
bool g_pad_button_edge_down(uint button);
// Check if a button has just been released on the global pad.
bool g_pad_button_edge_up(uint button);

// Check if a button has been pressed a given number of times within a given number of frames.
bool pad_button_edge_down_multiple(uint button, int num_presses, int time_limit, int pad_num);
// Check if a button has been pressed a given number of times within a given number of frames on the global pad.
bool g_pad_button_edge_down_multiple(uint button, int num_presses, int time_limit);

// Get the value of the left stick x-axis.
float pad_analog_get_l_stick_x(int pad_num);
// Get the value of the left stick y-axis.
float pad_analog_get_l_stick_y(int pad_num);
// Get the value of the left stick x-axis on the global pad.
float g_pad_analog_get_l_stick_x();
// Get the value of the left stick y-axis on the global pad.
float g_pad_analog_get_l_stick_y();
// Get the value of the right stick x-axis.
float pad_analog_get_r_stick_x(int pad_num);
// Get the value of the right stick y-axis.
float pad_analog_get_r_stick_y(int pad_num);
// Get the value of the right stick x-axis on the global pad.
float g_pad_analog_get_r_stick_x();
// Get the value of the right stick y-axis on the global pad.
float g_pad_analog_get_r_stick_y();
// Get the value of the left analog trigger.
float pad_analog_get_l_trigger(int pad_num);
// Get the value of the right analog trigger.
float pad_analog_get_r_trigger(int pad_num);
// Get the value of the left analog trigger on the global pad.
float g_pad_analog_get_l_trigger();
// Get the value of the right analog trigger on the global pad.
float g_pad_analog_get_r_trigger();

#endif /* PAD_H */