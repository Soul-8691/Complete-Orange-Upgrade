#ifndef GUARD_HELP_SYSTEM_H
#define GUARD_HELP_SYSTEM_H

#include "global.h"
#include "list_menu.h"
#include "blit.h"
#include "constants/help_system.h"

struct HelpSystemListMenu_sub
{
    struct ListMenuItem * items;
    u16 totalItems;
    u16 maxShowed;
    u8 left;
    u8 top;
};

struct HelpSystemListMenu
{
    struct HelpSystemListMenu_sub sub;
    u8 itemsAbove;
    u8 cursorPos;
    u8 state;
    u8 filler_10[0xC];
};

extern struct HelpSystemListMenu gHelpSystemListMenu;
extern struct ListMenuItem gHelpSystemListMenuItems[];
extern bool8 gHelpSystemEnabled;
extern bool8 gHelpSystemToggleWithRButtonDisabled;

// help_system_812B1E0
void __attribute__((long_call)) SetHelpContextDontCheckBattle(u8);
void __attribute__((long_call)) SetHelpContextForMap(void);
void __attribute__((long_call)) SetHelpContext(u8);
bool8 __attribute__((long_call)) HelpSystem_UpdateHasntSeenIntro(void);
bool8 __attribute__((long_call)) HelpSystem_IsSinglePlayer(void);
void __attribute__((long_call)) HelpSystem_Disable(void);
void __attribute__((long_call)) HelpSystem_Enable(void);
void __attribute__((long_call)) HelpSystem_EnableToggleWithRButton(void);
bool8 __attribute__((long_call)) RunHelpMenuSubroutine(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpSystemSubroutine_PrintWelcomeMessage(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpSystemSubroutine_WelcomeWaitButton(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpSystemSubroutine_WelcomeEndGotoMenu(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpSystemSubroutine_MenuInputHandlerMain(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpMenuSubroutine_InitSubmenu(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpMenuSubroutine_ReturnFromSubmenu(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpMenuSubroutine_SubmenuInputHandler(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
void __attribute__((long_call)) HelpSystem_PrintTopicLabel(void);
bool8 __attribute__((long_call)) HelpMenuSubroutine_HelpItemPrint(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpMenuSubroutine_ReturnFromHelpItem(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) HelpMenuSubroutine_HelpItemWaitButton(struct HelpSystemListMenu * helpListMenu, struct ListMenuItem * listMenuItemsBuffer);
bool8 __attribute__((long_call)) GetHelpSystemMenuLevel(void);

// help_system
bool8 __attribute__((long_call)) RunHelpSystemCallback(void);
void __attribute__((long_call)) SaveCallbacks(void);
void __attribute__((long_call)) SaveMapGPURegs(void);
void __attribute__((long_call)) SaveMapTiles(void);
void __attribute__((long_call)) SaveMapTextColors(void);
void __attribute__((long_call)) RestoreCallbacks(void);
void __attribute__((long_call)) RestoreGPURegs(void);
void __attribute__((long_call)) RestoreMapTiles(void);
void __attribute__((long_call)) RestoreMapTextColors(void);
void __attribute__((long_call)) CommitTilemap(void);
void __attribute__((long_call)) HS_BufferFillMapWithTile1FF(void);
void __attribute__((long_call)) HS_ShowOrHideWordHELPinTopLeft(u8 mode);
void __attribute__((long_call)) HS_ShowOrHideControlsGuideInTopRight(u8 mode);
void __attribute__((long_call)) HS_ShowOrHideMainWindowText(u8 mode);
void __attribute__((long_call)) HS_SetMainWindowBgBrightness(u8 mode);
void __attribute__((long_call)) HS_ShowOrHideToplevelTooltipWindow(u8 mode);
void __attribute__((long_call)) HS_ShowOrHideHeaderAndFooterLines_Lighter(u8 mode);
void __attribute__((long_call)) HS_ShowOrHideHeaderAndFooterLines_Darker(u8 mode);
void __attribute__((long_call)) HS_ShowOrHideVerticalBlackBarsAlongSides(u8 mode);
void __attribute__((long_call)) HS_ShowOrHideHeaderLine_Darker_FooterStyle(u8 mode);
void __attribute__((long_call)) HS_ShowOrHideScrollArrows(u8 which, u8 mode);
void __attribute__((long_call)) HelpSystem_PrintTextRightAlign_Row52(const u8 *str);
void __attribute__((long_call)) HelpSystem_PrintTextAt(const u8 *, u8, u8);
void __attribute__((long_call)) HelpSystem_PrintQuestionAndAnswerPair(const u8 *a0, const u8 *a1);
void __attribute__((long_call)) HelpSystem_PrintTopicMouseoverDescription(const u8 *str);
void __attribute__((long_call)) HelpSystem_FillPanel2(void);
void __attribute__((long_call)) HelpSystem_FillPanel1(void);
void __attribute__((long_call)) HelpSystem_InitListMenuController(struct HelpSystemListMenu *, u8, u8);
void __attribute__((long_call)) HelpSystem_SetInputDelay(u8);
s32 HelpSystem_GetMenuInput(void);
void __attribute__((long_call)) HS_UpdateMenuScrollArrows(void);

void __attribute__((long_call)) DecompressAndRenderGlyph(u8 fontId, u16 glyph, struct Bitmap *srcBlit, struct Bitmap *destBlit, u8 *destBuffer, u8 x, u8 y, u8 width, u8 height);
void __attribute__((long_call)) HelpSystem_PrintTextInTopLeftCorner(const u8 * str);
void __attribute__((long_call)) HelpSystem_FillPanel3(void);
void __attribute__((long_call)) PrintListMenuItems(void);
void __attribute__((long_call)) PlaceListMenuCursor(void);
bool8 __attribute__((long_call)) MoveCursor(u8 by, u8 dirn);
void __attribute__((long_call)) BackupHelpContext(void);
void __attribute__((long_call)) RestoreHelpContext(void);
void __attribute__((long_call)) HelpSystemRenderText(u8 fontId, u8 * dest, const u8 * src, u8 x, u8 y, u8 width, u8 height);
void __attribute__((long_call)) HelpSystem_DisableToggleWithRButton(void);

#endif //GUARD_HELP_SYSTEM_H
