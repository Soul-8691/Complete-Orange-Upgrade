#ifndef GUARD_BERRY_POUCH_H
#define GUARD_BERRY_POUCH_H

#include "task.h"

enum BerryPouchType
{
    BERRYPOUCH_FROMFIELD,
    BERRYPOUCH_FROMPARTYGIVE,
    BERRYPOUCH_FROMMARTSELL,
    BERRYPOUCH_FROMPOKEMONSTORAGEPC,
    BERRYPOUCH_FROMBATTLE,
    BERRYPOUCH_FROMBERRYCRUSH,
    BERRYPOUCH_NA
};

void __attribute__((long_call)) BerryPouch_StartFadeToExitCallback(u8 taskId);
void __attribute__((long_call)) BerryPouch_SetExitCallback(void (*exitCallback)(void));
void __attribute__((long_call)) InitBerryPouch(u8 type, void (*savedCallback)(void), u8 allowSelect);
void __attribute__((long_call)) DisplayItemMessageInBerryPouch(u8 taskId, u8 fontId, const u8 * str, TaskFunc followUpFunc);
void __attribute__((long_call)) Task_BerryPouch_DestroyDialogueWindowAndRefreshListMenu(u8 taskId);
void __attribute__((long_call)) BerryPouch_CursorResetToTop(void);

#endif //GUARD_BERRY_POUCH_H
