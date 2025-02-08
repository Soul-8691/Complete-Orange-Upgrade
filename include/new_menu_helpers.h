#ifndef GUARD_NEW_MENU_HELPERS_H
#define GUARD_NEW_MENU_HELPERS_H

#include "global.h"
#include "text.h"
#include "task.h"

extern const u16 gMenuMessageWindow_Gfx[];

void __attribute__((long_call)) ClearScheduledBgCopiesToVram(void);
void __attribute__((long_call)) ScheduleBgCopyTilemapToVram(u8 bgId);
void __attribute__((long_call)) DoScheduledBgTilemapCopiesToVram(void);
void __attribute__((long_call)) ResetTempTileDataBuffers(void);
bool8 __attribute__((long_call)) FreeTempTileDataBuffersIfPossible(void);
void __attribute__((long_call)) *DecompressAndCopyTileDataToVram(u8 bgId, const void *src, u32 size, u16 offset, u8 mode);
void __attribute__((long_call)) *DecompressAndCopyTileDataToVram2(u8 bgId, const void *src, u32 size, u16 offset, u8 mode);
void __attribute__((long_call)) DecompressAndLoadBgGfxUsingHeap(u8 bgId, const void *src, u32 size, u16 offset, u8 mode);
void __attribute__((long_call)) DecompressAndLoadBgGfxUsingHeap2(u8 bgId, const void *src, u32 size, u16 offset, u8 mode);
void __attribute__((long_call)) *MallocAndDecompress(const void *src, u32 * size);
void __attribute__((long_call)) SetBgTilemapPalette(u8 bgId, u8 left, u8 top, u8 width, u8 height, u8 palette);
void __attribute__((long_call)) CopyToBufferFromBgTilemap(u8 bgId, u16 *dest, u8 left, u8 top, u8 width, u8 height);
void __attribute__((long_call)) ResetBgPositions(void);
void __attribute__((long_call)) InitStandardTextBoxWindows(void);
void __attribute__((long_call)) FreeAllOverworldWindowBuffers(void);
void __attribute__((long_call)) InitTextBoxGfxAndPrinters(void);
u16 __attribute__((long_call)) RunTextPrinters_CheckPrinter0Active(void);
u16 __attribute__((long_call)) AddTextPrinterParameterized2(u8 windowId, u8 fontId, const u8 *str, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16), u8 fgColor, u8 bgColor, u8 shadowColor);
void __attribute__((long_call)) AddTextPrinterDiffStyle(bool8 allowSkippingDelayWithButtonPress);
void __attribute__((long_call)) AddTextPrinterForMessage(bool8 allowSkippingDelayWithButtonPress);
void __attribute__((long_call)) AddTextPrinterWithCustomSpeedForMessage(bool8 allowSkippingDelayWithButtonPress, u8 speed);
void __attribute__((long_call)) LoadStdWindowFrameGfx(void);
void __attribute__((long_call)) DrawDialogueFrame(u8 windowId, bool8 transfer);
void __attribute__((long_call)) DrawStdWindowFrame(u8 windowId, bool8 copyNow);
void __attribute__((long_call)) ClearDialogWindowAndFrame(u8 windowId, bool8 copyToVram);
void __attribute__((long_call)) ClearStdWindowAndFrame(u8 windowId, bool8 copyNow);
void __attribute__((long_call)) EraseFieldMessageBox(bool8 copyToVram);
void __attribute__((long_call)) SetStdWindowBorderStyle(u8 windowId, bool8 copyToVram);
void __attribute__((long_call)) LoadMessageBoxAndFrameGfx(u8 windowId, bool8 copyToVram);
void __attribute__((long_call)) Menu_LoadStdPal(void);
void __attribute__((long_call)) Menu_LoadStdPalAt(u16 offset);
void __attribute__((long_call)) DisplayItemMessageOnField(u8 taskId, u8 fontId, const u8 *src, TaskFunc callback);
void __attribute__((long_call)) DisplayYesNoMenuDefaultYes(void);
void __attribute__((long_call)) DisplayYesNoMenuDefaultNo(void);
u8 __attribute__((long_call)) GetTextSpeedSetting(void);
u8 __attribute__((long_call)) CreateStartMenuWindow(u8 height);
u8 __attribute__((long_call)) GetStartMenuWindowId(void);
void __attribute__((long_call)) RemoveStartMenuWindow(void);
u16 __attribute__((long_call)) GetStdWindowBaseTileNum(void);
void __attribute__((long_call)) DrawHelpMessageWindowWithText(const u8 * text);
void __attribute__((long_call)) DestroyHelpMessageWindow_(void);
void __attribute__((long_call)) LoadSignpostWindowFrameGfx(void);
void __attribute__((long_call)) SetDefaultFontsPointer(void);

#endif // GUARD_NEW_MENU_HELPERS_H
