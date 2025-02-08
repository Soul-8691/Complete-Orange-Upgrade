#ifndef GUARD_SPECIAL_FIELD_ANIM_H
#define GUARD_SPECIAL_FIELD_ANIM_H

#include "global.h"

void __attribute__((long_call)) StartEscalator(bool8 goingUp);
void __attribute__((long_call)) StopEscalator(void);
bool8 __attribute__((long_call)) IsEscalatorMoving(void);

#endif // GUARD_SPECIAL_FIELD_ANIM_H
