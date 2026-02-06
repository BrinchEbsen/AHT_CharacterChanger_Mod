#ifndef CHARACTER_CHANGER_H
#define CHARACTER_CHANGER_H
#include <color.h>

typedef enum MenuPage {
    MenuPage_Characters,
    MenuPage_Cheats,
    MenuPage_COUNT
} MenuPage;

typedef enum CharacterChangeMenuOption {
    CCMOption_Spyro,
    CCMOption_Hunter,
    CCMOption_Sparx,
    CCMOption_Blinky,
    CCMOption_SrgBird,
    CCMOption_BallGadget,
    CCMOption_Ember,
    CCMOption_Flame,
    CCMOption_COUNT
} CharacterChangeMenuOption;

typedef enum CheatsMenuOption {
    CheatsOption_AllAbilities,
    CheatsOption_InfiniteHealth,
    CheatsOption_InfiniteLockPicks,
    CheatsOption_InfiniteBreathAmmo,
    CheatsOption_InfiniteSupercharge,
    CheatsOption_InfiniteInvincibility,
    CheatsOption_InfiniteFireArrows,
    CheatsOption_InfiniteBlinkBombs,
    CheatsOption_COUNT
} CheatsMenuOption;

void characterchanger_update(void);

void do_character_menu(void);
void do_cheats_menu(void);

void handle_cheats(void);

void characterchanger_drawhud(void* pWnd);
void draw_menu_option(void* pWnd, MenuPage page, int index, int x, int y, RGBA* col);

#endif /* CHARACTER_CHANGER_H */