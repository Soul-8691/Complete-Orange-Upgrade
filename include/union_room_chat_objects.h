#ifndef GUARD_UNION_ROOM_CHAT_OBJECTS_H
#define GUARD_UNION_ROOM_CHAT_OBJECTS_H

bool32 __attribute__((long_call)) UnionRoomChat_TryAllocSpriteWork(void);
void __attribute__((long_call)) UnionRoomChat_FreeSpriteWork(void);
void __attribute__((long_call)) UnionRoomChat_CreateSelectorCursorObj(void);
void __attribute__((long_call)) UnionRoomChat_ToggleSelectorCursorObjVisibility(bool32 invisible);
void __attribute__((long_call)) UnionRoomChat_MoveSelectorCursorObj(void);
void __attribute__((long_call)) UnionRoomChat_UpdateObjPalCycle(u32 idx);
void __attribute__((long_call)) UnionRoomChat_SetSelectorCursorClosedImage(void);
bool32 __attribute__((long_call)) UnionRoomChat_AnimateSelectorCursorReopen(void);
void __attribute__((long_call)) UnionRoomChat_SpawnTextEntryPointerSprites(void);
void __attribute__((long_call)) CreatePageSwitchUISprites(void);
void __attribute__((long_call)) UpdateVisibleUnionRoomChatIcon(void);

#endif //GUARD_UNION_ROOM_CHAT_OBJECTS_H
