#ifndef GUARD_TILEMAP_UTIL_H
#define GUARD_TILEMAP_UTIL_H

void __attribute__((long_call)) TilemapUtil_Init(u8 numTilemapIds);
void __attribute__((long_call)) TilemapUtil_Free(void);
void __attribute__((long_call)) TilemapUtil_SetTilemap(u8 tilemapId, u8 bg, const void *tilemap, u16 width, u16 height);
void __attribute__((long_call)) TilemapUtil_SetPos(u8 tilemapId, u16 destX, u16 destY);
void __attribute__((long_call)) TilemapUtil_SetRect(u8 tilemapId, u16 x, u16 y, u16 width, u16 height);
void __attribute__((long_call)) TilemapUtil_Move(u8 tilemapId, u8 mode, s8 param);
void __attribute__((long_call)) TilemapUtil_Update(u8 tilemapId);

#endif //GUARD_TILEMAP_UTIL_H
