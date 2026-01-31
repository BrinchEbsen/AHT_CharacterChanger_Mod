#ifndef MAP_H
#define MAP_H
#include <loop.h>
#include <exvector.h>
#include <extypes.h>
#include <player.h>
#include <trigger.h>

typedef struct SE_Map SE_Map;

typedef enum RealmID {
    Realm_Undefined=0,
    Realm_1=1,
    Realm_2=2,
    Realm_3=3,
    Realm_4=4
} RealmID;

typedef enum LevelID {
    Level_Undefined=0,
    Level_A=1,
    Level_B=2,
    Level_C=3,
    Level_D=4,
    Level_E=5,
    Level_Z=6,
    Level_S=7,
    Level_MR_Spy=8,
    Level_MR_Spx=9,
    Level_MR_Sgt=10,
    Level_MR_Blk=11
} LevelID;

typedef enum PauseMode {
    PauseMode_Undefined=0,
    PauseMode_Normal=1,
    PauseMode_MiniGame=2
} PauseMode;

typedef enum TriggeringStates {
    TriggeringState_Undefined=0,
    TriggeringState_Start=1,
    TriggeringState_FindMap=2,
    TriggeringState_LoadingMap=3,
    TriggeringState_CreateMap=4,
    TriggeringState_StartPoint=5,
    TriggeringState_MapOnLoading=6,
    TriggeringState_LoadPlayer=7,
    TriggeringState_CreatePlayerx=8,
    TriggeringState_MapTriggersStart=9,
    TriggeringState_MapTriggers=10
} TriggeringStates;

typedef struct LevInfo {
    u32 m_Achieved;
    s16 m_visited;
    u16 m_summatelse;
} LevInfo;

typedef struct GeoItem {
    EXHashCode m_File;
    EXHashCode m_HashRef;
    s32 m_SectionIndex;
} GeoItem;

typedef struct GameState__SE_Map {
    s32 m_LastStartPoint;
    Players m_LastStartPointPlayer;
    int m_CollectMax[10];
    int m_CollectNum[10];
    u32 m_Flags;
    GameState__TriggerList m_TriggerList;
} GameState__SE_Map;

_Static_assert(sizeof(GameState__SE_Map) == 0x64);

typedef struct SE_Map__vtable SE_Map__vtable;
struct SE_Map__vtable {
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
    struct __vtbl_ptr_type SE_Map;
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
};

struct SE_Map {
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
	SE_Map__vtable* __vtable; /* Inherited from SE_Loop */
    /* XSEItemAnimator_Map* */ void* m_pMapAnimator; /* Inherited from SE_MapLoop */
    List m_SEHandlerList[1]; /* Inherited from SE_MapLoop */
    RealmID m_RealmID;
    LevelID m_LevelID;
    s32 m_Flags;
    EXVector m_SetStartPoint;
    EXMapOn m_StartMapOn;
    PauseMode m_PauseMode;
    EXHashCode m_MapSoundBank;
    Players m_DefaultPlayerType;
    Players m_OverrideDefaultPlayerType;
    TriggeringStates m_TriggeringState;
    s32 m_TriggersWaitingCount;
    s32 m_TriggerBitHeapSizeOverride;
    s32 m_MapListIndex;
    SE_Map *m_pWaitForMap;
    LevInfo m_LevelInfo;
    s32 m_Temps32;
    EXHashCode m_MapGeoHashCode;
    EXHashCode m_MapHashCode;
    GeoItem m_MapLoader;
    SE_TriggerList m_TriggerList;
    s32 m_SectionLoadViewDeleteCount;
    /* SEItemEnvView* */ void* m_pSectionLoadView;
    GameState__SE_Map *m_GameState;
    EXHashCode m_IntroCutSceneObjective;
};

_Static_assert(sizeof(SE_Map) == 0x128);

typedef struct SE_MapListEntry {
    SE_Map* m_pMap;
} SE_MapListEntry;

typedef struct SE_MapList {
    SE_MapListEntry m_List[200];
} SE_MapList;

extern SE_MapList gMapList;
extern int SE_MapList__m_gNumMaps;

#endif /* MAP_H */