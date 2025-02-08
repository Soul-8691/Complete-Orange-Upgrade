#ifndef GUARD_MONEY_H
#define GUARD_MONEY_H

#include "global.h"

u32 __attribute__((long_call)) GetMoney(u32 *moneyPtr);
void __attribute__((long_call)) SetMoney(u32 *moneyPtr, u32 newValue);
bool8 __attribute__((long_call)) IsEnoughMoney(u32 *moneyPtr, u32 cost);
void __attribute__((long_call)) AddMoney(u32 *moneyPtr, u32 toAdd);
void __attribute__((long_call)) RemoveMoney(u32 *moneyPtr, u32 toSub);
bool8 __attribute__((long_call)) IsEnoughForCostInVar0x8005(void);
void __attribute__((long_call)) SubtractMoneyFromVar0x8005(void);
void __attribute__((long_call)) PrintMoneyAmountInMoneyBox(u8 windowId, int amount, u8 speed);
void __attribute__((long_call)) PrintMoneyAmountInMoneyBox(u8 windowId, int amount, u8 speed);
void __attribute__((long_call)) PrintMoneyAmountInMoneyBoxWithBorder(u8 windowId, u16 tileStart, u8 pallete, int amount);
void __attribute__((long_call)) ChangeAmountInMoneyBox(int amount);
void __attribute__((long_call)) DrawMoneyBox(int amount, u8 x, u8 y);
void __attribute__((long_call)) HideMoneyBox(void);
void __attribute__((long_call)) AddMoneyLabelObject(u16 x, u16 y);
void __attribute__((long_call)) RemoveMoneyLabelObject(void);
void __attribute__((long_call)) PrintMoneyAmount(u8 windowId, u8 x, u8 y, int amount, u8 speed);

#endif // GUARD_MONEY_H
