#ifndef GUARD_POKEMON_SPECIAL_ANIM_H
#define GUARD_POKEMON_SPECIAL_ANIM_H

#include "global.h"

void __attribute__((long_call)) CreateLevelUpVerticalSpritesTask(u16 x, u16 y, u16 tileTag, u16 paletteTag, u16 priority, u16 subpriority);
bool8 __attribute__((long_call)) LevelUpVerticalSpritesTaskIsRunning(void);
void __attribute__((long_call)) GetMonLevelUpWindowStats(struct Pokemon *mon, u16 *currStats);
void __attribute__((long_call)) DrawLevelUpWindowPg1(u16 windowId, u16 *statsBefore, u16 *statsAfter, u8 bgClr, u8 fgClr, u8 shadowClr);
void __attribute__((long_call)) DrawLevelUpWindowPg2(u16 windowId, u16 *currStats, u8 bgClr, u8 fgClr, u8 shadowClr);
void __attribute__((long_call)) StartUseItemAnim_Normal(u8 slotId, u16 itemId, MainCallback callback);
void __attribute__((long_call)) StartUseItemAnim_CantEvolve(u8 slotId, u16 itemId, MainCallback callback);
bool32 __attribute__((long_call)) PSA_IsCancelDisabled(void);
void __attribute__((long_call)) StartUseItemAnim_ForgetMoveAndLearnTMorHM(u8 slotId, u16 itemId, u16 moveId, MainCallback callback);

#endif // GUARD_POKEMON_SPECIAL_ANIM_H
