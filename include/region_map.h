#ifndef GUARD_REGION_MAP_H
#define GUARD_REGION_MAP_H

#include "global.h"
#include "bg.h"

enum {
    REGIONMAP_TYPE_NORMAL,
    REGIONMAP_TYPE_WALL,
    REGIONMAP_TYPE_FLY,
    REGIONMAP_TYPE_COUNT
};

u8 __attribute__((long_call)) *GetMapName(u8 *dest, u16 mapsec, u16 fill);
u8 __attribute__((long_call)) *GetMapNameGeneric(u8 *dest, u16 mapsec);
u8 __attribute__((long_call)) *GetMapNameGeneric_(u8 *dest, u16 mapsec);
void __attribute__((long_call)) InitRegionMapWithExitCB(u8 type, void (*callback)(void));
void __attribute__((long_call)) CB2_OpenFlyMap(void);

#endif // GUARD_REGION_MAP_H
