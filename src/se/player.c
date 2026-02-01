#include <player.h>
#include <pad.h>

bool g_enable_scanmode = false;

bool XSEItemHandler_Player__TestScanMode_HOOK(void *player, int current_mode)
{
    if (!g_enable_scanmode) {
        return false;
    }

    bool dpad_held = g_pad_button_state(
        PAD_BUTTON_DPAD_DOWN |
        PAD_BUTTON_DPAD_LEFT |
        PAD_BUTTON_DPAD_RIGHT |
        PAD_BUTTON_DPAD_UP);
    bool z_pressed = g_pad_button_edge_down(PAD_BUTTON_Z);
    return dpad_held && z_pressed;
}
