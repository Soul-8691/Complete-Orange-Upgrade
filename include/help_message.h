#ifndef GUARD_HELP_MESSAGE_H
#define GUARD_HELP_MESSAGE_H

extern const u8 gHelpMessageWindow_Gfx[];

void __attribute__((long_call)) DestroyHelpMessageWindow(u8 a0);
u8 __attribute__((long_call)) CreateHelpMessageWindow(void);
void __attribute__((long_call)) PrintTextOnHelpMessageWindow(const u8 * text, u8 mode);
void __attribute__((long_call)) MapNamePopupWindowIdSetDummy(void);
void __attribute__((long_call)) DrawHelpMessageWindowTilesById(u8 windowId);

#endif //GUARD_HELP_MESSAGE_H
