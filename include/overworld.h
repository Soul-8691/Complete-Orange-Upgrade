#ifndef GUARD_OVERWORLD_H
#define GUARD_OVERWORLD_H

#include "global.h"
#include "main.h"

#define LINK_KEY_CODE_NULL 0x00
#define LINK_KEY_CODE_EMPTY 0x11
#define LINK_KEY_CODE_DPAD_DOWN 0x12
#define LINK_KEY_CODE_DPAD_UP 0x13
#define LINK_KEY_CODE_DPAD_LEFT 0x14
#define LINK_KEY_CODE_DPAD_RIGHT 0x15
#define LINK_KEY_CODE_READY 0x16
#define LINK_KEY_CODE_EXIT_ROOM 0x17
#define LINK_KEY_CODE_START_BUTTON 0x18
#define LINK_KEY_CODE_A_BUTTON 0x19
#define LINK_KEY_CODE_IDLE 0x1A

// These two are a hack to stop user input until link stuff can be
// resolved.
#define LINK_KEY_CODE_HANDLE_RECV_QUEUE 0x1B
#define LINK_KEY_CODE_HANDLE_SEND_QUEUE 0x1C

#define LINK_KEY_CODE_EXIT_SEAT 0x1D

#define MOVEMENT_MODE_FREE 0
#define MOVEMENT_MODE_FROZEN 1
#define MOVEMENT_MODE_SCRIPTED 2

struct LinkPlayerObjectEvent
{
    u8 active;
    u8 linkPlayerId;
    u8 objEventId;
    u8 movementMode;
};

struct CreditsOverworldCmd
{
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
};

/* gDisableMapMusicChangeOnMapLoad */
#define MUSIC_DISABLE_OFF 0
#define MUSIC_DISABLE_STOP 1
#define MUSIC_DISABLE_KEEP 2

extern const struct Coords32 gDirectionToVectors[];

extern struct LinkPlayerObjectEvent gLinkPlayerObjectEvents[4];
extern MainCallback gFieldCallback;

extern struct WarpData gLastUsedWarp;

extern u8 __attribute__((long_call)) gExitStairsMovementDisabled;
extern u8 __attribute__((long_call)) gFieldLinkPlayerCount;
extern u8 __attribute__((long_call)) gLocalLinkPlayerId;

void __attribute__((long_call)) IncrementGameStat(u8 index);

void __attribute__((long_call)) SetObjEventTemplateCoords(u8, s16, s16);
void __attribute__((long_call)) SetObjEventTemplateMovementType(u8, u8);

void __attribute__((long_call)) SetWarpDestination(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);

void __attribute__((long_call)) SetDynamicWarp(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId);
void __attribute__((long_call)) SetDynamicWarpWithCoords(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
void __attribute__((long_call)) SetFixedDiveWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
void __attribute__((long_call)) SetFixedHoleWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
void __attribute__((long_call)) SetEscapeWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y);
void __attribute__((long_call)) Overworld_SetHealLocationWarp(u8);
void __attribute__((long_call)) SetWarpDestinationToEscapeWarp(void);
void __attribute__((long_call)) SetWarpDestinationToLastHealLocation(void);
u8 __attribute__((long_call)) IsMapTypeOutdoors(u8 mapType);
void __attribute__((long_call)) Overworld_ClearSavedMusic(void);
bool32 __attribute__((long_call)) Overworld_MusicCanOverrideMapMusic(u16 song);

void __attribute__((long_call)) SetFlashLevel(s32 a1);
u8 __attribute__((long_call)) Overworld_GetFlashLevel(void);

void __attribute__((long_call)) Overworld_SetSavedMusic(u16);
void __attribute__((long_call)) Overworld_ChangeMusicToDefault(void);
void __attribute__((long_call)) Overworld_ChangeMusicTo(u16);

bool32 __attribute__((long_call)) IsUpdateLinkStateCBActive(void);

void __attribute__((long_call)) ClearLinkPlayerObjectEvents(void);
const struct MapHeader *const Overworld_GetMapHeaderByGroupAndId(u16, u16);
void __attribute__((long_call)) ObjectEventMoveDestCoords(struct ObjectEvent *, u32, s16 *, s16 *);
void __attribute__((long_call)) CB2_ReturnToField(void);
void __attribute__((long_call)) CB2_ReturnToFieldContinueScriptPlayMapMusic(void);
void __attribute__((long_call)) WarpIntoMap(void);
u8 __attribute__((long_call)) GetMapTypeByGroupAndId(s8 mapGroup, s8 mapNum);
void __attribute__((long_call)) SetWarpDestinationToMapWarp(s8 mapGroup, s8 mapNum, s8 warpNum);
void __attribute__((long_call)) SetWarpDestinationToDynamicWarp(u8 unused);

u32 __attribute__((long_call)) GetGameStat(u8 statId);
void __attribute__((long_call)) SetGameStat(u8 statId, u32 value);

void __attribute__((long_call)) CB2_ContinueSavedGame(void);
void __attribute__((long_call)) Overworld_SetWarpDestinationFromWarp(struct WarpData *);
void __attribute__((long_call)) CB2_SetUpOverworldForQLPlayback(void);
void __attribute__((long_call)) CB2_SetUpOverworldForQLPlaybackWithWarpExit(void);
void __attribute__((long_call)) CB2_EnterFieldFromQuestLog(void);
void __attribute__((long_call)) Overworld_PlaySpecialMapMusic(void);

u8 __attribute__((long_call)) GetCurrentRegionMapSectionId(void);

void __attribute__((long_call)) SetCurrentMapLayout(u16 mapLayoutId);
void __attribute__((long_call)) SetWarpDestinationToFixedHoleWarp(s16 x, s16 y);

void __attribute__((long_call)) ResetInitialPlayerAvatarState(void);
void __attribute__((long_call)) CleanupOverworldWindowsAndTilemaps(void);
u32 __attribute__((long_call)) ComputeWhiteOutMoneyLoss(void);

extern u8 __attribute__((long_call)) gDisableMapMusicChangeOnMapLoad;
extern u8 __attribute__((long_call)) gGlobalFieldTintMode;

extern bool8 (* gFieldCallback2)(void);

void __attribute__((long_call)) SetLastHealLocationWarp(u8 healLocaionId);
void __attribute__((long_call)) LoadMapFromCameraTransition(u8 mapGroup, u8 mapNum);
void __attribute__((long_call)) CB2_ReturnToFieldFromDiploma(void);
void __attribute__((long_call)) CB2_OverworldBasic(void);
void __attribute__((long_call)) CB2_NewGame(void);
bool8 __attribute__((long_call)) IsMapTypeOutdoors(u8 mapType);
bool8 __attribute__((long_call)) Overworld_MapTypeAllowsTeleportAndFly(u8 mapType);
void __attribute__((long_call)) Overworld_ResetStateAfterTeleport(void);

void __attribute__((long_call)) Overworld_FadeOutMapMusic(void);
void __attribute__((long_call)) CB2_LoadMap(void);
bool8 __attribute__((long_call)) BGMusicStopped(void);
bool8 __attribute__((long_call)) IsMapTypeIndoors(u8 mapType);
bool32 __attribute__((long_call)) Overworld_IsBikingAllowed(void);
void __attribute__((long_call)) Overworld_ResetStateAfterDigEscRope(void);
bool32 __attribute__((long_call)) Overworld_LinkRecvQueueLengthMoreThan2(void);
u8 __attribute__((long_call)) GetCurrentMapType(void);

u8 __attribute__((long_call)) GetLastUsedWarpMapType(void);
const struct MapHeader *const GetDestinationWarpMapHeader(void);
void __attribute__((long_call)) TryFadeOutOldMapMusic(void);
void __attribute__((long_call)) CB2_ReturnToFieldCableClub(void);
void __attribute__((long_call)) ResetGameStats(void);

void __attribute__((long_call)) Overworld_CreditsMainCB(void);
bool32 __attribute__((long_call)) Overworld_DoScrollSceneForCredits(u8 *, const struct CreditsOverworldCmd *, u8);

bool32 __attribute__((long_call)) IsSendingKeysOverCable(void);

void __attribute__((long_call)) CB2_ReturnToFieldWithOpenMenu(void);
void __attribute__((long_call)) CB2_WhiteOut(void);
void __attribute__((long_call)) CB2_ReturnToFieldFromMultiplayer(void);
void __attribute__((long_call)) ApplyNewEncryptionKeyToGameStats(u32 newKey);
void __attribute__((long_call)) SetContinueGameWarpToDynamicWarp(int);

void __attribute__((long_call)) SetContinueGameWarpToHealLocation(u8 loc);

void __attribute__((long_call)) UpdateAmbientCry(s16 *state, u16 *delayCounter);
void __attribute__((long_call)) SetWarpDestinationToHealLocation(u8 a0);
bool32 __attribute__((long_call)) Overworld_SendKeysToLinkIsRunning(void);
bool32 __attribute__((long_call)) Overworld_RecvKeysFromLinkIsRunning(void);
void __attribute__((long_call)) OverworldWhiteOutGetMoneyLoss(void);
u8 __attribute__((long_call)) GetCurrentMapBattleScene(void);
void __attribute__((long_call)) Overworld_ResetStateAfterFly(void);
bool8 __attribute__((long_call)) MetatileBehavior_IsSurfableInSeafoamIslands(u16 metatileBehavior);
void __attribute__((long_call)) Overworld_ResetMapMusic(void);
u16 __attribute__((long_call)) QueueExitLinkRoomKey(void);
u16 __attribute__((long_call)) SetInCableClubSeat(void);
u32 __attribute__((long_call)) GetCableClubPartnersReady(void);
u16 __attribute__((long_call)) SetStartedCableClubActivity(void);
u16 __attribute__((long_call)) SetLinkWaitingForScript(void);
void __attribute__((long_call)) SetMainCallback1(MainCallback cb);
void __attribute__((long_call)) CB1_Overworld(void);
void __attribute__((long_call)) CB2_ReturnToFieldContinueScript(void);
u8 __attribute__((long_call)) GetLastUsedWarpMapSectionId(void);
void __attribute__((long_call)) StoreInitialPlayerAvatarState(void);
void __attribute__((long_call)) UpdateEscapeWarp(s16 x, s16 y);
bool8 __attribute__((long_call)) SetDiveWarpEmerge(u16 x, u16 y);
bool8 __attribute__((long_call)) SetDiveWarpDive(u16 x, u16 y);

extern u16 __attribute__((long_call)) *gBGTilemapBuffers1;
extern u16 __attribute__((long_call)) *gBGTilemapBuffers2;
extern u16 __attribute__((long_call)) *gBGTilemapBuffers3;
extern u16 __attribute__((long_call)) gHeldKeyCodeToSend;

#endif //GUARD_OVERWORLD_H
