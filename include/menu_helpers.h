#ifndef GUARD_MENU_HELPERS_H
#define GUARD_MENU_HELPERS_H

#include "global.h"
#include "task.h"
#include "window.h"

#define MENU_L_PRESSED 1
#define MENU_R_PRESSED 2

struct YesNoFuncTable
{
    TaskFunc yesFunc;
    TaskFunc noFunc;
};

bool16 __attribute__((long_call)) RunTextPrinters_CheckActive(u8 textPrinterId);
bool8 __attribute__((long_call)) __attribute__((long_call)) IsActiveOverworldLinkBusy(void);
bool8 __attribute__((long_call)) MenuHelpers_ShouldWaitForLinkRecv(void);
bool8 __attribute__((long_call)) __attribute__((long_call)) MenuHelpers_IsLinkActive(void);
void __attribute__((long_call)) SetVBlankHBlankCallbacksToNull(void);
void __attribute__((long_call)) ResetAllBgsCoordinatesAndBgCntRegs(void);
u8 __attribute__((long_call)) GetDialogBoxFontId(void);
bool8 __attribute__((long_call)) AdjustQuantityAccordingToDPadInput(s16 *quantity_p, u16 qmax);
void __attribute__((long_call)) DisplayMessageAndContinueTask(u8 taskId, u8 windowId, u16 tileNum, u8 paletteNum, u8 fontId, u8 textSpeed, const u8 *string, void *taskFunc);
void __attribute__((long_call)) CreateYesNoMenuWithCallbacks(u8 taskId, const struct WindowTemplate *template, u8 fontId, u8 left, u8 top, u16 tileStart, u8 palette, const struct YesNoFuncTable *yesNo);
u8 __attribute__((long_call)) GetLRKeysPressed(void);
u8 __attribute__((long_call)) GetLRKeysPressedAndHeld(void);
bool8 __attribute__((long_call)) IsHoldingItemAllowed(u16 itemId);
bool8 __attribute__((long_call)) IsWritingMailAllowed(u16 itemId);
void __attribute__((long_call)) ResetVramOamAndBgCntRegs(void);

#endif //GUARD_MENU_HELPERS_H
