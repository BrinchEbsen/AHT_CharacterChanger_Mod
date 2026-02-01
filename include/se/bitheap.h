#ifndef BITHEAP_H
#define BITHEAP_H
#include <types.h>

typedef enum PreserveMode {
    Stop,
    Read,
    Write,
    GetSize
} PreserveMode;

typedef struct PreserveStackEntry {
    s32 Start;
    s32 Address;
    s32 End;
    PreserveMode m_PreserveMode;
    u32 BeenWrittenFlag;
} PreserveStackEntry;

typedef struct SE_BitHeap {
    unsigned char m_ByteHeap[0x4000];
    s32 m_NumBitsUsed;
    s32 m_StackPtr;
    PreserveStackEntry m_Stack[32];
} SE_BitHeap;

_Static_assert(sizeof(SE_BitHeap) == 0x4288);

#endif /* BITHEAP_H */