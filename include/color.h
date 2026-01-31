#ifndef COLOR_H
#define COLOR_H
#include <types.h>

typedef struct RGBA {
    union {
        u32 rgba;
        struct {
            u8 r;
            u8 g;
            u8 b;
            u8 a;
        };
    };
} RGBA;

typedef RGBA XRGBA;
typedef RGBA ARGB;

extern void RGBA_Interp(RGBA* Dest, RGBA From, RGBA To, float Amount);

#define COLOR_RGBA(R,G,B,A) ((RGBA){ .r=(R), .g=(G), .b=(B), .a=(A) })
#define COLOR_ARGB(A,R,G,B) ((ARGB){ .r=(R), .g=(G), .b=(B), .a=(A) })
#define COLOR_RGB(R,G,B) ((RGBA){ .r=(R), .g=(G), .b=(B), .a=0x80 })

#define COLOR_TEXT          COLOR_RGBA(0x80, 0x64, 0x32, 0xFF) // Used by various UI elements
#define COLOR_WHITE         COLOR_RGBA(0x80, 0x80, 0x80, 0x80)
#define COLOR_BLACK         COLOR_RGBA(0x00, 0x00, 0x00, 0x80)
#define COLOR_RED           COLOR_RGBA(0x80, 0x00, 0x00, 0x80)
#define COLOR_GREEN         COLOR_RGBA(0x00, 0x80, 0x00, 0x80)
#define COLOR_BLUE          COLOR_RGBA(0x00, 0x00, 0x80, 0x80)
#define COLOR_LIGHT_RED     COLOR_RGBA(0x80, 0x40, 0x40, 0x80)
#define COLOR_LIGHT_GREEN   COLOR_RGBA(0x40, 0x80, 0x40, 0x80)
#define COLOR_LIGHT_BLUE    COLOR_RGBA(0x40, 0x40, 0x80, 0x80)
#define COLOR_DARK_RED      COLOR_RGBA(0x40, 0x00, 0x00, 0x80)
#define COLOR_DARK_GREEN    COLOR_RGBA(0x00, 0x40, 0x00, 0x80)
#define COLOR_DARK_BLUE     COLOR_RGBA(0x00, 0x00, 0x40, 0x80)

#endif /* COLOR_H */