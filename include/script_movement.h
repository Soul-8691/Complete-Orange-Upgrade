#ifndef GUARD_SCRIPT_MOVEMENT_H
#define GUARD_SCRIPT_MOVEMENT_H

#include "global.h"

bool8 __attribute__((long_call)) ScriptMovement_StartObjectMovementScript(u8, u8, u8, const u8 *);
bool8 __attribute__((long_call)) ScriptMovement_IsObjectMovementFinished(u8, u8, u8);
void __attribute__((long_call)) ScriptMovement_UnfreezeObjectEvents(void);

#endif // GUARD_SCRIPT_MOVEMENT_H
