#include <main.h>
#include <types.h>
#include <paneldraw.h>
#include <gamedraw.h>
#include <gui_base.h>
#include <gameflow.h>
#include <os.h>
#include <characterchanger.h>

void main_panel_draw_loop(void* pWnd)
{
    characterchanger_drawhud(pWnd);
}

void main_game_draw_loop(void* pWnd)
{
    
}

void main_update_loop()
{
    characterchanger_update();
}

s32 SEGameFlow__v_StateRunning__VTHOOK(SEGameFlow* self)
{
    if (gp_paneldraw_loop == NULL) {
        GUI_Base* paneldraw = paneldraw_create();
        if (paneldraw != NULL) {
            paneldraw_callback = main_panel_draw_loop;
        }
    }

    if (gamedraw_callback == NULL) {
        gamedraw_callback = main_game_draw_loop;
    }

    main_update_loop();

    return SEGameFlow__v_StateRunning(self);
}