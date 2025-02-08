#ifndef GUARD_DECOMPRESS_H
#define GUARD_DECOMPRESS_H

#include "global.h"

#include "sprite.h"

extern u8 __attribute__((long_call)) gDecompressionBuffer[0x4000];

void __attribute__((long_call)) LZDecompressWram(const void *src, void *dest);
void __attribute__((long_call)) LZDecompressVram(const void *src, void *dest);

u16 __attribute__((long_call)) LoadCompressedSpriteSheet(const struct CompressedSpriteSheet *src);
void __attribute__((long_call)) LoadCompressedSpriteSheetOverrideBuffer(const struct CompressedSpriteSheet *src, void *buffer);
bool8 __attribute__((long_call)) LoadCompressedSpriteSheetUsingHeap(const struct CompressedSpriteSheet* src);

void __attribute__((long_call)) LoadCompressedSpritePalette(const struct CompressedSpritePalette *src);
void __attribute__((long_call)) LoadCompressedSpritePaletteOverrideBuffer(const struct CompressedSpritePalette *a, void *buffer);
bool8 __attribute__((long_call)) LoadCompressedSpritePaletteUsingHeap(const struct CompressedSpritePalette *src);

void __attribute__((long_call)) DecompressPicFromTable(const struct CompressedSpriteSheet *src, void *buffer, s32 species);
void __attribute__((long_call)) DecompressPicFromTable_2(const struct CompressedSpriteSheet *src, void *buffer, s32 species);
void __attribute__((long_call)) DecompressPicFromTable_DontHandleDeoxys(const struct CompressedSpriteSheet *src, void *buffer, s32 species);

void __attribute__((long_call)) HandleLoadSpecialPokePic(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality);
void __attribute__((long_call)) HandleLoadSpecialPokePic_DontHandleDeoxys(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality);

void __attribute__((long_call)) LoadSpecialPokePic(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic);
void __attribute__((long_call)) LoadSpecialPokePic_2(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic);
void __attribute__((long_call)) LoadSpecialPokePic_DontHandleDeoxys(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic);

u32 __attribute__((long_call)) GetDecompressedDataSize(const u8 *ptr);

#endif // GUARD_DECOMPRESS_H
