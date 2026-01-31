#ifndef EXTYPES_H
#define EXTYPES_H
#include <types.h>

typedef union EXVar32 {
    float f;
    s32 i;
    EXHashCode h;
} EXVar32;

typedef struct EXMapOn {
    s16 m_MapOn;
} EXMapOn;

#endif /* EXTYPES_H */