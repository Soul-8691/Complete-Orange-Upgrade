#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

#include "global.h"

bool8 __attribute__((long_call)) CheckForTrainersWantingBattle(void);
void __attribute__((long_call)) MovementAction_RevealTrainer_RunTrainerSeeFuncList(struct ObjectEvent *var);
u8 __attribute__((long_call)) FldEff_ExclamationMarkIcon1(void);
u8 __attribute__((long_call)) FldEff_DoubleExclMarkIcon(void);
u8 __attribute__((long_call)) FldEff_XIcon(void);
u8 __attribute__((long_call)) FldEff_SmileyFaceIcon(void);
u8 __attribute__((long_call)) FldEff_QuestionMarkIcon(void);

#endif //GUARD_TRAINER_SEE_H
