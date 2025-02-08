#ifndef GUARD_CABLE_CLUB_H
#define GUARD_CABLE_CLUB_H

void __attribute__((long_call)) Task_WaitForLinkPlayerConnection(u8 taskId);
u8 __attribute__((long_call)) CreateTask_ReestablishCableClubLink(void);
void __attribute__((long_call)) CB2_ReturnFromCableClubBattle(void);
bool32 __attribute__((long_call)) GetSeeingLinkPlayerCardMsg(u8 who);

#endif //GUARD_CABLE_CLUB_H
