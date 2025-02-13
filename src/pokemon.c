#define IS_POKEMON_C

#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/random.h"
#include "../include/text.h"
#include "../include/data.h"
#include "../include/battle.h"
#include "../include/battle_anim.h"
#include "../include/item.h"
#include "../include/event_data.h"
#include "../include/util.h"
#include "../include/pokemon_storage_system.h"
#include "../include/battle_gfx_sfx_util.h"
#include "../include/battle_controllers.h"
#include "../include/evolution_scene.h"
#include "../include/battle_message.h"
#include "../include/battle_util.h"
#include "../include/link.h"
#include "../include/m4a.h"
#include "../include/pokedex.h"
#include "../include/strings.h"
#include "../include/overworld.h"
#include "../include/party_menu.h"
#include "../include/field_specials.h"
#include "../include/constants/items.h"
#include "../include/constants/item_effects.h"
#include "../include/constants/hoenn_cries.h"
#include "../include/constants/pokemon.h"
#include "../include/constants/abilities.h"
#include "../include/constants/moves.h"
#include "../include/constants/songs.h"
#include "../include/constants/item_effects.h"
#include "../include/constants/trainers.h"
#include "../include/constants/hold_effects.h"
#include "../include/constants/battle_move_effects.h"

u32 GetMonData(struct Pokemon *mon, u8 *data)
{
    s32 field;
    return GetMonData_(mon, data, field);
}

u32 GetBoxMonData(struct BoxPokemon *boxMon, u8 *data)
{
    s32 field;
    return GetBoxMonData_(boxMon, data, field);
}

u8 CanLearnTeachableMove(u16 species, u16 move)
{
    if (species == SPECIES_EGG)
    {
        return FALSE;
    }
    else
    {
        u8 i;
        for (i = 0; gTeachableLearnsets[species][i] != MOVE_UNAVAILABLE; i++)
        {
            if (gTeachableLearnsets[species][i] == move)
                return TRUE;
        }
        return FALSE;
    }
}