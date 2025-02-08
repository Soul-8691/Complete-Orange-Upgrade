#ifndef GUARD_POKEMON_ICON_H
#define GUARD_POKEMON_ICON_H

#include "global.h"

extern const u8 *const gMonIconTable[];
extern const struct SpritePalette gMonIconPaletteTable[];
extern const u16 gMonIconPalettes[][16];
extern const u8 gMonIconPaletteIndices[];

const u8 *GetMonIconPtr(u16 speciesId, u32 personality, u32 frameNo);
const u8 *GetMonIconTiles(u16 iconSpecies, bool32 extra);
const u16 *GetValidMonIconPalettePtr(u16 speciesId);
void __attribute__((long_call)) LoadMonIconPalettes(void);
void __attribute__((long_call)) FreeMonIconPalettes(void);
u16 __attribute__((long_call)) MailSpeciesToIconSpecies(u16);
u8 __attribute__((long_call)) CreateMonIcon_HandleDeoxys(u16 species, SpriteCallback callback, s16 x, s16 y, u8 subpriority, bool32 extra);
void __attribute__((long_call)) DestroyMonIcon(struct Sprite *);
u16 __attribute__((long_call)) GetUnownLetterByPersonality(u32 personality);
void __attribute__((long_call)) SpriteCB_MonIcon(struct Sprite *);
u8 __attribute__((long_call)) CreateMonIcon(u16 species, SpriteCallback callback, s16 x, s16 y, u8 subpriority, u32 personality, bool32 extra);
u8 __attribute__((long_call)) UpdateMonIconFrame(struct Sprite *sprite);
void __attribute__((long_call)) LoadMonIconPalette(u16 iconId);
void __attribute__((long_call)) FreeMonIconPalette(u16 iconId);
void __attribute__((long_call)) SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum);
u8 __attribute__((long_call)) GetMonIconPaletteIndexFromSpecies(u16 species);
u16 __attribute__((long_call)) GetIconSpecies(u16 species, u32 personality);
void __attribute__((long_call)) LoadMonIconPalettesAt(u16 offset);
u8 __attribute__((long_call)) GetValidMonIconPalIndex(u16 species);
void __attribute__((long_call)) SafeLoadMonIconPalette(u16 species);
void __attribute__((long_call)) SafeFreeMonIconPalette(u16 species);

#endif // GUARD_POKEMON_ICON_H
