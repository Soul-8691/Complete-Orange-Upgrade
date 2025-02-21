#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/script.h"
#include "../include/mystery_event_script.h"
#include "../include/event_data.h"
#include "../include/random.h"
#include "../include/item.h"
#include "../include/overworld.h"
#include "../include/field_screen_effect.h"
#include "../include/quest_log.h"
#include "../include/map_preview_screen.h"
#include "../include/fieldmap.h"
#include "../include/field_weather.h"
#include "../include/field_tasks.h"
#include "../include/field_fadetransition.h"
#include "../include/field_player_avatar.h"
#include "../include/script_movement.h"
#include "../include/event_object_movement.h"
#include "../include/event_object_lock.h"
#include "../include/field_message_box.h"
#include "../include/new_menu_helpers.h"
#include "../include/script_menu.h"
#include "../include/data.h"
#include "../include/field_specials.h"
#include "../include/constants/items.h"
#include "../include/script_pokemon_util.h"
#include "../include/pokemon_storage_system.h"
#include "../include/party_menu.h"
#include "../include/money.h"
#include "../include/coins.h"
#include "../include/battle_setup.h"
#include "../include/shop.h"
#include "../include/slot_machine.h"
#include "../include/field_effect.h"
#include "../include/fieldmap.h"
#include "../include/field_door.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/maps.h"
#include "../include/constants/sound.h"

#include "../include/overworld.h"
#include "../include/region_map.h"
#include "../include/global.fieldmap.h"

bool8 ScrCmd_setwildbattlerandomlevel(struct ScriptContext * ctx)
{
    u16 species = ScriptReadHalfword(ctx);
    u8 level = ScriptReadByte(ctx);
    u16 item = ScriptReadHalfword(ctx);

    if (level == 0) level = gSpecialVar_Result;
    CreateScriptedWildMon(species, level, item);
    return FALSE;
}

bool8 ScrCmd_setflag_(struct ScriptContext * ctx)
{
    u16 flag = ScriptReadHalfword(ctx);
    if (flag >= 0x4000) flag = VarGet(flag);
    FlagSet(flag);
    return FALSE;
}

bool8 ScrCmd_clearflag_(struct ScriptContext * ctx)
{
    u16 flag = ScriptReadHalfword(ctx);
    if (flag >= 0x4000) flag = VarGet(flag);
    FlagClear(flag);
    return FALSE;
}

extern u8 *const __attribute__((long_call)) sScriptStringVars[];
extern const struct MapHeader *const __attribute__((long_call)) Overworld_GetMapHeaderByGroupAndId(u16, u16);

bool8 ScrCmd_givemon_(struct ScriptContext * ctx)
{
    u16 species = VarGet(ScriptReadHalfword(ctx));
    u8 level = ScriptReadByte(ctx);
    u16 item = VarGet(ScriptReadHalfword(ctx));
    u32 unkParam1 = ScriptReadWord(ctx);
    u32 unkParam2 = ScriptReadWord(ctx);
    u8 unkParam3 = ScriptReadByte(ctx);

    if (level == 0) {
        u8 mapName[25];
        const struct MapHeader * map = Overworld_GetMapHeaderByGroupAndId(species, item);
        GetMapName(mapName, map->regionMapSectionId, 0);
        StringCopy(sScriptStringVars[unkParam3], mapName);
    }
    else {
        gSpecialVar_Result = ScriptGiveMon(species, level, item, unkParam1, unkParam2, unkParam3);
    }
    return FALSE;
}