#ifndef GUARD_SAVE_H
#define GUARD_SAVE_H

#include "global.h"

// Each 4 KiB flash sector contains 3968 bytes of actual data followed by a 128 byte footer.
// Only 12 bytes of the footer are used.
#define NUM_SAVE_SLOTS 2

// If the sector's signature field is not this value then the sector is either invalid or empty.
#define SECTOR_SIGNATURE 0x08012025

#define SPECIAL_SECTOR_SENTINEL 0xB39D

#define SECTOR_ID_SAVEBLOCK2          0
#define SECTOR_ID_SAVEBLOCK1_START    1
#define SECTOR_ID_SAVEBLOCK1_END      4
#define SECTOR_ID_PKMN_STORAGE_START  5
#define SECTOR_ID_PKMN_STORAGE_END   13
#define NUM_SECTORS_PER_SLOT         14
// Save Slot 1: 0-13;  Save Slot 2: 14-27
#define SECTOR_ID_HOF_1              28
#define SECTOR_ID_HOF_2              29
#define SECTOR_ID_TRAINER_TOWER_1    30
#define SECTOR_ID_TRAINER_TOWER_2    31
#define SECTORS_COUNT                32

#define NUM_HOF_SECTORS 2

#define SAVE_STATUS_EMPTY    0
#define SAVE_STATUS_OK       1
#define SAVE_STATUS_INVALID  2
#define SAVE_STATUS_NO_FLASH 4
#define SAVE_STATUS_ERROR    0xFF

// Special sector id value for certain save functions
// to indicate that all sectors should be used
// instead of a specific sector.
#define FULL_SAVE_SLOT 0xFFFF

enum
{
    SAVE_NORMAL,
    SAVE_LINK,
    SAVE_EREADER,
    SAVE_HALL_OF_FAME,
    SAVE_OVERWRITE_DIFFERENT_FILE,
    SAVE_HALL_OF_FAME_ERASE_BEFORE, // unused
};

// A save sector location holds a pointer to the data for a particular sector
// and the size of that data. Size cannot be greater than SECTOR_DATA_SIZE.
struct SaveSectorLocation
{
    u8 *data;
    u16 size;
};

struct SaveSectionOffsets
{
    u16 toAdd;
    u16 size;
};

struct SaveSector
{
    u8 data[0xFF4];
    u16 id;
    u16 checksum;
    u32 signature;
    u32 counter;
}; // size is 0x1000

#define SECTOR_SIGNATURE_OFFSET offsetof(struct SaveSector, signature)
#define SECTOR_COUNTER_OFFSET   offsetof(struct SaveSector, counter)

// operations for SetDamagedSectorBits
enum
{
    ENABLE,
    DISABLE,
    CHECK // unused
};

extern u32 gDamagedSaveSectors;
extern struct SaveSector *gSaveDataBufferPtr; // the pointer is in fast IWRAM but points to the slower EWRAM.
extern u16 SaveFileStatus;
extern void (*gGameContinueCallback)(void);
extern u16 gSaveAttemptStatus;

extern struct SaveSector gSaveDataBuffer;

void __attribute__((long_call)) ClearSaveData(void);
void __attribute__((long_call)) Save_ResetSaveCounters(void);
u8 HandleSavingData_(u8 saveType);
u8 __attribute__((long_call)) TrySavingData(u8 saveType);
bool8 __attribute__((long_call)) LinkFullSave_Init(void);
bool8 __attribute__((long_call)) LinkFullSave_WriteSector(void);
bool8 __attribute__((long_call)) LinkFullSave_ReplaceLastSector(void);
bool8 __attribute__((long_call)) LinkFullSave_SetLastSectorSignature(void);
bool8 __attribute__((long_call)) WriteSaveBlock2(void);
bool8 __attribute__((long_call)) WriteSaveBlock1Sector(void);
u8 __attribute__((long_call)) LoadGameSave(u8 saveType);
u32 __attribute__((long_call)) TryReadSpecialSaveSector(u8 sector, u8 *dst);
u32 __attribute__((long_call)) TryWriteSpecialSaveSector(u8 sector, u8 *src);
void __attribute__((long_call)) Task_LinkFullSave(u8 taskId);

extern u16 gLastWrittenSector;
extern u32 gLastSaveCounter;
extern u16 gLastKnownGoodSector;
extern u32 gSaveCounter;
extern u16 gUnknown_3005398;
extern u16 gSaveUnusedVar;
extern struct SaveSectorLocation gRamSaveSectorLocations[0xE];

void __attribute__((long_call)) UpdateSaveAddresses(void);
u16 __attribute__((long_call)) CalculateChecksum(void* data, u16 size);
u8 __attribute__((long_call)) TryWriteSector(u8 sector, u8 *data);
u8 __attribute__((long_call)) ReadFlashSector(u8 sector, struct SaveSection *section);
u8 __attribute__((long_call)) HandleWriteSectorNBytes(u8 sector, u8 *data, u16 size);

#endif // GUARD_SAVE_H
