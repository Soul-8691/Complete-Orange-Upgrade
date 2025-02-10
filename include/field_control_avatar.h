#ifndef GUARD_FIELD_CONTROL_AVATAR_H
#define GUARD_FIELD_CONTROL_AVATAR_H

#include "global.h"

struct FieldInput
{
    bool8 pressedAButton:1;
    bool8 checkStandardWildEncounter:1;
    bool8 pressedStartButton:1;
    bool8 pressedSelectButton:1;
    bool8 heldDirection:1;
    bool8 heldDirection2:1;
    bool8 tookStep:1;
    bool8 pressedBButton:1;
    bool8 pressedRButton:1;
    bool8 input_field_1_0:1;
    bool8 input_field_1_1:1;
    bool8 input_field_1_2:1;
    bool8 input_field_1_3:1;
    u8 dpadDirection;
};

extern struct FieldInput gFieldInputRecord;

void __attribute__((long_call)) RestartWildEncounterImmunitySteps(void);
void __attribute__((long_call)) ClearPoisonStepCounter(void);
int SetCableClubWarp(void);
void __attribute__((long_call)) HandleBoulderFallThroughHole(struct ObjectEvent *);
bool8 __attribute__((long_call)) dive_warp(struct MapPosition * pos, u16 behavior);
bool8 __attribute__((long_call)) IsDirectionalStairWarpMetatileBehavior(u16 metatileBehavior, u8 playerDirection);
const u8 * __attribute__((long_call))GetInteractedLinkPlayerScript(struct MapPosition *position, u8 metatileBehavior, u8 direction);
const u8 * __attribute__((long_call))GetCoordEventScriptAtMapPosition(struct MapPosition *position);
void __attribute__((long_call)) FieldClearPlayerInput(struct FieldInput *input);
int ProcessPlayerFieldInput(struct FieldInput *input);
void __attribute__((long_call)) FieldInput_HandleCancelSignpost(struct FieldInput * input);
void __attribute__((long_call)) FieldGetPlayerInput(struct FieldInput *input, u16 newKeys, u16 heldKeys);
void __attribute__((long_call)) HandleBoulderActivateVictoryRoadSwitch(u16 x, u16 y);

#endif //GUARD_FIELD_CONTROL_AVATAR_H
