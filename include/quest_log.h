#ifndef GUARD_QUEST_LOG_H
#define GUARD_QUEST_LOG_H

#include "global.h"
#include "quest_log_battle.h"
#include "field_control_avatar.h"
#include "constants/quest_log.h"
#include "constants/battle.h"

// Layout of Quest Log script commands
#define QL_CMD_EVENT_MASK  0x0FFF
#define QL_CMD_COUNT_SHIFT 12
#define QL_CMD_COUNT_MASK  (0xF << QL_CMD_COUNT_SHIFT)

// Parameter to QuestLog_OnEscalatorWarp
#define QL_ESCALATOR_OUT 1
#define QL_ESCALATOR_IN  2

struct QuestLogAction
{
    union {
        struct {
            u8 localId;
            u8 mapNum;
            u8 mapGroup;
            u8 movementActionId;
        } a; // Data when type == 0
        struct {
            u8 localId;
            u8 mapNum;
            u8 mapGroup;
            u8 gfxState;
        } b; // Data when type == 1
        u8 fieldInput[4]; // Data when type == 2
        u8 raw[4];
    } data;
    u16 duration;
    u8 type;
};

struct QuestLogRepeatEventTracker
{
    u8 id;
    u8 numRepeats;
    u16 counter;
};

// Event data structs

// QL_EVENT_SWITCHED_PARTY_ORDER
struct QuestLogEvent_SwitchedPartyOrder
{
    u16 species1;
    u16 species2;
};

// QL_EVENT_USED_ITEM
// QL_EVENT_GAVE_HELD_ITEM
// QL_EVENT_GAVE_HELD_ITEM_BAG
// QL_EVENT_GAVE_HELD_ITEM_PC
// QL_EVENT_TOOK_HELD_ITEM
// QL_EVENT_DEPOSITED_ITEM_PC
// QL_EVENT_WITHDREW_ITEM_PC
struct QuestLogEvent_Item
{
    u16 itemId;
    u16 unused;
    u16 species;
    u16 itemParam;
};

// QL_EVENT_SWAPPED_HELD_ITEM
// QL_EVENT_SWAPPED_HELD_ITEM_PC
struct QuestLogEvent_SwappedHeldItem
{
    u16 takenItemId;
    u16 givenItemId;
    u16 species;
};

// QL_EVENT_LINK_TRADED
// QL_EVENT_LINK_TRADED_UNION
struct QuestLogEvent_Traded
{
    u16 speciesSent;
    u16 speciesReceived;
    u8 partnerName[PLAYER_NAME_LENGTH];
};

// QL_EVENT_LINK_BATTLED_SINGLE
// QL_EVENT_LINK_BATTLED_DOUBLE
// QL_EVENT_LINK_BATTLED_MULTI
// QL_EVENT_LINK_BATTLED_UNION
struct QuestLogEvent_LinkBattle
{
    u8 outcome;
    u8 playerNames[MAX_BATTLERS_COUNT - 1][PLAYER_NAME_LENGTH];
};

// QL_EVENT_SWITCHED_MONS_BETWEEN_BOXES
// QL_EVENT_SWITCHED_MONS_WITHIN_BOX
// QL_EVENT_SWITCHED_PARTY_MON_FOR_PC_MON
// QL_EVENT_MOVED_MON_BETWEEN_BOXES
// QL_EVENT_MOVED_MON_WITHIN_BOX
// QL_EVENT_WITHDREW_MON_PC
// QL_EVENT_DEPOSITED_MON_PC
// QL_EVENT_SWITCHED_MULTIPLE_MONS
struct QuestLogEvent_MovedBoxMon
{
    u16 species1;
    u16 species2;
    u8 box1;
    u8 box2;
};

// QL_EVENT_DEFEATED_TRAINER
// QL_EVENT_DEFEATED_GYM_LEADER
// QL_EVENT_DEFEATED_E4_MEMBER
// QL_EVENT_DEFEATED_CHAMPION
struct QuestLogEvent_TrainerBattle
{
    u16 trainerId;
    u16 speciesOpponent;
    u16 speciesPlayer;
    u8 hpFractionId;
    u8 mapSec;
};

// QL_EVENT_DEFEATED_WILD_MON
struct QuestLogEvent_WildBattle
{
    u16 defeatedSpecies;
    u16 caughtSpecies;
    u8 mapSec;
};

// QL_EVENT_DEPARTED
struct QuestLogEvent_Departed
{
    u8 mapSec;
    u8 locationId;
};

// QL_EVENT_USED_FIELD_MOVE
struct QuestLogEvent_FieldMove
{
    u16 species;
    u8 fieldMove;
    u8 mapSec;
};

// QL_EVENT_BOUGHT_ITEM
// QL_EVENT_SOLD_ITEM
struct QuestLogEvent_Shop
{
    u32 totalMoney; // Total amount of money spent buying or earned selling
    u16 lastItemId;
    u16 itemQuantity; // Total number of items bought or sold
    u8 mapSec;
    bool8 hasMultipleTransactions;
    u8 logEventId; // Either 0 (empty), 1 (bought) or 2 (sold)
};

// QL_EVENT_OBTAINED_STORY_ITEM
struct QuestLogEvent_StoryItem
{
    u16 itemId;
    u8 mapSec;
};

extern u8 __attribute__((long_call)) gQuestLogState;
extern u8 __attribute__((long_call)) gQuestLogPlaybackState;
extern struct FieldInput gQuestLogFieldInput;
extern struct QuestLogRepeatEventTracker gQuestLogRepeatEventTracker;
extern u16 __attribute__((long_call)) *gQuestLogDefeatedWildMonRecord;
extern u16 __attribute__((long_call)) *gQuestLogRecordingPointer;
extern u16 __attribute__((long_call)) gQuestLogCurActionIdx;

void __attribute__((long_call)) QuestLogRecordPlayerAvatarGfxTransition(u8);
void __attribute__((long_call)) SetQuestLogEvent(u16, const u16 *);
void __attribute__((long_call)) SetQLPlayedTheSlots(void);
void __attribute__((long_call)) QuestLog_RecordEnteredMap(u16);
u8 __attribute__((long_call)) QL_GetPlaybackState(void);
bool8 __attribute__((long_call)) QL_AvoidDisplay(void (*func)(void));
void __attribute__((long_call)) QuestLog_BackUpPalette(u16 offset, u16 size);
void __attribute__((long_call)) CommitQuestLogWindow1(void);
void __attribute__((long_call)) QuestLog_DrawPreviouslyOnQuestHeaderIfInPlaybackMode(void);
void __attribute__((long_call)) ResetQuestLog(void);
void __attribute__((long_call)) ResetTrainerFanClub(void);
void __attribute__((long_call)) TryStartQuestLogPlayback(u8 taskId);
void __attribute__((long_call)) SaveQuestLogData(void);
void __attribute__((long_call)) QuestLog_CutRecording(void);
void __attribute__((long_call)) ResetDeferredLinkEvent(void);
void __attribute__((long_call)) QL_FinishRecordingScene(void);
void __attribute__((long_call)) QuestLogEvents_HandleEndTrainerBattle(void);
void __attribute__((long_call)) *QuestLogGetFlagOrVarPtr(bool8 isFlag, u16 idx);
void __attribute__((long_call)) QuestLogSetFlagOrVar(bool8 isFlag, u16 idx, u16 value);
void __attribute__((long_call)) QL_AddASLROffset(void *oldSaveBlockPtr);
void __attribute__((long_call)) QL_UpdateObject(struct Sprite *sprite);
void __attribute__((long_call)) QuestLogRecordNPCStep(u8 a0, u8 a1, u8 a2, u8 a3);
bool8 __attribute__((long_call)) QL_IsTrainerSightDisabled(void);
void __attribute__((long_call)) QuestLog_OnEscalatorWarp(u8 direction);
void __attribute__((long_call)) QuestLogRecordPlayerAvatarGfxTransitionWithDuration(u8 movementActionId, u8 duration);
void __attribute__((long_call)) Special_UpdateTrainerFansAfterLinkBattle(void);
void __attribute__((long_call)) QuestLogRecordPlayerStep(u8 movementActionId);
void __attribute__((long_call)) QuestLogRecordPlayerStepWithDuration(u8 movementActionId, u8 duration);
void __attribute__((long_call)) QuestLogRecordNPCStepWithDuration(u8 localId, u8 mapNum, u8 mapGroup, u8 movementActionId, u8 duration);
void __attribute__((long_call)) QL_AfterRecordFishActionSuccessful(void);
void __attribute__((long_call)) QL_ResetDefeatedWildMonRecord(void);
void __attribute__((long_call)) QL_RestoreMapLayoutId(void);
void __attribute__((long_call)) QL_RecordFieldInput(struct FieldInput * fieldInput);
void __attribute__((long_call)) QL_TryRunActions(void);
void __attribute__((long_call)) RunQuestLogCB(void);
void __attribute__((long_call)) QL_HandleInput(void);
bool8 __attribute__((long_call)) QuestLogScenePlaybackIsEnding(void);
void __attribute__((long_call)) SetQuestLogEvent_Arrived(void);
bool8 __attribute__((long_call)) QuestLog_ShouldEndSceneOnMapChange(void);
void __attribute__((long_call)) QuestLog_AdvancePlayhead_(void);
void __attribute__((long_call)) QuestLog_InitPalettesBackup(void);
void __attribute__((long_call)) QL_InitSceneObjectsAndActions(void);
u8 __attribute__((long_call)) GetQuestLogStartType(void);
void __attribute__((long_call)) QL_CopySaveState(void);
void __attribute__((long_call)) QL_ResetPartyAndPC(void);
void __attribute__((long_call)) QL_StartRecordingAction(u16 eventId);
bool8 __attribute__((long_call)) QL_IsRoomToSaveAction(const void *cursor, size_t size);
bool8 __attribute__((long_call)) QL_IsRoomToSaveEvent(const void *cursor, size_t size);

void __attribute__((long_call)) QL_ResetEventStates(void);
void __attribute__((long_call)) QL_ResetRepeatEventTracker(void);
u16 __attribute__((long_call)) *QL_RecordAction_SceneEnd(u16 *);
u16 __attribute__((long_call)) *QL_LoadAction_Wait(u16 *, struct QuestLogAction *);
u16 __attribute__((long_call)) *QL_RecordAction_Input(u16 *, struct QuestLogAction *);
u16 __attribute__((long_call)) *QL_LoadAction_Input(u16 *, struct QuestLogAction *);
u16 __attribute__((long_call)) *QL_RecordAction_MovementOrGfxChange(u16 *, struct QuestLogAction *);
u16 __attribute__((long_call)) *QL_LoadAction_MovementOrGfxChange(u16 *, struct QuestLogAction *);
void __attribute__((long_call)) QL_EnableRecordingSteps(void);
u16 __attribute__((long_call)) *QL_SkipCommand(u16 *, u16 **);
void __attribute__((long_call)) QL_UpdateLastDepartedLocation(const u16 *);
u16 __attribute__((long_call)) *QL_LoadAction_SceneEnd(u16 *, struct QuestLogAction *);
bool8 __attribute__((long_call)) QL_LoadEvent(const u16 *);
bool8 __attribute__((long_call)) QL_TryRepeatEvent(const u16 *);
void __attribute__((long_call)) QL_RecordWait(u16);

#endif //GUARD_QUEST_LOG_H
