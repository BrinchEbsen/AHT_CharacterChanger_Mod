#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H
#include <types.h>
#include <exvector.h>
#include <player.h>
#include <camera.h>
#include <map.h>

#define ABILITY_DOUBLE_JUMP         0x1
#define ABILITY_HIT_POINT_UPGRADE   0x4
#define ABILITY_POLE_SPIN           0x10
#define ABILITY_ICE_BREATH          0x20
#define ABILITY_ELECTRIC_BREATH     0x40
#define ABILITY_WATER_BREATH        0x80
#define ABILITY_DOUBLE_GEM          0x200
#define ABILITY_AQUA_LUNG           0x800
#define ABILITY_SUPERCHARGE         0x1000
#define ABILITY_INVINCIBILITY       0x2000
#define ABILITY_BOUGHT_LOCK_PICK    0x4000
#define ABILITY_WING_SHIELD         0x8000
#define ABILITY_WALL_KICK           0x10000
#define ABILITY_HORN_DIVE_UPGRADE   0x20000
#define ABILITY_BUTTERFLY_JAR       0x40000

#define ABILITY_ALL_PERMANENT_ABILITIES \
    ABILITY_DOUBLE_JUMP |\
    ABILITY_HIT_POINT_UPGRADE |\
    ABILITY_POLE_SPIN |\
    ABILITY_ICE_BREATH |\
    ABILITY_ELECTRIC_BREATH |\
    ABILITY_WATER_BREATH |\
    ABILITY_BOUGHT_LOCK_PICK |\
    ABILITY_WING_SHIELD |\
    ABILITY_WALL_KICK |\
    ABILITY_HORN_DIVE_UPGRADE

#define PLAYERSTATE_BLINK_BOMBS_MAX 10

#define PLAYERSTATE_HEALTH_UPGRADED_GOLD    0xA0
#define PLAYERSTATE_HEALTH_UPGRADED_BLUE    0x80
#define PLAYERSTATE_HEALTH_UPGRADED_GREEN   0x60
#define PLAYERSTATE_HEALTH_UPGRADED_RED     0x40
#define PLAYERSTATE_HEALTH_UPGRADED_NOSPARX 0x20
#define PLAYERSTATE_HEALTH_UPGRADED_DEAD    0x00

#define PLAYERSTATE_HEALTH_GOLD     0xA0
#define PLAYERSTATE_HEALTH_BLUE     0x80
#define PLAYERSTATE_HEALTH_GREEN    0x60
#define PLAYERSTATE_HEALTH_NOSPARX  0x40
#define PLAYERSTATE_HEALTH_DEAD     0x20

typedef enum MiniGameID {
    MiniGameID_Undefined=0,
    MiniGameID_NoMiniGame=1,
    MiniGameID_Cannon=2,
    MiniGameID_Turret=3,
    MiniGameID_Sparx1=4
} MiniGameID;

typedef struct PlayerSetupInfo__vtable {
    u8 padding[8];
    struct __vtbl_ptr_type PlayerSetupInfo;
} PlayerSetupInfo__vtable;

typedef struct PlayerSetupInfo {
    EXVector m_Position;
    EXVector m_Rotation;
    Players m_Player;
    MiniGameID m_MiniGameID;
    s32 m_MapListIndex;
    CamTypes m_CameraType;
    CamCreateMode m_CameraCreateMode;
    u32 m_Flags;
    /* EXFixedArray<unsigned int,8> */ unsigned int m_Data_EXHashCode[8];
    /* EXFixedArray<float,8> */ float m_Data_r32[8];
    /* EXFixedArray<int,8> */ int m_Data_s32[8];
    /* EXFixedArray<unsigned int,8> */ unsigned int m_Data_u32[8];
    PlayerSetupInfo__vtable *__vtable;
    u8 _pad0[4];
} PlayerSetupInfo;

SE_Map* PlayerSetupInfo__GetMap(PlayerSetupInfo* self);

_Static_assert(sizeof(PlayerSetupInfo) == 0xc0);

typedef struct PlayerState {
    BreathType m_CurrentBreath;
    u32 m_Health;
    s32 m_Gems;
    s32 m_TotalGems;
    s8 m_LockPickers;
    s8 m_LockPickers_Max;
    s8 m_LockPickers_Total;
    s8 m_LockPickers_Magazines;
    s8 m_FlameBombs;
    s8 m_FlameBombs_Max;
    s8 m_FlameBombs_Total;
    s8 m_FlameBombs_Magazines;
    s8 m_IceBombs;
    s8 m_IceBombs_Max;
    s8 m_IceBombs_Total;
    s8 m_IceBombs_Magazines;
    s8 m_WaterBombs;
    s8 m_WaterBombs_Max;
    s8 m_WaterBombs_Total;
    s8 m_WaterBombs_Magazines;
    s8 m_ElectricBombs;
    s8 m_ElectricBombs_Max;
    s8 m_ElectricBombs_Total;
    s8 m_ElectricBombs_Magazines;
    s16 m_Xarrows;
    s16 m_Xarrows_Max;
    u32 m_AbilityFlags;
    float m_WaterDiveTimer;
    float m_SuperchargeTimer;
    float m_SuperchargeTimerMax;
    float m_InvincibleTimer;
    float m_InvincibleTimerMax;
    float m_DoubleGemTimer;
    float m_DoubleGemTimerMax;
    float m_SgtBird_Fuel;
    u16 m_SgtBird_Bombs;
    u16 m_SgtBird_Missiles;
    s16 m_SparxSmartBombs;
    s16 m_SparxSeekers;
    s16 m_BlinkBombs;
    s8 m_TotalLightGems;
    s8 m_TotalDarkGems;
    s8 m_TotalDragonEggs;
    s8 m_DragonEggSets;
    s8 m_UNK_GC;
    u8 _pad0[4];
    PlayerSetupInfo m_Setup;
    Players m_LastPlayerSetup;
    u8 _pad1[4];
} PlayerState;

_Static_assert(sizeof(PlayerState) == 0x128);

extern void PlayerState__SetHealth(PlayerState* self, int health);
extern void PlayerState__RestartGame(PlayerState* self);

#endif /* PLAYERSTATE_H */