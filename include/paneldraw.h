#ifndef PANELDRAW_H
#define PANELDRAW_H
#include <types.h>
#include <gui_base.h>
#include <wnd.h>

extern GUI_Base* gp_paneldraw_loop;
extern GUI_Base__vtable paneldraw_vtable;

extern char gVarTextBuffer[0x200];

extern DrawLoop paneldraw_callback;

void paneldraw_vtable_setup();
GUI_Base* paneldraw_create();
s32 paneldraw__draw(GUI_Base* self, void* pWnd);

void textprint_set_rect(void* pWnd, u16 x, u16 y);
void textprint_set_params(void *pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color);

void textprintw(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color, bool Shadow, wchar16 *pText);
void textprint(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color, bool Shadow, char* pText);
void textprint_hash(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color, bool Shadow, EXHashCode code);
void textprintf(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color, bool Shadow, char* pText, ...);

#define TEXT_PRINT(pWnd, x, y, pText) \
    textprint(pWnd, x, y, 1.0f, TopLeft, COLOR_TEXT, true, pText)

#define TEXT_PRINT_SCALE(pWnd, x, y, Scale, pText) \
    textprint(pWnd, x, y, Scale, TopLeft, COLOR_TEXT, true, pText)

#define TEXT_PRINT_ALIGN(pWnd, x, y, Align, pText) \
    textprint(pWnd, x, y, 1.0f, Align, COLOR_TEXT, true, pText)

#define TEXT_PRINT_COLOR(pWnd, x, y, Color, pText) \
    textprint(pWnd, x, y, 1.0f, TopLeft, Color, true, pText)

#define TEXT_PRINT_SCALE_ALIGN(pWnd, x, y, Scale, Align, pText) \
    textprint(pWnd, x, y, Scale, Align, COLOR_TEXT, true, pText)

#define TEXT_PRINT_SCALE_COLOR(pWnd, x, y, Scale, Color, pText) \
    textprint(pWnd, x, y, Scale, TopLeft, Color, true, pText)

#define TEXT_PRINT_ALIGN_COLOR(pWnd, x, y, Align, Color, pText) \
    textprint(pWnd, x, y, 1.0f, Align, Color, true, pText)

#define TEXT_PRINT_F(pWnd, x, y, pText, ...) \
    textprintf(pWnd, x, y, 1.0f, TopLeft, COLOR_TEXT, true, pText, __VA_ARGS__)

#define TEXT_PRINT_SCALE_F(pWnd, x, y, Scale, pText, ...) \
    textprintf(pWnd, x, y, Scale, TopLeft, COLOR_TEXT, true, pText, __VA_ARGS__)

#define TEXT_PRINT_ALIGN_F(pWnd, x, y, Align, pText, ...) \
    textprintf(pWnd, x, y, 1.0f, Align, COLOR_TEXT, true, pText, __VA_ARGS__)

#define TEXT_PRINT_COLOR_F(pWnd, x, y, Color, pText, ...) \
    textprintf(pWnd, x, y, 1.0f, TopLeft, Color, true, pText, __VA_ARGS__)

#define TEXT_PRINT_SCALE_ALIGN_F(pWnd, x, y, Scale, Align, pText, ...) \
    textprintf(pWnd, x, y, Scale, Align, COLOR_TEXT, true, pText, __VA_ARGS__)

#define TEXT_PRINT_SCALE_COLOR_F(pWnd, x, y, Scale, Color, pText, ...) \
    textprintf(pWnd, x, y, Scale, TopLeft, Color, true, pText, __VA_ARGS__)

#define TEXT_PRINT_ALIGN_COLOR_F(pWnd, x, y, Align, Color, pText, ...) \
    textprintf(pWnd, x, y, 1.0f, Align, Color, true, pText, __VA_ARGS__)

#endif /* PANELDRAW_H */