#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/decompress.h"
#include "../include/data.h"

extern const struct CompressedSpritePalette gMugshotPaletteTable[];

void LoadPicPaletteBySlot_(u16 species, u32 otId, u32 personality, u8 paletteSlot, bool8 isTrainer)
{
    if (!isTrainer && species < 5000)
        LoadCompressedPalette(GetMonSpritePalFromSpeciesAndPersonality(species, otId, personality), BG_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    else if (species >= 5000)
        LoadCompressedPalette(gMugshotPaletteTable[species - 5000].data, BG_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
    else
        LoadCompressedPalette(gTrainerFrontPicPaletteTable[species].data, BG_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
}
