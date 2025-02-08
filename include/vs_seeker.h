#ifndef GUARD_VS_SEEKER_H
#define GUARD_VS_SEEKER_H

#include "global.h"

void __attribute__((long_call)) Task_VsSeeker_0(u8 taskId);
void __attribute__((long_call)) ClearRematchStateByTrainerId(void);
void __attribute__((long_call)) ClearRematchStateOfLastTalked(void);
int GetRematchTrainerId(u16 trainerId);
bool8 __attribute__((long_call)) UpdateVsSeekerStepCounter(void);
void __attribute__((long_call)) MapResetTrainerRematches(u16 mapGroup, u16 mapNum);

#endif //GUARD_VS_SEEKER_H
