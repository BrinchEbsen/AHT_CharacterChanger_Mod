#ifndef MAP_MINIGAME_H
#define MAP_MINIGAME_H
#include <map.h>
#include <setime.h>

typedef enum MiniGameMode {
    MGM_StartConfirmInit=0,
    MGM_StartConfirmUpdate=1,
    MGM_ExitMenuInit=2,
    MGM_ExitMenuUpdate=3,
    MGM_QuitRetryMenuInit=4,
    MGM_QuitRetryMenuUpdate=5,
    MGM_CompleteConfirmInit=6,
    MGM_CompleteConfirmUpdate=7,
    MGM_Exit=8,
    MGM_Exiting=9,
    MGM_Running=10
} MiniGameMode;

typedef enum MiniGameLevel {
    MiniGame_Undefined=0,
    MiniGame_Easy=1,
    MiniGame_Hard=2,
    MiniGame_Timed=3
} MiniGameLevel;

typedef struct MiniGame_Waves {
    EXHashCode Identifier;
    float StartDelay;
    SE_Trigger *pController;
} MiniGame_Waves;

typedef struct SEMap_MiniGame__vtable {
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
    struct __vtbl_ptr_type SEMap_MiniGame;
    struct __vtbl_ptr_type GetItemEnv;
    struct __vtbl_ptr_type v_GetLoadPlayerType;
    struct __vtbl_ptr_type GetPreLoadList;
    struct __vtbl_ptr_type GetMapName;
    struct __vtbl_ptr_type GetMapCheatsName;
    struct __vtbl_ptr_type IncludeInGameStats;
    struct __vtbl_ptr_type UseNewShadow;
    struct __vtbl_ptr_type GetMapSelectMenuCode;
    struct __vtbl_ptr_type v_Constructor;
    struct __vtbl_ptr_type v_UpdateRunning;
    struct __vtbl_ptr_type v_Close;
    struct __vtbl_ptr_type v_PreLoadInitialise;
    struct __vtbl_ptr_type v_PostLoadInitialise;
    struct __vtbl_ptr_type PostLoadInitialise;
    struct __vtbl_ptr_type v_DoesPreserve;
    struct __vtbl_ptr_type v_IsGameMap;
    struct __vtbl_ptr_type v_GetDefaultTriggerRange;
    struct __vtbl_ptr_type v_PlayerSetup;
    struct __vtbl_ptr_type v_AddPlayer;
    struct __vtbl_ptr_type v_CollectedDarkGem;
    struct __vtbl_ptr_type v_CollectedLightGem;
    struct __vtbl_ptr_type v_CollectedDragonEgg;
    struct __vtbl_ptr_type v_LevelGemAttractRadius;
    struct __vtbl_ptr_type v_LevelGemPickupFlags;
    struct __vtbl_ptr_type v_MiniGameSetup;
    struct __vtbl_ptr_type v_MiniGameStart;
    struct __vtbl_ptr_type v_MiniGameRunning;
    struct __vtbl_ptr_type v_MiniGameClose;
    struct __vtbl_ptr_type v_MiniGameComplete;
    struct __vtbl_ptr_type SetMiniGameComplete;
    struct __vtbl_ptr_type SetMiniGameFailed;
    struct __vtbl_ptr_type SetMiniGameDie;
} SEMap_MiniGame__vtable;

typedef struct SEMap_MiniGame {
	SE_Loop *m_pParentLoop; /* Inherited from SE_Loop */
	SE_Loop *m_pthis; /* Inherited from SE_Loop */
	DLinkedTYPE m_DLink[2]; /* Inherited from SE_Loop */
	List m_DList[1]; /* Inherited from SE_Loop */
	s32 m_Flags_SE_Loop; /* Inherited from SE_Loop */
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
	SEMap_MiniGame__vtable* __vtable; /* Inherited from SE_Loop */
    /* XSEItemAnimator_Map* */ void* m_pMapAnimator; /* Inherited from SE_MapLoop */
    List m_SEHandlerList[1]; /* Inherited from SE_Map */
    RealmID m_RealmID; /* Inherited from SE_Map */
    LevelID m_LevelID; /* Inherited from SE_Map */
    s32 m_Flags; /* Inherited from SE_Map */
    EXVector m_SetStartPoint; /* Inherited from SE_Map */
    EXMapOn m_StartMapOn; /* Inherited from SE_Map */
    PauseMode m_PauseMode; /* Inherited from SE_Map */
    EXHashCode m_MapSoundBank; /* Inherited from SE_Map */
    Players m_DefaultPlayerType; /* Inherited from SE_Map */
    Players m_OverrideDefaultPlayerType; /* Inherited from SE_Map */
    TriggeringStates m_TriggeringState; /* Inherited from SE_Map */
    s32 m_TriggersWaitingCount; /* Inherited from SE_Map */
    s32 m_TriggerBitHeapSizeOverride; /* Inherited from SE_Map */
    s32 m_MapListIndex; /* Inherited from SE_Map */
    SE_Map *m_pWaitForMap; /* Inherited from SE_Map */
    LevInfo m_LevelInfo; /* Inherited from SE_Map */
    s32 m_Temps32; /* Inherited from SE_Map */
    EXHashCode m_MapGeoHashCode; /* Inherited from SE_Map */
    EXHashCode m_MapHashCode; /* Inherited from SE_Map */
    GeoItem m_MapLoader; /* Inherited from SE_Map */
    SE_TriggerList m_TriggerList; /* Inherited from SE_Map */
    s32 m_SectionLoadViewDeleteCount; /* Inherited from SE_Map */
    /* SEItemEnvView* */ void* m_pSectionLoadView; /* Inherited from SE_Map */
    GameState__SE_Map *m_GameState; /* Inherited from SE_Map */
    EXHashCode m_IntroCutSceneObjective; /* Inherited from SE_Map */
    MiniGameMode m_MiniGameMode;
    Players m_LastPlayer;
    SE_Map *m_pPrevMap;
    Bool m_PauseTimer;
    Bool m_BestTimeSet;
    Bool m_bMiniGameComplete;
    undefined field62_0x13f;
    int m_StoredHealth;
    int m_StoredGems;
    int m_GemsCollected;
    MiniGame_Waves *m_pMiniGameWaves;
    int m_nMiniGameWaves;
    int m_nCurrentWave;
    SETime m_WaveTimer;
    Bool m_TimerSet;
    EXHashCode m_MiniGameRetry;
    EXHashCode m_MiniGameObjective;
    EXHashCode m_MiniGameComplete;
    EXHashCode m_MiniGameFailed;
    EXHashCode m_MiniGameDied;
    EXHashCode m_MiniGameMusicLoop;
    EXHashCode m_MiniGameMusicWin;
    EXHashCode m_MiniGameMusicLose;
    EXHashCode m_MiniGameMusicDie;
    EXHashCode m_MiniGameObjComplete;
    int m_TimeLimit;
    int m_RemainCount;
    Players m_Player;
    Bool m_Retrying;
    Bool m_ForceRestartUpdate;
    float m_LastStartPointTime;
    int m_LastStartPointValue;
    int m_LastStartPointAmmo;
    int m_LastStartPoint;
    int m_StartPointValue;
    MiniGameLevel m_MinigameLevel;
    u8 _pad0[4];
} SEMap_MiniGame;

_Static_assert(sizeof(SEMap_MiniGame) == 0x1b0);

extern EXRuntimeClass classSEMap_MiniGame;

#endif /* MAP_MINIGAME_H */