#ifndef GUARD_BATTLE_SETUP_H
#define GUARD_BATTLE_SETUP_H

#include "global.h"

void __attribute__((long_call)) StartWildBattle(void);
void __attribute__((long_call)) StartRoamerBattle(void);
void __attribute__((long_call)) StartOldManTutorialBattle(void);
void __attribute__((long_call)) StartScriptedWildBattle(void);
void __attribute__((long_call)) StartMarowakBattle(void);
void __attribute__((long_call)) StartSouthernIslandBattle(void);
void __attribute__((long_call)) StartLegendaryBattle(void);
void __attribute__((long_call)) StartGroudonKyogreBattle(void);
void __attribute__((long_call)) StartRegiBattle(void);
u8 __attribute__((long_call)) BattleSetup_GetTerrainId(void);
u8 __attribute__((long_call)) BattleSetup_GetBattleTowerBattleTransition(void);
const u8 __attribute__((long_call)) *BattleSetup_ConfigureTrainerBattle(const u8 *data);
void __attribute__((long_call)) ConfigureAndSetUpOneTrainerBattle(u8 trainerEventObjId, const u8 *trainerScript);
bool32 __attribute__((long_call)) GetTrainerFlagFromScriptPointer(const u8 *data);
void __attribute__((long_call)) SetUpTrainerMovement(void);
u8 __attribute__((long_call)) GetTrainerBattleMode(void);
u16 __attribute__((long_call)) GetRivalBattleFlags(void);
void __attribute__((long_call)) SetBattledTrainerFlag(void);
bool8 __attribute__((long_call)) HasTrainerBeenFought(u16 trainerId);
void __attribute__((long_call)) SetTrainerFlag(u16 trainerId);
void __attribute__((long_call)) ClearTrainerFlag(u16 trainerId);
void __attribute__((long_call)) StartTrainerBattle(void);
void __attribute__((long_call)) StartRematchBattle(void);
void __attribute__((long_call)) ShowTrainerIntroSpeech(void);
const u8 __attribute__((long_call)) *BattleSetup_GetScriptAddrAfterBattle(void);
const u8 __attribute__((long_call)) *BattleSetup_GetTrainerPostBattleScript(void);
void __attribute__((long_call)) ShowTrainerCantBattleSpeech(void);
void __attribute__((long_call)) PlayTrainerEncounterMusic(void);
const u8 __attribute__((long_call)) *GetTrainerALoseText(void);
const u8 __attribute__((long_call)) *GetTrainerWonSpeech(void);

#endif // GUARD_BATTLE_SETUP_H
