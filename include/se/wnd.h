#ifndef WND_H
#define WND_H
#include <types.h>
#include <loop.h>
#include <color.h>
#include <exrect.h>
#include <expoint.h>
#include <exvector.h>
#include <arena.h>

typedef enum TextAlign {
    TopLeft,
    BottomLeft,
    CentreLeft,
    TopCentre,
    Centre,
    BottomCentre,
    TopRight,
    CentreRight,
    BottomRight
} TextAlign;

typedef enum TextureBoxTabs {
    Tab_Off,
    Tab_Left,
    Tab_Right
} TextureBoxTabs;

#define RECT_SIDE_UPPER 0b1
#define RECT_SIDE_LOWER 0b10
#define RECT_SIDE_LEFT  0b100
#define RECT_SIDE_RIGHT 0b1000
#define RECT_SIDE_ALL   RECT_SIDE_UPPER | RECT_SIDE_LOWER | RECT_SIDE_LEFT | RECT_SIDE_RIGHT

extern void* gpGameWnd;
extern void* gpPanelWnd;

typedef void(*DrawLoop)(void*);

extern void* gpGeoHT_File_Panel;

#define XWND_TEXT_BUFFER_SIZE 0x400
extern short unsigned int gTextBuffer[XWND_TEXT_BUFFER_SIZE];

typedef struct EXPrimVert {
    vec_xyzw vec;
    union {
        MXVector VtxColUV;
        struct {
            float u;
            float v;
            u32 Pad;
            XRGBA Col;
        };
    };
} EXPrimVert;

_Static_assert(sizeof(EXPrimVert) == 0x20);

extern void EXBaseWnd__SelectFont(void* self, void* pGeoFile, EXHashCode FontHash);

extern void XWnd__SetText(void* self, EXHashCode File, EXHashCode Font, RGBA* Col, TextAlign Align);

extern void XWnd__FontPrintW(void* self, u16 x, u16 y, wchar16* pText, float Scale, TextAlign Align, bool Filter);
extern void XWnd__FontPrint(void* self, u16 x, u16 y, char* pText, float Scale, TextAlign Align, bool Filter);

extern void XWnd__TextPrintH(void* self, EXHashCode Code);
extern void XWnd__TextPrintC(void* self, char* pText);
extern void XWnd__TextPrintW(void* self, wchar16* pText);

extern void XWnd__AddDrawSELoop_Tail(void* self, SE_Loop* pLoop);

/**
 * Draw a rectangle with an gradient outline.
 * @param Rect The rectangle defining the dimensions.
 * @param StartCol The start (outer) colour of the outline.
 * @param EndCol The end (inner) colour of the outline.
 * @param Size The outline thickness.
 * @param SideFlags Which sides of the outline to draw (use the "RECT_SIDE_" defines).
 */
extern void XWnd__DrawGraduatedRectOutline(void* self, EXRect* Rect, RGBA StartCol, RGBA EndCol, s32 Size, u32 SideFlags);
/**
 * Draw a solid rectangle.
 * @param R The rectangle defining the dimensions.
 * @param Col The color of the rectangle.
 */
extern void XWnd__DrawRect(void* self, EXRect* R, RGBA Col);
/**
 * Draw a rectangle with an outline.
 * @param R The rectangle defining the dimensions.
 * @param Col The colour of the outline.
 * @param Thick The outline thickness.
 * @param SideFlags Which sides of the outline to draw (use the "RECT_SIDE_" defines).
 */
extern void XWnd__DrawRectOutline(void* self, EXRect* R, RGBA Col, s32 Thick, u32 SideFlags);
/**
 * Draw a sector of a circle.
 * @param XY Center point of the circle.
 * @param InRad Inner radius of the circle.
 * @param OutRad Outer radius of the circle.
 * @param StartAng Start angle in radians.
 * @param EndAng End angle in radians.
 * @param StartInRGB Color of the vertex at the inner radius' start angle.
 * @param StartOutRGB Color of the vertex at the outer radius' start angle.
 * @param EndInRGB Color of the vertex at the inner radius' end angle.
 * @param EndOutRGB Color of the vertex at the outer radius' end angle.
 * @param Divisions Number of divisions ("resolution" of the shape).
 */
extern void XWnd__DrawSector(void* self, EXPoint *XY, float InRad, float OutRad, float StartAng, float EndAng,
    ARGB StartInRGB, ARGB StartOutRGB, ARGB EndInRGB, ARGB EndOutRGB, float Divisions);
/**
 * Draw a box with textured edges.
 * @param Rect The rectangle defining the dimensions.
 * @param borderoutsiderect Whether the border will be drawn on the inside or outside of the rectangle.
 * @param tab The type of tabs on this box.
 * @param Col The color of the box.
 * @param pTextures A list of texture hashcodes to be used for the box. Leave null to use default textures.
 */
extern void XWnd__DrawTextureBox(void* self, EXRect* Rect, Bool borderoutsiderect, TextureBoxTabs tab, RGBA Col,
    EXHashCode* pTextures);

#define WND_DRAWING_BUFFER_SIZE 0x2000
extern u8 wnd_drawing_buffer[WND_DRAWING_BUFFER_SIZE];
extern Arena wnd_drawing_arena;

extern void EXWnd__DrawLine(void* self, EXPrimVert* v1, EXPrimVert* v2);
extern void EXWnd__DrawTriFan(void* self, uint nVerts, EXPrimVert* pVert);
extern void EXWnd__DrawTriStrip(void* self, uint nVerts, EXPrimVert* pVert);
extern void EXWnd__SelectTriFanTexture(void* self, void* pTexture);

#define XWND_FONT_COLOR(pWnd) OFFSET_PTR(RGBA, pWnd, 0x80)
#define XWND_TEXT_SCALE(pWnd) OFFSET_PTR(float, pWnd, 0x2D8)
#define XWND_TEXT_RECT(pWnd) OFFSET_PTR(EXRect, pWnd, 0x2DC)
#define XWND_TEXT_ALIGN(pWnd) OFFSET_PTR(TextAlign, pWnd, 0x2EC)
#define XWND_LINE_SPACING(pWnd) OFFSET_PTR(u16, pWnd, 0x376)

#endif /* WND_H */