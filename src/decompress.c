#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/decompress.h"
#include "../include/pokemon.h"
#include "../include/data.h"
#include "../include/event_data.h"

extern void __attribute__((long_call)) DuplicateDeoxysTiles(void *pointer, s32 species);
extern const struct CompressedSpriteSheet gMugshots[];

void LoadSpecialPokePic_(const struct CompressedSpriteSheet *src, void *dest, s32 species, u32 personality, bool8 isFrontPic)
{
    if (FlagGet(FLAG_MUGSHOT))
        LZ77UnCompWram(gMugshots[species].data, dest);
    else if (species == SPECIES_UNOWN)
    {
        u16 i = (((personality & 0x3000000) >> 18) | ((personality & 0x30000) >> 12) | ((personality & 0x300) >> 6) | (personality & 3)) % 0x1C;

        // The other Unowns are separate from Unown A.
        if (i == 0)
            i = SPECIES_UNOWN;
        else
            i += SPECIES_UNOWN_B - 1;
        if (!isFrontPic)
            LZ77UnCompWram(gMonBackPicTable[i].data, dest);
        else
            LZ77UnCompWram(gMonFrontPicTable[i].data, dest);
    }
    else if (species > NUM_SPECIES) // is species unknown? draw the ? icon
        LZ77UnCompWram(gMonFrontPicTable[0].data, dest);
    else
        LZ77UnCompWram(src->data, dest);

    DuplicateDeoxysTiles(dest, species);
    DrawSpindaSpots(species, personality, dest, isFrontPic);
}
