#ifndef GUARD_EVOLUTION_GRAPHICS_H
#define GUARD_EVOLUTION_GRAPHICS_H

#include "global.h"

void __attribute__((long_call)) LoadEvoSparkleSpriteAndPal(void);

u8 __attribute__((long_call)) EvolutionSparkles_SpiralUpward(u16 arg0);
u8 __attribute__((long_call)) EvolutionSparkles_ArcDown(void);
u8 __attribute__((long_call)) EvolutionSparkles_CircleInward(void);
u8 __attribute__((long_call)) EvolutionSparkles_SprayAndFlash(u16 species);
u8 __attribute__((long_call)) EvolutionSparkles_SprayAndFlash_Trade(u16 species);
u8 __attribute__((long_call)) CycleEvolutionMonSprite(u8 preEvoSpriteId, u8 postEvoSpriteId);

#define EvoGraphicsTaskEvoStop  data[8]

#endif // GUARD_EVOLUTION_GRAPHICS_H
