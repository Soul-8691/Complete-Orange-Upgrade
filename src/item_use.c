#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/battle.h"
#include "../include/berry_pouch.h"
#include "../include/berry_powder.h"
#include "../include/bike.h"
#include "../include/coins.h"
#include "../include/event_data.h"
#include "../include/field_effect.h"
#include "../include/field_fadetransition.h"
#include "../include/event_object_movement.h"
#include "../include/field_player_avatar.h"
#include "../include/field_specials.h"
#include "../include/field_weather.h"
#include "../include/fieldmap.h"
#include "../include/item.h"
#include "../include/item_menu.h"
#include "../include/item_use.h"
#include "../include/itemfinder.h"
#include "../include/mail.h"
#include "../include/event_object_lock.h"
#include "../include/metatile_behavior.h"
#include "../include/new_menu_helpers.h"
#include "../include/overworld.h"
#include "../include/party_menu.h"
#include "../include/quest_log.h"
#include "../include/region_map.h"
#include "../include/script.h"
#include "../include/strings.h"
#include "../include/task.h"
#include "../include/teachy_tv.h"
#include "../include/tm_case.h"
#include "../include/vs_seeker.h"
#include "../include/constants/sound.h"
#include "../include/constants/items.h"
#include "../include/constants/item_effects.h"
#include "../include/constants/maps.h"
#include "../include/constants/moves.h"
#include "../include/constants/songs.h"
#include "../include/constants/field_weather.h"

#include "../include/constants/flags.h"

void FieldUseFunc_ExpShare(u8 taskId)
{
	if (FlagGet(FLAG_EXP_ALL))
	{
		PlaySE(SE_EXP_MAX);
		if (!gTasks[taskId].data[2]) // to account for pressing select in the overworld
			DisplayItemMessageOnField(taskId, 2, gText_ExpShareOn, Task_ItemUse_CloseMessageBoxAndReturnToField);
		else
			DisplayItemMessageInBag(taskId, 2, gText_ExpShareOn, Task_ReturnToBagFromContextMenu);
        FlagClear(FLAG_EXP_ALL);
	}
	else
	{
		PlaySE(SE_PC_OFF);
		if (!gTasks[taskId].data[2]) // to account for pressing select in the overworld
			DisplayItemMessageOnField(taskId, 2, gText_ExpShareOff, Task_ItemUse_CloseMessageBoxAndReturnToField);
		else
			DisplayItemMessageInBag(taskId, 2, gText_ExpShareOff, Task_ReturnToBagFromContextMenu);
        FlagSet(FLAG_EXP_ALL);
	}
}
