#ifndef GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_AI_SCRIPT_COMMANDS_H

#include "global.h"

// return values for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5

void __attribute__((long_call)) BattleAI_HandleItemUseBeforeAISetup(void);
void __attribute__((long_call)) BattleAI_SetupAIData(void);
u8 __attribute__((long_call)) BattleAI_ChooseMoveOrAction(void);
void __attribute__((long_call)) ClearBankMoveHistory(u8 bank);
void __attribute__((long_call)) RecordAbilityBattle(u8 bank, u8 abilityId);
void __attribute__((long_call)) ClearBankAbilityHistory(u8 bank);
void __attribute__((long_call)) RecordItemEffectBattle(u8 bank, u8 itemEffect);
void __attribute__((long_call)) ClearBankItemEffectHistory(u8 bank);
u8 __attribute__((long_call)) BattleAI_ChooseMoveOrAction(void);

#endif // GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
