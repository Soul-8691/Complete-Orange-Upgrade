#include "../include/global.h"
#include "../include/script.h"
#include "../include/event_data.h"
#include "../include/quest_log.h"
#include "../include/mystery_gift.h"
#include "../include/constants/maps.h"
#include "../include/constants/map_scripts.h"

#include "../include/trainer_see.h"
#include "../include/event_object_movement.h"

extern struct ScriptContext sGlobalScriptContext;

// trainer sight scripts
bool8 LoadTrainerObjectScript(void)
{
    sGlobalScriptContext.scriptPtr = GetObjectEventScriptPointerByObjectEventId(gSelectedObjectEvent);
    return TRUE;
}