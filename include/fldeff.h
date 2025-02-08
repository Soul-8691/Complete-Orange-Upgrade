#ifndef GUARD_FLDEFF_H
#define GUARD_FLDEFF_H

#define FLDEFF_CALL_FUNC_IN_DATA() ((void (*)(void))(((u16)gTasks[taskId].data[8] << 16) | (u16)gTasks[taskId].data[9]))();

#define FLDEFF_SET_FUNC_TO_DATA(func)                     \
gTasks[taskId].data[8] = (u32)func >> 16;                 \
gTasks[taskId].data[9] = (u32)func;

extern struct MapPosition gPlayerFacingPosition;

bool8 __attribute__((long_call)) CheckObjectGraphicsInFrontOfPlayer(u8 graphicsId);
u8 __attribute__((long_call)) CreateFieldEffectShowMon(void);

// flash
u8 __attribute__((long_call)) MapTransitionIsExit(u8 lightLevel, u8 mapType);
u8 __attribute__((long_call)) MapTransitionIsEnter(u8 mapType1, u8 mapType2);
bool8 __attribute__((long_call)) SetUpFieldMove_Flash(void);
void __attribute__((long_call)) CB2_DoChangeMap(void);

// cut
bool8 __attribute__((long_call)) SetUpFieldMove_Cut(void);

// dig
bool8 __attribute__((long_call)) SetUpFieldMove_Dig(void);
bool8 __attribute__((long_call)) FldEff_UseDig(void);

// rocksmash
bool8 __attribute__((long_call)) SetUpFieldMove_RockSmash(void);
bool8 __attribute__((long_call)) FldEff_UseRockSmash(void);

// berrytree
void __attribute__((long_call)) nullsub_56(void);

// poison
void __attribute__((long_call)) FldEffPoison_Start(void);
bool32 __attribute__((long_call)) FldEffPoison_IsActive(void);

// strength
bool8 __attribute__((long_call)) SetUpFieldMove_Strength(void);
bool8 __attribute__((long_call)) FldEff_UseStrength(void);

// teleport
bool8 __attribute__((long_call)) SetUpFieldMove_Teleport(void);
bool8 __attribute__((long_call)) FldEff_UseTeleport(void);

// softboiled
bool8 __attribute__((long_call)) SetUpFieldMove_SoftBoiled(void);
void __attribute__((long_call)) ChooseMonForSoftboiled(u8 taskId);
void __attribute__((long_call)) Task_TryUseSoftboiledOnPartyMon(u8 taskId);

// sweetscent
bool8 __attribute__((long_call)) SetUpFieldMove_SweetScent(void);
bool8 __attribute__((long_call)) FldEff_SweetScent(void);

#endif // GUARD_FLDEFF_H
