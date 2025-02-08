#ifndef GUARD_TASK_H
#define GUARD_TASK_H

#include "global.h"

#define HEAD_SENTINEL 0xFE
#define TAIL_SENTINEL 0xFF
#define TASK_NONE TAIL_SENTINEL

#define NUM_TASKS 16
#define NUM_TASK_DATA 16

typedef void (*TaskFunc)(u8 taskId);

struct Task
{
    TaskFunc func;
    bool8 isActive;
    u8 prev;
    u8 next;
    u8 priority;
    s16 data[NUM_TASK_DATA];
};

extern struct Task gTasks[];

void __attribute__((long_call)) ResetTasks(void);
u8 __attribute__((long_call)) CreateTask(TaskFunc func, u8 priority);
void __attribute__((long_call)) InsertTask(u8 newTaskId);
void __attribute__((long_call)) DestroyTask(u8 taskId);
void __attribute__((long_call)) RunTasks(void);
u8 __attribute__((long_call)) FindFirstActiveTask(void);
void __attribute__((long_call)) TaskDummy(u8 taskId);
void __attribute__((long_call)) SetTaskFuncWithFollowupFunc(u8 taskId, TaskFunc func, TaskFunc followupFunc);
void __attribute__((long_call)) SwitchTaskToFollowupFunc(u8 taskId);
bool8 __attribute__((long_call)) FuncIsActiveTask(TaskFunc func);
u8 __attribute__((long_call)) FindTaskIdByFunc(TaskFunc func);
u8 __attribute__((long_call)) GetTaskCount(void);

// void ResetTasks(void);
// u8 CreateTask(TaskFunc func, u8 priority);
// void DestroyTask(u8 taskId);
// void RunTasks(void);
// void TaskDummy(u8 taskId);
// void SetTaskFuncWithFollowupFunc(u8 taskId, TaskFunc func, TaskFunc followupFunc);
// void SwitchTaskToFollowupFunc(u8 taskId);
// bool8 FuncIsActiveTask(TaskFunc func);
// u8 FindTaskIdByFunc(TaskFunc func);
// u8 GetTaskCount(void);
// void SetWordTaskArg(u8 taskId, u8 dataElem, unsigned long value);
// u32 GetWordTaskArg(u8 taskId, u8 dataElem);

#endif // GUARD_TASK_H
