#ifndef GUARD_EGG_HATCH_H
#define GUARD_EGG_HATCH_H

#include "global.h"

void __attribute__((long_call)) ScriptHatchMon(void);
void __attribute__((long_call)) EggHatch(void);
u8 __attribute__((long_call)) GetEggStepsToSubtract(void);

#endif // GUARD_EGG_HATCH_H
