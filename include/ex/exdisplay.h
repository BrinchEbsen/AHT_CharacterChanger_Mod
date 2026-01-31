#ifndef EXDISPLAY_H
#define EXDISPLAY_H
#include <types.h>
#include <exdlist.h>
#include <exstring.h>
#include <exrect.h>

typedef struct EXPresentParams EXPresentParams;
struct EXPresentParams {
    u16 FBWidth;
    u16 FBHeight;
    u16 FBDepth;
    u16 BBWidth;
    u16 BBHeight;
    u16 BBDepth;
    u16 ZBDepth;
    u16 PresentMode;
    u32 Flags;
    Bool EnableVsync;
};

_Static_assert(sizeof(EXPresentParams) == 0x18);

typedef struct EXBaseDisplay__vtable EXBaseDisplay__vtable;
struct EXBaseDisplay__vtable {
    u8 padding[8];
    struct __vtbl_ptr_type EXBaseDisplay;
    struct __vtbl_ptr_type OpenDefault;
    struct __vtbl_ptr_type Open;
    struct __vtbl_ptr_type ReOpen;
    struct __vtbl_ptr_type Close;
    struct __vtbl_ptr_type SetColorAdjustment;
    struct __vtbl_ptr_type SetDefaultRenderState;
    struct __vtbl_ptr_type UpdateRenderState;
    struct __vtbl_ptr_type UpdateTransforms;
    struct __vtbl_ptr_type BeginDraw;
    struct __vtbl_ptr_type EndDraw;
    struct __vtbl_ptr_type Present;
    struct __vtbl_ptr_type CaptureToFile;
    struct __vtbl_ptr_type FlushAllWindowMem;
    struct __vtbl_ptr_type DeleteAllWindowMem;
    struct __vtbl_ptr_type WaitDrawSync;
    struct __vtbl_ptr_type RegisterWatcherVars;
    struct __vtbl_ptr_type GetAvailableResolutions;
};

typedef struct EXBaseDisplay EXBaseDisplay;
struct EXBaseDisplay {
    EXPresentParams m_Params;
    EXDList m_WndList;
    /* EXWnd* */ void* m_pFocusWnd;
    /* EXWnd* */ void* m_pMouseWnd;
    EXString m_CaptureDir;
    Bool m_DoCapture;
    Bool m_bCaptureContinuous;
    Bool m_FeedbackOn;
    u8 m_MouseTimer;
    Bool m_ResizeCursor;
    Bool m_DrawSafeFrame;
    u8 m_SafeFramePlatforms;
    EXRect m_SafeFrame;
    /* EXTextureArray* */ void* m_pRuntimeTex;
    u32 m_Effects;
    unsigned int m_iRunTimeTextureRefCount;
    u8 padding[4]; // ???
    EXBaseDisplay__vtable *__vtable;
};

_Static_assert(sizeof(EXBaseDisplay) == 0x58);

extern EXBaseDisplay* EXBaseDisplay__m_pDisplay;

#endif /* EXDISPLAY_H */