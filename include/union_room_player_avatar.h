#ifndef GUARD_UNION_ROOM_PLAYER_AVATAR_H
#define GUARD_UNION_ROOM_PLAYER_AVATAR_H

#include "union_room.h"

u8 __attribute__((long_call)) InitUnionRoomPlayerObjects(struct UnionRoomObject * players);
void __attribute__((long_call)) DestroyUnionRoomPlayerObjects(void);
void __attribute__((long_call)) CreateUnionRoomPlayerSprites(u8 *spriteIds, s32 leaderId);
void __attribute__((long_call)) DestroyUnionRoomPlayerSprites(u8 *spriteIds);
void __attribute__((long_call)) MakeGroupAssemblyAreasPassable(void);
void __attribute__((long_call)) ScheduleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom);
void __attribute__((long_call)) HandleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom);
bool32 __attribute__((long_call)) TryInteractWithUnionRoomMember(struct RfuPlayerList *list, s16 *memberIdPtr, s16 *leaderIdPtr, u8 *spriteIds);
void __attribute__((long_call)) UpdateUnionRoomMemberFacing(u32 memberId, u32 leaderId, struct RfuPlayerList *list);

#endif //GUARD_UNION_ROOM_PLAYER_AVATAR_H
