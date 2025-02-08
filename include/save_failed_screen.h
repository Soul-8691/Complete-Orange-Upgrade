#ifndef GUARD_SAVE_FAILED_SCREEN_H
#define GUARD_SAVE_FAILED_SCREEN_H

extern void __attribute__((long_call)) DoSaveFailedScreen(u8 saveType); // save_failed_screen
void __attribute__((long_call)) SetNotInSaveFailedScreen(void);
bool32 __attribute__((long_call)) RunSaveFailedScreen(void);

#endif //GUARD_SAVE_FAILED_SCREEN_H
