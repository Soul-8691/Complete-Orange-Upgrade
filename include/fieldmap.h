#ifndef GUARD_FIELDMAP_H
#define GUARD_FIELDMAP_H

#include "global.h"

#define NUM_TILES_IN_PRIMARY 640
#define NUM_TILES_TOTAL 1024
#define NUM_METATILES_IN_PRIMARY 640
#define NUM_METATILES_TOTAL 1024
#define NUM_PALS_IN_PRIMARY 7
#define NUM_PALS_TOTAL 13
#define MAX_MAP_DATA_SIZE 0x2800
#define VIRTUAL_MAP_SIZE (MAX_MAP_DATA_SIZE)

// Map coordinates are offset by 7 when using the map
// buffer because it needs to load sufficient border
// metatiles to fill the player's view (the player has
// 7 metatiles of view horizontally in either direction).
#define MAP_OFFSET 7
#define MAP_OFFSET_W (MAP_OFFSET * 2 + 1)
#define MAP_OFFSET_H (MAP_OFFSET * 2)

extern struct BackupMapLayout VMap;
extern const struct MapLayout Route1_Layout;

u32 __attribute__((long_call)) MapGridGetMetatileIdAt(s32, s32);
u32 __attribute__((long_call)) MapGridGetMetatileBehaviorAt(s16, s16);
u8 __attribute__((long_call)) MapGridGetMetatileLayerTypeAt(s16 x, s16 y);
void __attribute__((long_call)) MapGridSetMetatileIdAt(s32, s32, u16);
void __attribute__((long_call)) MapGridSetMetatileEntryAt(s32, s32, u16);
u8 __attribute__((long_call)) MapGridGetElevationAt(s32 x, s32 y);
void __attribute__((long_call)) GetCameraCoords(u16 *, u16 *);
bool8 __attribute__((long_call)) MapGridGetCollisionAt(s32, s32);
s32 __attribute__((long_call)) GetMapBorderIdAt(s32, s32);
bool32 __attribute__((long_call)) CanCameraMoveInDirection(s32);
const struct MapHeader * GetMapHeaderFromConnection(const struct MapConnection * connection);
const struct MapConnection * GetMapConnectionAtPos(s16 x, s16 y);
void __attribute__((long_call)) ApplyGlobalTintToPaletteSlot(u8 slot, u8 count);
void __attribute__((long_call)) SaveMapView(void);
u32 __attribute__((long_call)) ExtractMetatileAttribute(u32 attributes, u8 attributeType);
u32 __attribute__((long_call)) MapGridGetMetatileAttributeAt(s16 x, s16 y, u8 attributeType);
void __attribute__((long_call)) MapGridSetMetatileImpassabilityAt(s32 x, s32 y, bool32 arg2);
bool8 __attribute__((long_call)) CameraMove(s32 x, s32 y);
void __attribute__((long_call)) CopyMapTilesetsToVram(struct MapLayout const * mapLayout);
void __attribute__((long_call)) LoadMapTilesetPalettes(struct MapLayout const * mapLayout);
void __attribute__((long_call)) InitMap(void);
void __attribute__((long_call)) CopySecondaryTilesetToVramUsingHeap(const struct MapLayout * mapLayout);
void __attribute__((long_call)) LoadSecondaryTilesetPalette(const struct MapLayout * mapLayout);
void __attribute__((long_call)) InitMapFromSavedGame(void);
void __attribute__((long_call)) CopyPrimaryTilesetToVram(const struct MapLayout *mapLayout);
void __attribute__((long_call)) CopySecondaryTilesetToVram(const struct MapLayout *mapLayout);
void __attribute__((long_call)) GetCameraFocusCoords(u16 *x, u16 *y);
void __attribute__((long_call)) SetCameraFocusCoords(u16 x, u16 y);

#endif //GUARD_FIELDMAP_H
