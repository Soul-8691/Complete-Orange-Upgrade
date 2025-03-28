#include "../../include/gba/types.h"
#include "../../include/constants/moves.h"
#include "../../include/constants/items.h"

static const u16 sTMHMMoves[NUM_TMHMS] = {
	MOVE_FOCUSPUNCH,
	MOVE_DRAGONCLAW,
	MOVE_WATERPULSE,
	MOVE_CALMMIND,
	MOVE_ROAR,
	MOVE_TOXIC,
	MOVE_HAIL,
	MOVE_BULKUP,
	MOVE_BULLETSEED,
	MOVE_HIDDENPOWER,
	MOVE_SUNNYDAY,
	MOVE_TAUNT,
	MOVE_ICEBEAM,
	MOVE_BLIZZARD,
	MOVE_HYPERBEAM,
	MOVE_LIGHTSCREEN,
	MOVE_PROTECT,
	MOVE_RAINDANCE,
	MOVE_GIGADRAIN,
	MOVE_SAFEGUARD,
	MOVE_FRUSTRATION,
	MOVE_SOLARBEAM,
	MOVE_IRONTAIL,
	MOVE_THUNDERBOLT,
	MOVE_THUNDER,
	MOVE_EARTHQUAKE,
	MOVE_RETURN,
	MOVE_DIG,
	MOVE_PSYCHIC,
	MOVE_SHADOWBALL,
	MOVE_BRICKBREAK,
	MOVE_DOUBLETEAM,
	MOVE_REFLECT,
	MOVE_SHOCKWAVE,
	MOVE_FLAMETHROWER,
	MOVE_SLUDGEBOMB,
	MOVE_SANDSTORM,
	MOVE_FIREBLAST,
	MOVE_ROCKTOMB,
	MOVE_AERIALACE,
	MOVE_TORMENT,
	MOVE_FACADE,
	MOVE_SECRETPOWER,
	MOVE_REST,
	MOVE_ATTRACT,
	MOVE_THIEF,
	MOVE_STEELWING,
	MOVE_SKILLSWAP,
	MOVE_SNATCH,
	MOVE_OVERHEAT,
	MOVE_CUT,
	MOVE_FLY,
	MOVE_SURF,
	MOVE_STRENGTH,
	MOVE_FLASH,
	MOVE_ROCKSMASH,
	MOVE_WATERFALL,
	MOVE_DIVE,
    MOVE_SPIKES,
    MOVE_HYDROPUMP,
    MOVE_BATONPASS,
    MOVE_PURSUIT,
    MOVE_ICEPUNCH,
    MOVE_AGILITY,
    MOVE_RAPIDSPIN,
    MOVE_LEECHSEED,
    MOVE_RECOVER,
    MOVE_WILLOWISP,
    MOVE_FIREPUNCH,
    MOVE_SELFDESTRUCT,
    MOVE_CURSE,
    MOVE_WISH,
    MOVE_REFRESH,
    MOVE_SLEEPTALK,
    MOVE_BEATUP,
    MOVE_WHIRLWIND,
    MOVE_ENDEAVOR,
    MOVE_MEGAHORN,
    MOVE_AROMATHERAPY,
    MOVE_ENDURE,
    MOVE_ANCIENTPOWER,
    MOVE_HEALBELL,
    MOVE_HYPNOSIS,
    MOVE_DESTINYBOND,
    MOVE_THUNDERPUNCH,
    MOVE_MEANLOOK,
    MOVE_SCREECH,
    MOVE_HAZE,
    MOVE_KNOCKOFF,
    MOVE_REVERSAL,
    MOVE_DYNAMICPUNCH,
    MOVE_METALSOUND,
    MOVE_ZAPCANNON,
    MOVE_MIRRORCOAT,
    MOVE_DRAGONBREATH,
    MOVE_STUNSPORE,
    MOVE_YAWN,
    MOVE_SILVERWIND,
    MOVE_NIGHTSHADE,
    MOVE_ENCORE,
    MOVE_CONFUSERAY,
    MOVE_EXTRASENSORY,
    MOVE_PAINSPLIT,
    MOVE_MUDDYWATER,
    MOVE_SUPERPOWER,
    MOVE_ICYWIND,
    MOVE_IRONDEFENSE,
    MOVE_AMNESIA,
    MOVE_CHARM,
    MOVE_TRIATTACK,
    MOVE_LOWKICK,
    MOVE_BITE,
    MOVE_HEATWAVE,
    MOVE_TRICK,
    MOVE_WINGATTACK,
    MOVE_MEMENTO,
    MOVE_SKYATTACK,
    MOVE_RAZORLEAF,
    MOVE_ROCKBLAST,
    MOVE_FIRESPIN,
    MOVE_REVENGE,
    MOVE_DETECT,
    MOVE_FAKETEARS,
    MOVE_MUDSHOT,
    MOVE_SYNTHESIS,
    MOVE_OUTRAGE,
    MOVE_FLAIL,
    MOVE_PSYBEAM,
};