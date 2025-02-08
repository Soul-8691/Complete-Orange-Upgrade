#ifndef GUARD_POKEDEX_AREA_MARKERS_H
#define GUARD_POKEDEX_AREA_MARKERS_H

void __attribute__((long_call)) GetAreaMarkerSubsprite(s32 i, s32 dexArea, struct Subsprite * subsprites);
void __attribute__((long_call)) DestroyPokedexAreaMarkers(u8 taskId);
u8 __attribute__((long_call)) CreatePokedexAreaMarkers(u16 species, u16 tilesTag, u8 palIdx, u8 y);
u8 __attribute__((long_call)) GetNumPokedexAreaMarkers(u8 taskId);

#endif //GUARD_POKEDEX_AREA_MARKERS_H
