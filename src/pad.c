#include "pad.h"

int button_state_counts[PAD_NUM_BUTTONS * PAD_NUM_PORTS];
int button_state_timers[PAD_NUM_BUTTONS * PAD_NUM_PORTS];

// BUTTONS

inline bool pad_button_state(uint button, int pad_num)
{
    return (gpGamePad->m_ButtonState[pad_num] & button) != 0;
}

inline bool pad_last_button_state(uint button, int pad_num)
{
    return (gpGamePad->m_LastButtonState[pad_num] & button) != 0;
}

inline bool pad_button_edge_down(uint button, int pad_num)
{
    return (gpGamePad->m_ButtonEdgeDown[pad_num] & button) != 0;
}

inline bool pad_button_edge_up(uint button, int pad_num)
{
    return (gpGamePad->m_ButtonEdgeUp[pad_num] & button) != 0;
}

// BUTTONS (global pad)

inline bool g_pad_button_state(uint button)
{
    return pad_button_state(button, g_PadNum);
}

inline bool g_pad_last_button_state(uint button)
{
    return pad_last_button_state(button, g_PadNum);
}

inline bool g_pad_button_edge_down(uint button)
{
    return pad_button_edge_down(button, g_PadNum);
}

inline bool g_pad_button_edge_up(uint button)
{
    return pad_button_edge_up(button, g_PadNum);
}

bool pad_button_edge_down_multiple(uint button, int num_presses, int time_limit, int pad_num)
{
    if (button == 0) return false;

    // Get index into buffers
    int index = __builtin_ctz(button) + (PAD_NUM_BUTTONS * pad_num);

    // Number of times pressed
    int* count = button_state_counts + index;
    // Number of frames since first press
    int* timer = button_state_timers + index;

    // Whether button is pressed
    bool state = pad_button_edge_down(button, pad_num);

    // If hasn't been pressed and isn't pressed
    if ((*count == 0) && !state) {
        *timer = 0;

        return false;
    }

    (*timer)++;

    if (*timer < time_limit) {
        // If button pressed within time limit
        if (state) {
            (*count)++;
        }

        // Check if goal reached
        if (*count >= num_presses) {
            *timer = 0;
            *count = 0;

            return true;
        }

        return false;
    } else {
        // Time ran out
        *timer = 0;
        *count = 0;

        return false;
    }
}

bool g_pad_button_edge_down_multiple(uint button, int num_presses, int time_limit)
{
    return pad_button_edge_down_multiple(button, num_presses, time_limit, g_PadNum);
}

// LEFT STICK

inline float pad_analog_get_l_stick_x(int pad_num)
{
    return gpGamePad->m_AnalogChan[pad_num][0];
}

inline float pad_analog_get_l_stick_y(int pad_num)
{
    return gpGamePad->m_AnalogChan[pad_num][1];
}

// LEFT STICK (global pad)

inline float g_pad_analog_get_l_stick_x()
{
    return gpGamePad->m_AnalogChan[g_PadNum][0];
}

inline float g_pad_analog_get_l_stick_y()
{
    return gpGamePad->m_AnalogChan[g_PadNum][1];
}

// RIGHT STICK

inline float pad_analog_get_r_stick_x(int pad_num)
{
    return gpGamePad->m_AnalogChan[pad_num][2];
}

inline float pad_analog_get_r_stick_y(int pad_num)
{
    return gpGamePad->m_AnalogChan[pad_num][3];
}

// RIGHT STICK (global pad)

inline float g_pad_analog_get_r_stick_x()
{
    return gpGamePad->m_AnalogChan[g_PadNum][2];
}

inline float g_pad_analog_get_r_stick_y()
{
    return gpGamePad->m_AnalogChan[g_PadNum][3];
}

// TRIGGERS

float pad_analog_get_l_trigger(int pad_num)
{
    return gpGamePad->m_AnalogChan[pad_num][12];
}

float pad_analog_get_r_trigger(int pad_num)
{
    return gpGamePad->m_AnalogChan[pad_num][14];
}

// TRIGGERS (global pad)

float g_pad_analog_get_l_trigger()
{
    return gpGamePad->m_AnalogChan[g_PadNum][12];
}

float g_pad_analog_get_r_trigger()
{
    return gpGamePad->m_AnalogChan[g_PadNum][14];
}
