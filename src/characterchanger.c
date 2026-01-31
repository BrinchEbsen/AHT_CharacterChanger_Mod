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

bool do_characterchanger_menu = false;

typedef enum CharacterChangeMenuOption {
    Option_Spyro,
    Option_Hunter,
    Option_Sparx,
    Option_Blinky,
    Option_SrgBird,
    Option_BallGadget,
    Option_Ember,
    Option_Flame,
    Option_COUNT
} CharacterChangeMenuOption;

int curr_option = 0;

RGBA selected_col = COLOR_GREEN;
RGBA unselected_col = COLOR_RGBA(0x40, 0x40, 0x40, 0x80);

Players player_to_load = Player_Undefined;
Players previous_player = Player_Undefined;

inline Players option_to_player(CharacterChangeMenuOption option) {
    return (Players)(option + 1);
}

inline bool player_can_move() {
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

void inc_option() {
    curr_option++;
    if (curr_option >= Option_COUNT) {
        curr_option = 0;
    }
}

void dec_option() {
    curr_option--;
    if (curr_option < 0) {
        curr_option = Option_COUNT-1;
    }
}

void characterchanger_update(void)
{
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
        SE_GameLoop__GameSetPauseOn(&gGameLoop, 0);
        PlaySFX(HT_Sound_SFX_GEN_HUD_PAUSE);
    }

    if (!do_characterchanger_menu) {
        return;
    }

    // At this point, do menu logic

    if (player_to_load != Player_Undefined) {
        // Note: IsLoaded disregards the player parameter and simply checks
        // if the last player that was requested preloaded is loaded yet.
        // Thanks Eurocom
        if (PlayerLoader__IsLoaded(&gPlayerLoader, player_to_load)) {
            XSEItemhandler_Player__ChangePlayer(player_to_load, false);

            player_to_load = Player_Undefined;
            do_characterchanger_menu = false;
            SE_GameLoop__GameSetPauseOff(&gGameLoop, 0);
        }

        return;
    }
    
    if (g_pad_button_edge_down(PAD_BUTTON_DPAD_DOWN) || g_pad_button_edge_down(PAD_BUTTON_LANALOG_DOWN)) {
        inc_option();
        PlaySFX(HT_Sound_SFX_GEN_HUD_CURSOR);
    } else if (g_pad_button_edge_down(PAD_BUTTON_DPAD_UP) || g_pad_button_edge_down(PAD_BUTTON_LANALOG_UP)) {
        dec_option();
        PlaySFX(HT_Sound_SFX_GEN_HUD_CURSOR);
    }
    
    if (g_pad_button_edge_down(PAD_BUTTON_A)) {
        Players player = XSEITEMHANDLER_PLAYER__PLAYER_TYPE;
        Players selected_player = option_to_player(curr_option);

        if (player == selected_player) {
            return;
        }

        player_to_load = selected_player;
        previous_player = player;
        PlayerLoader__PreLoad(&gPlayerLoader, player_to_load);

        PlaySFX(HT_Sound_SFX_GEN_HUD_SELECT);
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
    static int menu_offs_y = 100;

    EXRect menu_rect = {
        .x = menu_offs_x,
        .y = menu_offs_y,
        .w = 200,
        .h = text_buffer*2 + text_spacing*Option_COUNT
    };

    XWnd__DrawRect(pWnd, &menu_rect, COLOR_RGBA(0, 0, 0, 0x40));
    XWnd__DrawGraduatedRectOutline(pWnd, &menu_rect, COLOR_GREEN, COLOR_BLACK, 5, RECT_SIDE_ALL);

    int text_pos_x = menu_offs_x + text_buffer + 30;
    int text_pos_y = menu_offs_y + text_buffer;

    for (int i = 0; i < Option_COUNT; i++) {
        Players selected_player = option_to_player(i);

        RGBA* col = (curr_option == i) ? &selected_col : &unselected_col;

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

        switch ((CharacterChangeMenuOption)i) {
            case Option_Spyro: {
                TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y, *col, "Spyro");
            } break;
            case Option_Hunter: {
                TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y, *col, "Hunter");
            } break;
            case Option_Sparx: {
                TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y, *col, "Sparx");
            } break;
            case Option_Blinky: {
                TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y, *col, "Blink");
            } break;
            case Option_SrgBird: {
                TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y, *col, "Sgt. Byrd");
            } break;
            case Option_BallGadget: {
                TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y, *col, "Ball Gadget");
            } break;
            case Option_Ember: {
                TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y, *col, "Ember");
            } break;
            case Option_Flame: {
                TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y, *col, "Flame");
            } break;
        }

        text_pos_y += text_spacing;
    }

    if (player_to_load != Player_Undefined) {
        TEXT_PRINT_COLOR(pWnd, text_pos_x, text_pos_y+10, COLOR_WHITE, "Loading...");
    }
}
