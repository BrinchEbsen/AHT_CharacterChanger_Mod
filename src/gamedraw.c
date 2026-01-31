#include <gamedraw.h>
#include <types.h>
#include <player.h>
#include <wnd.h>
#include <util.h>
#include <hashcodes.h>
#include <os.h>
#include <exmatrix.h>
#include <igmath.h>
#include <trigger_specialbase.h>
#include <map.h>

typedef void (*XSEItemHandler_Player__GameWndDraw)(void*);

void player_game_wnd_draw(void)
{
    if (gpPlayer == NULL) return;

    void* vtable = OFFSET_VAL(void*, gpPlayer, 0x4);
    XSEItemHandler_Player__GameWndDraw func
        = OFFSET_VAL(XSEItemHandler_Player__GameWndDraw, vtable, 0x20c);

    func(gpPlayer);
}

DrawLoop gamedraw_callback = NULL;

// Hooks into the player game window drawing routine
void gamedraw_loop(void)
{
    player_game_wnd_draw();

    if ((gpGameWnd != NULL) && (gamedraw_callback != NULL)) {
        gamedraw_callback(gpGameWnd);
    }

    return;

    if ((gpGameWnd != NULL) && (gpPlayerItem != NULL)) {
        EXVector* playerPos = OFFSET_PTR(EXVector, gpPlayerItem, 0xD0);

        for (int i = 0; i < SE_MapList__m_gNumMaps; i++) {
            SE_Map* map = gMapList.m_List[i].m_pMap;
            
            if (map->m_State == Running) {
                SE_TriggerList* list = &map->m_TriggerList;

                if (list->m_pTriggers != NULL) {
                    SE_TriggerHeader* triggerheader = list->m_pTriggers;

                    for (int j = 0; j < list->m_NumTriggers; j++) {
                        SE_Trigger* trigger = triggerheader[j].m_pSE_Trigger;
                        if (trigger == NULL) continue;

                        if (EXVector_Dist((EXVector*)&trigger->m_Position, playerPos) > 100.0f) {
                            continue;
                        }

                        RGBA col;
                        switch (trigger->m_TypeSubHashCode) {
                            case HT_TriggerSubType_LoadMap:
                                col.rgba = COLOR_BLUE.rgba;
                                break;
                            case HT_TriggerSubType_CloseMap:
                                col.rgba = COLOR_RED.rgba;
                                break;
                            default:
                                continue;
                        }

                        Trigger_SpecialBase* triggerSpecial = (Trigger_SpecialBase*)trigger;

                        EXVector triggerPos = {
                            .x = triggerSpecial->m_Position.x,
                            .y = triggerSpecial->m_Position.y,
                            .z = triggerSpecial->m_Position.z,
                            .w = 0.0f
                        };

                        mat_44* normal = &triggerSpecial->m_PlaneNormalMatrix;
                        
                        draw_3d_ellipse(
                            gpGameWnd,
                            normal,
                            &triggerPos,
                            triggerSpecial->m_Width,
                            triggerSpecial->m_Height,
                            col,
                            32);
                    }
                }
            }
        }
    }
}
