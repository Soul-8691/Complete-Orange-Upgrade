#ifndef GUARD_UNION_ROOM_CHAT_H
#define GUARD_UNION_ROOM_CHAT_H

enum
{
    UNION_ROOM_KB_PAGE_UPPER,
    UNION_ROOM_KB_PAGE_LOWER,
    UNION_ROOM_KB_PAGE_EMOJI,
    UNION_ROOM_KB_PAGE_COUNT
};

extern const u8 *const gUnionRoomKeyboardText[UNION_ROOM_KB_PAGE_COUNT][UNION_ROOM_KB_ROW_COUNT];

void __attribute__((long_call)) EnterUnionRoomChat(void);
u8 __attribute__((long_call)) *UnionRoomChat_GetWorkRegisteredText(int arg0);
void __attribute__((long_call)) UnionRoomChat_GetCursorColAndRow(u8 *colp, u8 *rowp);
u8 __attribute__((long_call)) *UnionRoomChat_GetMessageEntryBuffer(void);
int UnionRoomChat_LenMessageEntryBuffer(void);
void __attribute__((long_call)) UnionRoomChat_GetBufferSelectionRegion(u32 *startp, u32 *diffp);
u8 __attribute__((long_call)) *UnionRoomChat_GetEndOfMessageEntryBuffer(void);
u16 __attribute__((long_call)) UnionRoomChat_GetNumCharsInMessageEntryBuffer(void);
u8 __attribute__((long_call)) *UnionRoomChat_GetLastReceivedMessage(void);
u16 __attribute__((long_call)) UnionRoomChat_GetReceivedPlayerIndex(void);
int UnionRoomChat_GetMessageEntryCursorPosition(void);
int UnionRoomChat_GetWhetherShouldShowCaseToggleIcon(void);
u8 __attribute__((long_call)) *UnionRoomChat_GetNameOfPlayerWhoDisbandedChat(void);
void __attribute__((long_call)) UnionRoomChat_InitializeRegisteredTexts(void);
u8 __attribute__((long_call)) GetCurrentKeyboardPage(void);

#endif // GUARD_UNION_ROOM_CHAT_H
