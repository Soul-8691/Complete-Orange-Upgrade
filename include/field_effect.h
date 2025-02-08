#ifndef GUARD_FIELD_EFFECTS_H
#define GUARD_FIELD_EFFECTS_H

#include "global.h"
#include "constants/field_effects.h"

extern u32 __attribute__((long_call)) gFieldEffectArguments[8];
extern void (*gPostMenuFieldCallback)(void);
extern bool8 (*gFieldCallback2)(void);

u32 __attribute__((long_call)) FieldEffectStart(u8);
bool8 __attribute__((long_call)) FieldEffectActiveListContains(u8 id);
void __attribute__((long_call)) CreateTeleportFieldEffectTask(void);
void __attribute__((long_call)) FieldEffectActiveListRemove(u8 id);
void __attribute__((long_call)) StartEscapeRopeFieldEffect(void);
void __attribute__((long_call)) FieldEffectStop(struct Sprite *sprite, u8 id);
u8 __attribute__((long_call)) CreateTrainerSprite(u8 trainerSpriteID, s16 x, s16 y, u8 subpriority, u8 *buffer);
void __attribute__((long_call)) FieldCB_FallWarpExit(void);
void __attribute__((long_call)) StartEscalatorWarp(u8 metatileBehavior, u8 priority);
void __attribute__((long_call)) StartLavaridgeGymB1FWarp(u8 a0);
void __attribute__((long_call)) StartLavaridgeGym1FWarp(u8 a0);
void __attribute__((long_call)) ApplyGlobalFieldPaletteTint(u8 paletteIdx);
void __attribute__((long_call)) FreeResourcesAndDestroySprite(struct Sprite *sprite, u8 spriteId);
u8 __attribute__((long_call)) CreateMonSprite_PicBox(u16 species, s16 x, s16 y, bool8 unused);
void __attribute__((long_call)) ReturnToFieldFromFlyMapSelect(void);
void __attribute__((long_call)) MultiplyInvertedPaletteRGBComponents(u16 i, u8 r, u8 g, u8 b);
void __attribute__((long_call)) SpriteCB_PopOutOfAsh(struct Sprite *sprite);
void __attribute__((long_call)) SpriteCB_AshLaunch(struct Sprite *sprite);
void __attribute__((long_call)) FieldEffectActiveListClear(void);

#endif //GUARD_FIELD_EFFECTS_H
