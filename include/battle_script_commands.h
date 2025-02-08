#ifndef GUARD_BATTLE_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_SCRIPT_COMMANDS_H

#include "global.h"

// Arguments for 'flags' in HandleBattleWindow
#define WINDOW_CLEAR (1 << 0)
#define WINDOW_BG1   (1 << 7)

void __attribute__((long_call)) AI_CalcDmg(u8 attacker, u8 defender);
u8 __attribute__((long_call)) TypeCalc(u16 move, u8 attacker, u8 defender);
u8 __attribute__((long_call)) AI_TypeCalc(u16 move, u16 targetSpecies, u8 targetAbility);
u8 __attribute__((long_call)) GetBattlerTurnOrderNum(u8 battlerId);
void __attribute__((long_call)) SetMoveEffect(bool8 primary, u8 certain);
bool32 __attribute__((long_call)) IsMonGettingExpSentOut(void);
void __attribute__((long_call)) BattleDestroyYesNoCursorAt(void);
void __attribute__((long_call)) BattleCreateYesNoCursorAt(void);
void __attribute__((long_call)) BufferMoveToLearnIntoBattleTextBuff2(void);
void __attribute__((long_call)) HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags);
bool8 __attribute__((long_call)) UproarWakeUpCheck(u8 battlerId);

extern void __attribute__((long_call)) (* const gBattleScriptingCommandsTable[])(void);

#endif // GUARD_BATTLE_SCRIPT_COMMANDS_H
