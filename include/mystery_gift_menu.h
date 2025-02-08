#ifndef GUARD_MYSTERY_GIFT_MENU_H
#define GUARD_MYSTERY_GIFT_MENU_H

extern bool8 gGiftIsFromEReader;

bool32 __attribute__((long_call)) PrintMysteryGiftMenuMessage(u8 * cmdPtr, const u8 * src);
void __attribute__((long_call)) AddTextPrinterToWindow1(const u8 *str);
void __attribute__((long_call)) MainCB_FreeAllBuffersAndReturnToInitTitleScreen(void);
void __attribute__((long_call)) PrintMysteryGiftOrEReaderTopMenu(bool8, bool32);
void __attribute__((long_call)) CB2_InitMysteryGift(void);
void __attribute__((long_call)) CB2_MysteryGiftEReader(void);
s8 DoMysteryGiftYesNo(u8 * textState, u16 * windowId, bool8 yesNoBoxPlacement, const u8 * str);
void __attribute__((long_call)) MG_DrawTextBorder(u8 windowId);
u16 __attribute__((long_call)) GetMysteryGiftBaseBlock(void);

#endif //GUARD_MYSTERY_GIFT_MENU_H
