#ifndef MAIN_H
#define MAIN_H
#include <gameflow.h>

void main_panel_draw_loop(void* pWnd);
void main_game_draw_loop(void* pWnd);
void main_update_loop();
s32 SEGameFlow__v_StateRunning__VTHOOK(SEGameFlow* self);

#endif /* MAIN_H */