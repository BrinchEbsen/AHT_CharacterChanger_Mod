#include <paneldraw.h>
#include <os.h>
#include <igstdlib.h>
#include <wnd.h>
#include <gameflow.h>
#include <hashcodes.h>
#include <exdisplay.h>
#include <exrect.h>
#include <pad.h>
#include <gameloop.h>

GUI_Base* gp_paneldraw_loop = NULL;
GUI_Base__vtable paneldraw_vtable;

char gVarTextBuffer[0x200];

DrawLoop paneldraw_callback = NULL;

void paneldraw_vtable_setup() {
    // Copy the GUI_Base virtual table to our custom one, and replace the functions we want.
    memcpy(&paneldraw_vtable, &GUI_Base_virtual_table, sizeof(GUI_Base__vtable));
    paneldraw_vtable.v_Draw.__pfn = paneldraw__draw;
}

// Create or get the paneldraw loop.
GUI_Base* paneldraw_create() {
    ONCE {
        paneldraw_vtable_setup();
    }

    // Check if already created
    if (gp_paneldraw_loop != NULL) {
        return gp_paneldraw_loop;
    }

    // Create loop
    gp_paneldraw_loop = GUI_Base__CreateObject();
    if (gp_paneldraw_loop == NULL) {
        OS_PANIC("Unable to create paneldraw loop!\n");
        return NULL;
    }

    // Replace with custom vtable
    gp_paneldraw_loop->__vtable = &paneldraw_vtable;

    // Assign the panel window to the loop
    gp_paneldraw_loop->m_pAddDrawToXWnd = gpPanelWnd;

    // Add loop to the game flow
    SE_Loop__CueChildLoop((SE_Loop*)&theGameFlow, (SE_Loop*)gp_paneldraw_loop, 0);

    // Get the loop running
    SE_Loop__CueRun((SE_Loop*)gp_paneldraw_loop);

    return gp_paneldraw_loop;
}

// Custom draw method of the paneldraw loop
s32 paneldraw__draw(GUI_Base* self, void* pWnd) {
    GUI_Base__v_Draw(self, pWnd);

    if (paneldraw_callback != NULL) {
        paneldraw_callback(pWnd);
    }
    
    return 0;
}

void textprint_set_rect(void* pWnd, u16 x, u16 y)
{
    EXRect* textRect = XWND_TEXT_RECT(pWnd);
    EXRect* displayRect = &EXBaseDisplay__m_pDisplay->m_SafeFrame;

    textRect->x = x;
    textRect->y = y;
    textRect->w = displayRect->w - x;
    textRect->h = displayRect->h - y;
}

void textprint_set_params(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color)
{
    EXBaseWnd__SelectFont(pWnd, gpGeoHT_File_Panel, HT_Font_Test);

    *XWND_TEXT_SCALE(pWnd) = Scale;
    *XWND_TEXT_ALIGN(pWnd) = Align;
    *XWND_LINE_SPACING(pWnd) = 0;
    XWND_FONT_COLOR(pWnd)->rgba = Color.rgba;
    
    textprint_set_rect(pWnd, x, y);
}

void textprintw(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color, bool Shadow, wchar16 *pText)
{
    if (Shadow) {
        textprint_set_params(pWnd, x+2, y+2, Scale, Align, COLOR_BLACK);
        XWnd__TextPrintW(pWnd, pText);
    
        XWND_FONT_COLOR(pWnd)->rgba = Color.rgba;
        textprint_set_rect(pWnd, x, y);
        XWnd__TextPrintW(pWnd, pText);
    } else {
        textprint_set_params(pWnd, x, y, Scale, Align, Color);
        XWnd__TextPrintW(pWnd, pText);
    }
}

void textprint_hash(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color, bool Shadow, EXHashCode code)
{
    if (Shadow) {
        textprint_set_params(pWnd, x+2, y+2, Scale, Align, COLOR_BLACK);
        XWnd__TextPrintH(pWnd, code);
    
        XWND_FONT_COLOR(pWnd)->rgba = Color.rgba;
        textprint_set_rect(pWnd, x, y);
        XWnd__TextPrintH(pWnd, code);
    } else {
        textprint_set_params(pWnd, x, y, Scale, Align, Color);
        XWnd__TextPrintH(pWnd, code);
    }
}

void textprint(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color, bool Shadow, char *pText)
{
    if (Shadow) {
        textprint_set_params(pWnd, x+2, y+2, Scale, Align, COLOR_BLACK);
        XWnd__TextPrintC(pWnd, pText);
    
        XWND_FONT_COLOR(pWnd)->rgba = Color.rgba;
        textprint_set_rect(pWnd, x, y);
        XWnd__TextPrintC(pWnd, pText);
    } else {
        textprint_set_params(pWnd, x, y, Scale, Align, Color);
        XWnd__TextPrintC(pWnd, pText);
    }
}

void textprintf(void* pWnd, u16 x, u16 y, float Scale, TextAlign Align, RGBA Color, bool Shadow, char *pText, ...)
{
    va_list args;
    va_start(args, pText);

    vsprintf(gVarTextBuffer, pText, args);
    textprint(pWnd, x, y, Scale, Align, Color, Shadow, gVarTextBuffer);

    va_end(args);
}