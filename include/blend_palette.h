#ifndef GUARD_BLEND_PALETTE_H
#define GUARD_BLEND_PALETTE_H

#include "global.h"

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations

void __attribute__((long_call)) BlendPalette(u16, u16, u8, u16);
void __attribute__((long_call)) BlendPalettesAt(u16 * palbuff, u16 blend_pal, u32 coefficient, s32 size);

#endif //GUARD_BLEND_PALETTE_H
