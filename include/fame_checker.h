#ifndef GUARD_FAME_CHECKER_H
#define GUARD_FAME_CHECKER_H

#include "main.h"
#include "constants/fame_checker.h"

enum {
    FCWINDOWID_LIST,
    FCWINDOWID_UIHELP,
    FCWINDOWID_MSGBOX,
    FCWINDOWID_ICONDESC
};

extern struct ListMenuTemplate gFameChecker_ListMenuTemplate;
extern u8 __attribute__((long_call)) gIconDescriptionBoxIsOpen;

void __attribute__((long_call)) ResetFameChecker(void);
void __attribute__((long_call)) FullyUnlockFameChecker(void);
void __attribute__((long_call)) UseFameChecker(MainCallback savedCallback);
void __attribute__((long_call)) SetFlavorTextFlagFromSpecialVars(void);
void __attribute__((long_call)) UpdatePickStateFromSpecialVar8005(void);

#endif //GUARD_FAME_CHECKER_H
