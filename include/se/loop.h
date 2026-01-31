#ifndef LOOP_H
#define LOOP_H
#include <types.h>
#include <runtimeclass.h>
#include <dlinked.h>
#include <fade.h>
#include <exdlist.h>

typedef enum m_States {
	Start = 0,
	Loading = 1,
	Triggering = 2,
	Running = 3,
	Closed = 4,
	Undefined = 5,
	Locked = 6,
	WaitingForKick = 7,
	NumStates = 8
} m_States;

typedef struct SE_Loop__vtable SE_Loop__vtable;
struct SE_Loop__vtable {
    u8 padding[8];
    struct __vtbl_ptr_type GetRuntimeClass;
    struct __vtbl_ptr_type v_UseFiles;
    struct __vtbl_ptr_type v_OnMessage;
    struct __vtbl_ptr_type v_SendMessage;
    struct __vtbl_ptr_type RequestClose;
    struct __vtbl_ptr_type v_ForceClose;
    struct __vtbl_ptr_type v_OnStart;
    struct __vtbl_ptr_type v_OnStarted;
    struct __vtbl_ptr_type v_StateStart;
    struct __vtbl_ptr_type v_OnLoading;
    struct __vtbl_ptr_type v_OnLoaded;
    struct __vtbl_ptr_type v_StateLoading;
    struct __vtbl_ptr_type v_OnTriggering;
    struct __vtbl_ptr_type v_StateTriggering;
    struct __vtbl_ptr_type v_OnTriggered;
    struct __vtbl_ptr_type v_OnRunning;
    struct __vtbl_ptr_type v_StateRunning;
    struct __vtbl_ptr_type v_PausedStateRunning;
    struct __vtbl_ptr_type v_OnClose;
    struct __vtbl_ptr_type v_StateClosed;
    struct __vtbl_ptr_type v_DoClose;
    struct __vtbl_ptr_type Update;
    struct __vtbl_ptr_type v_DrawStateRunning;
    struct __vtbl_ptr_type v_Draw;
    struct __vtbl_ptr_type v_Cue;
    struct __vtbl_ptr_type v_IsCueing;
    struct __vtbl_ptr_type v_IsCued;
    struct __vtbl_ptr_type v_CueRun;
    struct __vtbl_ptr_type SE_Loop;
};

extern SE_Loop__vtable SE_Loop__virtual_table;

typedef struct SE_Loop SE_Loop;
struct SE_Loop { // 0x78
	/* 0x00 */ SE_Loop *m_pParentLoop;
	/* 0x04 */ SE_Loop *m_pthis;
	/* 0x08 */ DLinkedTYPE m_DLink[2];
	/* 0x28 */ List m_DList[1];
	/* 0x38 */ s32 m_Flags;
	/* 0x3c */ s32 m_PauseOnCount;
	/* 0x40 */ s32 m_DisplayOffCount;
	/* 0x44 */ EXHashCode m_ID;
	/* 0x48 */ EXHashCode *m_pLoadList;
	/* 0x4c */ SEFade *m_pFade;
	/* 0x50 */ SE_Loop *m_pMessageLoop;
	/* 0x54 */ m_States m_State;
	/* 0x58 */ m_States m_NextState;
	/* 0x5c */ s32 m_Delay;
	/* 0x60 */ s32 m_KickFlags;
	/* 0x64 */ s32 m_WaitingForKickFlags;
	/* 0x68 */ s32 m_WaitForKickFlags;
	/* 0x6c */ s32 m_UpdateCounter;
	/* 0x70 */ s32 m_CloseRequestedCount;
	/* 0x74 */ SE_Loop__vtable* __vtable;
};

_Static_assert(sizeof(SE_Loop) == 0x78);

extern SE_Loop* SE_Loop__CreateObject(void);
extern s32 SE_Loop__DrawStateRunning(SE_Loop* self, void* pWnd);
extern s32 SE_Loop__ChildListDraw(SE_Loop* self, void* pWnd);
extern s32 SE_Loop__Cue(SE_Loop* self);
extern s32 SE_Loop__CueRun(SE_Loop* self);
extern void SE_Loop__CueChildLoop(SE_Loop* self, SE_Loop* pChild, s32 HeadFlag);
extern void SE_Loop__AddDrawToXWnd(SE_Loop* self, EXDListItem* pWnd);

#endif /* LOOP_H */