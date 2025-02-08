#ifndef GUARD_BAG_H
#define GUARD_BAG_H

#include "menu_helpers.h"

void __attribute__((long_call)) InitBagWindows(void);
void __attribute__((long_call)) BagPrintTextOnWindow(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx);
void __attribute__((long_call)) BagPrintTextOnWin1CenteredColor0(const u8 * str, u8 unused);
void __attribute__((long_call)) BagDrawDepositItemTextBox(void);
u8 __attribute__((long_call)) ShowBagWindow(u8 whichWindow, u8 nItems);
void __attribute__((long_call)) HideBagWindow(u8 whichWindow);
u8 __attribute__((long_call)) OpenBagWindow(u8 whichWindow);
void __attribute__((long_call)) CloseBagWindow(u8 whichWindow);
u8 __attribute__((long_call)) GetBagWindow(u8 whichWindow);
void __attribute__((long_call)) BagCreateYesNoMenuBottomRight(u8 taskId, const struct YesNoFuncTable * ptrs);
void __attribute__((long_call)) BagCreateYesNoMenuTopRight(u8 taskId, const struct YesNoFuncTable * ptrs);
void __attribute__((long_call)) BagPrintMoneyAmount(void);
void __attribute__((long_call)) BagDrawTextBoxOnWindow(u8 windowId);

#endif //GUARD_BAG_H
