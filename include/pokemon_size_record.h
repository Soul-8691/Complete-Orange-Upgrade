#ifndef GUARD_POKEMON_SIZE_RECORD_H
#define GUARD_POKEMON_SIZE_RECORD_H

#include "global.h"

void __attribute__((long_call)) InitSeedotSizeRecord(void);
void __attribute__((long_call)) GetSeedotSizeRecordInfo(void);
void __attribute__((long_call)) CompareSeedotSize(void);

void __attribute__((long_call)) InitLotadSizeRecord(void);
void __attribute__((long_call)) GetLotadSizeRecordInfo(void);
void __attribute__((long_call)) CompareLotadSize(void);

void __attribute__((long_call)) InitHeracrossSizeRecord(void);
void __attribute__((long_call)) InitMagikarpSizeRecord(void);

void __attribute__((long_call)) GiveGiftRibbonToParty(u8 index, u8 ribbonId);

#endif // GUARD_POKEMON_SIZE_RECORD_H
