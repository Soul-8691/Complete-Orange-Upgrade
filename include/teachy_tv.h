#ifndef GUARD_TEACHY_TV_H
#define GUARD_TEACHY_TV_H

enum TeachyTvScript
{
    TTVSCR_BATTLE,
    TTVSCR_STATUS,
    TTVSCR_MATCHUPS,
    TTVSCR_CATCHING,
    TTVSCR_TMS,
    TTVSCR_REGISTER
};

void __attribute__((long_call)) InitTeachyTvController(u8 mode, void (*cb)());
void __attribute__((long_call)) CB2_ReturnToTeachyTV(void);
void __attribute__((long_call)) SetTeachyTvControllerModeToResume(void);

#endif //GUARD_TEACHY_TV_H
