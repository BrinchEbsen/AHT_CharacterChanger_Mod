#ifndef GAMEDRAW_H
#define GAMEDRAW_H
#include <types.h>
#include <exmatrix.h>
#include <exvector.h>
#include <color.h>
#include <wnd.h>

extern DrawLoop gamedraw_callback;

void gamedraw_loop(void);

#endif /* GAMEDRAW_H */