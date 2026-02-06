#include <gamedraw.h>
#include <types.h>
#include <player.h>
#include <wnd.h>
#include <util.h>
#include <hashcodes.h>
#include <os.h>
#include <exmatrix.h>
#include <igmath.h>
#include <trigger_specialbase.h>
#include <map.h>

typedef void (*XSEItemHandler_Player__GameWndDraw)(void*);

void player_game_wnd_draw(void)
{
    if (gpPlayer == NULL) return;

    void* vtable = OFFSET_VAL(void*, gpPlayer, 0x4);
    XSEItemHandler_Player__GameWndDraw func
        = OFFSET_VAL(XSEItemHandler_Player__GameWndDraw, vtable, 0x20c);

    func(gpPlayer);
}

DrawLoop gamedraw_callback = NULL;

// Hooks into the player game window drawing routine
void gamedraw_loop(void)
{
    player_game_wnd_draw();

    if ((gpGameWnd != NULL) && (gamedraw_callback != NULL)) {
        gamedraw_callback(gpGameWnd);
    }
}
