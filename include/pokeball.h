#ifndef GUARD_POKEBALL_H
#define GUARD_POKEBALL_H

#include "global.h"

enum
{
    BALL_POKE,
    BALL_GREAT,
    BALL_SAFARI,
    BALL_ULTRA,
    BALL_MASTER,
    BALL_NET,
    BALL_DIVE,
    BALL_NEST,
    BALL_REPEAT,
    BALL_TIMER,
    BALL_LUXURY,
    BALL_PREMIER,
    POKEBALL_COUNT
};

enum {
    BALL_AFFINE_ANIM_0,
    BALL_ROTATE_RIGHT,
    BALL_ROTATE_LEFT,
    BALL_AFFINE_ANIM_3,
    BALL_AFFINE_ANIM_4
};

extern const struct CompressedSpriteSheet gBallSpriteSheets[POKEBALL_COUNT];
extern const struct CompressedSpritePalette gBallSpritePalettes[POKEBALL_COUNT];
extern const struct SpriteTemplate gBallSpriteTemplates[];

#define POKEBALL_PLAYER_SENDOUT     0xFF
#define POKEBALL_OPPONENT_SENDOUT   0xFE

u8 __attribute__((long_call)) DoPokeballSendOutAnimation(s16 pan, u8 kindOfThrow);
void __attribute__((long_call)) CreatePokeballSpriteToReleaseMon(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subpriortiy, u8 delay, u32 fadePalettes);
u8 __attribute__((long_call)) CreateTradePokeballSprite(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subPriority, u8 delay, u32 fadePalettes);
void __attribute__((long_call)) DoHitAnimHealthboxEffect(u8 bank);
void __attribute__((long_call)) LoadBallGfx(u8 ballId);
void __attribute__((long_call)) FreeBallGfx(u8 ballId);
void __attribute__((long_call)) StartHealthboxSlideIn(u8 battler);
void __attribute__((long_call)) DestroySpriteAndFreeResources_Ball(struct Sprite *sprite);

#endif // GUARD_POKEBALL_H
