#ifndef GUARD_CALCULATE_BASE_DAMAGE_H
#define GUARD_CALCULATE_BASE_DAMAGE_H

#include "global.h"

s32 __attribute__((long_call)) CalculateBaseDamage(struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 move, u16 sideStatus, u16 powerOverride, u8 typeOverride, u8 bankAtk, u8 bankDef);

#endif // GUARD_CALCULATE_BASE_DAMAGE_H
