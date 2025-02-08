#ifndef GUARD_FIELD_PLAYER_AVATAR_H
#define GUARD_FIELD_PLAYER_AVATAR_H

#include "global.h"

void __attribute__((long_call)) ClearPlayerAvatarInfo(void);
void __attribute__((long_call)) SetPlayerAvatarExtraStateTransition(u8, u8);
u8 __attribute__((long_call)) GetPlayerAvatarGenderByGraphicsId(u8);
bool8 __attribute__((long_call)) TestPlayerAvatarFlags(u8);
void __attribute__((long_call)) PlayerGetDestCoords(s16 *, s16 *);
u8 __attribute__((long_call)) GetPlayerFacingDirection(void);
u8 __attribute__((long_call)) GetPlayerMovementDirection(void);
u8 __attribute__((long_call)) PlayerGetCopyableMovement(void);
void __attribute__((long_call)) MovePlayerNotOnBike(u8 direction, u16 heldKeys);

void __attribute__((long_call)) MovementType_Player(struct Sprite *sprite);
void __attribute__((long_call)) HandleEnforcedLookDirectionOnPlayerStopMoving(void);
void __attribute__((long_call)) StopPlayerAvatar(void);
void __attribute__((long_call)) GetXYCoordsOneStepInFrontOfPlayer(s16 *xPtr, s16 *yPtr);
u8 __attribute__((long_call)) GetPlayerAvatarGraphicsIdByStateId(u8);
void __attribute__((long_call)) SetPlayerAvatarStateMask(u8 mask);
void __attribute__((long_call)) AlignFishingAnimationFrames(struct Sprite *sprite);
void __attribute__((long_call)) CreateStopSurfingTask_NoMusicChange(u8 direction);
void __attribute__((long_call)) SavePlayerFacingDirectionForTeleport(u8 direction);
void __attribute__((long_call)) SetPlayerAvatarTransitionFlags(u16 flags);
bool8 __attribute__((long_call)) IsPlayerFacingSurfableFishableWater(void);
void __attribute__((long_call)) StartFishing(u8 secondaryId);
u8 __attribute__((long_call)) GetPlayerAvatarObjectId(void);
u8 __attribute__((long_call)) PlayerGetElevation(void);
u8 __attribute__((long_call)) GetPlayerAvatarGraphicsIdByCurrentState(void);
void __attribute__((long_call)) StartPlayerAvatarSummonMonForFieldMoveAnim(void);
void __attribute__((long_call)) SetPlayerInvisibility(bool8);
void __attribute__((long_call)) StartTeleportInPlayerAnim(void);
void __attribute__((long_call)) StartTeleportWarpOutPlayerAnim(void);
bool32 __attribute__((long_call)) WaitTeleportWarpOutPlayerAnim(void);
bool32 __attribute__((long_call)) WaitTeleportInPlayerAnim(void);
bool8 __attribute__((long_call)) PartyHasMonWithSurf(void);
bool8 __attribute__((long_call)) IsPlayerSurfingNorth(void);
u8 __attribute__((long_call)) player_get_pos_including_state_based_drift(s16 *x, s16 *y);
void __attribute__((long_call)) StartPlayerAvatarVsSeekerAnim(void);
u8 __attribute__((long_call)) GetRivalAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender);
u8 __attribute__((long_call)) GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender);
u8 __attribute__((long_call)) CheckForObjectEventCollision(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction, u8 metatileBehavior);
void __attribute__((long_call)) PlayerWalkSlower(u8 direction);
void __attribute__((long_call)) PlayerWalkSlow(u8 direction);
void __attribute__((long_call)) PlayerWalkNormal(u8 direction);
void __attribute__((long_call)) PlayerWalkFast(u8 direction);
void __attribute__((long_call)) PlayerGlide(u8 direction);
void __attribute__((long_call)) PlayerRideWaterCurrent(u8 direction);
void __attribute__((long_call)) PlayerWalkFaster(u8 direction);
void __attribute__((long_call)) PlayerRun(u8 direction);
void __attribute__((long_call)) PlayerRunSlow(u8 direction);
void __attribute__((long_call)) PlayerOnBikeCollide(u8 direction);
void __attribute__((long_call)) PlayerNotOnBikeCollide(u8 direction);
void __attribute__((long_call)) PlayerFaceDirection(u8 direction);
void __attribute__((long_call)) PlayerFaceDirectionFast(u8 direction);
void __attribute__((long_call)) PlayerTurnInPlace(u8 direction);
void __attribute__((long_call)) PlayerJumpLedge(u8 direction);
void __attribute__((long_call)) PlayerShakeHeadOrWalkInPlace(void);
void __attribute__((long_call)) player_step(u8 direction, u16 newKeys, u16 heldKeys);
bool32 __attribute__((long_call)) PlayerIsMovingOnRockStairs(u8 direction);
void __attribute__((long_call)) UpdatePlayerAvatarTransitionState(void);
void __attribute__((long_call)) InitPlayerAvatar(s16 x, s16 y, u8 direction, u8 gender);
void __attribute__((long_call)) PlayerUseAcroBikeOnBumpySlope(u8 direction);
u8 __attribute__((long_call)) GetRSAvatarGraphicsIdByGender(u8 gender);

#endif //GUARD_FIELD_PLAYER_AVATAR_H
