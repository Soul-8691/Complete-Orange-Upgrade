#ifndef GUARD_EVENT_DATA_H
#define GUARD_EVENT_DATA_H

#include "global.h"

extern u16 __attribute__((long_call)) gSpecialVar_0x8000;
extern u16 __attribute__((long_call)) gSpecialVar_0x8001;
extern u16 __attribute__((long_call)) gSpecialVar_0x8002;
extern u16 __attribute__((long_call)) gSpecialVar_0x8003;
extern u16 __attribute__((long_call)) gSpecialVar_0x8004;
extern u16 __attribute__((long_call)) gSpecialVar_0x8005;
extern u16 __attribute__((long_call)) gSpecialVar_0x8006;
extern u16 __attribute__((long_call)) gSpecialVar_0x8007;
extern u16 __attribute__((long_call)) gSpecialVar_0x8008;
extern u16 __attribute__((long_call)) gSpecialVar_0x8009;
extern u16 __attribute__((long_call)) gSpecialVar_0x800A;
extern u16 __attribute__((long_call)) gSpecialVar_0x800B;
extern u16 __attribute__((long_call)) gSpecialVar_Facing;
extern u16 __attribute__((long_call)) gSpecialVar_Result;
extern u16 __attribute__((long_call)) gSpecialVar_LastTalked;
extern u16 __attribute__((long_call)) gSpecialVar_MonBoxId;
extern u16 __attribute__((long_call)) gSpecialVar_MonBoxPos;
extern u16 __attribute__((long_call)) gSpecialVar_TextColor;
extern u16 __attribute__((long_call)) gSpecialVar_PrevTextColor;

void __attribute__((long_call)) InitEventData(void);
void __attribute__((long_call)) ClearTempFieldEventData(void);
void __attribute__((long_call)) ClearUpperFlags(void);
void __attribute__((long_call)) DisableNationalPokedex(void);
void __attribute__((long_call)) EnableNationalPokedex(void);
bool32 __attribute__((long_call)) IsNationalPokedexEnabled(void);
void __attribute__((long_call)) DisableMysteryEvent(void);
void __attribute__((long_call)) EnableMysteryEvent(void);
bool32 __attribute__((long_call)) IsMysteryEventEnabled(void);
void __attribute__((long_call)) DisableMysteryGift(void);
void __attribute__((long_call)) EnableMysteryGift(void);
bool32 __attribute__((long_call)) IsMysteryGiftEnabled(void);
void __attribute__((long_call)) DisableResetRTC(void);
void __attribute__((long_call)) EnableResetRTC(void);
bool32 __attribute__((long_call)) CanResetRTC(void);
u16 __attribute__((long_call)) *GetVarPointer(u16 id);
u16 __attribute__((long_call)) VarGet(u16 id);
bool8 __attribute__((long_call)) VarSet(u16 id, u16 value);
u8 __attribute__((long_call)) VarGetObjectEventGraphicsId(u8 id);
u8 __attribute__((long_call)) *GetFlagPointer(u16 id);
u8 __attribute__((long_call)) FlagSet(u16 id);
u8 __attribute__((long_call)) FlagClear(u16 id);
bool8 __attribute__((long_call)) FlagGet(u16 id);
u16 __attribute__((long_call)) * GetVarPointer(u16 id);
bool32 __attribute__((long_call)) IsMysteryGiftEnabled(void);
void __attribute__((long_call)) ResetSpecialVars(void);
void __attribute__((long_call)) ClearMysteryGiftFlags(void);
void __attribute__((long_call)) ClearMysteryGiftVars(void);
bool32 __attribute__((long_call)) IsNationalPokedexEnabled(void);
void __attribute__((long_call)) EnableNationalPokedex_RSE(void);
void __attribute__((long_call)) ClearTempFieldEventData(void);

#define var8000 (*((u16*) 0x20370B8))
#define gPlayerAvatar ((struct PlayerAvatar*) 0x02037078)
#define gSpecialVar_LastResult (*((u16*) 0x20370D0))

#endif // GUARD_EVENT_DATA_H
