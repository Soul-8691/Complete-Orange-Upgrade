#ifndef GUARD_COINS_H
#define GUARD_COINS_H

#include "global.h"

void __attribute__((long_call)) PrintCoinsString(u32 coinAmount);
void __attribute__((long_call)) ShowCoinsWindow(u32 coinAmount, u8 x, u8 y);
void __attribute__((long_call)) HideCoinsWindow(void);
u16 __attribute__((long_call)) GetCoins(void);
void __attribute__((long_call)) SetCoins(u16 coinAmount);
bool8 __attribute__((long_call)) AddCoins(u16 toAdd);
bool8 __attribute__((long_call)) RemoveCoins(u16 toSub);

#endif // GUARD_COINS_H
