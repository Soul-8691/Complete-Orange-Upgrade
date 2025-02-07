#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/berry.h"
#include "../include/event_data.h"
#include "../include/item.h"
#include "../include/item_use.h"
#include "../include/load_save.h"
#include "../include/quest_log.h"
#include "../include/strings.h"
#include "../include/constants/hold_effects.h"
#include "../include/constants/items.h"
#include "../include/constants/maps.h"

void SortPocketAndPlaceHMsFirst_(struct BagPocket * pocket)
{
    u16 i;
    u16 j = 0;
    u16 k, l;
    struct ItemSlot * buff;

    SortAndCompactBagPocket(pocket);

    for (i = 0; i < pocket->capacity; i++)
    {
        if (pocket->itemSlots[i].itemId == ITEM_NONE && GetBagItemQuantity(&pocket->itemSlots[i].quantity) == 0)
            return;
        if (pocket->itemSlots[i].itemId >= ITEM_TM01 && pocket->itemSlots[i].itemId <= ITEM_LAST_TM && GetBagItemQuantity(&pocket->itemSlots[i].quantity) != 0)
        {
            if (pocket->itemSlots[i].itemId >= ITEM_HM01 && pocket->itemSlots[i].itemId <= ITEM_HM08)
            {
                for (j = i + 1; j < pocket->capacity; j++)
                {
                    if (pocket->itemSlots[j].itemId == ITEM_NONE && GetBagItemQuantity(&pocket->itemSlots[j].quantity) == 0)
                        break;
                }
                break;
            }
        }
    }

    for (k = 0; k < pocket->capacity; k++)
        pocket->itemSlots[k].quantity = GetBagItemQuantity(&pocket->itemSlots[k].quantity);
    buff = AllocZeroed(pocket->capacity * sizeof(struct ItemSlot));
    CpuCopy16(pocket->itemSlots + i, buff, (j - i) * sizeof(struct ItemSlot));
    CpuCopy16(pocket->itemSlots, buff + (j - i), i * sizeof(struct ItemSlot));
    CpuCopy16(buff, pocket->itemSlots, pocket->capacity * sizeof(struct ItemSlot));
    for (k = 0; k < pocket->capacity; k++)
        SetBagItemQuantity(&pocket->itemSlots[k].quantity, pocket->itemSlots[k].quantity);
    Free(buff);
}

u16 SanitizeItemId_(u16 itemId)
{
    if (itemId >= ITEMS_COUNT)
        return ITEM_NONE;
    return itemId;
}