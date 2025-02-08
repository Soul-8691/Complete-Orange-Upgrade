#ifndef GUARD_FIELDDOOR_H
#define GUARD_FIELDDOOR_H

#include "global.h"

void __attribute__((long_call)) FieldSetDoorOpened(int x, int y);
void __attribute__((long_call)) FieldSetDoorClosed(int x, int y);
s8 FieldAnimateDoorClose(int x, int y);
s8 FieldAnimateDoorOpen(int x, int y);
bool8 __attribute__((long_call)) FieldIsDoorAnimationRunning(void);
u16 __attribute__((long_call)) GetDoorSoundEffect(int x, int y);

#endif
