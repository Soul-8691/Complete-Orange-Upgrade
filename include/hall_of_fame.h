#ifndef GUARD_HALL_OF_FAME_H
#define GUARD_HALL_OF_FAME_H

#include "global.h"

void __attribute__((long_call)) CB2_DoHallOfFameScreen(void);
void __attribute__((long_call)) CB2_DoHallOfFameScreenDontSaveData(void);
void __attribute__((long_call)) CB2_DoHallOfFamePC(void);
void __attribute__((long_call)) CB2_InitHofPC(void);
void __attribute__((long_call)) HallOfFamePCBeginFade(void);
void __attribute__((long_call)) ReturnFromHallOfFamePC(void);

#endif // GUARD_HALL_OF_FAME_H
