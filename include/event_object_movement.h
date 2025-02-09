#ifndef GUARD_EVENT_OBJECT_MOVEMENT_H
#define GUARD_EVENT_OBJECT_MOVEMENT_H

// Palette slots for overworld NPCs.
// The same standard set of palettes for overworld objects are normally always loaded at the same
// time while walking around the overworld. The only exceptions are the palettes for the player and
// the "special" NPC, which can be swapped out. This also means that e.g. two "special" NPCs
// with competing palettes cannot be properly loaded at the same time.
enum {
    PALSLOT_PLAYER,
    PALSLOT_PLAYER_REFLECTION,
    PALSLOT_NPC_1,
    PALSLOT_NPC_2,
    PALSLOT_NPC_3,
    PALSLOT_NPC_4,
    PALSLOT_NPC_1_REFLECTION,
    PALSLOT_NPC_2_REFLECTION,
    PALSLOT_NPC_3_REFLECTION,
    PALSLOT_NPC_4_REFLECTION,
    PALSLOT_NPC_SPECIAL,
    PALSLOT_NPC_SPECIAL_REFLECTION,
    OBJ_PALSLOT_COUNT
    // the remaining sprite palette slots (12-15) are used by field effects, the interface, etc.
};

enum SpinnerRunnerFollowPatterns
{
    RUNFOLLOW_ANY,
    RUNFOLLOW_NORTH_SOUTH,
    RUNFOLLOW_EAST_WEST,
    RUNFOLLOW_NORTH_WEST,
    RUNFOLLOW_NORTH_EAST,
    RUNFOLLOW_SOUTH_WEST,
    RUNFOLLOW_SOUTH_EAST,
    RUNFOLLOW_NORTH_SOUTH_WEST,
    RUNFOLLOW_NORTH_SOUTH_EAST,
    RUNFOLLOW_NORTH_EAST_WEST,
    RUNFOLLOW_SOUTH_EAST_WEST
};

struct StepAnimTable
{
    const union AnimCmd *const *anims;
    u8 animPos[4];
};

typedef void (*MovementAction)(u8 direction);

#define GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN   (1 << 0)
#define GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE    (1 << 1)
#define GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN   (1 << 2)
#define GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE    (1 << 3)
#define GROUND_EFFECT_FLAG_ICE_REFLECTION        (1 << 4)
#define GROUND_EFFECT_FLAG_REFLECTION            (1 << 5)
#define GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER (1 << 6)
#define GROUND_EFFECT_FLAG_SAND                  (1 << 7)
#define GROUND_EFFECT_FLAG_DEEP_SAND             (1 << 8)
#define GROUND_EFFECT_FLAG_RIPPLES               (1 << 9)
#define GROUND_EFFECT_FLAG_PUDDLE                (1 << 10)
#define GROUND_EFFECT_FLAG_SAND_PILE             (1 << 11)
#define GROUND_EFFECT_FLAG_LAND_IN_TALL_GRASS    (1 << 12)
#define GROUND_EFFECT_FLAG_LAND_IN_LONG_GRASS    (1 << 13)
#define GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER (1 << 14)
#define GROUND_EFFECT_FLAG_LAND_IN_DEEP_WATER    (1 << 15)
#define GROUND_EFFECT_FLAG_LAND_ON_NORMAL_GROUND (1 << 16)
#define GROUND_EFFECT_FLAG_SHORT_GRASS           (1 << 17)
#define GROUND_EFFECT_FLAG_HOT_SPRINGS           (1 << 18)
#define GROUND_EFFECT_FLAG_SEAWEED               (1 << 19)

struct PairedPalettes
{
    u16 tag;
    const u16 *data;
};

// Exported RAM declarations

// Exported ROM declarations

u8 __attribute__((long_call)) GetObjectEventIdByLocalIdAndMap(u8, u8, u8);
bool8 __attribute__((long_call)) TryGetObjectEventIdByLocalIdAndMap(u8, u8, u8, u8 *);
u8 __attribute__((long_call)) GetObjectEventIdByXY(s16, s16);
void __attribute__((long_call)) SetObjectEventDirection(struct ObjectEvent *, u8);
void __attribute__((long_call)) RemoveObjectEventByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup);
u16 __attribute__((long_call)) GetBoulderRevealFlagByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup);
void __attribute__((long_call)) LoadPlayerObjectReflectionPalette(u16, u8);
void __attribute__((long_call)) LoadSpecialObjectReflectionPalette(u16, u8);
void __attribute__((long_call)) TryMoveObjectEventToMapCoords(u8, u8, u8, s16, s16);
void __attribute__((long_call)) PatchObjectPalette(u16, u8);
void __attribute__((long_call)) SpawnObjectEventsOnReturnToField(s16 x, s16 y);
void __attribute__((long_call)) GetMapCoordsFromSpritePos(s16, s16, s16 *, s16 *);
u8 __attribute__((long_call)) GetFaceDirectionAnimNum(u8);
void __attribute__((long_call)) SetSpritePosToOffsetMapCoords(s16 *, s16 *, s16, s16);
void __attribute__((long_call)) ObjectEventClearHeldMovement(struct ObjectEvent *);
void __attribute__((long_call)) ObjectEventClearHeldMovementIfActive(struct ObjectEvent *);
u8 __attribute__((long_call)) CreateVirtualObject(u8 graphicsId, u8 virtualObjId, s16 x, s16 y, u8 elevation, u8 direction);
u8 __attribute__((long_call)) CreateObjectGraphicsSprite(u16 graphicsId, SpriteCallback callback, s16 x, s16 y, u8 subpriority);
u8 __attribute__((long_call)) TrySpawnObjectEvent(u8 localId, u8 mapNum, u8 mapGroup);
int SpawnSpecialObjectEventParameterized(u8, u8, u8, s16, s16, u8);
u8 __attribute__((long_call)) SpawnSpecialObjectEvent(struct ObjectEventTemplate *);
void __attribute__((long_call)) CameraObjectReset1(void);
void __attribute__((long_call)) CameraObjectReset2(void);
void __attribute__((long_call)) ObjectEventSetGraphicsId(struct ObjectEvent *, u8);
void __attribute__((long_call)) ObjectEventTurn(struct ObjectEvent *, u8);
void __attribute__((long_call)) ObjectEventTurnByLocalIdAndMap(u8, u8, u8, u8);
void __attribute__((long_call)) ObjectEventForceSetHeldMovement(struct ObjectEvent *, u8);
const struct ObjectEventGraphicsInfo *GetObjectEventGraphicsInfo(u8);
void __attribute__((long_call)) SetObjectInvisibility(u8 localId, u8 mapNum, u8 mapGroup, u8 state);
void __attribute__((long_call)) FreeAndReserveObjectSpritePalettes(void);
void __attribute__((long_call)) SetObjectPositionByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);
void __attribute__((long_call)) ResetObjectSubpriority(u8 localId, u8 mapNum, u8 mapGroup);
void __attribute__((long_call)) SetObjectSubpriority(u8 localId, u8 mapNum, u8 mapGroup, u8 subpriority);
void __attribute__((long_call)) ObjectEventGetLocalIdAndMap(struct ObjectEvent *objectEvent, void *localId, void *mapNum, void *mapGroup);
void __attribute__((long_call)) ShiftObjectEventCoords(struct ObjectEvent *, s16, s16);
void __attribute__((long_call)) TryOverrideObjectEventTemplateCoords(u8, u8, u8);
void __attribute__((long_call)) UpdateObjectEventCurrentMovement(struct ObjectEvent *, struct Sprite *, bool8(struct ObjectEvent *, struct Sprite *));
u8 __attribute__((long_call)) ObjectEventFaceOppositeDirection(struct ObjectEvent *, u8);
u8 __attribute__((long_call)) GetOppositeDirection(u8);
u8 __attribute__((long_call)) GetWalkInPlaceFasterMovementAction(u32);
u8 __attribute__((long_call)) GetStepInPlaceDelay8AnimId(u32);
u8 __attribute__((long_call)) GetWalkInPlaceNormalMovementAction(u32);
u8 __attribute__((long_call)) GetWalkInPlaceSlowMovementAction(u32);
u8 __attribute__((long_call)) GetWalkInPlaceFastMovementAction(u32);
u8 __attribute__((long_call)) GetCollisionAtCoords(struct ObjectEvent *, s16, s16, u32);
void __attribute__((long_call)) MoveCoords(u8, s16 *, s16 *);
bool8 __attribute__((long_call)) ObjectEventIsHeldMovementActive(struct ObjectEvent *);
u8 __attribute__((long_call)) ObjectEventClearHeldMovementIfFinished(struct ObjectEvent *);
u8 __attribute__((long_call)) GetObjectEventIdByPosition(u16 x, u16 y, u8 elevation);
void __attribute__((long_call)) QL_UpdateObjectEventCurrentMovement(struct ObjectEvent *, struct Sprite *);
bool8 __attribute__((long_call)) ObjectEventSetHeldMovement(struct ObjectEvent *, u8);
void __attribute__((long_call)) ShiftStillObjectEventCoords(struct ObjectEvent *);
void __attribute__((long_call)) OverrideMovementTypeForObjectEvent(const struct ObjectEvent *, u8);
void __attribute__((long_call)) SetTrainerMovementType(struct ObjectEvent *, u8);
u8 __attribute__((long_call)) GetFishingDirectionAnimNum(u8 direction);
u8 __attribute__((long_call)) GetFishingNoCatchDirectionAnimNum(u8 a0);
void __attribute__((long_call)) ObjectEventSetGraphicsId(struct ObjectEvent *objectEvent, u8 a1);
u8 __attribute__((long_call)) CreateFameCheckerObject(u8 graphicsId, u8 localId, s16 x, s16 y);
void __attribute__((long_call)) InitObjectEventPalettes(u8 mode);
bool8 __attribute__((long_call)) ObjectEventIsMovementOverridden(struct ObjectEvent *objectEvent);
u8 __attribute__((long_call)) ObjectEventCheckHeldMovementStatus(struct ObjectEvent *objectEvent);
u8 __attribute__((long_call)) GetWalkNormalMovementAction(u32);
u8 __attribute__((long_call)) GetWalkFastMovementAction(u32);
u8 __attribute__((long_call)) GetWalkFasterMovementAction(u32);
u8 __attribute__((long_call)) GetWalkSlowerMovementAction(u32 direction);
u8 __attribute__((long_call)) GetTrainerFacingDirectionMovementType(u8 direction);
u8 __attribute__((long_call)) GetFaceDirectionMovementAction(u32);
u8 __attribute__((long_call)) GetFaceDirectionFastMovementAction(u32);
void __attribute__((long_call)) CameraObjectSetFollowedObjectId(u8 objectId);
void __attribute__((long_call)) UnfreezeObjectEvents(void);
u8 __attribute__((long_call)) GetSlideMovementAction(u32);
u8 __attribute__((long_call)) GetJumpInPlaceMovementAction(u32);
u8 __attribute__((long_call)) GetJumpMovementAction(u32);
u8 __attribute__((long_call)) GetJump2MovementAction(u32);
bool8 __attribute__((long_call)) UpdateWalkSlowerAnim(struct Sprite *sprite);
void __attribute__((long_call)) SetJumpSpriteData(struct Sprite *, u8, u8, u8);
u8 __attribute__((long_call)) DoJumpSpriteMovement(struct Sprite *);
u8 __attribute__((long_call)) DoJumpSpecialSpriteMovement(struct Sprite *);
void __attribute__((long_call)) TurnVirtualObject(u8 virtualObjId, u8 direction);
const u8 __attribute__((long_call)) *GetObjectEventScriptPointerByObjectEventId(u8 objectEventId);
u8 __attribute__((long_call)) GetFirstInactiveObjectEventId(void);
u8 __attribute__((long_call)) GetCollisionFlagsAtCoords(struct ObjectEvent * objectEvent, s16 x, s16 y, u8 direction);
void __attribute__((long_call)) OverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent);
void __attribute__((long_call)) CancelPlayerForcedMovement(void);
void __attribute__((long_call)) FreezeObjectEvents(void);
bool8 __attribute__((long_call)) FreezeObjectEvent(struct ObjectEvent *);
void __attribute__((long_call)) UnfreezeObjectEvent(struct ObjectEvent *);
void __attribute__((long_call)) FreezeObjectEventsExceptOne(u8 objEventId);
void __attribute__((long_call)) SetVirtualObjectGraphics(u8 virtualObjId, u8 direction);
void __attribute__((long_call)) SetVirtualObjectInvisibility(u8 virtualObjId, bool32 invisible);
bool32 __attribute__((long_call)) IsVirtualObjectInvisible(u8 virtualObjId);
void __attribute__((long_call)) SetVirtualObjectSpriteAnim(u8 virtualObjId, u8 animNo);
bool32 __attribute__((long_call)) IsVirtualObjectAnimating(u8 virtualObjId);
u8 __attribute__((long_call)) GetJumpSpecialMovementAction(u32 direction);
void __attribute__((long_call)) EnableObjectGroundEffectsByXY(s16 x, s16 y);
void __attribute__((long_call)) MoveObjectEventToMapCoords(struct ObjectEvent *objectEvent, s16 x, s16 y);
u8 __attribute__((long_call)) CreateCopySpriteAt(struct Sprite *sprite, s16 x, s16 y, u8 subpriority);
u16 __attribute__((long_call)) GetObjectPaletteTag(u8 paletteIndex);
void __attribute__((long_call)) SetSpritePosToMapCoords(s16 x, s16 y, s16 *x2, s16 *y2);
void __attribute__((long_call)) UpdateObjectEventSpriteInvisibility(struct Sprite *sprite, bool8 invisible);
u8 __attribute__((long_call)) ElevationToPriority(u8 elevation);
void __attribute__((long_call)) ObjectEventUpdateElevation(struct ObjectEvent *pObject);
void __attribute__((long_call)) SetObjectSubpriorityByElevation(u8 elevation, struct Sprite *sprite, u8 offset);
void __attribute__((long_call)) CopyObjectGraphicsInfoToSpriteTemplate(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables);
u8 __attribute__((long_call)) AddCameraObject(u8 trackedSpriteId);
void __attribute__((long_call)) UpdateObjectEventsForCameraUpdate(s16 x, s16 y);
void __attribute__((long_call)) SpriteCB_VirtualObject(struct Sprite *);
void __attribute__((long_call)) SetMovementDelay(struct Sprite *, s16);
bool8 __attribute__((long_call)) WaitForMovementDelay(struct Sprite *);
void __attribute__((long_call)) SetSpriteDataForNormalStep(struct Sprite *, u8, u8);
bool8 __attribute__((long_call)) NpcTakeStep(struct Sprite *sprite);
void __attribute__((long_call)) SetWalkSlowerSpriteData(struct Sprite *, u8);
void __attribute__((long_call)) SetWalkSlowestSpriteData(struct Sprite *, u8);
bool8 __attribute__((long_call)) UpdateWalkSlowestAnim(struct Sprite *sprite);
void __attribute__((long_call)) SetWalkSlowSpriteData(struct Sprite *, u8);
bool8 __attribute__((long_call)) UpdateWalkSlowAnim(struct Sprite *sprite);
void __attribute__((long_call)) DoShadowFieldEffect(struct ObjectEvent *);
void __attribute__((long_call)) SetRunSlowSpriteData(struct Sprite *, u8);
bool8 __attribute__((long_call)) UpdateRunSlowAnim(struct Sprite *sprite);
void __attribute__((long_call)) SetAndStartSpriteAnim(struct Sprite *, u8, u8);
bool8 __attribute__((long_call)) SpriteAnimEnded(struct Sprite *);
u8 __attribute__((long_call)) ObjectEventGetHeldMovementActionId(struct ObjectEvent *objectEvent);
u8 __attribute__((long_call)) GetMoveDirectionAnimNum(u8 direction);

// Exported data declarations

extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];
extern const struct SpritePalette gSpritePalette_GeneralFieldEffect1;
extern const struct SpriteTemplate * const gFieldEffectObjectTemplatePointers[];
extern const struct OamData gObjectEventBaseOam_32x32;
extern const u16 gFieldEffectObjectPic_CutGrass[];
extern const u16 gFieldEffectPal_CutGrass[];
extern const u8 gReflectionEffectPaletteMap[];
u8 __attribute__((long_call)) GetLedgeJumpDirection(s16 x, s16 y, u8 direction);
u8 __attribute__((long_call)) GetGlideMovementAction(u32 direction);
u8 __attribute__((long_call)) GetRideWaterCurrentMovementAction(u32 direction);
u8 __attribute__((long_call)) GetPlayerRunMovementAction(u32 direction);
u8 __attribute__((long_call)) GetPlayerRunSlowMovementAction(u32 direction);
u8 __attribute__((long_call)) GetWalkSlowMovementAction(u32 direction);
u8 __attribute__((long_call)) GetSpinMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroWheelieFaceDirectionMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroPopWheelieFaceDirectionMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroEndWheelieFaceDirectionMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroWheelieHopFaceDirectionMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroWheelieHopMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroPopWheelieMoveMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroWheelieJumpMovementAction(u32 direction);
u8 __attribute__((long_call)) GetJumpInPlaceTurnAroundMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroWheelieInPlaceMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroPopWheelieMoveMovementAction(u32 direction);
u8 __attribute__((long_call)) GetAcroWheelieMoveMovementAction(u32 direction);
u8 __attribute__((long_call)) GetJumpSpecialWithEffectMovementAction(u32 direction);
u8 __attribute__((long_call)) GetFishingBiteDirectionAnimNum(u8 direction);
void __attribute__((long_call)) TrySpawnObjectEvents(s16 cameraX, s16 cameraY);
void __attribute__((long_call)) ResetObjectEvents(void);

#endif // GUARD_EVENT_OBJECT_MOVEMENT_H
