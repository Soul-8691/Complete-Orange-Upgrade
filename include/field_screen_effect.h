#ifndef GUARD_FIELD_SCREEN_EFFECT_H
#define GUARD_FIELD_SCREEN_EFFECT_H

#include "global.h"

void __attribute__((long_call)) AnimateFlash(u8);
void __attribute__((long_call)) FieldCB_SafariZoneRanOutOfBalls(void);
void __attribute__((long_call)) DoOutwardBarnDoorWipe(void);
void __attribute__((long_call)) Task_BarnDoorWipe(u8 taskId);
void __attribute__((long_call)) FieldCB_RushInjuredPokemonToCenter(void);
void __attribute__((long_call)) WriteFlashScanlineEffectBuffer(u8 flashLevel);

extern const s32 gMaxFlashLevel;

#endif // GUARD_FIELD_SCREEN_EFFECT_H
