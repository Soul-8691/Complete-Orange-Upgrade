#include "../include/global.h"
#include "../include/malloc.h"
#include "../include/bg.h"
#include "../include/decompress.h"
#include "../include/gpu_regs.h"
#include "../include/palette.h"
#include "../include/graphics.h"
#include "../include/task.h"
#include "../include/text.h"
#include "../include/text_window.h"
#include "../include/menu.h"
#include "../include/menu_helpers.h"
#include "../include/new_menu_helpers.h"
#include "../include/list_menu.h"
#include "../include/item.h"
#include "../include/item_menu.h"
#include "../include/link.h"
#include "../include/money.h"
#include "../include/shop.h"
#include "../include/teachy_tv.h"
#include "../include/pokemon_storage_system.h"
#include "../include/string_util.h"
#include "../include/party_menu.h"
#include "../include/data.h"
#include "../include/scanline_effect.h"
#include "../include/sound.h"
#include "../include/strings.h"
#include "../include/menu_indicators.h"
#include "../include/constants/items.h"
#include "../include/constants/songs.h"

#include "../include/event_data.h"

extern void __attribute__((long_call)) RemoveContextMenu(u8 * windowId);
extern void __attribute__((long_call)) PrintError_ThereIsNoPokemon(u8 taskId);
extern void __attribute__((long_call)) Task_BeginFadeOutFromTMCase(u8 taskId);
extern void __attribute__((long_call)) PrintError_ItemCantBeHeld(u8 taskId);
extern void __attribute__((long_call)) PrintListCursor(u8 listTaskId, u8 colorIdx);
extern void __attribute__((long_call)) ReturnToList(u8 taskId);
extern void __attribute__((long_call)) PlaceHMTileInWindow(u8 windowId, u8 x, u8 y);
extern void __attribute__((long_call)) TMCase_SetWindowBorder1(u8 windowId);
extern void __attribute__((long_call)) TMCase_SetWindowBorder2(u8 windowId);
extern const u8 sText_ClearTo18[];
extern const u8 sText_SingleSpace[];

enum {
    COLOR_LIGHT,
    COLOR_DARK,
    COLOR_CURSOR_SELECTED,
    COLOR_MOVE_INFO,
    COLOR_CURSOR_ERASE = 0xFF
};

static const u8 sTextColors[][3] = {
    [COLOR_LIGHT] = {0, 1, 2},
    [COLOR_DARK] = {0, 2, 3},
    [COLOR_CURSOR_SELECTED] = {0, 3, 6},
    [COLOR_MOVE_INFO] = {0, 14, 10},
};

static const struct OamData sTMSpriteOamData = {
    .size = 2,
    .priority = 2
};

// The "dynamic" resources will be reset any time the TM case is exited, even temporarily.
extern struct {
    void (* nextScreenCallback)(void);
    u8 discSpriteId;
    u8 maxTMsShown;
    u8 numTMs;
    u8 contextMenuWindowId;
    u8 scrollArrowsTaskId;
    u16 currItem;
    const u8 * menuActionIndices;
    u8 numMenuActions;
    s16 seqId;
    u8 unused[8];
} * sTMCaseDynamicResources;

// IDs for the actions in the context menu
enum {
    ACTION_USE,
    ACTION_GIVE,
    ACTION_EXIT
};

static const u8 sMenuActionIndices_Field[] = {ACTION_USE, ACTION_GIVE, ACTION_EXIT};
static const u8 sMenuActionIndices_UnionRoom[] = {ACTION_GIVE, ACTION_EXIT};

// Base position for TM/HM disc sprite
#define DISC_BASE_X 41
#define DISC_BASE_Y 46

#define DISC_CASE_DISTANCE 20 // The total number of pixels a disc travels vertically in/out of the case
#define DISC_Y_MOVE 10 // The number of pixels a disc travels vertically per movement step

#define TAG_DISC 400

#define DISC_HIDDEN 0xFF // When no TM/HM is selected, hide the disc sprite

enum {
    WIN_LIST,
    WIN_DESCRIPTION,
    WIN_SELECTED_MSG,
    WIN_TITLE,
    WIN_MOVE_INFO_LABELS,
    WIN_MOVE_INFO,
    WIN_MESSAGE,
    WIN_SELL_QUANTITY,
    WIN_MONEY,
};

#define tListTaskId       data[0]
#define tSelection        data[1]

extern void __attribute__((long_call)) Action_Use(u8 taskId);

#define IS_HM(itemId) (gSpecialVar_ItemId >= ITEM_HM01 && gSpecialVar_ItemId <= ITEM_HM08)

extern void __attribute__((long_call)) Action_Give(u8 taskId);

extern void __attribute__((long_call)) Action_Exit(u8 taskId);

static const struct MenuAction sMenuActions_UseGiveExit[] = {
    [ACTION_USE]  = {gOtherText_Use,  Action_Use },
    [ACTION_GIVE] = {gOtherText_Give, Action_Give},
    [ACTION_EXIT] = {gOtherText_Exit, Action_Exit},
};

extern void __attribute__((long_call)) Task_ContextMenu_HandleInput(u8 taskId);

enum {
    ANIM_TM,
    ANIM_HM,
};

static const union AnimCmd sAnim_TM[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HM[] = {
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Disc[] = {
    [ANIM_TM] = sAnim_TM,
    [ANIM_HM] = sAnim_HM
};

void GetTMNumberAndMoveString_(u8 * dest, u16 itemId)
{
    StringCopy(gStringVar4, gText_FontSmall);
    if (itemId >= ITEM_HM01 && itemId <= ITEM_HM08)
    {
        u8 hmDigits = 1;
        if (NUM_HIDDEN_MACHINES >= 10)
            hmDigits = 2;
        
        StringAppend(gStringVar4, sText_ClearTo18);
        StringAppend(gStringVar4, gText_NumberClear01);
        ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_HM01 + 1, STR_CONV_MODE_LEADING_ZEROS, hmDigits);
        StringAppend(gStringVar4, gStringVar1);
    }
    else
    {
        u8 tmDigits = 2;
        if (NUM_TECHNICAL_MACHINES >= 100)
            tmDigits = 3;
        
        StringAppend(gStringVar4, gText_NumberClear01);
        if (itemId <= ITEM_TM50) ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_TM01 + 1, STR_CONV_MODE_LEADING_ZEROS, tmDigits);
        else ConvertIntToDecimalStringN(gStringVar1, itemId - 326 + 1, STR_CONV_MODE_LEADING_ZEROS, tmDigits);
        StringAppend(gStringVar4, gStringVar1);
    }
    
    StringAppend(gStringVar4, sText_SingleSpace);
    StringAppend(gStringVar4, gText_FontNormal);
    StringAppend(gStringVar4, gMoveNames[ItemIdToBattleMoveId_(itemId)]);
    StringCopy(dest, gStringVar4);
}

extern void __attribute__((long_call)) TMCase_Print(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx);

void TMCase_ItemPrintFunc(u8 windowId, s32 itemId, u8 y)
{
    bool8 isHm = FALSE;
    bool8 showQuantity = TRUE;
    
    if (itemId != -2)
    {
        if (BagGetItemIdByPocketPosition(POCKET_TM_CASE, itemId) >= ITEM_HM01 && BagGetItemIdByPocketPosition(POCKET_TM_CASE, itemId) <= ITEM_HM08)
            isHm = TRUE;
        
		#ifdef REUSABLE_TMS
            showQuantity = FALSE;
		#endif
        
        if (!isHm)
        {
            if (showQuantity)
            {
                ConvertIntToDecimalStringN(gStringVar1, BagGetQuantityByPocketPosition(POCKET_TM_CASE, itemId), STR_CONV_MODE_RIGHT_ALIGN, 3);
                StringExpandPlaceholders(gStringVar4, gText_TimesStrVar1);
                TMCase_Print(windowId, 0, gStringVar4, 0x7E, y, 0, 0, 0xFF, 1);
            }
        }
        else
        {
            PlaceHMTileInWindow(windowId, 8, y);
        }
    }
}

static const struct WindowTemplate sTMContextWindowTemplates[] = {
    {0x01, 0x16, 0x0d, 0x07, 0x06, 0x0f, 0x01cf},
    {0x01, 0x16, 0x0f, 0x07, 0x04, 0x0f, 0x01cf}
};

extern u8 __attribute__((long_call)) AddContextMenu(u8 * a0, u8 a1);

#define TM_CASE_TM_TAG 400

static const u16 sTMSpritePaletteOffsetByType[] = {
    [TYPE_NORMAL]   = 0x000,
    [TYPE_FIRE]     = 0x010,
    [TYPE_WATER]    = 0x020,
    [TYPE_GRASS]    = 0x030,
    [TYPE_ELECTRIC] = 0x040,
    [TYPE_ROCK]     = 0x050,
    [TYPE_GROUND]   = 0x060,
    [TYPE_ICE]      = 0x070,
    [TYPE_FLYING]   = 0x080,
    [TYPE_FIGHTING] = 0x090,
    [TYPE_GHOST]    = 0x0a0,
    [TYPE_BUG]      = 0x0b0,
    [TYPE_POISON]   = 0x0c0,
    [TYPE_PSYCHIC]  = 0x0d0,
    [TYPE_STEEL]    = 0x0e0,
    [TYPE_DARK]     = 0x0f0,
    [TYPE_DRAGON]   = 0x100
};

// Window IDs for the context menu that opens when a TM/HM is selected
enum {
    WIN_USE_GIVE_EXIT,
    WIN_GIVE_EXIT,
};

// When a TM/HM in the list is selected in the field, create a context
// menu with a list of actions that can be taken.
void Task_SelectTMAction_FromFieldBag_(u8 taskId)
{
    u8 * strbuf;
    TMCase_SetWindowBorder2(2);
    if (!MenuHelpers_IsLinkActive() && InUnionRoom() != TRUE)
    {
        AddContextMenu(&sTMCaseDynamicResources->contextMenuWindowId, 0);
        sTMCaseDynamicResources->menuActionIndices = sMenuActionIndices_Field;
        sTMCaseDynamicResources->numMenuActions = NELEMS(sMenuActionIndices_Field);
    }
    else
    {
        AddContextMenu(&sTMCaseDynamicResources->contextMenuWindowId, 1);
        sTMCaseDynamicResources->menuActionIndices = sMenuActionIndices_UnionRoom;
        sTMCaseDynamicResources->numMenuActions = NELEMS(sMenuActionIndices_UnionRoom);
    }
    AddItemMenuActionTextPrinters(sTMCaseDynamicResources->contextMenuWindowId, 2, GetMenuCursorDimensionByFont(2, 0), 2, 0, GetFontAttribute(2, 1) + 2, sTMCaseDynamicResources->numMenuActions, sMenuActions_UseGiveExit, sTMCaseDynamicResources->menuActionIndices);
    Menu_InitCursor(sTMCaseDynamicResources->contextMenuWindowId, 2, 0, 2, GetFontAttribute(2, 1) + 2, sTMCaseDynamicResources->numMenuActions, 0);
    strbuf = Alloc(256);
    GetTMNumberAndMoveString_(strbuf, gSpecialVar_ItemId);
    StringAppend(strbuf, gText_Var1IsSelected + 2); // +2 skips over the stringvar
    TMCase_Print(2, 2, strbuf, 0, 2, 1, 0, 0, 1);
    Free(strbuf);
    
    if (gSpecialVar_ItemId >= ITEM_HM01 && gSpecialVar_ItemId <= ITEM_HM08)
    {
        PlaceHMTileInWindow(2, 0, 2);
        CopyWindowToVram(2, 2);
    }
    
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    gTasks[taskId].func = Task_ContextMenu_HandleInput;
}

void SetTMSpriteAnim(struct Sprite * sprite, u8 idx)
{
    if (idx > NUM_TECHNICAL_MACHINES)
        StartSpriteAnim(sprite, 1);
    else
        StartSpriteAnim(sprite, 0);
}

static void SetDiscSpritePosition(struct Sprite *sprite, u8 tmIdx)
{
    s32 x, y;
    if (tmIdx == DISC_HIDDEN)
    {
        x = 27;
        y = 54;
        sprite->y2 = DISC_CASE_DISTANCE;
    }
    else
    {
        if (tmIdx >= NUM_TECHNICAL_MACHINES)
            tmIdx -= NUM_TECHNICAL_MACHINES;
        else
            tmIdx += NUM_HIDDEN_MACHINES;

        x = DISC_BASE_X - Q_24_8_TO_INT(Q_24_8(14 * tmIdx) / (NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES));
        y = DISC_BASE_Y + Q_24_8_TO_INT(Q_24_8(8 * tmIdx) / (NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES));
    }
    sprite->x = x;
    sprite->y = y;
}

static void SetDiscSpriteAnim(struct Sprite *sprite, u8 tmIdx)
{
    if (tmIdx >= NUM_TECHNICAL_MACHINES)
        StartSpriteAnim(sprite, ANIM_HM);
    else
        StartSpriteAnim(sprite, ANIM_TM);
}

static const struct SpriteTemplate sSpriteTemplate_Disc = {
    .tileTag = TAG_DISC,
    .paletteTag = TAG_DISC,
    .oam = &sTMSpriteOamData,
    .anims = sAnims_Disc,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

extern void __attribute__((long_call)) TintDiscpriteByType(u8 type);

u8 CreateDiscSprite_(u16 itemId)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Disc, DISC_BASE_X, DISC_BASE_Y, 0);
    u8 tmIdx;
    if (itemId == ITEM_NONE)
    {
        SetDiscSpritePosition(&gSprites[spriteId], DISC_HIDDEN);
        return spriteId;
    }
    else
    {
        tmIdx = itemId - ITEM_TM01;
        SetDiscSpriteAnim(&gSprites[spriteId], tmIdx);
        TintDiscpriteByType(gBattleMoves[ItemIdToBattleMoveId_(itemId)].type);
        SetDiscSpritePosition(&gSprites[spriteId], tmIdx);
        return spriteId;
    }
}