#ifndef GUARD_SHOP_H
#define GUARD_SHOP_H

#include "global.h"
#include "menu_helpers.h"

#define INDEX_CANCEL -2

void __attribute__((long_call)) CreatePokemartMenu(const u16 *itemsForSale);
void __attribute__((long_call)) CreateDecorationShop1Menu(const u16 *);
void __attribute__((long_call)) CreateDecorationShop2Menu(const u16 *);
u8 __attribute__((long_call)) GetMartFontId(void);
void __attribute__((long_call)) RecordItemTransaction(u16 itemId, u16 quantity, u8 logEventId);

// buy_menu_helper
void __attribute__((long_call)) BuyMenuInitWindows(bool32 isSellingTM);
void __attribute__((long_call)) BuyMenuDrawMoneyBox(void);
void __attribute__((long_call)) BuyMenuPrint(u8 windowId, u8 font, const u8 *text, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 color);
void __attribute__((long_call)) BuyMenuDisplayMessage(u8 taskId, const u8 *text, TaskFunc callback);
void __attribute__((long_call)) BuyMenuQuantityBoxNormalBorder(u8 windowId, bool8 copyToVram);
void __attribute__((long_call)) BuyMenuQuantityBoxThinBorder(u8 windowId, bool8 copyToVram);
void __attribute__((long_call)) BuyMenuConfirmPurchase(u8 taskId, const struct YesNoFuncTable *yesNo);

#endif // GUARD_SHOP_H
