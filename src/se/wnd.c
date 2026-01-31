#include <wnd.h>
#include <igstdlib.h>

Arena wnd_drawing_arena = {
    .begin = (u8*)&wnd_drawing_buffer,
    .current = (u8*)&wnd_drawing_buffer,
    .size = WND_DRAWING_BUFFER_SIZE,
    .name = "Window Drawing Buffer Arena"
};
