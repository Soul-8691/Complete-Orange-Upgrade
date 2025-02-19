#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/quest_log.h"
#include "../include/list_menu.h"
#include "../include/diploma.h"
#include "../include/script.h"
#include "../include/field_player_avatar.h"
#include "../include/overworld.h"
#include "../include/field_message_box.h"
#include "../include/event_data.h"
#include "../include/strings.h"
#include "../include/battle.h"
#include "../include/fieldmap.h"
#include "../include/field_specials.h"
#include "../include/region_map.h"
#include "../include/task.h"
#include "../include/battle_tower.h"
#include "../include/field_camera.h"
#include "../include/field_effect.h"
#include "../include/event_object_movement.h"
#include "../include/menu_indicators.h"
#include "../include/random.h"
#include "../include/mail_data.h"
#include "../include/help_system.h"
#include "../include/pokemon_storage_system.h"
#include "../include/script_menu.h"
#include "../include/data.h"
#include "../include/pokedex.h"
#include "../include/text_window.h"
#include "../include/menu.h"
#include "../include/mystery_gift.h"
#include "../include/naming_screen.h"
#include "../include/party_menu.h"
#include "../include/dynamic_placeholder_text_util.h"
#include "../include/new_menu_helpers.h"
#include "../include/constants/songs.h"
#include "../include/constants/items.h"
#include "../include/constants/maps.h"
#include "../include/constants/region_map_sections.h"
#include "../include/constants/moves.h"
#include "../include/constants/menu.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/metatile_labels.h"

bool8 BufferTMHMMoveName_(void)
{
    // 8004 = item ID
    if ((gSpecialVar_0x8004 >= ITEM_TM01 && gSpecialVar_0x8004 <= ITEM_HM08) || gSpecialVar_0x8004 >= ITEM_TM51)
    {
        StringCopy(gStringVar1, gMoveNames[ItemIdToBattleMoveId_(gSpecialVar_0x8004)]);
        return TRUE;
    }
    else
        return FALSE;
}