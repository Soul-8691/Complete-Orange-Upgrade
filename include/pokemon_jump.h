#ifndef GUARD_POKEMON_JUMP_H
#define GUARD_POKEMON_JUMP_H

#include "main.h"

void __attribute__((long_call)) ResetPokemonJumpRecords(void);
bool32 __attribute__((long_call)) IsSpeciesAllowedInPokemonJump(u16 species);
void __attribute__((long_call)) StartPokemonJump(u16 species, MainCallback callback);

#endif // GUARD_POKEMON_JUMP_H
