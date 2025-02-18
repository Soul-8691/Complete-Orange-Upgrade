#ifndef GUARD_ITEM_H
#define GUARD_ITEM_H

#include "global.h"

typedef void (*ItemUseFunc)(u8);

struct Item
{
    u8 name[ITEM_NAME_LENGTH];
    u16 itemId;
    u16 price;
    u8 holdEffect;
    u8 holdEffectParam;
    const u8 *description;
    u8 importance;
    u8 registrability;
    u8 pocket;
    u8 type; // unused for balls
    ItemUseFunc fieldUseFunc;
    u8 battleUsage;
    ItemUseFunc battleUseFunc;
    u8 secondaryId; // only used for fishing rods
};

struct BagPocket
{
    struct ItemSlot *itemSlots;
    u8 capacity;
};

// Item type IDs (used to determine the exit callback)
enum {
    ITEM_TYPE_MAIL,
    ITEM_TYPE_PARTY_MENU,
    ITEM_TYPE_FIELD,
    ITEM_TYPE_UNUSED, // Used for Pokeblock case in RSE
    ITEM_TYPE_BAG_MENU, // No exit callback, stays in bag menu
};

extern const struct Item gItems[];
extern struct BagPocket gBagPockets[];

void __attribute__((long_call)) GetBerryCountString(u8 *dst, const u8 *berryName, u32 quantity);
void __attribute__((long_call)) CopyItemName(u16 itemId, u8 *string);
void __attribute__((long_call)) CopyItemNameHandlePlural(u16 itemId, u8 *string, u32 quantity);
bool8 __attribute__((long_call)) IsBagPocketNonEmpty(u8 pocket);
bool8 __attribute__((long_call)) CheckBagHasItem(u16 itemId, u16 count);
bool8 __attribute__((long_call)) CheckBagHasSpace(u16 itemId, u16 count);
bool8 __attribute__((long_call)) RemoveBagItem(u16 itemId, u16 count);
u8 __attribute__((long_call)) GetPocketByItemId(u16 itemId);
void __attribute__((long_call)) ClearItemSlots(struct ItemSlot *itemSlots, u8 b);
u8 __attribute__((long_call)) CountUsedPCItemSlots(void);
bool8 __attribute__((long_call)) CheckPCHasItem(u16 itemId, u16 count);
bool8 __attribute__((long_call)) AddPCItem(u16 itemId, u16 count);
void __attribute__((long_call)) SwapRegisteredBike(void);
const u8 * __attribute__((long_call))ItemId_GetName(u16 itemId);
u16 __attribute__((long_call)) ItemId_GetId(u16 itemId);
u16 __attribute__((long_call)) ItemId_GetPrice(u16 itemId);
u8 __attribute__((long_call)) ItemId_GetHoldEffect(u16 itemId);
u8 __attribute__((long_call)) ItemId_GetHoldEffectParam(u16 itemId);
const u8 * __attribute__((long_call))ItemId_GetDescription(u16 itemId);
bool32 __attribute__((long_call)) ItemId_CopyDescription(u8 *a, u32 itemId, u32 c);
u8 __attribute__((long_call)) ItemId_GetImportance(u16 itemId);
u8 __attribute__((long_call)) ItemId_GetUnknownValue(u16 itemId);
u8 __attribute__((long_call)) ItemId_GetPocket(u16 itemId);
u8 __attribute__((long_call)) ItemId_GetType(u16 itemId);
ItemUseFunc ItemId_GetFieldFunc(u16 itemId);
u8 __attribute__((long_call)) ItemId_GetBattleUsage(u16 itemId);
ItemUseFunc ItemId_GetBattleFunc(u16 itemId);
u8 __attribute__((long_call)) ItemId_GetSecondaryId(u16 itemId);
u16 __attribute__((long_call)) ItemId_GetPrice(u16 itemId);
void __attribute__((long_call)) ClearBag(void);
void __attribute__((long_call)) ClearPCItemSlots(void);
void __attribute__((long_call)) TrySetObtainedItemQuestLogEvent(u16 itemId);
bool8 __attribute__((long_call)) AddBagItem(u16 itemId, u16 amount);

void __attribute__((long_call)) SortPocketAndPlaceHMsFirst(struct BagPocket * pocket);
u16 __attribute__((long_call)) BagGetItemIdByPocketPosition(u8 pocketId, u16 itemId);
u16 __attribute__((long_call)) BagGetQuantityByPocketPosition(u8 pocketId, u16 itemId);
u16 __attribute__((long_call)) BagGetQuantityByItemId(u16 item);
u8 __attribute__((long_call)) ItemId_GetImportance(u16 itemId);
void __attribute__((long_call)) BagPocketCompaction(struct ItemSlot * slots, u8 capacity);
u16 __attribute__((long_call)) GetPcItemQuantity(u16 *);
void __attribute__((long_call)) SetBagPocketsPointers(void);

void __attribute__((long_call)) ItemPcCompaction(void);
void __attribute__((long_call)) RemovePCItem(u16 itemId, u16 quantity);
void __attribute__((long_call)) SortAndCompactBagPocket(struct BagPocket * pocket);
u8 __attribute__((long_call)) CountItemsInPC(void);
void __attribute__((long_call)) ApplyNewEncryptionKeyToBagItems(u32 newKey);
bool8 __attribute__((long_call)) HasAtLeastOneBerry(void);

#endif // GUARD_ITEM_H
