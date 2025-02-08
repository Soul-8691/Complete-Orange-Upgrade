#ifndef GUARD_MENU_INDICATORS_H
#define GUARD_MENU_INDICATORS_H

#include "global.h"

struct ScrollArrowsTemplate
{
    u8 firstArrowType;
    u8 firstX;
    u8 firstY;
    u8 secondArrowType;
    u8 secondX;
    u8 secondY;
    u16 fullyUpThreshold;
    u16 fullyDownThreshold;
    u16 tileTag;
    u16 palTag;
    u8 palNum;
};

struct CursorStruct
{
    u8 left;
    u8 top;
    u16 rowWidth;
    u16 rowHeight;
    u16 tileTag;
    u16 palTag;
    u8 palNum;
};

u8 __attribute__((long_call)) AddScrollIndicatorArrowPairParameterized(u32 arrowType, s32 commonPos, s32 firstPos, s32 secondPos, s32 fullyDownThreshold, s32 tileTag, s32 palTag, u16 *scrollOffset);
u8 __attribute__((long_call)) AddScrollIndicatorArrowPair(const struct ScrollArrowsTemplate * template, u16 * a1);
void __attribute__((long_call)) RemoveScrollIndicatorArrowPair(u8);
u8 __attribute__((long_call)) ListMenuAddCursorObjectInternal(const struct CursorStruct *cursor, u32 cursorKind);
u8 __attribute__((long_call)) ListMenuAddRedOutlineCursorObject(const struct CursorStruct *cursor);
void __attribute__((long_call)) ListMenuUpdateRedOutlineCursorObject(u8 taskId, u16 x, u16 y);
void __attribute__((long_call)) ListMenuRemoveRedOutlineCursorObject(u8 taskId);
void __attribute__((long_call)) ListMenuRemoveCursorObject(u8 taskId, u32 cursorKind);
void __attribute__((long_call)) ListMenuUpdateCursorObject(u8 taskId, u16 x, u16 y, u32 cursorKind);

#endif //GUARD_MENU_INDICATORS_H
