#ifndef GUARD_SAFARI_ZONE_H
#define GUARD_SAFARI_ZONE_H

#include "global.h"

extern u8 __attribute__((long_call)) gNumSafariBalls;
extern u16 __attribute__((long_call)) gSafariZoneStepCounter;

bool32 __attribute__((long_call)) GetSafariZoneFlag(void);
void __attribute__((long_call)) SetSafariZoneFlag(void);
void __attribute__((long_call)) ResetSafariZoneFlag(void);

void __attribute__((long_call)) EnterSafariMode(void);
void __attribute__((long_call)) ExitSafariMode(void);

bool8 __attribute__((long_call)) SafariZoneTakeStep(void);
void __attribute__((long_call)) SafariZoneRetirePrompt(void);

void __attribute__((long_call)) CB2_EndSafariBattle(void);

#endif // GUARD_SAFARI_ZONE_H
