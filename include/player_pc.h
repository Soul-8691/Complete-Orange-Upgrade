#ifndef GUARD_PLAYER_PC_H
#define GUARD_PLAYER_PC_H

#include "global.h"
#include "list_menu.h"

// Exported type declarations

struct PlayerPCItemPageStruct
{
    u16 itemsAbove;
    u16 cursorPos;
    u8 pageItems;
    u8 count;
    u8 filler_6[3];
    bool8 notInRoom;
    u8 scrollIndicatorId;
    u8 filler_B[5];
};

// Exported RAM declarations
extern struct PlayerPCItemPageStruct gPlayerPcMenuManager;

// Exported ROM declarations

void __attribute__((long_call)) NewGameInitPCItems(void);
void __attribute__((long_call)) Mailbox_ReturnToMailListAfterDeposit(void);

#endif //GUARD_PLAYER_PC_H
