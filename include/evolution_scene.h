#ifndef GUARD_EVOLUTION_SCENE_H
#define GUARD_EVOLUTION_SCENE_H

#include "global.h"

extern void (*gCB2_AfterEvolution)(void);

void __attribute__((long_call)) BeginEvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, u8, u8 partyId);
void __attribute__((long_call)) EvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, u8, u8 partyId);
void __attribute__((long_call)) TradeEvolutionScene(struct Pokemon* mon, u16 speciesToEvolve, u8 preEvoSpriteId, u8 partyId);
void __attribute__((long_call)) IsMovingBackgroundTaskRunning(void);

#endif // GUARD_EVOLUTION_SCENE_H
