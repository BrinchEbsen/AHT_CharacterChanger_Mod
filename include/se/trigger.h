#ifndef TRIGGER_H
#define TRIGGER_H
#include <types.h>
#include <exvector.h>
#include <extrigger.h>
#include <color.h>
#include <runtimeclass.h>

typedef struct TriggerSetupInfo {
    s32 TriggerClassSize;
    void* Trigger_CtorFunc;
    void* Trigger_DtorFunc;
} TriggerSetupInfo;

typedef struct HandlerSetupInfo {
    void* Handler_TriggerCreateFunc;
    void* new_XSEItemHandler;
    EXRuntimeClass* pItemEXRuntimeClass;
    void* new_XSEItem;
    s32 StoredDataSize;
} HandlerSetupInfo;

typedef struct TriggerTableEntry {
    EXHashCode PrimaryHashCode;
    EXHashCode SubHashCode;
    HandlerSetupInfo xHandlerSetup;
    TriggerSetupInfo TriggerSetup;
} TriggerTableEntry;

_Static_assert(sizeof(TriggerTableEntry) == 0x28);

typedef enum States__SE_Trigger {
    State_Undefined=0,
    State_Suspended=1,
    State_Activating=2,
    State_Activated=3,
    State_Killed=4
} States__SE_Trigger;

typedef struct SE_Trigger__vtable SE_Trigger__vtable;
struct SE_Trigger__vtable {
    u8 padding[8];
    struct __vtbl_ptr_type GetRuntimeClass;
    struct __vtbl_ptr_type v_ExpandCollision;
    struct __vtbl_ptr_type v_ExpandTint;
    struct __vtbl_ptr_type SE_Trigger;
    struct __vtbl_ptr_type GetRange;
    struct __vtbl_ptr_type v_IsInsideActiveRange;
    struct __vtbl_ptr_type v_IsOutsideActiveRange;
    struct __vtbl_ptr_type v_IsOutsideActiveAndTriggerRange;
    struct __vtbl_ptr_type v_OnCreate;
    struct __vtbl_ptr_type v_OnMapState;
    struct __vtbl_ptr_type v_OnDestuct;
    struct __vtbl_ptr_type v_ActivateStart;
    struct __vtbl_ptr_type v_CanBeActivated;
    struct __vtbl_ptr_type v_ActivateUpdate;
    struct __vtbl_ptr_type v_UpdateSuspended;
    struct __vtbl_ptr_type v_UpdateActivated;
    struct __vtbl_ptr_type v_Suspend;
    struct __vtbl_ptr_type v_Preserve;
    struct __vtbl_ptr_type v_Draw;
    struct __vtbl_ptr_type v_GetHandlerSetupInfo;
};

typedef struct SE_Trigger SE_Trigger;
struct SE_Trigger {
    EXVector3 m_Position;
    States__SE_Trigger m_State;
    float m_Range;
    u16 m_Flags;
    s16 m_LoadingCount;
    EXTrigger m_EXTrigger;
    EXVector3 m_Rotation;
    RGBA m_Tint;
    EXMapOn m_MapOn;
    /* HandlerSetupInfo* */ void* m_pHandlerSetups;
    s16 m_NumHandlerSetups;
    s16 m_GeoTriggerIndex;
    TriggerTableEntry *m_pTriggerTableEntry;
    s32 m_BitHeapAddress;
    /* SE_Map* */ void* m_pMap;
    /* EXGeoFile* */ void* m_pGeoFile;
    unsigned int m_ScanID[3];
    /* XSEItemHandler* */ void* m_pXSEItemHandler;
    EXHashCode m_TypeHashCode;
    EXHashCode m_TypeSubHashCode;
    SE_Trigger__vtable *__vtable;
};

_Static_assert(sizeof(SE_Trigger) == 0xc8);

typedef struct TriggerBitArray {
    s32 m_BitsPerElement; /* Inherited from BitArray */
    s32 m_NumElements; /* Inherited from BitArray */
    u8 *m_pBits; /* Inherited from BitArray */
    s32 m_Numu8; /* Inherited from BitArray */
} TriggerBitArray;

typedef struct GameState__TriggerList {
    s32 m_BitHeapAddress;
    s32 m_BitHeapSize;
} GameState__TriggerList;

typedef struct SE_TriggerHeader {
    SE_Trigger *m_pSE_Trigger;
} SE_TriggerHeader;

typedef struct SE_Map SE_Map;
typedef struct SE_TriggerList {
    TriggerBitArray m_TriggerBits;
    GameState__TriggerList *m_pGameState;
    SE_Map *m_pMap;
    s32 m_NumTriggers;
    SE_TriggerHeader *m_pTriggers;
    u8 *m_pSE_TriggerMem;
    u32 m_Flags;
} SE_TriggerList;

_Static_assert(sizeof(SE_TriggerList) == 0x28);

#endif /* TRIGGER_H */