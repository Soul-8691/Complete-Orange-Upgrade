#ifndef GUARD_TRAINER_TOWER_H
#define GUARD_TRAINER_TOWER_H

void __attribute__((long_call)) PrintTrainerTowerRecords(void);
void __attribute__((long_call)) InitTrainerTowerBattleStruct(void);
void __attribute__((long_call)) FreeTrainerTowerBattleStruct(void);
u8 __attribute__((long_call)) GetTrainerTowerTrainerFrontSpriteId(void);
void __attribute__((long_call)) ResetTrainerTowerResults(void);
void __attribute__((long_call)) GetTrainerTowerOpponentWinText(u8 *dest, u8 opponentIdx);
void __attribute__((long_call)) GetTrainerTowerOpponentLoseText(u8 *dest, u8 opponentIdx);
void __attribute__((long_call)) GetTrainerTowerOpponentName(u8 *text);
u8 __attribute__((long_call)) GetTrainerTowerOpponentClass(void);

#endif //GUARD_TRAINER_TOWER_H
