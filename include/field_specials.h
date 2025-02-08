#ifndef GUARD_FIELD_SPECIALS_H
#define GUARD_FIELD_SPECIALS_H

#include "global.h"

u8 __attribute__((long_call)) GetLeadMonIndex(void);
s32 CountDigits(s32 number);
void __attribute__((long_call)) TV_PrintIntToStringVar(u8 varidx, s32 number);
u16 __attribute__((long_call)) GetStarterSpecies(void);
void __attribute__((long_call)) StopPokemonLeagueLightingEffectTask(void);
void __attribute__((long_call)) FieldCB_ShowPortholeView(void);
u8 __attribute__((long_call)) ContextNpcGetTextColor(void);
void __attribute__((long_call)) SetPCBoxToSendMon(u8);
u16 __attribute__((long_call)) GetPCBoxToSendMon(void);
bool8 __attribute__((long_call)) IsDestinationBoxFull(void);
bool8 __attribute__((long_call)) ShouldShowBoxWasFullMessage(void);
u16 __attribute__((long_call)) GetHiddenItemAttr(u32 hiddenItem, u8 attr);
u8 __attribute__((long_call)) GetUnlockedSeviiAreas(void);
u32 __attribute__((long_call)) GetPlayerTrainerId(void);
bool8 __attribute__((long_call)) CutMoveRuinValleyCheck(void);
void __attribute__((long_call)) CutMoveOpenDottedHoleDoor(void);
void __attribute__((long_call)) RunMassageCooldownStepCounter(void);
void __attribute__((long_call)) IncrementResortGorgeousStepCounter(void);
void __attribute__((long_call)) IncrementBirthIslandRockStepCount(void);
void __attribute__((long_call)) ResetCyclingRoadChallengeData(void);
void __attribute__((long_call)) ResetFieldTasksArgs(void);
bool8 __attribute__((long_call)) UsedPokemonCenterWarp(void);
void __attribute__((long_call)) QuestLog_CheckDepartingIndoorsMap(void);
void __attribute__((long_call)) QuestLog_TryRecordDepartedLocation(void);

#endif // GUARD_FIELD_SPECIALS_H
