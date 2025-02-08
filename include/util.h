#ifndef GUARD_UTIL_H
#define GUARD_UTIL_H

#include "global.h"

#include "sprite.h"

extern const u8 gMiscBlank_Gfx[]; // unused in Emerald
extern const u32 gBitTable[];

u8 __attribute__((long_call)) CreateInvisibleSpriteWithCallback(void (*)(struct Sprite *));
void __attribute__((long_call)) StoreWordInTwoHalfwords(u16 *, u32);
void __attribute__((long_call)) LoadWordFromTwoHalfwords(u16 *, u32 *);
int CountTrailingZeroBits(u32 value);
u16 __attribute__((long_call)) CalcCRC16(const u8 *data, u32 length);
u16 __attribute__((long_call)) CalcCRC16WithTable(const u8 *data, u32 length);
u32 __attribute__((long_call)) CalcByteArraySum(const u8 *data, u32 length);
void __attribute__((long_call)) BlendPalette(u16 palOffset, u16 numEntries, u8 coeff, u16 blendColor);
void __attribute__((long_call)) DoBgAffineSet(struct BgAffineDstData * dest, u32 texX, u32 texY, s16 srcX, s16 srcY, s16 sx, s16 sy, u16 alpha);

#endif // GUARD_UTIL_H
