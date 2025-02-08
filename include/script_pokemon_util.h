#ifndef GUARD_SCRIPT_POKEMON_UTIL_H
#define GUARD_SCRIPT_POKEMON_UTIL_H

bool8 __attribute__((long_call)) ScriptGiveMon(u16 species, u8 level, u16 item, u32 unk1, u32 unk2, u8 unk3);
bool8 __attribute__((long_call)) ScriptGiveEgg(u16 species);
void __attribute__((long_call)) ScriptSetMonMoveSlot(u8 partyIdx, u16 move, u8 slot);
void __attribute__((long_call)) HealPlayerParty(void);
void __attribute__((long_call)) ReducePlayerPartyToThree(void);
void __attribute__((long_call)) CreateScriptedWildMon(u16 species, u8 level, u16 item);

#endif //GUARD_SCRIPT_POKEMON_UTIL_H
