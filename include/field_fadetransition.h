#ifndef GUARD_FIELD_FADETRANSITION_H
#define GUARD_FIELD_FADETRANSITION_H

#include "global.h"

void __attribute__((long_call)) FieldCB_RushInjuredPokemonToCenter(void);
void __attribute__((long_call)) DoWarp(void);
void __attribute__((long_call)) DoDiveWarp(void);
void __attribute__((long_call)) DoDoorWarp(void);

void __attribute__((long_call)) DoFallWarp(void);
void __attribute__((long_call)) DoTeleportWarp(void);
void __attribute__((long_call)) DoTeleport2Warp(void);
void __attribute__((long_call)) FieldCB_DefaultWarpExit(void);
void __attribute__((long_call)) WarpFadeOutScreen(void);
void __attribute__((long_call)) FieldCB_ContinueScriptHandleMusic(void);
void __attribute__((long_call)) FadeInFromBlack(void);
void __attribute__((long_call)) FadeTransition_FadeInOnReturnToStartMenu(void);
void __attribute__((long_call)) WarpFadeInScreen(void);

void __attribute__((long_call)) FieldCB_ContinueScriptUnionRoom(void);

bool32 __attribute__((long_call)) FieldFadeTransitionBackgroundEffectIsFinished(void);
void __attribute__((long_call)) palette_bg_faded_fill_black(void);
void __attribute__((long_call)) DoStairWarp(u16 metatileBehavior, u16 delay);
void __attribute__((long_call)) DoEscalatorWarp(u8 a0);
void __attribute__((long_call)) DoLavaridgeGymB1FWarp(void);
void __attribute__((long_call)) DoLavaridgeGym1FWarp(void);
void __attribute__((long_call)) DoTeleportWarp(void);
void __attribute__((long_call)) DoUnionRoomWarp(void);
void __attribute__((long_call)) FieldCB_ReturnToFieldWirelessLink(void);
void __attribute__((long_call)) FieldCB_ReturnToFieldCableLink(void);
bool8 __attribute__((long_call)) FieldCB_ReturnToFieldOpenStartMenu(void);
void __attribute__((long_call)) FieldCB_ContinueScript(void);
void __attribute__((long_call)) FieldCB_ContinueScriptHandleMusic(void);
void __attribute__((long_call)) FieldCB_WarpExitFadeFromBlack(void);

#endif // GUARD_FIELD_FADETRANSITION_H
