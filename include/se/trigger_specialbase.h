#ifndef TRIGGER_SPECIALBASE_H
#define TRIGGER_SPECIALBASE_H
#include <types.h>
#include <trigger.h>
#include <exdatum.h>
#include <exmatrix.h>
#include <runtimeclass.h>

typedef struct Trigger_SpecialBase__vtable Trigger_SpecialBase__vtable;
struct Trigger_SpecialBase__vtable {
    u8 padding[8];
    struct __vtbl_ptr_type GetRuntimeClass;
    struct __vtbl_ptr_type v_ExpandCollision;
    struct __vtbl_ptr_type v_ExpandTint;
    struct __vtbl_ptr_type Trigger_SpecialBase;
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
    struct __vtbl_ptr_type v_IsInside;
    struct __vtbl_ptr_type v_UpdateCommon;
    struct __vtbl_ptr_type v_OnCrossIn;
    struct __vtbl_ptr_type v_OnCrossOut;
};

typedef struct Trigger_SpecialBase Trigger_SpecialBase;
struct Trigger_SpecialBase {
    EXVector3 m_Position; /* Inherited from SE_Trigger */
    States__SE_Trigger m_State; /* Inherited from SE_Trigger */
    float m_Range; /* Inherited from SE_Trigger */
    u16 m_Flags_SE_Trigger; /* Inherited from SE_Trigger */
    s16 m_LoadingCount; /* Inherited from SE_Trigger */
    EXTrigger m_EXTrigger; /* Inherited from SE_Trigger */
    EXVector3 m_Rotation; /* Inherited from SE_Trigger */
    RGBA m_Tint; /* Inherited from SE_Trigger */
    EXMapOn m_MapOn; /* Inherited from SE_Trigger */
    /* HandlerSetupInfo* */ void* m_pHandlerSetups; /* Inherited from SE_Trigger */
    s16 m_NumHandlerSetups; /* Inherited from SE_Trigger */
    s16 m_GeoTriggerIndex; /* Inherited from SE_Trigger */
    TriggerTableEntry *m_pTriggerTableEntry; /* Inherited from SE_Trigger */
    s32 m_BitHeapAddress; /* Inherited from SE_Trigger */
    /* SE_Map* */ void* m_pMap; /* Inherited from SE_Trigger */
    /* EXGeoFile* */ void* m_pGeoFile; /* Inherited from SE_Trigger */
    unsigned int m_ScanID[3]; /* Inherited from SE_Trigger */
    /* XSEItemHandler* */ void* m_pXSEItemHandler; /* Inherited from SE_Trigger */
    EXHashCode m_TypeHashCode; /* Inherited from SE_Trigger */
    EXHashCode m_TypeSubHashCode; /* Inherited from SE_Trigger */
    Trigger_SpecialBase__vtable *__vtable; /* Inherited from SE_Trigger */
    EXDatumTemp m_Datum;
    EXMatrix m_InvMatrix;
    EXGeoTriggerDatum m_EXGeoTriggerDatum;
    EXVector m_PlaneNormal;
    EXMatrix m_PlaneNormalMatrix;
    EXMatrix m_PlaneNormalInvMatrix;
    float m_Width;
    float m_Height;
    u32 m_Flags;
    undefined4 _pad0;
};

_Static_assert(sizeof(Trigger_SpecialBase) == 0x208);

extern EXRuntimeClass classTrigger_SpecialBase;

#endif /* TRIGGER_SPECIALBASE_H */