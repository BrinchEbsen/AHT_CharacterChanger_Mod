#ifndef EXRANDOM_H
#define EXRANDOM_H
#include <types.h>

typedef struct EXRandClass {
    u32 m_RandShift;
} EXRandClass;

extern EXRandClass g_EXRandClass;

extern u32 EXRandClass__Rand32(EXRandClass* self);
extern float EXRandClass__Randf(EXRandClass* self);

// Random 32-bit integer.
#define RAND_32 EXRandClass__Rand32(&g_EXRandClass)
// Random float between 0 and 1.
#define RAND_F EXRandClass__Randf(&g_EXRandClass)

typedef struct EXRandFastClass {
    u32 m_Seed;
} EXRandFastClass;

extern EXRandFastClass g_EXRandFastClass;

// Fast random 32-bit integer.
#define RAND_FAST_32 (g_EXRandFastClass.m_Seed = (g_EXRandFastClass.m_Seed * 0x19660d) + 0x3c6ef35f, g_EXRandFastClass.m_Seed)
// Fast random float between 0 and 1.
#define RAND_FAST_F ((RAND_FAST_32 / 2) * 4.656613e-10f)

#endif /* EXRANDOM_H */