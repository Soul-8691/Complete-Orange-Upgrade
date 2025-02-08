#ifndef GUARD_ITEM_USE_H
#define GUARD_ITEM_USE_H

#include "global.h"

void __attribute__((long_call)) Task_ItemUse_CloseMessageBoxAndReturnToField_VsSeeker(u8);
void __attribute__((long_call)) ItemUse_SetQuestLogEvent(u8, struct Pokemon *, u16, u16);

void __attribute__((long_call)) FieldUseFunc_Mail(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_Bike(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_Rod(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_CoinCase(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_PowderJar(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_PokeFlute(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_Medicine(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_Ether(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_PpUp(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_RareCandy(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_EvoItem(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_SacredAsh(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_TmCase(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_BerryPouch(u8 taskId);
void __attribute__((long_call)) BattleUseFunc_BerryPouch(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_TeachyTv(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_Repel(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_BlackWhiteFlute(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_TownMap(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_FameChecker(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_VsSeeker(u8 taskId);
void __attribute__((long_call)) BattleUseFunc_PokeBallEtc(u8 taskId);
void __attribute__((long_call)) BattleUseFunc_PokeFlute(u8 taskId);
void __attribute__((long_call)) BattleUseFunc_StatBooster(u8 taskId);
void __attribute__((long_call)) BattleUseFunc_Medicine(u8 taskId);
void __attribute__((long_call)) BattleUseFunc_Ether(u8 taskId);
void __attribute__((long_call)) BattleUseFunc_PokeDoll(u8 taskId);
void __attribute__((long_call)) FieldUseFunc_OakStopsYou(u8 taskId);
void __attribute__((long_call)) ItemUseOutOfBattle_EscapeRope(u8 taskId);
void __attribute__((long_call)) ItemUseOutOfBattle_EnigmaBerry(u8 taskId);
void __attribute__((long_call)) ItemUseInBattle_EnigmaBerry(u8 taskId);
void __attribute__((long_call)) ItemUseOutOfBattle_Itemfinder(u8 taskId);
void __attribute__((long_call)) Task_UseDigEscapeRopeOnField(u8 taskId);
u8 __attribute__((long_call)) CanUseEscapeRopeOnCurrMap(void);
u8 __attribute__((long_call)) CheckIfItemIsTMHMOrEvolutionStone(u16 itemId);

#endif //GUARD_ITEM_USE_H
