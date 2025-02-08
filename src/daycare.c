#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/data.h"
#include "../include/battle.h"
#include "../include/constants/items.h"
#include "../include/mail_data.h"
#include "../include/pokemon_storage_system.h"
#include "../include/event_data.h"
#include "../include/random.h"
#include "../include/constants/moves.h"
#include "../include/menu.h"
#include "../include/new_menu_helpers.h"
#include "../include/script.h"
#include "../include/strings.h"
#include "../include/party_menu.h"
#include "../include/list_menu.h"
#include "../include/overworld.h"
#include "../include/pokedex.h"
#include "../include/decompress.h"
#include "../include/constants/songs.h"
#include "../include/text_window.h"
#include "../include/trig.h"
#include "../include/m4a.h"
#include "../include/graphics.h"
#include "../include/scanline_effect.h"
#include "../include/naming_screen.h"
#include "../include/help_system.h"
#include "../include/field_fadetransition.h"
#include "../include/trade.h"
#include "../include/item.h"
#include "../include/pokemon.h"
#include "../include/constants/daycare.h"
#include "../include/constants/region_map_sections.h"

extern u8 GetEggMoves(struct Pokemon *pokemon, u16 *eggMoves);

// RAM buffers used to assist with BuildEggMoveset()
extern u16 sHatchedEggLevelUpMoves[EGG_LVL_UP_MOVES_ARRAY_COUNT] = {0};
extern u16 sHatchedEggFatherMoves[4] = {0};
extern u16 sHatchedEggFinalMoves[4] = {0};
extern u16 sHatchedEggEggMoves[EGG_MOVES_ARRAY_COUNT] = {0};
extern u16 sHatchedEggMotherMoves[4] = {0};

void BuildEggMoveset_(struct Pokemon *egg, struct BoxPokemon *father, struct BoxPokemon *mother)
{
    u16 numSharedParentMoves;
    u32 numLevelUpMoves;
    u16 numEggMoves;
    u16 i, j;

    numSharedParentMoves = 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        sHatchedEggMotherMoves[i] = MOVE_NONE;
        sHatchedEggFatherMoves[i] = MOVE_NONE;
        sHatchedEggFinalMoves[i] = MOVE_NONE;
    }
    for (i = 0; i < EGG_MOVES_ARRAY_COUNT; i++)
        sHatchedEggEggMoves[i] = MOVE_NONE;
    for (i = 0; i < EGG_LVL_UP_MOVES_ARRAY_COUNT; i++)
        sHatchedEggLevelUpMoves[i] = MOVE_NONE;

    numLevelUpMoves = GetLevelUpMovesBySpecies(GetMonData(egg, MON_DATA_SPECIES, NULL), sHatchedEggLevelUpMoves);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        sHatchedEggFatherMoves[i] = GetBoxMonData(father, MON_DATA_MOVE1 + i, NULL);
        sHatchedEggMotherMoves[i] = GetBoxMonData(mother, MON_DATA_MOVE1 + i, NULL);
    }

    numEggMoves = GetEggMoves(egg, sHatchedEggEggMoves);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFatherMoves[i] != MOVE_NONE)
        {
            for (j = 0; j < numEggMoves; j++)
            {
                if (sHatchedEggFatherMoves[i] == sHatchedEggEggMoves[j])
                {
                    if (GiveMoveToMon(egg, sHatchedEggFatherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFatherMoves[i]);
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFatherMoves[i] != MOVE_NONE)
        {
            for (j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
            {
                u16 moveId = ItemIdToBattleMoveId_(ITEM_TM01 + j);
                if (sHatchedEggFatherMoves[i] == moveId && CanLearnTeachableMove(GetMonData(egg, MON_DATA_SPECIES_OR_EGG, NULL), moveId))
                {
                    if (GiveMoveToMon(egg, sHatchedEggFatherMoves[i]) == MON_HAS_MAX_MOVES)
                        DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFatherMoves[i]);
                }
            }
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFatherMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            if (sHatchedEggFatherMoves[i] == sHatchedEggMotherMoves[j] && sHatchedEggFatherMoves[i] != MOVE_NONE)
                sHatchedEggFinalMoves[numSharedParentMoves++] = sHatchedEggFatherMoves[i];
        }
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (sHatchedEggFinalMoves[i] == MOVE_NONE)
            break;
        for (j = 0; j < numLevelUpMoves; j++)
        {
            if (sHatchedEggLevelUpMoves[j] != MOVE_NONE && sHatchedEggFinalMoves[i] == sHatchedEggLevelUpMoves[j])
            {
                if (GiveMoveToMon(egg, sHatchedEggFinalMoves[i]) == MON_HAS_MAX_MOVES)
                    DeleteFirstMoveAndGiveMoveToMon(egg, sHatchedEggFinalMoves[i]);
                break;
            }
        }
    }
}