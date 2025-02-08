#ifndef GUARD_BATTLE_ANIM_H
#define GUARD_BATTLE_ANIM_H

#include "battle.h"
#include "data.h"
#include "task.h"
#include "constants/battle_anim.h"

enum
{
    BG_ANIM_SCREEN_SIZE,
    BG_ANIM_AREA_OVERFLOW_MODE,
    BG_ANIM_MOSAIC,
    BG_ANIM_CHAR_BASE_BLOCK,
    BG_ANIM_PRIORITY,
    BG_ANIM_PALETTES_MODE,
    BG_ANIM_SCREEN_BASE_BLOCK
};

enum
{
    BATTLER_COORD_X,
    BATTLER_COORD_Y,
    BATTLER_COORD_X_2,
    BATTLER_COORD_Y_PIC_OFFSET,
    BATTLER_COORD_Y_PIC_OFFSET_DEFAULT,
};

enum
{
    BATTLER_COORD_ATTR_HEIGHT,
    BATTLER_COORD_ATTR_WIDTH,
    BATTLER_COORD_ATTR_TOP,
    BATTLER_COORD_ATTR_BOTTOM,
    BATTLER_COORD_ATTR_LEFT,
    BATTLER_COORD_ATTR_RIGHT,
    BATTLER_COORD_ATTR_RAW_BOTTOM,
};

// battle_anim_status_effects.s
#define STAT_ANIM_PLUS1  15
#define STAT_ANIM_PLUS2  39
#define STAT_ANIM_MINUS1 22
#define STAT_ANIM_MINUS2 46
#define STAT_ANIM_MULTIPLE_PLUS1 55
#define STAT_ANIM_MULTIPLE_PLUS2 56
#define STAT_ANIM_MULTIPLE_MINUS1 57
#define STAT_ANIM_MULTIPLE_MINUS2 58

struct BattleAnimBgData
{
    u8 *bgTiles;
    u16 *bgTilemap;
    u8 paletteId;
    u8 bgId;
    u16 tilesOffset;
    u16 unused;
};

struct BattleAnimBackground
{
    const u32 *image;
    const u32 *palette;
    const u32 *tilemap;
};

#define ANIM_ARGS_COUNT 8

// Linear Translation
#define sTransl_Speed    data[0]
#define sTransl_Duration data[0] // for Fast
#define sTransl_InitX    data[1]
#define sTransl_DestX    data[2]
#define sTransl_InitY    data[3]
#define sTransl_DestY    data[4]
#define sTransl_ArcAmpl  data[5]

extern void (*gAnimScriptCallback)(void);
extern bool8 __attribute__((long_call)) gAnimScriptActive;
extern u8 __attribute__((long_call)) gAnimVisualTaskCount;
extern u8 __attribute__((long_call)) gAnimSoundTaskCount;
extern struct DisableStruct *gAnimDisableStructPtr;
extern u16 __attribute__((long_call)) gAnimMovePower;
extern u8 __attribute__((long_call)) gAnimFriendship;
extern u16 __attribute__((long_call)) gWeatherMoveAnim;
extern s16 __attribute__((long_call)) gBattleAnimArgs[ANIM_ARGS_COUNT];
extern u8 __attribute__((long_call)) gAnimMoveTurn;
extern u8 __attribute__((long_call)) gBattleAnimAttacker;
extern u8 __attribute__((long_call)) gBattleAnimTarget;
extern u8 __attribute__((long_call)) gBattlerSpriteIds[MAX_BATTLERS_COUNT];
extern s32 __attribute__((long_call)) gAnimMoveDmg;
extern u16 __attribute__((long_call)) gAnimBattlerSpecies[MAX_BATTLERS_COUNT];
extern u8 __attribute__((long_call)) gAnimCustomPanning;

extern const struct OamData gOamData_AffineOff_ObjNormal_8x8;
extern const struct OamData gOamData_AffineOff_ObjNormal_16x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_64x64;
extern const struct OamData gOamData_AffineOff_ObjNormal_16x8;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x8;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_64x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_8x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_8x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_16x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x64;
extern const struct OamData gOamData_AffineNormal_ObjNormal_8x8;
extern const struct OamData gOamData_AffineNormal_ObjNormal_16x16;
extern const struct OamData gOamData_AffineNormal_ObjNormal_32x32;
extern const struct OamData gOamData_AffineNormal_ObjNormal_64x64;
extern const struct OamData gOamData_AffineNormal_ObjNormal_16x8;
extern const struct OamData gOamData_AffineNormal_ObjNormal_32x8;
extern const struct OamData gOamData_AffineNormal_ObjNormal_32x16;
extern const struct OamData gOamData_AffineNormal_ObjNormal_64x32;
extern const struct OamData gOamData_AffineNormal_ObjNormal_8x16;
extern const struct OamData gOamData_AffineNormal_ObjNormal_8x32;
extern const struct OamData gOamData_AffineNormal_ObjNormal_16x32;
extern const struct OamData gOamData_AffineNormal_ObjNormal_32x64;
extern const struct OamData gOamData_AffineDouble_ObjNormal_8x8;
extern const struct OamData gOamData_AffineDouble_ObjNormal_16x16;
extern const struct OamData gOamData_AffineDouble_ObjNormal_32x32;
extern const struct OamData gOamData_AffineDouble_ObjNormal_64x64;
extern const struct OamData gOamData_AffineDouble_ObjNormal_16x8;
extern const struct OamData gOamData_AffineDouble_ObjNormal_32x8;
extern const struct OamData gOamData_AffineDouble_ObjNormal_32x16;
extern const struct OamData gOamData_AffineDouble_ObjNormal_64x32;
extern const struct OamData gOamData_AffineDouble_ObjNormal_8x16;
extern const struct OamData gOamData_AffineDouble_ObjNormal_8x32;
extern const struct OamData gOamData_AffineDouble_ObjNormal_16x32;
extern const struct OamData gOamData_AffineDouble_ObjNormal_32x64;
extern const struct OamData gOamData_AffineOff_ObjBlend_8x8;
extern const struct OamData gOamData_AffineOff_ObjBlend_16x16;
extern const struct OamData gOamData_AffineOff_ObjBlend_32x32;
extern const struct OamData gOamData_AffineOff_ObjBlend_64x64;
extern const struct OamData gOamData_AffineOff_ObjBlend_16x8;
extern const struct OamData gOamData_AffineOff_ObjBlend_32x8;
extern const struct OamData gOamData_AffineOff_ObjBlend_32x16;
extern const struct OamData gOamData_AffineOff_ObjBlend_64x32;
extern const struct OamData gOamData_AffineOff_ObjBlend_8x16;
extern const struct OamData gOamData_AffineOff_ObjBlend_8x32;
extern const struct OamData gOamData_AffineOff_ObjBlend_16x32;
extern const struct OamData gOamData_AffineOff_ObjBlend_32x64;
extern const struct OamData gOamData_AffineNormal_ObjBlend_8x8;
extern const struct OamData gOamData_AffineNormal_ObjBlend_16x16;
extern const struct OamData gOamData_AffineNormal_ObjBlend_32x32;
extern const struct OamData gOamData_AffineNormal_ObjBlend_64x64;
extern const struct OamData gOamData_AffineNormal_ObjBlend_16x8;
extern const struct OamData gOamData_AffineNormal_ObjBlend_32x8;
extern const struct OamData gOamData_AffineNormal_ObjBlend_32x16;
extern const struct OamData gOamData_AffineNormal_ObjBlend_64x32;
extern const struct OamData gOamData_AffineNormal_ObjBlend_8x16;
extern const struct OamData gOamData_AffineNormal_ObjBlend_8x32;
extern const struct OamData gOamData_AffineNormal_ObjBlend_16x32;
extern const struct OamData gOamData_AffineNormal_ObjBlend_32x64;
extern const struct OamData gOamData_AffineDouble_ObjBlend_8x8;
extern const struct OamData gOamData_AffineDouble_ObjBlend_16x16;
extern const struct OamData gOamData_AffineDouble_ObjBlend_32x32;
extern const struct OamData gOamData_AffineDouble_ObjBlend_64x64;
extern const struct OamData gOamData_AffineDouble_ObjBlend_16x8;
extern const struct OamData gOamData_AffineDouble_ObjBlend_32x8;
extern const struct OamData gOamData_AffineDouble_ObjBlend_32x16;
extern const struct OamData gOamData_AffineDouble_ObjBlend_64x32;
extern const struct OamData gOamData_AffineDouble_ObjBlend_8x16;
extern const struct OamData gOamData_AffineDouble_ObjBlend_8x32;
extern const struct OamData gOamData_AffineDouble_ObjBlend_16x32;
extern const struct OamData gOamData_AffineDouble_ObjBlend_32x64;
extern const struct MonCoords gCastformFrontSpriteCoords[];
extern const struct CompressedSpriteSheet gBattleAnimPicTable[];
extern const struct CompressedSpritePalette gBattleAnimPaletteTable[];
extern const struct SpriteTemplate gFlashingHitSplatSpriteTemplate;
extern const struct SpriteTemplate gBasicHitSplatSpriteTemplate;
extern const struct SpriteTemplate gWaterHitSplatSpriteTemplate;
extern const struct SpriteTemplate gWishStarSpriteTemplate;
extern const struct SpriteTemplate gMiniTwinklingStarSpriteTemplate;
extern const struct SpriteTemplate gThoughtBubbleSpriteTemplate;
extern const union AffineAnimCmd *const gAffineAnims_Bite[];
extern const union AffineAnimCmd *const gAffineAnims_Droplet[];
extern const union AffineAnimCmd *const gGrowingRingAffineAnimTable[];
extern const union AnimCmd *const gAnims_SmallBubblePair[];
extern const union AnimCmd *const gAnims_BasicFire[];
extern const union AnimCmd *const gAnims_WaterMudOrb[];
extern const union AnimCmd *const gAnims_WaterBubble[];
extern const union AnimCmd *const gMusicNotesAnimTable[];
extern const u8 *const gBattleAnims_StatusConditions[];
extern const u8 *const gBattleAnims_Moves[];
extern const u16 gMovesWithQuietBGM[];

void __attribute__((long_call)) MoveBattlerSpriteToBG(u8 battlerId, u8);
void __attribute__((long_call)) ResetBattleAnimBg(u8);
void __attribute__((long_call)) ClearBattleAnimationVars(void);
void __attribute__((long_call)) DoMoveAnim(u16 move);
void __attribute__((long_call)) LaunchBattleAnimation(const u8 *const animsTable[], u16 tableId, bool8 isMoveAnim);
void __attribute__((long_call)) DestroyAnimSprite(struct Sprite *sprite);
void __attribute__((long_call)) DestroyAnimVisualTask(u8 taskId);
void __attribute__((long_call)) DestroyAnimSoundTask(u8 taskId);
bool8 __attribute__((long_call)) IsContest(void);
s8 __attribute__((long_call)) BattleAnimAdjustPanning(s8 pan);
s8 __attribute__((long_call)) BattleAnimAdjustPanning2(s8 pan);
s16 __attribute__((long_call)) CalculatePanIncrement(s16 sourcePan, s16 targetPan, s16 incrementPan);
bool8 __attribute__((long_call)) IsBattlerSpriteVisible(u8 battlerId);
s16 __attribute__((long_call)) KeepPanInRange(s16 a, s32 oldPan);
void __attribute__((long_call)) RelocateBattleBgPal(u16 paletteNum, u16 *dest, s32 offset, u8 largeScreen);
void __attribute__((long_call)) SetAnimBgAttribute(u8 bgId, u8 attributeId, u8 value);
s32 __attribute__((long_call)) GetAnimBgAttribute(u8 bgId, u8 attributeId);
void __attribute__((long_call)) HandleIntroSlide(u8 terrain);
void __attribute__((long_call)) BattleIntroSlideEnd(u8 taskId);
void __attribute__((long_call)) CopyBattlerSpriteToBg(s32 bgId, u8 x, u8 y, u8 battlerPosition, u8 palno, u8 *tilesDest, u16 *tilemapDest, u16 tilesOffset);
void __attribute__((long_call)) SetSpriteNextToMonHead(u8 battler, struct Sprite* sprite);
void __attribute__((long_call)) TryShinyAnimation(u8 battler, struct Pokemon *mon);
u8 __attribute__((long_call)) ItemIdToBallId(u16 itemId);
u8 __attribute__((long_call)) AnimateBallOpenParticles(u8 x, u8 y, u8 priority, u8 subpriority, u8 ballId);
u8 __attribute__((long_call)) LaunchBallFadeMonTask(bool8 unFadeLater, u8 battlerId, u32 arg2, u8 ballId);
void __attribute__((long_call)) DoLoadHealthboxPalsForLevelUp(u8 *, u8 *, u8 battlerId);
void __attribute__((long_call)) DoFreeHealthboxPalsForLevelUp(u8 batterId);
void __attribute__((long_call)) LaunchStatusAnimation(u8 battlerId, u8 statusAnimId);
u8 __attribute__((long_call)) GetBattlerSpriteCoord(u8 battlerId, u8 coordType);
u8 __attribute__((long_call)) GetBattlerSpriteCoord2(u8 battlerId, u8 coordType);
u8 __attribute__((long_call)) GetBattlerSpriteDefault_Y(u8 battlerId);
u8 __attribute__((long_call)) GetSubstituteSpriteDefault_Y(u8 battlerId);
u8 __attribute__((long_call)) GetGhostSpriteDefault_Y(u8 battlerId);
u8 __attribute__((long_call)) GetBattlerYCoordWithElevation(u8 battlerId);
u8 __attribute__((long_call)) GetAnimBattlerSpriteId(u8 animBattler);
void __attribute__((long_call)) StoreSpriteCallbackInData6(struct Sprite *sprite, SpriteCallback callback);
void __attribute__((long_call)) TranslateSpriteInCircle(struct Sprite *sprite);
void __attribute__((long_call)) TranslateSpriteInGrowingCircle(struct Sprite *sprite);
void __attribute__((long_call)) TranslateSpriteInEllipse(struct Sprite *sprite);
void __attribute__((long_call)) WaitAnimForDuration(struct Sprite *sprite);
void __attribute__((long_call)) ConvertPosDataToTranslateLinearData(struct Sprite *sprite);
void __attribute__((long_call)) TranslateSpriteLinear(struct Sprite *sprite);
void __attribute__((long_call)) TranslateSpriteLinearFixedPoint(struct Sprite *sprite);
void __attribute__((long_call)) TranslateSpriteLinearById(struct Sprite *sprite);
void __attribute__((long_call)) TranslateSpriteLinearByIdFixedPoint(struct Sprite *sprite);
void __attribute__((long_call)) TranslateSpriteLinearAndFlicker(struct Sprite *sprite);
void __attribute__((long_call)) DestroySpriteAndMatrix(struct Sprite *sprite);
void __attribute__((long_call)) RunStoredCallbackWhenAffineAnimEnds(struct Sprite *sprite);
void __attribute__((long_call)) RunStoredCallbackWhenAnimEnds(struct Sprite *sprite);
void __attribute__((long_call)) DestroyAnimSpriteAndDisableBlend(struct Sprite *sprite);
void __attribute__((long_call)) DestroyAnimVisualTaskAndDisableBlend(u8 taskId);
void __attribute__((long_call)) SetSpriteCoordsToAnimAttackerCoords(struct Sprite *sprite);
void __attribute__((long_call)) SetAnimSpriteInitialXOffset(struct Sprite *sprite, s16 xOffset);
void __attribute__((long_call)) InitAnimArcTranslation(struct Sprite *sprite);
bool8 __attribute__((long_call)) TranslateAnimHorizontalArc(struct Sprite *sprite);
bool8 __attribute__((long_call)) TranslateAnimVerticalArc(struct Sprite *sprite);
void __attribute__((long_call)) SetSpritePrimaryCoordsFromSecondaryCoords(struct Sprite *sprite);
void __attribute__((long_call)) InitSpritePosToAnimTarget(struct Sprite *sprite, bool8 respectMonPicOffsets);
void __attribute__((long_call)) InitSpritePosToAnimAttacker(struct Sprite *sprite, bool8 respectMonPicOffsets);
u8 __attribute__((long_call)) GetBattlerSide(u8 battlerId);
u8 __attribute__((long_call)) GetBattlerPosition(u8 battlerId);
u8 __attribute__((long_call)) GetBattlerAtPosition(u8 position);
bool8 __attribute__((long_call)) IsBattlerSpritePresent(u8 battlerId);
bool8 __attribute__((long_call)) IsDoubleBattle(void);
void __attribute__((long_call)) GetBattleAnimBg1Data(struct BattleAnimBgData *animBgData);
void __attribute__((long_call)) GetBattleAnimBgData(struct BattleAnimBgData *animBgData, u32 bgId);
void __attribute__((long_call)) GetBattleAnimBgDataByPriorityRank(struct BattleAnimBgData *animBgData, u8 unused);
void __attribute__((long_call)) InitBattleAnimBg(u32 bgId);
void __attribute__((long_call)) AnimLoadCompressedBgGfx(u32 bgId, const u32 *src, u32 tilesOffset);
void __attribute__((long_call)) InitAnimBgTilemapBuffer(u32 bgId, const void *src);
void __attribute__((long_call)) AnimLoadCompressedBgTilemap(u32 bgId, const u32 *src);
u8 __attribute__((long_call)) GetBattleBgPaletteNum(void);
void __attribute__((long_call)) ToggleBg3Mode(bool8 arg0);
void __attribute__((long_call)) Trade_MoveSelectedMonToTarget(struct Sprite *sprite);
void __attribute__((long_call)) InitSpriteDataForLinearTranslation(struct Sprite *sprite);
void __attribute__((long_call)) InitAnimLinearTranslation(struct Sprite *sprite);
void __attribute__((long_call)) StartAnimLinearTranslation(struct Sprite *sprite);
void __attribute__((long_call)) PlayerThrowBall_StartAnimLinearTranslation(struct Sprite *sprite);
bool8 __attribute__((long_call)) AnimTranslateLinear(struct Sprite *sprite);
void __attribute__((long_call)) AnimTranslateLinear_WithFollowup(struct Sprite *sprite);
void __attribute__((long_call)) InitAnimLinearTranslationWithSpeed(struct Sprite *sprite);
void __attribute__((long_call)) InitAnimLinearTranslationWithSpeedAndPos(struct Sprite *sprite);
void __attribute__((long_call)) InitAndRunAnimFastLinearTranslation(struct Sprite *sprite);
bool8 __attribute__((long_call)) AnimFastTranslateLinear(struct Sprite *sprite);
void __attribute__((long_call)) InitAnimFastLinearTranslationWithSpeed(struct Sprite *sprite);
void __attribute__((long_call)) InitAnimFastLinearTranslationWithSpeedAndPos(struct Sprite *sprite);
void __attribute__((long_call)) SetSpriteRotScale(u8 spriteId, s16 xScale, s16 yScale, u16 rotation);
void __attribute__((long_call)) PrepareBattlerSpriteForRotScale(u8 spriteId, u8 objMode);
void __attribute__((long_call)) ResetSpriteRotScale(u8 spriteId);
void __attribute__((long_call)) SetBattlerSpriteYOffsetFromRotation(u8 spriteId);
void __attribute__((long_call)) TrySetSpriteRotScale(struct Sprite *sprite, bool8 recalcCenterVector, s16 xScale, s16 yScale, u16 rotation);
void __attribute__((long_call)) TryResetSpriteAffineState(struct Sprite *sprite);
u16 __attribute__((long_call)) ArcTan2Neg(s16 a, s16 b);
void __attribute__((long_call)) SetGreyscaleOrOriginalPalette(u16 paletteNum, bool8 restoreOriginalColor);
u32 __attribute__((long_call)) GetBattlePalettesMask(bool8 battleBackground, bool8 attacker, bool8 target, bool8 attackerPartner, bool8 targetPartner, bool8 a6, bool8 a7);
u32 __attribute__((long_call)) GetBattleMonSpritePalettesMask(bool8 playerLeft, bool8 playerRight, bool8 foeLeft, bool8 foeRight);
u8 __attribute__((long_call)) GetSpritePalIdxByBattler(u8 a1);
void __attribute__((long_call)) AnimSpriteOnMonPos(struct Sprite *sprite);
void __attribute__((long_call)) TranslateAnimSpriteToTargetMonLocation(struct Sprite *sprite);
void __attribute__((long_call)) AnimThrowProjectile(struct Sprite *sprite);
void __attribute__((long_call)) AnimTravelDiagonally(struct Sprite *sprite);
s16 __attribute__((long_call)) CloneBattlerSpriteWithBlend(u8 animBattler);
void __attribute__((long_call)) DestroySpriteWithActiveSheet(struct Sprite *sprite);
void __attribute__((long_call)) PrepareAffineAnimInTaskData(struct Task *task, u8 spriteId, const union AffineAnimCmd *affineAnimCmds);
bool8 __attribute__((long_call)) RunAffineAnimFromTaskData(struct Task *task);
void __attribute__((long_call)) SetBattlerSpriteYOffsetFromYScale(u8 spriteId);
void __attribute__((long_call)) SetBattlerSpriteYOffsetFromOtherYScale(u8 spriteId, u8 otherSpriteId);
void __attribute__((long_call)) StorePointerInVars(s16 *lo, s16 *hi, const void *ptr);
void __attribute__((long_call)) *LoadPointerFromVars(s16 lo, s16 hi);
void __attribute__((long_call)) BattleAnimHelper_SetSpriteSquashParams(struct Task *task, u8 spriteId, s16 xScale0, s16 yScale0, s16 xScale1, s16 yScale1, u16 duration);
u8 __attribute__((long_call)) BattleAnimHelper_RunSpriteSquash(struct Task *task);
void __attribute__((long_call)) InitPrioritiesForVisibleBattlers(void);
u8 __attribute__((long_call)) GetBattlerSpriteSubpriority(u8 battlerId);
u8 __attribute__((long_call)) GetBattlerSpriteBGPriority(u8 battlerId);
u8 __attribute__((long_call)) GetBattlerSpriteBGPriorityRank(u8 battlerId);
u8 __attribute__((long_call)) CreateAdditionalMonSpriteForMoveAnim(u16 species, bool8 isBackpic, u8 templateId, s16 x, s16 y, u8 subpriority, u32 personality, u32 trainerId, u32 battlerId, u32 ignoreDeoxys);
void __attribute__((long_call)) DestroySpriteAndFreeResources_(struct Sprite *sprite);
s16 __attribute__((long_call)) GetBattlerSpriteCoordAttr(u8 battlerId, u8 attr);
void __attribute__((long_call)) SetAverageBattlerPositions(u8 battlerId, bool8 respectMonPicOffsets, s16 *x, s16 *y);
u8 __attribute__((long_call)) CreateInvisibleSpriteCopy(s32 battlerId, u8 spriteId, s32 species);
void __attribute__((long_call)) AnimTranslateLinearAndFlicker_Flipped(struct Sprite *sprite);
void __attribute__((long_call)) AnimTranslateLinearAndFlicker(struct Sprite *sprite);
void __attribute__((long_call)) AnimSpinningSparkle(struct Sprite *sprite);
void __attribute__((long_call)) AnimWeatherBallUp(struct Sprite *sprite);
void __attribute__((long_call)) AnimWeatherBallDown(struct Sprite *sprite);
void __attribute__((long_call)) AnimParticleBurst(struct Sprite *);
void __attribute__((long_call)) AnimMoveTwisterParticle(struct Sprite *);
u32 __attribute__((long_call)) UnpackSelectedBattlePalettes(s16 selector);
void __attribute__((long_call)) AnimTask_HorizontalShake(u8 taskId);
void __attribute__((long_call)) DestroyAnimSpriteAfterTimer(struct Sprite *sprite);
void __attribute__((long_call)) AnimWaterPulseRing(struct Sprite *sprite);
u8 __attribute__((long_call)) SmokescreenImpact(s16 x, s16 y, u8 a3);
void __attribute__((long_call)) InitStatsChangeAnimation(u8 taskId);
void __attribute__((long_call)) StartMonScrollingBgMask(u8 taskId, s32 unused, u16 arg2, u8 battler1, u8 arg4, u8 arg5, u8 arg6, u8 arg7, const u32 *gfx, const u32 *tilemap, const u32 *palette);

#endif // GUARD_BATTLE_ANIM_H
