#ifndef GUARD_MYSTERY_EVENT_SCRIPT_H
#define GUARD_MYSTERY_EVENT_SCRIPT_H

#include "global.h"

u32 __attribute__((long_call)) RunMysteryEventScript(u8 *);
void __attribute__((long_call)) SetMysteryEventScriptStatus(u32 val);

void __attribute__((long_call)) MEventScript_InitContext(u8 *);
bool32 __attribute__((long_call)) MEventScript_Run(u32 *);

#endif // GUARD_MYSTERY_EVENT_SCRIPT_H
