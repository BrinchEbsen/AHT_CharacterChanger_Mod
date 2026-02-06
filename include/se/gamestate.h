#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <types.h>
#include <player.h>
#include <exvector.h>
#include <apptime.h>
#include <playerstate.h>
#include <map.h>
#include <bitheap.h>

typedef struct TypeUnion__RestartPoint {
    u32 HasVisited:1;
    EXHashCode HashCode;
    EXHashCode NameTextHashCode;
} TypeUnion__RestartPoint;

typedef struct TypeUnion__LightGem {
    u32 IsLight:1;
} TypeUnion__LightGem;

typedef struct TypeUnion__MapReveal {
    EXHashCode Identifier_HashCode;
    u32 IsRevealed:1;
} TypeUnion__MapReveal;

typedef union TypeUnion {
    TypeUnion__RestartPoint RestartPoint;
    TypeUnion__LightGem LightGem;
    TypeUnion__MapReveal MapReveal;
} TypeUnion;

typedef enum Type__GameStateTrigInfo {
    Type_Undefined=0,
    Type_RestartPoint=1,
    Type_LightGem=2,
    Type_MapReveal=3
} Type__GameStateTrigInfo;

typedef struct GameStateTrigInfo {
    s16 m_MapIndex;
    s16 m_TrigIndex;
    EXVector3 m_XYZ;
    Type__GameStateTrigInfo m_Type;
    TypeUnion u;
} GameStateTrigInfo;

typedef struct PlayerObjectives {
    uint m_CompletedObjectives[16];
} PlayerObjectives;

typedef struct PlayerTasks {
    uint m_TasksState[5];
} PlayerTasks;

typedef struct PlayerShop {
    uint m_AvailableFlags;
} PlayerShop;

typedef struct SE_GameState {
    s32 m_Version;
    s32 m_VersionValid;
    s32 m_StartMapIndex;
    u32 m_Flags;
    s32 m_NumTrigInfo;
    GameStateTrigInfo m_TrigInfo[256];
    Players m_CheatsPlayerType;
    XAppTime m_StartTime;
    float m_PlayTimer;
    float m_TimeOutTimer;
    PlayerState m_PlayerState;
    PlayerObjectives m_PlayerObjectives;
    PlayerTasks m_PlayerTasks;
    u8 _pad0[4];
    PlayerShop m_PlayerShop;
    SE_BitHeap m_BitHeap;
    GameState__SE_Map m_Map[200];
} SE_GameState;

_Static_assert(sizeof(SE_GameState) == 0xb254);

extern SE_GameState gGameState;

#endif /* GAMESTATE_H */