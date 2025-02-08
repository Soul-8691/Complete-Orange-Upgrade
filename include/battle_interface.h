#ifndef GUARD_BATTLE_INTERFACE_H
#define GUARD_BATTLE_INTERFACE_H

#include "global.h"
#include "battle_controllers.h"

enum
{
    HP_CURRENT,
    HP_MAX
};

enum
{
    HEALTH_BAR,
    EXP_BAR
};

enum
{
    HP_BAR_EMPTY,
    HP_BAR_RED,
    HP_BAR_YELLOW,
    HP_BAR_GREEN,
    HP_BAR_FULL,
};

#define TAG_HEALTHBOX_PLAYER1_TILE              55039
#define TAG_HEALTHBOX_PLAYER2_TILE              55040
#define TAG_HEALTHBOX_OPPONENT1_TILE            55041
#define TAG_HEALTHBOX_OPPONENT2_TILE            55042

#define TAG_HEALTHBAR_PLAYER1_TILE              55044
#define TAG_HEALTHBAR_OPPONENT1_TILE            55045
#define TAG_HEALTHBAR_PLAYER2_TILE              55046
#define TAG_HEALTHBAR_OPPONENT2_TILE            55047

#define TAG_HEALTHBOX_PALS_1                    55049
#define TAG_HEALTHBOX_PALS_2                    55050
#define TAG_HEALTHBOX_SAFARI_TILE               55051
#define TAG_PARTY_SUMMARY_BAR_PLAYER_TILE       55052
#define TAG_PARTY_SUMMARY_BAR_OPPONENT_TILE     55053

#define TAG_PARTY_SUMMARY_BAR_PLAYER_PAL        55056
#define TAG_PARTY_SUMMARY_BAR_OPPONENT_PAL      55057
#define TAG_PARTY_SUMMARY_BALL_PLAYER_PAL       55058
#define TAG_PARTY_SUMMARY_BALL_OPPONENT_PAL     55059
#define TAG_PARTY_SUMMARY_BALL_PLAYER_TILE      55060
#define TAG_PARTY_SUMMARY_BALL_OPPONENT_TILE    55061

#define TAG_HEALTHBOX_PAL                       TAG_HEALTHBOX_PLAYER1_TILE
#define TAG_HEALTHBAR_PAL                       TAG_HEALTHBAR_PLAYER1_TILE

enum
{
    HEALTHBOX_ALL,
    HEALTHBOX_CURRENT_HP,
    HEALTHBOX_MAX_HP,
    HEALTHBOX_LEVEL,
    HEALTHBOX_NICK,
    HEALTHBOX_HEALTH_BAR,
    HEALTHBOX_EXP_BAR,
    HEALTHBOX_UNUSED_7,
    HEALTHBOX_UNUSED_8,
    HEALTHBOX_STATUS_ICON,
    HEALTHBOX_SAFARI_ALL_TEXT,
    HEALTHBOX_SAFARI_BALLS_TEXT
};

void __attribute__((long_call)) Task_HidePartyStatusSummary(u8 taskId);
u8 __attribute__((long_call)) CreateBattlerHealthboxSprites(u8 battlerId);
u8 __attribute__((long_call)) CreateSafariPlayerHealthboxSprites(void);
void __attribute__((long_call)) SetBattleBarStruct(u8 battlerId, u8 healthboxSpriteId, s32 maxVal, s32 currVal, s32 receivedValue);
void __attribute__((long_call)) SetHealthboxSpriteInvisible(u8 healthboxSpriteId);
void __attribute__((long_call)) SetHealthboxSpriteVisible(u8 healthboxSpriteId);
void __attribute__((long_call)) DestoryHealthboxSprite(u8 healthboxSpriteId);
void __attribute__((long_call)) DummyBattleInterfaceFunc(u8 healthboxSpriteId, bool8 isDoubleBattleBankOnly);
void __attribute__((long_call)) UpdateOamPriorityInAllHealthboxes(u8 priority);
void __attribute__((long_call)) InitBattlerHealthboxCoords(u8 battlerId);
void __attribute__((long_call)) UpdateHpTextInHealthbox(u8 healthboxSpriteId, s16 value, u8 maxOrCurrent);
void __attribute__((long_call)) SwapHpBarsWithHpText(void);
u8 __attribute__((long_call)) CreatePartyStatusSummarySprites(u8 battlerId, struct HpAndStatus *partyInfo, u8 isSwitchingMons, bool8 isBattleStart);
void __attribute__((long_call)) UpdateHealthboxAttribute(u8 healthboxSpriteId, struct Pokemon *mon, u8 elementId);
u8 __attribute__((long_call)) GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale);
u8 __attribute__((long_call)) GetHPBarLevel(s16 hp, s16 maxhp);
void __attribute__((long_call)) UpdateNickInHealthbox(u8 spriteId, struct Pokemon *mon);
void __attribute__((long_call)) TryAddPokeballIconToHealthbox(u8 spriteId, u8);
s32 __attribute__((long_call)) MoveBattleBar(u8 battler, u8 healthboxSpriteId, u8 whichBar, u8 arg3);

#endif // GUARD_BATTLE_INTERFACE_H
