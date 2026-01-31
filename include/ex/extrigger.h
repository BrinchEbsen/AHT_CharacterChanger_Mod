#ifndef EXTRIGGER_H
#define EXTRIGGER_H
#include <types.h>
#include <extypes.h>

typedef struct EXTrigger__vtable EXTrigger__vtable;
struct EXTrigger__vtable {
    u8 padding[8];
    struct __vtbl_ptr_type GetRuntimeClass;
    struct __vtbl_ptr_type EXTrigger;
};

typedef struct EXTrigger EXTrigger;
struct EXTrigger {
    u32 m_TrigFlags;
    u32 m_GameFlags;
    EXHashCode m_GeoFileHashRef;
    EXHashCode m_GfxHashRef;
    s32 m_TrigScriptIndex;
    EXVar32 m_Data[16];
    short int m_Links[8];
    EXTrigger__vtable *__vtable;
};

_Static_assert(sizeof(EXTrigger) == 0x68);

#endif /* EXTRIGGER_H */