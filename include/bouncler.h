#ifndef BOUNCLER_H
#define BOUNCLER_H
#include <types.h>
#include <exvector.h>

extern u8 theItemEnv;

extern void XSEItemEnv__AddXSEItem(void* self, void* pItem, u32 GroupFlags);
extern void* XSEItem__CreateObject(void);
extern void EXItem__AddAnimator(void* self, void* animator);
extern void* EXItemAnimator__CreateFrom(void* pGeoFile, EXHashCode HashRef);
extern void* EXGeoFile__GetGeoFile(EXHashCode Code);

extern EXVector scale_low;
extern EXVector scale_high;
extern int cycle_timer;
extern int cycle_length;
extern int half_cycle_length;

void* create_the_thing(EXVector* pos, EXVector* rot);

void change_item_scale(void* item, EXVector* scl);

void animate_bouncler(void* item);

float cosine_interp(float start, float end, int time, int end_time);

#endif /* BOUNCLER_H */