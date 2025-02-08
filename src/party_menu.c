#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/battle.h"
#include "../include/battle_anim.h"
#include "../include/battle_controllers.h"
#include "../include/battle_gfx_sfx_util.h"
#include "../include/battle_interface.h"
#include "../include/battle_tower.h"
#include "../include/berry_pouch.h"
#include "../include/data.h"
#include "../include/decompress.h"
#include "../include/easy_chat.h"
#include "../include/event_data.h"
#include "../include/evolution_scene.h"
#include "../include/field_effect.h"
#include "../include/field_player_avatar.h"
#include "../include/field_fadetransition.h"
#include "../include/field_weather.h"
#include "../include/fieldmap.h"
#include "../include/fldeff.h"
#include "../include/graphics.h"
#include "../include/help_message.h"
#include "../include/help_system.h"
#include "../include/item.h"
#include "../include/item_menu.h"
#include "../include/item_use.h"
#include "../include/link.h"
#include "../include/link_rfu.h"
#include "../include/load_save.h"
#include "../include/mail.h"
#include "../include/mail_data.h"
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/menu_helpers.h"
#include "../include/new_menu_helpers.h"
#include "../include/metatile_behavior.h"
#include "../include/overworld.h"
#include "../include/party_menu.h"
#include "../include/player_pc.h"
#include "../include/pokedex.h"
#include "../include/pokemon.h"
#include "../include/pokemon_icon.h"
#include "../include/pokemon_jump.h"
#include "../include/pokemon_special_anim.h"
#include "../include/pokemon_summary_screen.h"
#include "../include/quest_log.h"
#include "../include/region_map.h"
#include "../include/reshow_battle_screen.h"
#include "../include/scanline_effect.h"
#include "../include/script.h"
#include "../include/start_menu.h"
#include "../include/string_util.h"
#include "../include/strings.h"
#include "../include/task.h"
#include "../include/teachy_tv.h"
#include "../include/text_window.h"
#include "../include/tm_case.h"
#include "../include/trade.h"
#include "../include/union_room.h"
#include "../include/constants/battle.h"
#include "../include/constants/easy_chat.h"
#include "../include/constants/field_effects.h"
#include "../include/constants/item_effects.h"
#include "../include/constants/items.h"
#include "../include/constants/maps.h"
#include "../include/constants/moves.h"
#include "../include/constants/pokemon.h"
#include "../include/constants/quest_log.h"
#include "../include/constants/songs.h"
#include "../include/constants/sound.h"

#include "data/party_menu.c"

extern void Task_SetSacredAshCB(u8 taskId);
extern void Task_DoLearnedMoveFanfareAfterText(u8 taskId);

#define PARTY_PAL_SELECTED     (1 << 0)
#define PARTY_PAL_FAINTED      (1 << 1)
#define PARTY_PAL_TO_SWITCH    (1 << 2)
#define PARTY_PAL_MULTI_ALT    (1 << 3)
#define PARTY_PAL_SWITCHING    (1 << 4)
#define PARTY_PAL_TO_SOFTBOIL  (1 << 5)
#define PARTY_PAL_NO_MON       (1 << 6)
#define PARTY_PAL_UNUSED       (1 << 7)

#define MENU_DIR_DOWN     1
#define MENU_DIR_UP      -1
#define MENU_DIR_RIGHT    2
#define MENU_DIR_LEFT    -2

enum
{
    CAN_LEARN_MOVE,
    CANNOT_LEARN_MOVE,
    ALREADY_KNOWS_MOVE,
    CANNOT_LEARN_MOVE_IS_EGG
};

struct PartyMenuBoxInfoRects
{
    void (*blitFunc)(u8 windowId, u8 x, u8 y, u8 width, u8 height, bool8 isEgg);
    u8 dimensions[24];
    u8 descTextLeft;
    u8 descTextTop;
    u8 descTextWidth;
    u8 descTextHeight;
};

struct PartyMenuInternal
{
    TaskFunc task;
    MainCallback exitCallback;
    u32 chooseHalf:1;
    u32 lastSelectedSlot:3;  // Used to return to same slot when going left/right bewtween columns
    u32 spriteIdConfirmPokeball:7;
    u32 spriteIdCancelPokeball:7;
    u32 messageId:14;
    u8 windowId[3];
    u8 actions[8];
    u8 numActions;
    u16 palBuffer[BG_PLTT_SIZE / sizeof(u16)];
    s16 data[16];
};

struct PartyMenuBox
{
    const struct PartyMenuBoxInfoRects *infoRects;
    const u8 *spriteCoords;
    u8 windowId;
    u8 monSpriteId;
    u8 itemSpriteId;
    u8 pokeballSpriteId;
    u8 statusSpriteId;
};

extern void ItemUseCB_LearnedMove(u8 taskId, TaskFunc func);
extern void Task_ReplaceMoveYesNo(u8 taskId);
extern void DisplayPartyPokemonDescriptionData(u8 slot, u8 stringId);
extern void Task_DoUseItemAnim(u8 taskId);
void Task_LearnedMove_(u8 taskId);
static u8 CanTeachMove(struct Pokemon *mon, u16 move);

static void DisplayLearnMoveMessage(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    DisplayPartyMenuMessage(gStringVar4, TRUE);
    ScheduleBgCopyTilemapToVram(2);
}

extern EWRAM_DATA struct PartyMenuInternal *sPartyMenuInternal = NULL;

static void Task_ClosePartyMenuAfterText(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        if (gPartyMenuUseExitCallback == FALSE)
            sPartyMenuInternal->exitCallback = NULL;
        Task_ClosePartyMenu(taskId);
    }
}

static void DisplayLearnMoveMessageAndClose(u8 taskId, const u8 *str)
{
    DisplayLearnMoveMessage(str);
    gTasks[taskId].func = Task_ClosePartyMenuAfterText;
}

void DisplayPartyPokemonDataToTeachMove_(u8 slot, u16 move)
{
    switch (CanTeachMove(&gPlayerParty[slot], move))
    {
    case CANNOT_LEARN_MOVE:
    case CANNOT_LEARN_MOVE_IS_EGG:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NOT_ABLE_2);
        break;
    case ALREADY_KNOWS_MOVE:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_LEARNED);
        break;
    default:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_ABLE_2);
        break;
    }
}

// Returns TRUE if teaching move or cant evolve with item (i.e. description data is shown), FALSE otherwise
bool8 DisplayPartyPokemonDataForMoveTutorOrEvolutionItem_(u8 slot)
{
    struct Pokemon *currentPokemon = &gPlayerParty[slot];
    u16 item = gSpecialVar_ItemId;

    if (gPartyMenu.action == PARTY_ACTION_MOVE_TUTOR)
    {
        gSpecialVar_Result = FALSE;
        DisplayPartyPokemonDataToTeachMove_(slot, gSpecialVar_0x8005);
    }
    else
    {
        if (gPartyMenu.action != PARTY_ACTION_USE_ITEM)
            return FALSE;
        switch (CheckIfItemIsTMHMOrEvolutionStone(item))
        {
        default:
            return FALSE;
        case 1: // TM/HM
            DisplayPartyPokemonDataToTeachMove_(slot, ItemIdToBattleMoveId_(item));
            break;
        case 2: // Evolution stone
            if (!GetMonData(currentPokemon, MON_DATA_IS_EGG, NULL) && GetEvolutionTargetSpecies(currentPokemon, EVO_MODE_ITEM_CHECK, item) != SPECIES_NONE)
                return FALSE;
            DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NO_USE);
            break;
        }
    }
    return TRUE;
}

static u8 CanTeachMove(struct Pokemon *mon, u16 move)
{
    if (GetMonData(mon, MON_DATA_IS_EGG, NULL))
        return CANNOT_LEARN_MOVE_IS_EGG;
    else if (!CanLearnTeachableMove(GetMonData(mon, MON_DATA_SPECIES_OR_EGG, NULL), move))
        return CANNOT_LEARN_MOVE;
    else if (MonKnowsMove(mon, move) == TRUE)
        return ALREADY_KNOWS_MOVE;
    else
        return CAN_LEARN_MOVE;
}

void ItemUseCB_TMHM_(u8 taskId, TaskFunc func)
{
    struct Pokemon *mon;
    u16 item = gSpecialVar_ItemId;
    u16 move = ItemIdToBattleMoveId_(item);

    gPartyMenu.data1 = move;

    PlaySE(SE_SELECT);
    mon = &gPlayerParty[gPartyMenu.slotId];
    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames_[move]);
    switch (CanTeachMove(mon, move))
    {
    case CANNOT_LEARN_MOVE:
        DisplayLearnMoveMessageAndClose(taskId, gText_PkmnCantLearnMove);
        return;
    case ALREADY_KNOWS_MOVE:
        DisplayLearnMoveMessageAndClose(taskId, gText_PkmnAlreadyKnows);
        return;
    }
    if (GiveMoveToMon(mon, move) != MON_HAS_MAX_MOVES)
    {
        ItemUse_SetQuestLogEvent(QL_EVENT_USED_ITEM, mon, item, 0xFFFF);
        Task_DoUseItemAnim(taskId);
        gItemUseCB = ItemUseCB_LearnedMove;
    }
    else
    {
        DisplayLearnMoveMessage(gText_PkmnNeedsToReplaceMove);
        gTasks[taskId].func = Task_ReplaceMoveYesNo;
    }
}

void TryTutorSelectedMon_(u8 taskId)
{
    struct Pokemon *mon;
    s16 *move;

    if (!gPaletteFade.active)
    {
        mon = &gPlayerParty[gPartyMenu.slotId];
        move = &gPartyMenu.data1;
        GetMonNickname(mon, gStringVar1);
        gPartyMenu.data1 = gSpecialVar_0x8005;
        StringCopy(gStringVar2, gMoveNames_[gPartyMenu.data1]);
        move[1] = 2;
        switch (CanTeachMove(mon, gPartyMenu.data1))
        {
        case CANNOT_LEARN_MOVE:
            DisplayLearnMoveMessageAndClose(taskId, gText_PkmnCantLearnMove);
            return;
        case ALREADY_KNOWS_MOVE:
            DisplayLearnMoveMessageAndClose(taskId, gText_PkmnAlreadyKnows);
            return;
        default:
            if (GiveMoveToMon(mon, gPartyMenu.data1) != MON_HAS_MAX_MOVES)
            {
                Task_LearnedMove_(taskId);
                return;
            }
            break;
        }
        DisplayLearnMoveMessage(gText_PkmnNeedsToReplaceMove);
        gTasks[taskId].func = Task_ReplaceMoveYesNo;
    }
}

void ChooseMonForMoveTutor_(void)
{
    InitPartyMenu(PARTY_MENU_TYPE_FIELD,
                    PARTY_LAYOUT_SINGLE,
                    PARTY_ACTION_MOVE_TUTOR,
                    FALSE,
                    PARTY_MSG_TEACH_WHICH_MON,
                    Task_HandleChooseMonInput,
                    CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void CB2_UseItem_(void)
{
    if (ItemId_GetPocket(gSpecialVar_ItemId) == POCKET_TM_CASE && PSA_IsCancelDisabled() == TRUE)
    {
        GiveMoveToMon(&gPlayerParty[gPartyMenu.slotId], ItemIdToBattleMoveId_(gSpecialVar_ItemId));
        AdjustFriendship(&gPlayerParty[gPartyMenu.slotId], FRIENDSHIP_EVENT_LEARN_TMHM);
        #ifndef REUSABLE_TMS
        if (gSpecialVar_ItemId >= ITEM_FIRST_TM && gSpecialVar_ItemId <= ITEM_LAST_TM)
            RemoveBagItem(gSpecialVar_ItemId, 1);
        #endif
        SetMainCallback2(gPartyMenu.exitCallback);
    }
    else
        InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, PARTY_ACTION_CHOOSE_MON, gPartyMenu.slotId, PARTY_MSG_NONE, Task_SetSacredAshCB, gPartyMenu.exitCallback);
}

void CB2_UseTMHMAfterForgettingMove_(void)
{
    if (PSA_IsCancelDisabled() == TRUE)
    {
        struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];
        u8 moveIdx = GetMoveSlotToReplace();
        u16 move = GetMonData(mon, moveIdx + MON_DATA_MOVE1, NULL);
        
        RemoveMonPPBonus(mon, moveIdx);
        SetMonMoveSlot(mon, ItemIdToBattleMoveId_(gSpecialVar_ItemId), moveIdx);
        AdjustFriendship(mon, FRIENDSHIP_EVENT_LEARN_TMHM);
        ItemUse_SetQuestLogEvent(QL_EVENT_USED_ITEM, mon, gSpecialVar_ItemId, move);
        #ifndef REUSABLE_TMS
        if (gSpecialVar_ItemId >= ITEM_FIRST_TM && gSpecialVar_ItemId <= ITEM_LAST_TM)
            RemoveBagItem(gSpecialVar_ItemId, 1);
        #endif
        SetMainCallback2(gPartyMenu.exitCallback);
    }
    else
        InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, gPartyMenu.action, gPartyMenu.slotId, PARTY_MSG_NONE, Task_SetSacredAshCB, gPartyMenu.exitCallback);
}

u16 ItemIdToBattleMoveId_(u16 item)
{
    u16 tmNumber;
    if (item >= ITEM_TM01 && item <= ITEM_HM08) tmNumber = item - ITEM_TM01;
    else if (item >= ITEM_TM51) tmNumber = item - 318;

    return sTMHMMoves[tmNumber];
}

void Task_LearnedMove_(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];
    s16 *move = &gPartyMenu.data1;
    u16 item = gSpecialVar_ItemId;

    if (move[1] == 0)
    {
        AdjustFriendship(mon, 4);
        #ifndef REUSABLE_TMS
        if ((gSpecialVar_ItemId >= ITEM_FIRST_TM && gSpecialVar_ItemId <= ITEM_TM50) || (gSpecialVar_ItemId >= ITEM_TM51 && gSpecialVar_ItemId <= ITEM_LAST_TM))
            RemoveBagItem(item, 1);
        #endif
    }
    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gMoveNames_[move[0]]);
    StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
    DisplayPartyMenuMessage(gStringVar4, TRUE);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_DoLearnedMoveFanfareAfterText;
}