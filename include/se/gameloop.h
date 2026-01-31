#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <loop.h>

typedef struct SE_GameLoop__vtable SE_GameLoop__vtable;
struct SE_GameLoop__vtable {
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
    struct __vtbl_ptr_type SE_GameLoop;
};

typedef struct SE_GameLoop SE_GameLoop;
struct SE_GameLoop {
	SE_Loop *m_pParentLoop; /* Inherited from SE_Loop */
	SE_Loop *m_pthis; /* Inherited from SE_Loop */
	DLinkedTYPE m_DLink[2]; /* Inherited from SE_Loop */
	List m_DList[1]; /* Inherited from SE_Loop */
	s32 m_Flags; /* Inherited from SE_Loop */
	s32 m_PauseOnCount; /* Inherited from SE_Loop */
	s32 m_DisplayOffCount; /* Inherited from SE_Loop */
	EXHashCode m_ID; /* Inherited from SE_Loop */
	EXHashCode *m_pLoadList; /* Inherited from SE_Loop */
	SEFade *m_pFade; /* Inherited from SE_Loop */
	SE_Loop *m_pMessageLoop; /* Inherited from SE_Loop */
	m_States m_State; /* Inherited from SE_Loop */
	m_States m_NextState; /* Inherited from SE_Loop */
	s32 m_Delay; /* Inherited from SE_Loop */
	s32 m_KickFlags; /* Inherited from SE_Loop */
	s32 m_WaitingForKickFlags; /* Inherited from SE_Loop */
	s32 m_WaitForKickFlags; /* Inherited from SE_Loop */
	s32 m_UpdateCounter; /* Inherited from SE_Loop */
	s32 m_CloseRequestedCount; /* Inherited from SE_Loop */
	SE_GameLoop__vtable* __vtable; /* Inherited from SE_Loop */
    /* GameLoop_MapChanger* */ void* m_pMapChanger;
    s32 m_PauseEnable;
    SE_Loop *m_pOnCloseLoop;
    /* GUI_Panel* */ void* m_pPanel;
    u32 m_GameIsPaused:1;
    u32 m_GameIsDisplayed:1;
    u32 m_GameIsIdle:1;
    u32 m_MiniGameTimedMode:1;
    u32 m_MiniGameEasy:1;
    u32 m_MiniGameHard:1;
    s32 m_GamePausedCount;
    s32 m_GameDisplayedCount;
    u32 m_SingleStep_Flag:1;
    u32 m_SingleStep_DoFlag:1;
    u32 m_SingleStep_Speed;
    u32 m_SingleStep_Count;
    u32 m_gc_unknown; // not on PS2?
};

_Static_assert(sizeof(SE_GameLoop) == 0xA4);

extern SE_GameLoop gGameLoop;

extern void SE_GameLoop__GameSetPauseOn(SE_GameLoop* this, s32 PanelFlag);
extern void SE_GameLoop__GameSetPauseOff(SE_GameLoop* this, s32 PanelFlag);

#endif /* GAMELOOP_H */