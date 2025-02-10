#ifndef GUARD_ITEM_MENU_ICONS
#define GUARD_ITEM_MENU_ICONS

#include "global.h"

// Values for 2nd argument to GetItemIconGfxPtr
enum {
    ITEMICON_TILES,
    ITEMICON_PAL,
};

extern const struct CompressedSpriteSheet gSpriteSheet_BagMale;
extern const struct CompressedSpriteSheet gSpriteSheet_BagFemale;
extern const struct CompressedSpritePalette gSpritePalette_Bag;

extern const struct CompressedSpriteSheet gBagSwapSpriteSheet;
extern const struct CompressedSpritePalette gBagSwapSpritePalette;

void __attribute__((long_call)) ResetItemMenuIconState(void);
void __attribute__((long_call)) CreateSwapLine(void);
void __attribute__((long_call)) DestroyItemMenuIcon(bool8 a0);
void __attribute__((long_call)) CreateItemMenuIcon(u16 itemId, bool8 a0);
void __attribute__((long_call)) CopyItemIconPicTo4x4Buffer(const void *src, void *dest);
u8 __attribute__((long_call)) AddItemIconObject(u16 tilesTag, u16 paletteTag, u16 itemId);
u8 __attribute__((long_call)) AddItemIconObjectWithCustomObjectTemplate(const struct SpriteTemplate * origTemplate, u16 tilesTag, u16 paletteTag, u16 itemId);
void __attribute__((long_call)) CreateBerryPouchItemIcon(u16 itemId, u8 idx);
void __attribute__((long_call)) UpdateSwapLinePos(s16 x, u16 y);
void __attribute__((long_call)) SetSwapLineInvisibility(bool8 invisible);
void __attribute__((long_call)) SetBagVisualPocketId(u8);
void __attribute__((long_call)) ShakeBagSprite(void);
const u32 * __attribute__((long_call))GetItemIconGfxPtr(u16 itemId, u8 ptrId);
void __attribute__((long_call)) CreateBagSprite(u8 animNum);

#endif // GUARD_ITEM_MENU_ICONS
