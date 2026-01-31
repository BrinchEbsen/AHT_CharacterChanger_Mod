#ifndef GUI_BASE_H
#define GUI_BASE_H
#include <types.h>
#include <loop.h>
#include <dlinked.h>
#include <runtimeclass.h>
#include <expoint.h>
#include <exvector.h>
#include <color.h>

typedef struct SETUP_GUIItem__vtable SETUP_GUIItem__vtable;
struct SETUP_GUIItem__vtable {
    u8 padding[8];
    struct __vtbl_ptr_type SETUP_GUIItem;
    struct __vtbl_ptr_type v_OnCreate;
    struct __vtbl_ptr_type GetSELoop;
    struct __vtbl_ptr_type GetGUIItem;
};

typedef struct SETUP_GUIItem SETUP_GUIItem;
struct SETUP_GUIItem {
    s32 m_ID; /* Inherited from SETUP_SELoop */
    SE_Loop *m_pLoop; /* Inherited from SETUP_SELoop */
    SE_Loop **m_ppLoop; /* Inherited from SETUP_SELoop */
    EXRuntimeClass *m_pRuntimeClass; /* Inherited from SETUP_SELoop */
    SETUP_GUIItem__vtable *__vtable; /* Inherited from SETUP_SELoop */
    EXHashCode m_FileHashCode;
    EXHashCode m_ItemHashCode;
    float m_X;
    float m_Y;
    char *m_pString;
    wchar_t *m_pWideString;
    u32 m_SetupFlags;
    u32 m_GCFlags;
    /* XWnd** */ void** m_ppXWnd;
    EXPoint m_Inflate;
    float m_Scale;
};

typedef struct GUI_Coord GUI_Coord;
struct GUI_Coord {
    GUI_Coord* m_pParent;
    GUI_Coord* m_pMorph;
    /* XWnd* */ void* m_pDisplayWnd;
    EXVector3 XYZ;
    float Width;
    float Height;
    u32 Flags;
    SEFade m_Fade;
};

typedef struct GUI_Col GUI_Col;
struct GUI_Col {
    float m_FadeAmount;
    float m_FadeSpeed;
    u32 m_FadeClippedCount;
    GUI_Col* m_pParent;
    float m_Component[4];
};

typedef struct GUI_Base__vtable GUI_Base__vtable;
struct GUI_Base__vtable {
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
    struct __vtbl_ptr_type GUI_Base;
    struct __vtbl_ptr_type v_GetDefaultPixelWH;
    struct __vtbl_ptr_type v_PreDrawText;
    struct __vtbl_ptr_type v_WorldPos;
    struct __vtbl_ptr_type SetCamera;
};

extern GUI_Base__vtable GUI_Base_virtual_table;

typedef struct GUI_Base GUI_Base;
struct GUI_Base {
    SE_Loop *m_pParentLoop; /* Inherited from SE_Loop */
    SE_Loop *m_pthis_SE_Loop; /* Inherited from SE_Loop */
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
    GUI_Base__vtable *__vtable; /* Inherited from SE_Loop */
    GUI_Base *m_pthis;
    List m_GUIItemList;
    DLinkedTYPE m_GUIItemLink;
    SETUP_GUIItem *m_pSetupList;
    s32 m_SetupListNum;
    EXPoint m_SetupResize;
    EXVector2 m_SetupCentre;
    u32 m_Flags;
    RGBA m_ClsColour;
    /* XWnd* */ void* m_pAddDrawToXWnd;
    GUI_Coord m_GUI_Coord[2];
    /* XWnd* */ void* m_pXWnd;
    /* XWnd* */ void* m_pParentXWnd;
    struct GUI_Col m_Col;
    struct SEFade *m_pWatchFade;
    struct SEFade m_HiLightFade;
    float m_HiLightFadeSpeed;
};

_Static_assert(sizeof(GUI_Base) == 0x15c);

extern GUI_Base* GUI_Base__CreateObject(void);
extern s32 GUI_Base__Update(GUI_Base* self);
extern s32 GUI_Base__v_Draw(GUI_Base* self, void* pWnd);

#endif /* GUI_BASE_H */