#ifndef GUARD_FIELD_TASKS_H
#define GUARD_FIELD_TASKS_H

#include "global.h"

void __attribute__((long_call)) ActivatePerStepCallback(u8);
void __attribute__((long_call)) SetUpFieldTasks(void);

#endif // GUARD_FIELD_TASKS_H
