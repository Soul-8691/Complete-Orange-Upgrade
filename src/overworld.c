#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/bg_regs.h"
#include "../include/cable_club.h"
#include "../include/credits.h"
#include "../include/event_data.h"
#include "../include/event_object_movement.h"
#include "../include/event_scripts.h"
#include "../include/field_camera.h"
#include "../include/field_control_avatar.h"
#include "../include/field_effect.h"
#include "../include/field_fadetransition.h"
#include "../include/field_message_box.h"
#include "../include/field_player_avatar.h"
#include "../include/field_screen_effect.h"
#include "../include/field_specials.h"
#include "../include/field_tasks.h"
#include "../include/field_weather.h"
#include "../include/fieldmap.h"
#include "../include/fldeff.h"
#include "../include/heal_location.h"
#include "../include/help_system.h"
#include "../include/link.h"
#include "../include/link_rfu.h"
#include "../include/load_save.h"
#include "../include/m4a.h"
#include "../include/map_name_popup.h"
#include "../include/map_preview_screen.h"
#include "../include/metatile_behavior.h"
#include "../include/money.h"
#include "../include/new_game.h"
#include "../include/new_menu_helpers.h"
#include "../include/overworld.h"
#include "../include/play_time.h"
#include "../include/quest_log.h"
#include "../include/quest_log_objects.h"
#include "../include/random.h"
#include "../include/renewable_hidden_items.h"
#include "../include/roamer.h"
#include "../include/safari_zone.h"
#include "../include/save_location.h"
#include "../include/scanline_effect.h"
#include "../include/script.h"
#include "../include/script_pokemon_util.h"
#include "../include/start_menu.h"
#include "../include/tileset_anims.h"
#include "../include/trainer_pokemon_sprites.h"
#include "../include/vs_seeker.h"
#include "../include/wild_encounter.h"
#include "../include/constants/cable_club.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/maps.h"
#include "../include/constants/region_map_sections.h"
#include "../include/constants/songs.h"
#include "../include/constants/sound.h"

static bool8 GetProperDirection(u16 currentX, u16 currentY, u16 toX, u16 toY)
{
	u8 ret = FALSE;

	if (currentX == toX)
	{
		if (currentY < toY)
			gSpecialVar_LastResult = DIR_SOUTH;
		else
			gSpecialVar_LastResult = DIR_NORTH;

		ret = TRUE;
	}
	else if (currentY == toY)
	{
		if (currentX < toX)
			gSpecialVar_LastResult = DIR_EAST;
		else
			gSpecialVar_LastResult = DIR_WEST;

		ret = TRUE;
	}

	return ret;
}

void TrainerFaceFix(void)
{
	u8 playerObjId = gPlayerAvatar->objectEventId;
	u16 playerX = gObjectEvents[playerObjId].currentCoords.x;
	u16 playerY = gObjectEvents[playerObjId].currentCoords.y;
	u16 npcX = gObjectEvents[gSelectedEventObject].currentCoords.x;
	u16 npcY = gObjectEvents[gSelectedEventObject].currentCoords.y;

	if (!GetProperDirection(playerX, playerY, npcX, npcY))
		gSpecialVar_LastResult = 0xFFFF;
}