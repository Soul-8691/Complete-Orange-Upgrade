#ifndef GUARD_PARTY_MENU_H
#define GUARD_PARTY_MENU_H

#include "main.h"
#include "task.h"
#include "constants/party_menu.h"

struct PartyMenu
{
    MainCallback exitCallback;
    TaskFunc task;
    u8 menuType:4;
    u8 layout:2;
    u8 chooseMonsBattleType:2;
    s8 slotId;
    s8 slotId2;
    u8 action;
    u16 bagItem;
    s16 data1;           // used variously as a moveId, counter, moveSlotId, or cursorPos
    s16 learnMoveState;
};

extern struct PartyMenu gPartyMenu;
extern bool8 __attribute__((long_call)) gPartyMenuUseExitCallback;
extern u8 __attribute__((long_call)) gSelectedMonPartyId;
extern MainCallback gPostMenuFieldCallback;
extern u8 __attribute__((long_call)) gSelectedOrderFromParty[3];
extern u8 __attribute__((long_call)) gBattlePartyCurrentOrder[PARTY_SIZE / 2];

extern void (*gItemUseCB)(u8, TaskFunc);

void __attribute__((long_call)) InitPartyMenu(u8 menuType, u8 layout, u8 partyAction, bool8 keepCursorPos, u8 messageId, TaskFunc task, MainCallback callback);
void __attribute__((long_call)) AnimatePartySlot(u8 slot, u8 animNum);
bool8 __attribute__((long_call)) IsMultiBattle(void);
u8 __attribute__((long_call)) GetCursorSelectionMonId(void);
u8 __attribute__((long_call)) GetPartyMenuType(void);
void __attribute__((long_call)) Task_HandleChooseMonInput(u8 taskId);
u8* __attribute__((long_call)) GetMonNickname(struct Pokemon *mon, u8 *dest);
u8 __attribute__((long_call)) DisplayPartyMenuMessage(const u8 *str, bool8 keepOpen);
bool8 __attribute__((long_call)) IsPartyMenuTextPrinterActive(void);
void __attribute__((long_call)) PartyMenuModifyHP(u8 taskId, u8 slot, s8 hpIncrement, s16 hpDifference, TaskFunc task);
u8 __attribute__((long_call)) GetAilmentFromStatus(u32 status);
u8 __attribute__((long_call)) GetMonAilment(struct Pokemon *mon);
void __attribute__((long_call)) DisplayPartyMenuStdMessage(u32 stringId);
void __attribute__((long_call)) LoadHeldItemIcons(void);
void __attribute__((long_call)) DrawHeldItemIconsForTrade(u8 *partyCounts, u8 *partySpriteIds, u8 whichParty);
void __attribute__((long_call)) SpriteCB_BounceConfirmCancelButton(u8 spriteId, u8 spriteId2, u8 animNum);
void __attribute__((long_call)) CB2_SelectBagItemToGive(void);
void __attribute__((long_call)) CB2_GiveHoldItem(void);
bool8 __attribute__((long_call)) FieldCallback_PrepareFadeInFromMenu(void);
void __attribute__((long_call)) CB2_ReturnToPartyMenuFromFlyMap(void);
void __attribute__((long_call)) SetUsedFlyQuestLogEvent(const u8 *healLocCtrlData);
void __attribute__((long_call)) CB2_ShowPartyMenuForItemUse(void);
void __attribute__((long_call)) ItemUseCB_Medicine(u8 taskId, TaskFunc func);
void __attribute__((long_call)) ItemUseCB_MedicineStep(u8 taskId, TaskFunc func);
void __attribute__((long_call)) ItemUseCB_TryRestorePP(u8 taskId, TaskFunc func);
void __attribute__((long_call)) ItemUseCB_PPUp(u8 taskId, TaskFunc func);
u16 __attribute__((long_call)) ItemIdToBattleMoveId(u16 item);
u16 __attribute__((long_call)) ItemIdToBattleMoveId_(u16 item);
bool8 __attribute__((long_call)) IsMoveHm(u16 move);
bool8 __attribute__((long_call)) MonKnowsMove(struct Pokemon *mon, u16 move);
void __attribute__((long_call)) ItemUseCB_TMHM(u8 taskId, TaskFunc func);
void __attribute__((long_call)) ItemUseCB_TMHM_(u8 taskId, TaskFunc func);
void __attribute__((long_call)) ItemUseCB_RareCandy(u8 taskId, TaskFunc func);
void __attribute__((long_call)) ItemUseCB_SacredAsh(u8 taskId, TaskFunc func);
void __attribute__((long_call)) ItemUseCB_EvolutionStone(u8 taskId, TaskFunc func);
u8 __attribute__((long_call)) GetItemEffectType(u16 item);
void __attribute__((long_call)) CB2_PartyMenuFromStartMenu(void);
void __attribute__((long_call)) CB2_ChooseMonToGiveItem(void);
void __attribute__((long_call)) ChooseMonToGiveMailFromMailbox(void);
void __attribute__((long_call)) InitChooseMonsForBattle(u8 chooseMonsBattleType);
void __attribute__((long_call)) ClearSelectedPartyOrder(void);
void __attribute__((long_call)) ChooseMonForTradingBoard(u8 menuType, MainCallback callback);
void __attribute__((long_call)) ChooseMonForMoveTutor(void);
void __attribute__((long_call)) ChooseMonForWirelessMinigame(void);
void __attribute__((long_call)) OpenPartyMenuInTutorialBattle(u8 partyAction);
void __attribute__((long_call)) Pokedude_OpenPartyMenuInBattle(void);
void __attribute__((long_call)) Pokedude_ChooseMonForInBattleItem(void);
void __attribute__((long_call)) EnterPartyFromItemMenuInBattle(void);
void __attribute__((long_call)) BufferBattlePartyCurrentOrder(void);
void __attribute__((long_call)) BufferBattlePartyCurrentOrderBySide(u8 battlerId, u8 flankId);
void __attribute__((long_call)) SwitchPartyOrderLinkMulti(u8 battlerId, u8 slot, u8 slot2);
void __attribute__((long_call)) SwitchPartyMonSlots(u8 slot, u8 slot2);
u8 __attribute__((long_call)) GetPartyIdFromBattlePartyId(u8 battlePartyId);
void __attribute__((long_call)) ShowPartyMenuToShowcaseMultiBattleParty(void);
void __attribute__((long_call)) ChooseMonForDaycare(void);
void __attribute__((long_call)) ChoosePartyMonByMenuType(u8 menuType);

#define MENU_SUMMARY 0
#define MENU_SWITCH 1
#define MENU_CANCEL1 2
#define MENU_ITEM 3
#define MENU_GIVE 4
#define MENU_TAKE_ITEM 5
#define MENU_MAIL 6
#define MENU_TAKE_MAIL 7
#define MENU_READ 8
#define MENU_CANCEL2 9
#define MENU_SHIFT 10
#define MENU_SEND_OUT 11
#define MENU_ENTER 12
#define MENU_NO_ENTRY 13
#define MENU_STORE 14
#define MENU_REGISTER 15
#define MENU_TRADE1 16
#define MENU_TRADE2 17
#define MENU_MOVE_ITEM 18
#define MENU_FIELD_MOVES 19

#endif // GUARD_PARTY_MENU_H
