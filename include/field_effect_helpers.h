//
// Created by scott on 9/7/2017.
//

#ifndef GUARD_FIELD_EFFECT_HELPERS_H
#define GUARD_FIELD_EFFECT_HELPERS_H

#include "global.h"

enum {
    BOB_NONE,
    BOB_PLAYER_AND_MON,
    BOB_MON_ONLY, // when player has jumped / flown off
};

u8 __attribute__((long_call)) CreateWarpArrowSprite(void);
void __attribute__((long_call)) SetSurfBlob_BobState(u8 spriteId, u8 bobState);
void __attribute__((long_call)) SetSurfBlob_DontSyncAnim(u8 spriteId, bool8 value);
void __attribute__((long_call)) StartAshFieldEffect(s16, s16, u16, s16);
void __attribute__((long_call)) StartRevealDisguise(struct ObjectEvent *);
bool8 __attribute__((long_call)) UpdateRevealDisguise(struct ObjectEvent *);
void __attribute__((long_call)) SetUpReflection(struct ObjectEvent *, struct Sprite *, u8);
u32 __attribute__((long_call)) StartFieldEffectForObjectEvent(u8, struct ObjectEvent *);
u8 __attribute__((long_call)) FindTallGrassFieldEffectSpriteId(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);
void __attribute__((long_call)) ShowWarpArrowSprite(u8 spriteId, u8 direction, s16 x, s16 y);
void __attribute__((long_call)) SetSpriteInvisible(u8 spriteId);
void __attribute__((long_call)) SetSurfBlob_PlayerOffset(u8 spriteId, bool8 hasOffset, s16 offset);
void __attribute__((long_call)) UpdateJumpImpactEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateShadowFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateBubblesFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateSparkleFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateTallGrassFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) WaitFieldEffectSpriteAnim(struct Sprite *sprite);
void __attribute__((long_call)) UpdateAshFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateSurfBlobFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateFootprintsTireTracksFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateSplashFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateShortGrassFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateLongGrassFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateSandPileFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateDisguiseFieldEffect(struct Sprite *sprite);
void __attribute__((long_call)) UpdateHotSpringsWaterFieldEffect(struct Sprite *sprite);

#endif //GUARD_FIELD_EFFECT_HELPERS_H
