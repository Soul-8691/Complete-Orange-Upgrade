#ifndef GUARD_ROAMER_H
#define GUARD_ROAMER_H

#include "global.h"

void __attribute__((long_call)) ClearRoamerData(void);
void __attribute__((long_call)) ClearRoamerLocationData(void);
void __attribute__((long_call)) InitRoamer(void);
void __attribute__((long_call)) UpdateLocationHistoryForRoamer(void);
void __attribute__((long_call)) RoamerMoveToOtherLocationSet(void);
void __attribute__((long_call)) RoamerMove(void);
bool8 __attribute__((long_call)) IsRoamerAt(u8 mapGroup, u8 mapNum);
void __attribute__((long_call)) CreateRoamerMonInstance(void);
u8 __attribute__((long_call)) TryStartRoamerEncounter(void);
void __attribute__((long_call)) UpdateRoamerHPStatus(struct Pokemon *mon);
void __attribute__((long_call)) SetRoamerInactive(void);
void __attribute__((long_call)) GetRoamerLocation(u8 *mapGroup, u8 *mapNum);
u16 __attribute__((long_call)) GetRoamerLocationMapSectionId(void);

#endif // GUARD_ROAMER_H
