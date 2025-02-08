#ifndef GUARD_BATTLE_TOWER_H
#define GUARD_BATTLE_TOWER_H

#include "global.h"
#include "constants/battle_tower.h"

#define BATTLE_TOWER_EREADER_TRAINER_ID 200
#define BATTLE_TOWER_RECORD_MIXING_TRAINER_BASE_ID 100

struct BattleTowerTrainer
{
    u8 trainerClass;
    u8 name[3];
    u8 teamFlags;
    u16 greeting[6];
};

struct BattleTowerPokemonTemplate
{
    u16 species;
    u8 heldItem;
    u8 teamFlags;
    u16 moves[4];
    u8 evSpread;
    u8 nature;
};

extern const u16 gBattleTowerBannedSpecies[];

void __attribute__((long_call)) ClearEReaderTrainer(struct BattleTowerEReaderTrainer *);
void __attribute__((long_call)) ValidateEReaderTrainer(void);
u8 __attribute__((long_call)) GetBattleTowerTrainerFrontSpriteId(void);
u8 __attribute__((long_call)) GetEreaderTrainerFrontSpriteId(void);
void __attribute__((long_call)) CopyEReaderTrainerName5(u8 *dest);
void __attribute__((long_call)) GetBattleTowerTrainerName(u8 *text);
u8 __attribute__((long_call)) GetEreaderTrainerClassId(void);
u8 __attribute__((long_call)) GetBattleTowerTrainerClassNameId(void);

#endif //GUARD_BATTLE_TOWER_H
