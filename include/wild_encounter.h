#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "global.h"

#define LAND_WILD_COUNT     12
#define WATER_WILD_COUNT    5
#define ROCK_WILD_COUNT     5
#define FISH_WILD_COUNT     10

#define NUM_ALTERING_CAVE_TABLES 9

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon;
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *fishingMonsInfo;
};

extern const struct WildPokemonHeader gWildMonHeaders[];

void __attribute__((long_call)) DisableWildEncounters(bool8 disabled);
bool8 __attribute__((long_call)) StandardWildEncounter(u32 currMetatileAttrs, u16 previousMetaTileBehavior);
bool8 __attribute__((long_call)) SweetScentWildEncounter(void);
bool8 __attribute__((long_call)) DoesCurrentMapHaveFishingMons(void);
void __attribute__((long_call)) FishingWildEncounter(u8 rod);
u16 __attribute__((long_call)) GetLocalWildMon(bool8 *isWaterMon);
u16 __attribute__((long_call)) GetLocalWaterMon(void);
bool8 __attribute__((long_call)) UpdateRepelCounter(void);
void __attribute__((long_call)) DisableWildEncounters(bool8 state);
u8 __attribute__((long_call)) GetUnownLetterByPersonalityLoByte(u32 personality);
bool8 __attribute__((long_call)) SweetScentWildEncounter(void);
void __attribute__((long_call)) SeedWildEncounterRng(u16 randVal);
void __attribute__((long_call)) ResetEncounterRateModifiers(void);
bool8 __attribute__((long_call)) TryStandardWildEncounter(u32 currMetatileAttrs);

#endif // GUARD_WILD_ENCOUNTER_H
