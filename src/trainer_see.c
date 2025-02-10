#include "../include/global.h"
#include "../include/battle_setup.h"
#include "../include/event_object_movement.h"
#include "../include/field_effect.h"
#include "../include/field_player_avatar.h"
#include "../include/quest_log.h"
#include "../include/script.h"
#include "../include/task.h"
#include "../include/util.h"
#include "../include/constants/battle_setup.h"
#include "../include/constants/event_object_movement.h"
#include "../include/constants/event_objects.h"
#include "../include/constants/trainer_types.h"

#include "../include/event_scripts.h"
#include "../include/event_data.h"

typedef u8 (*TrainerApproachFunc)(struct ObjectEvent *, s16, s16, s16);
typedef bool8 (*TrainerSeeFunc)(u8, struct Task *, struct ObjectEvent *);

extern u8 __attribute__((long_call)) GetTrainerApproachDistanceSouth(struct ObjectEvent * trainerObj, s16 range, s16 x, s16 y);
extern u8 __attribute__((long_call)) GetTrainerApproachDistanceNorth(struct ObjectEvent * trainerObj, s16 range, s16 x, s16 y);
extern u8 __attribute__((long_call)) GetTrainerApproachDistanceWest(struct ObjectEvent * trainerObj, s16 range, s16 x, s16 y);
extern u8 __attribute__((long_call)) GetTrainerApproachDistanceEast(struct ObjectEvent * trainerObj, s16 range, s16 x, s16 y);
extern u8 __attribute__((long_call)) CheckPathBetweenTrainerAndPlayer(struct ObjectEvent * trainerObj, u8 approachDistance, u8 facingDirection);
extern void __attribute__((long_call)) TrainerApproachPlayer(struct ObjectEvent * trainerObj, u8 approachDistance);

// u8 func(struct ObjectEvent * trainerObj, s16 range, s16 x, s16 y)
// range is the maximum distance the trainer can see
// x and y are the player's coordinates
// Returns distance to walk if trainer has unobstructed view of player
// Returns 0 if trainer can't see player
static const TrainerApproachFunc sDirectionalApproachDistanceFuncs[] = {
    GetTrainerApproachDistanceSouth,
    GetTrainerApproachDistanceNorth,
    GetTrainerApproachDistanceWest,
    GetTrainerApproachDistanceEast
};

static bool8 CheckTrainer_(u8 trainerObjId);
static u8 GetTrainerApproachDistance_(struct ObjectEvent *trainerObj);

bool8 CheckForTrainersWantingBattle_(void)
{
    u8 i;
    u8 trainerObjId;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (!gObjectEvents[i].active)
            continue;
        if (gObjectEvents[i].trainerType == TRAINER_TYPE_NONE || gObjectEvents[i].trainerType == TRAINER_TYPE_SEE_ALL_DIRECTIONS)
            continue;
        trainerObjId = CheckTrainer_(i);
        if (trainerObjId > 1)    //run script
            break;
    }
    if (trainerObjId > 1)
    {
        gSelectedObjectEvent = trainerObjId - 2;
        gSpecialVar_LastTalked = gObjectEvents[trainerObjId - 2].localId;
        ScriptContext_SetupScript(EventScript_ObjectApproachPlayer);
        LockPlayerFieldControls();
        return TRUE;
    }
    return FALSE;
}

static bool8 CheckTrainer_(u8 trainerObjId)
{
    const u8 *script = GetObjectEventScriptPointerByObjectEventId(trainerObjId);
    u8 approachDistance;
    u16 scriptFlag = gObjectEvents[trainerObjId].trainerType;
    approachDistance = GetTrainerApproachDistance_(&gObjectEvents[trainerObjId]);
    if (approachDistance != 0)
    {
        if (scriptFlag >= TRAINER_TYPE_RUN_SCRIPT)
        {
            if (!FlagGet(scriptFlag) && script != NULL)
            {
                // TRAINER_TYPE_RUN_SCRIPT
                FlagSet(scriptFlag);
                TrainerApproachPlayer(&gObjectEvents[trainerObjId], approachDistance - 1);
                return trainerObjId + 2;
            }
            else
            {
                return 0;
            }
        }
        else if (script[1] == TRAINER_BATTLE_DOUBLE && GetMonsStateToDoubles() || GetTrainerFlagFromScriptPointer(script))
            return FALSE;
        ConfigureAndSetUpOneTrainerBattle(trainerObjId, script);
        TrainerApproachPlayer(&gObjectEvents[trainerObjId], approachDistance - 1);
        return TRUE;
    }
    return FALSE;
}

static u8 GetTrainerApproachDistance_(struct ObjectEvent *trainerObj)
{
    s16 x, y;
    u8 i;
    u8 approachDistance;

    PlayerGetDestCoords(&x, &y);
    if (trainerObj->trainerType == TRAINER_TYPE_NORMAL || trainerObj->trainerType >= TRAINER_TYPE_RUN_SCRIPT)  // can only see in one direction
    {
        approachDistance = sDirectionalApproachDistanceFuncs[trainerObj->facingDirection - 1](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
        return CheckPathBetweenTrainerAndPlayer(trainerObj, approachDistance, trainerObj->facingDirection);
    }
    else // TRAINER_TYPE_SEE_ALL_DIRECTIONS, TRAINER_TYPE_BURIED
    {
        for (i = 0; i < 4; i++)
        {
            approachDistance = sDirectionalApproachDistanceFuncs[i](trainerObj, trainerObj->trainerRange_berryTreeId, x, y);
            if (CheckPathBetweenTrainerAndPlayer(trainerObj, approachDistance, i + 1)) // directions are 1-4 instead of 0-3. south north west east
                return approachDistance;
        }
    }

    return 0;
}
