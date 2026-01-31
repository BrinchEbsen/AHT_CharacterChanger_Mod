#ifndef GAME_FLOW_H
#define GAME_FLOW_H
#include <loop.h>

typedef struct SEGameFlow SEGameFlow;
struct SEGameFlow {
	SE_Loop *m_pParentLoop; /* Inherited from SE_Loop */
	SE_Loop *m_pthis; /* Inherited from SE_Loop */
	DLinkedTYPE m_DLink[2]; /* Inherited from SE_Loop */
	List m_DList[1]; /* Inherited from SE_Loop */
	s32 m_Flags__SE_Loop; /* Inherited from SE_Loop */
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
	SE_Loop__vtable* __vtable; /* Inherited from SE_Loop */
    u32 m_Flags;
    // u32 m_SkipMoviesFlag; /* ONLY ON PS2? */
    /* LoadingScreen* */ void* m_pLoadingScreen;
    /* GameBooter* */ void* m_pGameBooter;
    /* BootupTitleSequence* */ void* m_pBootupTitleSequence;
    float m_GamePadIdleTime;
    s32 m_PlayerHasControlCount;
};

_Static_assert(sizeof(SEGameFlow) == 0x90);

extern SEGameFlow theGameFlow;

extern s32 SEGameFlow__v_StateRunning(SEGameFlow* self);

#endif /* GAME_FLOW_H */