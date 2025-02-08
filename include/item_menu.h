#ifndef GUARD_ITEM_MENU_H
#define GUARD_ITEM_MENU_H

#include "global.h"
#include "task.h"
#include "constants/item_menu.h"

// Exported type declarations

// Exported RAM declarations

struct BagStruct
{
    MainCallback bagCallback;
    u8 location;
    bool8 bagOpen;
    u16 pocket;
    u16 itemsAbove[NUM_BAG_POCKETS_NO_CASES];
    u16 cursorPos[NUM_BAG_POCKETS_NO_CASES];
};

extern struct BagStruct gBagMenuState;

extern u16 gSpecialVar_ItemId;

// Exported ROM declarations
void __attribute__((long_call)) CB2_SetUpReshowBattleScreenAfterMenu(void);
void __attribute__((long_call)) ResetBagCursorPositions(void);
void __attribute__((long_call)) InitPokedudeBag(u8);
void __attribute__((long_call)) CB2_BagMenuFromStartMenu(void);
void __attribute__((long_call)) MoveItemSlotInList(struct ItemSlot * itemSlots_, u32 from, u32 to_);
void __attribute__((long_call)) ItemMenu_StartFadeToExitCallback(u8 taskId);
void __attribute__((long_call)) Bag_BeginCloseWin0Animation(void);
void __attribute__((long_call)) ItemMenu_SetExitCallback(void (*)(void));
void __attribute__((long_call)) DisplayItemMessageInBag(u8 taskId, u8 fontId, const u8 * string, TaskFunc followUpFunc);
void __attribute__((long_call)) Task_ReturnToBagFromContextMenu(u8 taskId);
void __attribute__((long_call)) CB2_BagMenuFromBattle(void);
void __attribute__((long_call)) InitOldManBag(void);
void __attribute__((long_call)) Pocket_CalculateNItemsAndMaxShowed(u8 pocketId);
void __attribute__((long_call)) PocketCalculateInitialCursorPosAndItemsAbove(u8 pocketId);
void __attribute__((long_call)) GoToBagMenu(u8 menuType, u8 pocket, MainCallback callback);
bool8 __attribute__((long_call)) UseRegisteredKeyItemOnField(void);

#endif //GUARD_ITEM_MENU_H
