#ifndef GUARD_TEXT_WINDOW_H
#define GUARD_TEXT_WINDOW_H

#include "global.h"

struct TilesPal
{
    u32 *tiles;
    u16 *pal;
};

void __attribute__((long_call)) rbox_fill_rectangle(u8 windowId);
const u16 *GetTextWindowPalette(u8 id);
const u16 *GetOverworldTextboxPalettePtr(void);
void __attribute__((long_call)) LoadMenuMessageWindowGfx(u8 windowId, u16 tileStart, u8 palette);
void __attribute__((long_call)) LoadStdWindowGfx(u8 windowId, u16 tileStart, u8 palette);
void __attribute__((long_call)) LoadUserWindowGfx(u8 windowId, u16 tileStart, u8 palette);
void __attribute__((long_call)) LoadUserWindowGfx2(u8 windowId, u16 tileStart, u8 palette);
void __attribute__((long_call)) LoadStdWindowGfxOnBg(u8 bgId, u16 tileStart, u8 palette);
void __attribute__((long_call)) DrawTextBorderOuter(u8 windowId, u16 tileStart, u8 palette);
void __attribute__((long_call)) DrawTextBorderInner(u8 windowId, u16 tileNum, u8 palNum);
void __attribute__((long_call)) LoadHelpMessageWindowGfx(u8 windowId, u16 destOffset, u8 palIdx);
void __attribute__((long_call)) LoadSignpostWindowGfx(u8 windowId, u16 destOffset, u8 palIdx);
void __attribute__((long_call)) LoadStdWindowTiles(u8 windowId, u16 destOffset);
void __attribute__((long_call)) LoadQuestLogWindowTiles(u8 windowId, u16 destOffset);

#endif // GUARD_TEXT_WINDOW_H
