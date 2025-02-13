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

#include "../include/constants/party_menu.h"
#include "../include/constants/moves.h"
#include "../include/constants/items.h"

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

u8 *MapHeaderCheckScriptTable(u8 tag);

extern const u8 EventScript_UseFlash[];
extern const u8 EventScript_UseSurf[];
extern const u8 EventScript_UseWaterfall[];
extern const u8 EventScript_WaterDyedBlue[];
extern const u8 EventScript_WallOfWater[];
extern const u8 EventScript_CantUseWaterfall[];

// The values here can be modified i guess
const u8 gFieldMoveBadgeRequirements[] =
{
	[FIELD_MOVE_FLASH] = 1,
	[FIELD_MOVE_CUT] = 2,
	[FIELD_MOVE_FLY] = 3,
	[FIELD_MOVE_STRENGTH] = 4,
	[FIELD_MOVE_SURF] = 5,
	[FIELD_MOVE_ROCK_SMASH] = 6,
	[FIELD_MOVE_WATERFALL] = 0,
};

bool8 HasBadgeToUseFieldMove(u8 id)
{
	return gFieldMoveBadgeRequirements[id] == 0 || FlagGet(FLAG_BADGE01_GET + (gFieldMoveBadgeRequirements[id] - 1));
}

void CanPlayerUseFlashInCurrentLocation(void)
{
	gSpecialVar_Result = gMapHeader.cave == TRUE && !FlagGet(FLAG_SYS_FLASH_ACTIVE);
}

u8 PartyHasMonWithFieldMovePotential(u16 move, u16 item, u8 surfingType)
{
	bool8 isSurfing = TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING);

	if (surfingType == 0 || (surfingType == 1 && !isSurfing) || (surfingType == 2 && isSurfing))
	{
		bool8 hasHM = CheckBagHasItem(item, 1) > 0;

		for (u32 i = 0; i < PARTY_SIZE; ++i)
		{
			struct Pokemon* mon = &gPlayerParty[i];

			if (GetMonData(mon, MON_DATA_SPECIES, NULL) != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
			{
				if (MonKnowsMove(mon, move) && move != 0)
					return i;

				if (hasHM && CanMonLearnTMTutor(mon, item, 0) == 0)
					return i;
			}
		}
	}

	return PARTY_SIZE;
}

bool8 IsPlayerSurfingNorthOrSouth(void)
{
	u8 dir = GetPlayerMovementDirection();

	return (dir == DIR_SOUTH || dir == DIR_NORTH) && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING);
}

static const u8* TryUseFlashInDarkCave(void)
{
	CanPlayerUseFlashInCurrentLocation();

	if (gSpecialVar_Result && HasBadgeToUseFieldMove(FIELD_MOVE_FLASH))
	{
		if ((gSpecialVar_0x8004 = gFieldEffectArguments[0] = PartyHasMonWithFieldMovePotential(MOVE_FLASH, ITEM_HM05_FLASH, 0)) < PARTY_SIZE)
			return EventScript_UseFlash;
	}

	return NULL;
}

bool8 TryRunOnFrameMapScript_(void)
{
	if (gQuestLogState != 3)
	{
		const u8* ptr;

		ptr = TryUseFlashInDarkCave();

		if (ptr == NULL)
			ptr = MapHeaderCheckScriptTable(2);

		if (ptr != NULL)
		{
			ScriptContext_SetupScript(ptr);
			return TRUE;
		}
	}

	return FALSE;
}

const u8* GetInteractedWaterScript_(u32 unused1, u8 metatileBehavior, u8 direction)
{
	u16 item = ITEM_NONE;

	if (IsPlayerFacingSurfableFishableWater())
	{
		if (HasBadgeToUseFieldMove(FIELD_MOVE_SURF))
		{
			item = ITEM_HM03_SURF;
			u8 partyId = PartyHasMonWithFieldMovePotential(MOVE_SURF, item, 1);

			if (partyId < PARTY_SIZE)
			{
				gSpecialVar_0x8004 = partyId;
				return EventScript_UseSurf;
			}

			return EventScript_WaterDyedBlue;
		}
	}
	else if (MetatileBehavior_IsWaterfall(metatileBehavior))
	{
		if (HasBadgeToUseFieldMove(FIELD_MOVE_WATERFALL))
		{
			if (IsPlayerSurfingNorthOrSouth())
			{
				item = ITEM_HM07_WATERFALL;
				u8 partyId = PartyHasMonWithFieldMovePotential(MOVE_WATERFALL, item, 2);

				if (partyId < PARTY_SIZE)
				{
					gSpecialVar_0x8004 = partyId;
					return EventScript_UseWaterfall;
				}

				return EventScript_WallOfWater;
			}
			else
				return EventScript_CantUseWaterfall;
		}
	}

	return NULL;
}
