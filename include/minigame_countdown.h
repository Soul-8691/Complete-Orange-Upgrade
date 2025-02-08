#ifndef GUARD_MINIGAME_COUNTDOWN_H
#define GUARD_MINIGAME_COUNTDOWN_H

void __attribute__((long_call)) StartMinigameCountdown(u16 tilesTag, u16 palTag, s16 x, s16 y, u8 subpriority);
bool32 __attribute__((long_call)) IsMinigameCountdownRunning(void);

#endif //GUARD_MINIGAME_COUNTDOWN_H
