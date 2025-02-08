#ifndef GUARD_SLOT_MACHINE_H
#define GUARD_SLOT_MACHINE_H

#include "global.h"

void __attribute__((long_call)) PlaySlotMachine(u16, void (*)(void));

#endif // GUARD_SLOT_MACHINE_H
