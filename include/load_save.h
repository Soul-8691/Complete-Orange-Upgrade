#ifndef GUARD_LOAD_SAVE_H
#define GUARD_LOAD_SAVE_H

#include "global.h"

extern bool32 gFlashMemoryPresent;
extern struct SaveBlock1 gSaveBlock1;
extern struct SaveBlock2 gSaveBlock2;
extern struct PokemonStorage gPokemonStorage;

void __attribute__((long_call)) ClearSav2(void);
void __attribute__((long_call)) ClearSav1(void);
void __attribute__((long_call)) CheckForFlashMemory(void);
void __attribute__((long_call)) MoveSaveBlocks_ResetHeap(void);
bool32 __attribute__((long_call)) GetSecretBase2Field_9(void);
void __attribute__((long_call)) ClearSecretBase2Field_9(void);
void __attribute__((long_call)) SetSecretBase2Field_9(void);
void __attribute__((long_call)) SetSecretBase2Field_9_AndHideBG(void);
void __attribute__((long_call)) ClearSecretBase2Field_9_2(void);
void __attribute__((long_call)) SavePlayerParty(void);
void __attribute__((long_call)) LoadPlayerParty(void);
void __attribute__((long_call)) SaveSerializedGame(void);
void __attribute__((long_call)) LoadSerializedGame(void);
void __attribute__((long_call)) LoadPlayerBag(void);
void __attribute__((long_call)) SavePlayerBag(void);
void __attribute__((long_call)) SetSaveBlocksPointers(void);
void __attribute__((long_call)) MoveSaveBlocks_ResetHeap(void);
void __attribute__((long_call)) ApplyNewEncryptionKeyToAllEncryptedData(u32 encryptionKey);
void __attribute__((long_call)) ApplyNewEncryptionKeyToBagItems(u32 encryptionKey);
void __attribute__((long_call)) ApplyNewEncryptionKeyToWord(u32 * word, u32 encryptionKey);
void __attribute__((long_call)) ApplyNewEncryptionKeyToHword(u16 * hword, u32 encryptionKey);
void __attribute__((long_call)) ClearContinueGameWarpStatus2(void);
void __attribute__((long_call)) SetContinueGameWarpStatusToDynamicWarp(void);
void __attribute__((long_call)) SetContinueGameWarpStatus(void);
bool32 __attribute__((long_call)) UseContinueGameWarp(void);
void __attribute__((long_call)) ClearContinueGameWarpStatus();

#endif // GUARD_LOAD_SAVE_H
