#ifndef GUARD_TRAINER_POKEMON_SPRITES_H
#define GUARD_TRAINER_POKEMON_SPRITES_H

#include "global.h"

u16 __attribute__((long_call)) CreateTrainerCardTrainerPicSprite(u16 species, bool8 isFrontPic, u16 destX, u16 destY, u8 paletteSlot, u8 windowId);
bool16 __attribute__((long_call)) ResetAllPicSprites(void);
u16 __attribute__((long_call)) CreateTrainerPicSprite(u16 species, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag);
u16 __attribute__((long_call)) FreeAndDestroyMonPicSprite(u16);
u16 __attribute__((long_call)) FreeAndDestroyTrainerPicSprite(u16);
u16 __attribute__((long_call)) PlayerGenderToFrontTrainerPicId(u8 gender, bool8 getClass);
u16 __attribute__((long_call)) CreateMonPicSprite_HandleDeoxys(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag);
u16 __attribute__((long_call)) LoadMonPicInWindow(u16 species, u32 otId, u32 personality, bool8 isFrontPic, u8 paletteSlot, u8 windowId);
u16 __attribute__((long_call)) CreateMonPicSprite(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag, bool8 ignoreDeoxys);
u16 __attribute__((long_call)) CreateMonPicSprite_HandleDeoxys(u16 species, u32 otId, u32 personality, bool8 isFrontPic, s16 x, s16 y, u8 paletteSlot, u16 paletteTag);

#endif // GUARD_TRAINER_POKEMON_SPRITES_H
