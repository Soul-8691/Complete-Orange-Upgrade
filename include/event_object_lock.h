#ifndef GUARD_EVENT_OBJECT_LOCK_H
#define GUARD_EVENT_OBJECT_LOCK_H

#include "global.h"

bool8 __attribute__((long_call)) IsFreezePlayerFinished(void);
void __attribute__((long_call)) FreezeObjects_WaitForPlayer(void);
bool8 __attribute__((long_call)) IsFreezeSelectedObjectAndPlayerFinished(void);
void __attribute__((long_call)) FreezeObjects_WaitForPlayerAndSelected(void);
void __attribute__((long_call)) ClearPlayerHeldMovementAndUnfreezeObjectEvents(void);
bool8 __attribute__((long_call)) walkrun_is_standing_still(void);
void __attribute__((long_call)) UnionRoom_UnlockPlayerAndChatPartner(void);

#endif // GUARD_EVENT_OBJECT_LOCK_H
