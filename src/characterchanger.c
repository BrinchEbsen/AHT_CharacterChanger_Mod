#include <characterchanger.h>
#include <types.h>
#include <pad.h>
#include <gameloop.h>
#include <color.h>
#include <exrect.h>
#include <wnd.h>
#include <paneldraw.h>
#include <playerloader.h>
#include <player.h>
#include <filemanager.h>
#include <os.h>
#include <Sound.h>
#include <sfx.h>
#include <playerstate.h>
#include <gamestate.h>
#include <player.h>

bool do_characterchanger_menu = false;

int curr_page = MenuPage_Characters;

int curr_ccm_option = 0;

int curr_cheats_option = 0;

RGBA selected_col = COLOR_GREEN;
RGBA unselected_col = COLOR_RGBA(0x40, 0x40, 0x40, 0x80);

Players player_to_load = Player_Undefined;
Players previous_player = Player_Undefined;

bool cheat_infinite_lockpicks = false;
bool cheat_infinite_health = false;
bool cheat_infinite_breathammo = false;
bool cheat_infinite_supercharge = false;
bool cheat_infinite_invincibility = false;
bool cheat_infinite_firearrows = false;
bool cheat_infinite_blinkbombs = false;

inline Players option_to_player(CharacterChangeMenuOption option) {
    return (Players)(option + 1);
}

bool player_can_move() {
    if (gpPlayer == NULL) return false;

    PlayerModes mode = XSEITEMHANDLER_PLAYER__PLAYER_MODE;
    if ((mode == listen) || (mode == listen_water)) {
        return false;
    }

    PStateFlags stateflags = XSEITEMHANDLER_PLAYER__PLAYER_STATE_FLAGS;
    eMoveFlags moveflags = XSEITEMHANDLER_PLAYER__MOVE_FLAGS;

    if (((stateflags & ps_Locked) != 0) || ((moveflags & mf_IgnoreInput) != 0)) {
        return false;
    }

    return true;
}

inline void inc_page() {
    curr_page++;
    if (curr_page >= MenuPage_COUNT) {
        curr_page = 0;
    }
}

inline void dec_page() {
    curr_page--;
    if (curr_page < 0) {
        curr_page = MenuPage_COUNT-1;
    }
}

inline void inc_option() {
    switch (curr_page) {
        case MenuPage_Characters: {
            curr_ccm_option++;
            if (curr_ccm_option >= CCMOption_COUNT) {
                curr_ccm_option = 0;
            }
        } break;
        case MenuPage_Cheats: {
            curr_cheats_option++;
            if (curr_cheats_option >= CheatsOption_COUNT) {
                curr_cheats_option = 0;
            }
        } break;
    }
}

inline void dec_option() {
    switch (curr_page) {
        case MenuPage_Characters: {
            curr_ccm_option--;
            if (curr_ccm_option < 0) {
                curr_ccm_option = CCMOption_COUNT-1;
            }
        } break;
        case MenuPage_Cheats: {
            curr_cheats_option--;
            if (curr_cheats_option < 0) {
                curr_cheats_option = CheatsOption_COUNT-1;
            }
        } break;
    }
}

void characterchanger_update(void)
{
    handle_cheats();

    bool z_double_press = g_pad_button_edge_down_multiple(PAD_BUTTON_Z, 2, 20);

    // Only if game loop is running
    if (gGameLoop.m_State != Running) {
        do_characterchanger_menu = false;
        return;
    }

    // Only if the player exists and can move around (not in a cutscene)
    if (!player_can_move()) {
        do_characterchanger_menu = false;
        return;
    }

    // If the menu is rendering when the game is unpaused, something's wrong
    if (do_characterchanger_menu && !gGameLoop.m_GameIsPaused) {
        do_characterchanger_menu = false;
        return;
    
    // If the game is already paused, some other menu is probably rendering
    } else if (!do_characterchanger_menu && gGameLoop.m_GameIsPaused) {
        return;
    }

    // Toggle menu with z double-press (exit can be done with B)
    if ((z_double_press || g_pad_button_edge_down(PAD_BUTTON_B)) && do_characterchanger_menu) {
        do_characterchanger_menu = false;
        SE_GameLoop__GameSetPauseOff(&gGameLoop, 0);
        PlaySFX(HT_Sound_SFX_GEN_HUD_SELECT);
    } else if (z_double_press && !do_characterchanger_menu) {
        do_characterchanger_menu = true;
        curr_page = MenuPage_Characters;
        SE_GameLoop__GameSetPauseOn(&gGameLoop, 0);
        PlaySFX(HT_Sound_SFX_GEN_HUD_PAUSE);
    }

    if (!do_characterchanger_menu) {
        return;
    }

    // At this point, do menu logic

    // Toggle scanmode
    if (g_pad_button_edge_down(PAD_BUTTON_X)) {
        g_enable_scanmode = !g_enable_scanmode;
        PlaySFX(HT_Sound_SFX_GEN_HUD_NPC_CHOOSE);
    }

    if (player_to_load != Player_Undefined) {
        // Note: IsLoaded disregards the player parameter and simply checks
        // if the last player that was requested preloaded is loaded yet.
        // Thanks Eurocom
        if (PlayerLoader__IsLoaded(&gPlayerLoader, player_to_load)) {
            s32 lvl_index = gGameState.m_PlayerState.m_Setup.m_MapListIndex;
            MiniGameID mini_id = gGameState.m_PlayerState.m_Setup.m_MiniGameID;
            XSEItemhandler_Player__ChangePlayer(player_to_load, false);
            gGameState.m_PlayerState.m_Setup.m_MapListIndex = lvl_index;
            gGameState.m_PlayerState.m_Setup.m_MiniGameID = mini_id;

            player_to_load = Player_Undefined;
            do_characterchanger_menu = false;
            SE_GameLoop__GameSetPauseOff(&gGameLoop, 0);
        }

        return;
    }

    if (g_pad_button_edge_down(PAD_BUTTON_DPAD_RIGHT) || g_pad_button_edge_down(PAD_BUTTON_LANALOG_RIGHT)) {
        inc_page();
        PlaySFX(HT_Sound_SFX_GEN_HUD_CURSOR);
    } else if (g_pad_button_edge_down(PAD_BUTTON_DPAD_LEFT) || g_pad_button_edge_down(PAD_BUTTON_LANALOG_LEFT)) {
        dec_page();
        PlaySFX(HT_Sound_SFX_GEN_HUD_CURSOR);
    }

    if (g_pad_button_edge_down(PAD_BUTTON_DPAD_DOWN) || g_pad_button_edge_down(PAD_BUTTON_LANALOG_DOWN)) {
        inc_option();
        PlaySFX(HT_Sound_SFX_GEN_HUD_CURSOR);
    } else if (g_pad_button_edge_down(PAD_BUTTON_DPAD_UP) || g_pad_button_edge_down(PAD_BUTTON_LANALOG_UP)) {
        dec_option();
        PlaySFX(HT_Sound_SFX_GEN_HUD_CURSOR);
    }
    
    switch (curr_page) {
        case MenuPage_Characters: do_character_menu(); break;
        case MenuPage_Cheats: do_cheats_menu(); break;
    }
}

void do_character_menu(void)
{
    if (g_pad_button_edge_down(PAD_BUTTON_A)) {
        Players player = XSEITEMHANDLER_PLAYER__PLAYER_TYPE;
        Players selected_player = option_to_player(curr_ccm_option);

        if (player == selected_player) {
            return;
        }

        player_to_load = selected_player;
        previous_player = player;
        PlayerLoader__PreLoad(&gPlayerLoader, player_to_load);

        PlaySFX(HT_Sound_SFX_GEN_HUD_SELECT);
    }
}

void do_cheats_menu(void)
{
    switch ((CheatsMenuOption)curr_cheats_option) {
        case CheatsOption_AllAbilities: {
            if (g_pad_button_edge_down(PAD_BUTTON_A)) {
                gGameState.m_PlayerState.m_AbilityFlags |= ABILITY_ALL_PERMANENT_ABILITIES;
            }
        } break;
        case CheatsOption_InfiniteLockPicks: {
            if (g_pad_button_edge_down(PAD_BUTTON_A)) {
                cheat_infinite_lockpicks = !cheat_infinite_lockpicks;
            }
        } break;
        case CheatsOption_InfiniteHealth: {
            if (g_pad_button_edge_down(PAD_BUTTON_A)) {
                cheat_infinite_health = !cheat_infinite_health;
            }
        } break;
        case CheatsOption_InfiniteBreathAmmo: {
            if (g_pad_button_edge_down(PAD_BUTTON_A)) {
                cheat_infinite_breathammo = !cheat_infinite_breathammo;
            }
        } break;
        case CheatsOption_InfiniteSupercharge: {
            if (g_pad_button_edge_down(PAD_BUTTON_A)) {
                cheat_infinite_supercharge = !cheat_infinite_supercharge;
            }
        } break;
        case CheatsOption_InfiniteInvincibility: {
            if (g_pad_button_edge_down(PAD_BUTTON_A)) {
                cheat_infinite_invincibility = !cheat_infinite_invincibility;
            }
        } break;
        case CheatsOption_InfiniteFireArrows: {
            if (g_pad_button_edge_down(PAD_BUTTON_A)) {
                cheat_infinite_firearrows = !cheat_infinite_firearrows;
            }
        } break;
        case CheatsOption_InfiniteBlinkBombs: {
            if (g_pad_button_edge_down(PAD_BUTTON_A)) {
                cheat_infinite_blinkbombs = !cheat_infinite_blinkbombs;
            }
        } break;
    }
}

void handle_cheats(void)
{
    if (cheat_infinite_lockpicks) {
        gGameState.m_PlayerState.m_LockPickers = gGameState.m_PlayerState.m_LockPickers_Max;
    }
    if (cheat_infinite_health) {
        gGameState.m_PlayerState.m_Health = PLAYERSTATE_HEALTH_GOLD;
    }
    if (cheat_infinite_breathammo) {
        gGameState.m_PlayerState.m_FlameBombs       = gGameState.m_PlayerState.m_FlameBombs_Max;
        gGameState.m_PlayerState.m_ElectricBombs    = gGameState.m_PlayerState.m_ElectricBombs_Max;
        gGameState.m_PlayerState.m_WaterBombs       = gGameState.m_PlayerState.m_WaterBombs_Max;
        gGameState.m_PlayerState.m_IceBombs         = gGameState.m_PlayerState.m_IceBombs_Max;
    }
    if (cheat_infinite_supercharge) {
        gGameState.m_PlayerState.m_SuperchargeTimerMax = 100.0f;
        gGameState.m_PlayerState.m_SuperchargeTimer = gGameState.m_PlayerState.m_SuperchargeTimerMax;
        gGameState.m_PlayerState.m_AbilityFlags |= ABILITY_SUPERCHARGE;
    }
    if (cheat_infinite_invincibility) {
        gGameState.m_PlayerState.m_InvincibleTimerMax = 100.0f;
        gGameState.m_PlayerState.m_InvincibleTimer = gGameState.m_PlayerState.m_InvincibleTimerMax;
        gGameState.m_PlayerState.m_AbilityFlags |= ABILITY_INVINCIBILITY;
    }
    if (cheat_infinite_firearrows) {
        gGameState.m_PlayerState.m_Xarrows = gGameState.m_PlayerState.m_Xarrows_Max;
    }
    if (cheat_infinite_blinkbombs) {
        gGameState.m_PlayerState.m_BlinkBombs = PLAYERSTATE_BLINK_BOMBS_MAX;
    }
}

void characterchanger_drawhud(void *pWnd)
{
    if (!do_characterchanger_menu) {
        return;
    }

    if (gpPlayer == NULL) {
        return;
    }

    Players player = XSEITEMHANDLER_PLAYER__PLAYER_TYPE;

    static int text_spacing = 22;
    static int text_buffer = 5;
    static int menu_offs_x = 10;
    static int menu_offs_y = 160;

    int option_count;
    int current_selected_option;
    EXRect menu_rect;
    switch(curr_page) {
        case MenuPage_Characters: {
            option_count = CCMOption_COUNT;
            current_selected_option = curr_ccm_option;
            menu_rect = (EXRect){
                .x = menu_offs_x,
                .y = menu_offs_y,
                .w = 150,
                .h = text_buffer*2 + text_spacing*option_count
            };

            int text_pos_x = menu_offs_x + text_buffer + 30;
            int text_pos_y = menu_offs_y + text_buffer;

            TEXT_PRINT_COLOR(pWnd, menu_offs_x, menu_offs_y - 25, COLOR_WHITE, "< Characters >");
        } break;
        case MenuPage_Cheats: {
            option_count = CheatsOption_COUNT;
            current_selected_option = curr_cheats_option;
            menu_rect = (EXRect){
                .x = menu_offs_x,
                .y = menu_offs_y,
                .w = 250,
                .h = text_buffer*2 + text_spacing*option_count
            };

            int text_pos_x = menu_offs_x + text_buffer + 5;
            int text_pos_y = menu_offs_y + text_buffer;

            TEXT_PRINT_COLOR(pWnd, menu_offs_x, menu_offs_y - 25, COLOR_WHITE, "< Cheats >");
        } break;
    }

    XWnd__DrawRect(pWnd, &menu_rect, COLOR_RGBA(0, 0, 0, 0x40));
    XWnd__DrawGraduatedRectOutline(pWnd, &menu_rect, COLOR_GREEN, COLOR_BLACK, 5, RECT_SIDE_ALL);

    int text_pos_x = menu_offs_x + text_buffer + 5;
    if (curr_page == MenuPage_Characters) text_pos_x += 25;

    int text_pos_y = menu_offs_y + text_buffer;

    for (int i = 0; i < option_count; i++) {
        Players selected_player = option_to_player(i);
        
        RGBA* col = (current_selected_option == i) ? &selected_col : &unselected_col;

        if (curr_page == MenuPage_Characters) {
            EXRect square = {
                .x = menu_offs_x + 10,
                .y = text_pos_y + 2,
                .w = 15,
                .h = 15
            };
            
            // If this option is the current player already
            if (selected_player == player) {
                XWnd__DrawRect(pWnd, &square, COLOR_RED);
            // If this option is a player that is loading
            } else if (player_to_load == selected_player) {
                RGBA load_icon_col = COLOR_RED;
                int counter = gGameLoop.m_UpdateCounter % 20;
                counter = (counter < 10) ? counter : (20 - counter);
                load_icon_col.a = (u8)(0x80 * ((float)counter / (float)10));
                XWnd__DrawRect(pWnd, &square, load_icon_col);
            }
        }

        draw_menu_option(pWnd, curr_page, i, text_pos_x, text_pos_y, col);

        text_pos_y += text_spacing;
    }

    if (player_to_load != Player_Undefined) {
        TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y+10, COLOR_WHITE, "Loading...");
    }

    if (g_enable_scanmode) {
        TEXT_PRINT_ALIGN_COLOR(pWnd, 0, 0, BottomRight, COLOR_WHITE,
            "~B: Scanmode enable: Yes\nToggle: Hold any d-pad dir, press ~S\n ");
    } else {
        TEXT_PRINT_ALIGN_COLOR(pWnd, 0, 0, BottomRight, COLOR_WHITE,
            "~B: Scanmode enable: No\n \n ");
    }
}

void draw_menu_option(void* pWnd, MenuPage page, int index, int x, int y, RGBA *col)
{
    switch (page) {
        case MenuPage_Characters: {

            switch ((CharacterChangeMenuOption)index) {
                case CCMOption_Spyro: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Spyro");
                } break;
                case CCMOption_Hunter: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Hunter");
                } break;
                case CCMOption_Sparx: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Sparx");
                } break;
                case CCMOption_Blinky: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Blink");
                } break;
                case CCMOption_SrgBird: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Sgt. Byrd");
                } break;
                case CCMOption_BallGadget: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Ball Gadget");
                } break;
                case CCMOption_Ember: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Ember");
                } break;
                case CCMOption_Flame: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Flame");
                } break;
            }

        } break;
        case MenuPage_Cheats: {

            switch ((CheatsMenuOption)index) {
                case CheatsOption_AllAbilities: {
                    TEXT_PRINT_COLOR(pWnd, x, y, *col, "Get All Abilities");
                } break;
                case CheatsOption_InfiniteHealth: {
                    TEXT_PRINT_COLOR_F(pWnd, x, y, *col, "Infinite Health: %s",
                        cheat_infinite_health ? "On" : "Off");
                } break;
                case CheatsOption_InfiniteLockPicks: {
                    TEXT_PRINT_COLOR_F(pWnd, x, y, *col, "Infinite Lockpicks: %s",
                        cheat_infinite_lockpicks ? "On" : "Off");
                } break;
                case CheatsOption_InfiniteBreathAmmo: {
                    TEXT_PRINT_COLOR_F(pWnd, x, y, *col, "Infinite Breath Ammo: %s",
                        cheat_infinite_breathammo ? "On" : "Off");
                } break;
                case CheatsOption_InfiniteSupercharge: {
                    TEXT_PRINT_COLOR_F(pWnd, x, y, *col, "Infinite Supercharge: %s",
                        cheat_infinite_supercharge ? "On" : "Off");
                } break;
                case CheatsOption_InfiniteInvincibility: {
                    TEXT_PRINT_COLOR_F(pWnd, x, y, *col, "Infinite Invincibility: %s",
                        cheat_infinite_invincibility ? "On" : "Off");
                } break;
                case CheatsOption_InfiniteFireArrows: {
                    TEXT_PRINT_COLOR_F(pWnd, x, y, *col, "Infinite Fire Arrows: %s",
                        cheat_infinite_firearrows ? "On" : "Off");
                } break;
                case CheatsOption_InfiniteBlinkBombs: {
                    TEXT_PRINT_COLOR_F(pWnd, x, y, *col, "Infinite Blink Bombs: %s",
                        cheat_infinite_blinkbombs ? "On" : "Off");
                } break;
            }

        } break;
    }
}
