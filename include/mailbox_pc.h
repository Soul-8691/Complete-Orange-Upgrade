#ifndef GUARD_MAILBOX_PC_H
#define GUARD_MAILBOX_PC_H

#include "player_pc.h"

bool8 __attribute__((long_call)) MailboxPC_InitBuffers(u8 num);
u8 __attribute__((long_call)) MailboxPC_GetAddWindow(u8 winIdx);
void __attribute__((long_call)) MailboxPC_RemoveWindow(u8 winIdx);
u8 __attribute__((long_call)) MailboxPC_GetWindowId(u8 winIdx);
u8 __attribute__((long_call)) MailboxPC_InitListMenu(struct PlayerPCItemPageStruct * playerPcStruct);
void __attribute__((long_call)) MailboxPC_AddScrollIndicatorArrows(struct PlayerPCItemPageStruct * playerPcStruct);
void __attribute__((long_call)) MailboxPC_DestroyListMenuBuffer(void);

#endif //GUARD_MAILBOX_PC_H
