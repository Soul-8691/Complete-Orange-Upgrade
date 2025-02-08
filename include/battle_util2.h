#ifndef GUARD_BATTLE_UTIL2_H
#define GUARD_BATTLE_UTIL2_H

#include "global.h"

void __attribute__((long_call)) AllocateBattleResources(void);
void __attribute__((long_call)) FreeBattleResources(void);
void __attribute__((long_call)) AdjustFriendshipOnBattleFaint(u8 bank);

#endif // GUARD_BATTLE_UTIL_H
