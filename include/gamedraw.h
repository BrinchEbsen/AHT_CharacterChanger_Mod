#ifndef GAMEDRAW_H
#define GAMEDRAW_H
#include <types.h>
#include <exmatrix.h>
#include <exvector.h>
#include <color.h>
#include <wnd.h>

extern DrawLoop gamedraw_callback;

void gamedraw_loop(void);

void draw_3d_ellipse(void *pWnd, mat_44 *normalMtx, EXVector *centerPos,
    float width, float height, RGBA color, int divisions);

void draw_load_triggers(void* pWnd);

#endif /* GAMEDRAW_H */