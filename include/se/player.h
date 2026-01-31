#ifndef PLAYER_H
#define PLAYER_H
#include <types.h>

typedef enum Players {
    Player_Undefined=0,
    Player_Spyro=1,
    Player_Hunter=2,
    Player_Sparx=3,
    Player_Blinky=4,
    Player_SrgBird=5,
    Player_BallGadget=6,
    Player_Ember=7,
    Player_Flame=8
} Players;

typedef enum PlayerModes {
	nomode = 0,
	breathe = 1,
	forcebreathe = 2,
	listen = 3,
	listen_water = 4,
	fall = 5,
	fallland = 6,
	falllongland = 7,
	jump = 8,
	swampjump = 9,
	jumpland = 10,
	doublejump = 11,
	jumpledgegrab = 12,
	jumpslam = 13,
	jumpslamland = 14,
	scan = 15,
	walk = 16,
	charge = 17,
	supercharge = 18,
	glide = 19,
	glideland = 20,
	glidestart = 21,
	walkstop = 22,
	walkturn180 = 23,
	hitwall = 24,
	hitwallwater = 25,
	breatheFire = 26,
	tailspin = 27,
	jumpcharge = 28,
	chargepunch = 29,
	polegrab = 30,
	polegrabslip = 31,
	firstperson = 32,
	firstpersonwater = 33,
	takedamage = 34,
	death = 35,
	iceydeath = 36,
	teeter = 37,
	collidebounce = 38,
	spit = 39,
	deathfall = 40,
	teleportIn = 41,
	teleportOut = 42,
	idleSparx = 43,
	wallkick = 44,
	wallkickledgegrab = 45,
	stunned = 46,
	sneak = 47,
	water_paddle = 48,
	water_dive = 49,
	water_jump = 50,
	water_surface = 51,
	water_hitswim = 52,
	water_hitpaddle = 53,
	water_death = 54,
	fire_cannon = 55,
	fire_turret = 56,
	fire_cannonMini = 57,
	thermal_glide = 58,
	swamp_death = 59,
	eaten = 60,
	track2point = 61,
	swim2point = 62,
	followpath = 63,
	bombing = 64,
	wingshield = 65,
	roofhang = 66,
	squashed = 67,
	throwbomb = 68,
	shootgun = 69,
	digwall = 70,
	digfloor = 71,
	crouch = 72,
	drown = 73,
	shopping = 74,
	frozen = 75,
	forceturn = 76,
	lockpick = 77,
	hunter_firebow = 78,
	hunter_jumpattack = 79,
	hunter_dbljumpattack = 80,
	hunter_dashpunch = 81,
	hunter_defend = 82,
	hunter_slidekick = 83,
	hunter_roundhousekick = 84,
	hunter_backflipkick = 85,
	hunter_hide = 86,
	hunter_wallclimb = 87,
	hunter_wallclimbjump = 88,
	hunter_stompkick = 89,
	hunter_uppercut = 90,
	hunter_ledgecling = 91,
	hunter_tarBreathe = 92,
	hunter_tarLand = 93,
	hunter_tarWalk = 94,
	hunter_tarJump = 95,
	hunter_tarPunch = 96,
	hunter_tarShoot = 97,
	hunter_tarDefend = 98,
	hunter_tarFirstPerson = 99,
	hunter_tarHit = 100,
	hunter_climbhit = 101,
	sparx_flytunnel = 102,
	spark_heldinweb = 103,
	endjump = 104,
	icejump = 105
} PlayerModes;

typedef enum PStateFlags {
	ps_none = 0,
	ps_willdie = 1,
	ps_dead = 2,
	ps_willwin = 4,
	ps_forceOff = 8,
	ps_Blocking = 16,
	ps_MiniGame = 32,
	ps_Shopping = 64,
	ps_NoObjectCollision = 128,
	ps_NoMoreHits = 256,
	ps_Locked = 512,
	ps_InstantDeath = 1024
} PStateFlags;

typedef enum eMoveFlags {
	mf_none = 0,
	mf_ApplyGroundVector = 1,
	mf_ApplyGroundVectorFast = 2,
	mf_CalcGroundVector = 4,
	mf_ApplyMovement = 8,
	mf_IgnoreInput = 16,
	mf_DisableFirstPerson = 32,
	mf_DisableKeepRotation = 64,
	mf_DbouncePad = 128,
	mf_DefendCollision = 256,
	mf_DiableShield = 512,
	mf_CancelMovement = 1024,
	mf_AllowCancelMovement = 2048,
	mf_ToxicWater = 4096,
	mf_IceWater = 8192,
	mf_CancelCollisionBlend = 16384,
	mf_OnMainBodyCollision = 32768,
	mf_OnPlatformJump = 65536,
	mf_FrozenDamage = 131072,
	mf_SuperCharge = 262144
} eMoveFlags;

extern void* gpPlayer;
extern void* gpPlayerItem;

#define XSEITEMHANDLER_PLAYER__PLAYER_TYPE          OFFSET_VAL(Players, gpPlayer, 0x578)
#define XSEITEMHANDLER_PLAYER__MOVE_FLAGS           OFFSET_VAL(eMoveFlags, gpPlayer, 0x57c)
#define XSEITEMHANDLER_PLAYER__PLAYER_STATE_FLAGS   OFFSET_VAL(PStateFlags, gpPlayer, 0x580)
#define XSEITEMHANDLER_PLAYER__PLAYER_MODE          OFFSET_VAL(PlayerModes, gpPlayer, 0x834)

// Runs when the game wants to test if the player should enter "Scanmode" (free-fly around through walls).
// Normally always returns false. Return true to toggle it on/off (from a button press for example).
bool XSEItemHandler_Player__TestScanMode_HOOK(void* player, int current_mode);

void XSEItemhandler_Player__ChangePlayer(Players player, Bool incutscene);
EXHashCode* XSEItemhandler_Player__GetPlayersFileList(Players player);

#endif /* PLAYER_H */