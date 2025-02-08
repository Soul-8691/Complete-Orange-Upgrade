#ifndef GUARD_DAYCARE_H
#define GUARD_DAYCARE_H

#include "global.h"

u8 __attribute__((long_call)) *GetMonNick(struct Pokemon *mon, u8 *dest);
u8 __attribute__((long_call)) *GetBoxMonNick(struct BoxPokemon *mon, u8 *dest);
u8 __attribute__((long_call)) CountPokemonInDaycare(struct DayCare *daycare);
void __attribute__((long_call)) InitDaycareMailRecordMixing(struct DayCare *daycare, struct RecordMixingDayCareMail *daycareMail);
void __attribute__((long_call)) StoreSelectedPokemonInDaycare(void);
u16 __attribute__((long_call)) TakePokemonFromDaycare(void);
void __attribute__((long_call)) GetDaycareCost(void);
u8 __attribute__((long_call)) GetNumLevelsGainedFromDaycare(void);
void __attribute__((long_call)) TriggerPendingDaycareEgg(void);
void __attribute__((long_call)) RejectEggFromDayCare(void);
void __attribute__((long_call)) CreateEgg(struct Pokemon *mon, u16 species, bool8 setHotSpringsLocation);
void __attribute__((long_call)) GiveEggFromDaycare(void);
bool8 __attribute__((long_call)) DoEggActions_CheckHatch(void);
u16 __attribute__((long_call)) GetSelectedMonNickAndSpecies(void);
void __attribute__((long_call)) GetDaycareMonNicknames(void);
u8 __attribute__((long_call)) GetDaycareState(void);
void __attribute__((long_call)) SetDaycareCompatibilityString(void);
bool8 __attribute__((long_call)) NameHasGenderSymbol(const u8 *name, u8 genderRatio);
void __attribute__((long_call)) ShowDaycareLevelMenu(void);
void __attribute__((long_call)) ChooseSendDaycareMon(void);

void __attribute__((long_call)) ScriptHatchMon(void);
void __attribute__((long_call)) EggHatch(void);
u8 __attribute__((long_call)) GetEggStepsToSubtract(void);
bool8 __attribute__((long_call)) ShouldEggHatch(void);

#endif // GUARD_DAYCARE_H
