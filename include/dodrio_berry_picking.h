#ifndef GUARD_DODRIO_BERRY_PICKING_H
#define GUARD_DODRIO_BERRY_PICKING_H

// Berries fall in predefined columns.
// A total of 10 are available, though fewer will be used with < 5 players
// The 11th column is a repeat of the 1st column wrapped around, so only
// the values 0-9 are unique 'valid' columns
#define NUM_BERRY_COLUMNS 11

struct DodrioGame_Berries
{
    u8 ids[NUM_BERRY_COLUMNS];
    u8 fallDist[NUM_BERRY_COLUMNS];
};

struct DodrioGame_PlayerCommData
{
    u8 pickState;
    bool8 ALIGNED(4) ateBerry;
    bool8 ALIGNED(4) missedBerry;
};

struct DodrioGame_Player
{
    u8 name[16];
    bool32 receivedGameStatePacket; // Never read
    struct DodrioGame_Berries berries;
    struct DodrioGame_PlayerCommData comm;
    u32 unused;
}; // size = 0x3C

// dodrio_berry_picking.c
void __attribute__((long_call)) StartDodrioBerryPicking(u16 partyId, MainCallback exitCallback);
void __attribute__((long_call)) ShowDodrioBerryPickingRecords(void);
void __attribute__((long_call)) IsDodrioInParty(void);

// dodrio_berry_picking_comm.c
void __attribute__((long_call)) SendPacket_ReadyToStart(bool32 ready);
bool8 __attribute__((long_call)) RecvPacket_ReadyToStart(s32 playerId);
void __attribute__((long_call)) SendPacket_GameState(struct DodrioGame_Player *player,
                          struct DodrioGame_PlayerCommData *player1,
                          struct DodrioGame_PlayerCommData *player2,
                          struct DodrioGame_PlayerCommData *player3,
                          struct DodrioGame_PlayerCommData *player4,
                          struct DodrioGame_PlayerCommData *player5,
                          u8 numGraySquares,
                          bool32 berriesFalling,
                          bool32 allReadyToEnd);
bool32 __attribute__((long_call)) RecvPacket_GameState(u32 playerId,
                            struct DodrioGame_Player *player,
                            struct DodrioGame_PlayerCommData *player1,
                            struct DodrioGame_PlayerCommData *player2,
                            struct DodrioGame_PlayerCommData *player3,
                            struct DodrioGame_PlayerCommData *player4,
                            struct DodrioGame_PlayerCommData *player5,
                            u8 *numGraySquares,
                            bool32 *berriesFalling,
                            bool32 *allReadyToEnd);
void __attribute__((long_call)) SendPacket_PickState(u8 pickState);
bool32 __attribute__((long_call)) RecvPacket_PickState(u32 playerId, u8 *pickState);
void __attribute__((long_call)) SendPacket_ReadyToEnd(bool32 readyToEnd);
bool32 __attribute__((long_call)) RecvPacket_ReadyToEnd(u32 playerId);

#endif //GUARD_DODRIO_BERRY_PICKING_H
