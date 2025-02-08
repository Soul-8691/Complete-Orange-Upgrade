#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

#include "global.h"
#include "characters.h"

#define NUM_TEXT_PRINTERS 32

#define TEXT_SPEED_INSTANT 0

// Given as a text speed when all the text should be
// loaded at once but not copied to vram yet.
#define TEXT_SKIP_DRAW 0xFF

enum {
    FONT_SMALL,
    FONT_NORMAL_COPY_1,
    FONT_NORMAL,
    FONT_NORMAL_COPY_2,
    FONT_MALE,
    FONT_FEMALE,
    FONT_BRAILLE,
    FONT_BOLD,
};

// Return values for font functions
enum {
    RENDER_PRINT,
    RENDER_FINISH,
    RENDER_REPEAT, // Run render function again, if e.g. a control code is encountered.
    RENDER_UPDATE,
};

// Text printer states read by RenderText / FontFunc_Braille
enum {
    RENDER_STATE_HANDLE_CHAR,
    RENDER_STATE_WAIT,
    RENDER_STATE_CLEAR,
    RENDER_STATE_SCROLL_START,
    RENDER_STATE_SCROLL,
    RENDER_STATE_WAIT_SE,
    RENDER_STATE_PAUSE,
};

enum
{
    FONTATTR_MAX_LETTER_WIDTH,
    FONTATTR_MAX_LETTER_HEIGHT,
    FONTATTR_LETTER_SPACING,
    FONTATTR_LINE_SPACING,
    FONTATTR_UNKNOWN,   // dunno what this is yet
    FONTATTR_COLOR_FOREGROUND,
    FONTATTR_COLOR_BACKGROUND,
    FONTATTR_COLOR_SHADOW
};

struct GlyphInfo
{
    u8 pixels[0x80];
    u8 width;
    u8 height;
};

extern struct GlyphInfo gGlyphInfo;

struct TextPrinterSubStruct
{
    u8 glyphId:4;  // 0x14
    bool8 hasPrintBeenSpedUp:1;
    u8 font_type_5:3;
    u8 downArrowDelay:5;
    u8 downArrowYPosIdx:2;
    u8 hasGlyphIdBeenSet:1;
    u8 autoScrollDelay;
};

struct TextPrinterTemplate // TODO: Better name
{
    const u8 *currentChar;
    u8 windowId;
    u8 fontId;
    u8 x;
    u8 y;
    u8 currentX;        // 0x8
    u8 currentY;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 unk:4;   // 0xC
    u8 fgColor:4;
    u8 bgColor:4;
    u8 shadowColor:4;
};

struct TextPrinter
{
    struct TextPrinterTemplate printerTemplate;
    void (*callback)(struct TextPrinterTemplate *, u16); // 0x10
    union __attribute__((packed)) {
        struct TextPrinterSubStruct sub;
        u8 fields[7];
    } subUnion;
    u8 active;
    u8 state;       // 0x1C
    u8 textSpeed;
    u8 delayCounter;
    u8 scrollDistance;
    u8 minLetterSpacing;  // 0x20
    u8 japanese;
};

struct FontInfo
{
    u16 (*fontFunction)(struct TextPrinter *x);
    u8 maxLetterWidth;
    u8 maxLetterHeight;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 unk:4;
    u8 fgColor:4;
    u8 bgColor:4;
    u8 shadowColor:4;
};

extern const struct FontInfo *gFonts;

struct GlyphWidthFunc
{
    u32 fontId;
    s32 (*func)(u16 glyphId, bool32 isJapanese);
};

typedef struct {
    u8 canABSpeedUpPrint:1;
    u8 useAlternateDownArrow:1;
    u8 autoScroll:1;
    u8 forceMidTextSpeed:1;
} TextFlags;

extern TextFlags gTextFlags;

extern u8 __attribute__((long_call)) gStringVar1[];
extern u8 __attribute__((long_call)) gStringVar2[];
extern u8 __attribute__((long_call)) gStringVar3[];
extern u8 __attribute__((long_call)) gStringVar4[];

extern const u8 gKeypadIconTiles[];

void __attribute__((long_call)) SetFontsPointer(const struct FontInfo *fonts);
void __attribute__((long_call)) DeactivateAllTextPrinters(void);
u16 __attribute__((long_call)) AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16));
bool16 __attribute__((long_call)) AddTextPrinter(struct TextPrinterTemplate *textSubPrinter, u8 speed, void (*callback)(struct TextPrinterTemplate *, u16));
void __attribute__((long_call)) RunTextPrinters(void);
bool16 __attribute__((long_call)) IsTextPrinterActive(u8 id);
u32 __attribute__((long_call)) RenderFont(struct TextPrinter *textPrinter);
void __attribute__((long_call)) GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor);
void __attribute__((long_call)) SaveTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor);
void __attribute__((long_call)) RestoreTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor);
void __attribute__((long_call)) DecompressGlyphTile(const u16 *src, u16 *dest);
u8 __attribute__((long_call)) GetLastTextColor(u8 colorType);
void __attribute__((long_call)) CopyGlyphToWindow(struct TextPrinter *x);
void __attribute__((long_call)) ClearTextSpan(struct TextPrinter *textPrinter, u32 width);

u16 __attribute__((long_call)) FontFunc_Small(struct TextPrinter *textPrinter);
u16 __attribute__((long_call)) FontFunc_NormalCopy1(struct TextPrinter *textPrinter);
u16 __attribute__((long_call)) FontFunc_Normal(struct TextPrinter *textPrinter);
u16 __attribute__((long_call)) FontFunc_NormalCopy2(struct TextPrinter *textPrinter);
u16 __attribute__((long_call)) FontFunc_Male(struct TextPrinter *textPrinter);
u16 __attribute__((long_call)) FontFunc_Female(struct TextPrinter *textPrinter);
u16 __attribute__((long_call)) FontFunc_Braille(struct TextPrinter *textPrinter);

void __attribute__((long_call)) TextPrinterInitDownArrowCounters(struct TextPrinter *textPrinter);
void __attribute__((long_call)) TextPrinterDrawDownArrow(struct TextPrinter *textPrinter);
void __attribute__((long_call)) TextPrinterClearDownArrow(struct TextPrinter *textPrinter);
bool8 __attribute__((long_call)) TextPrinterWaitAutoMode(struct TextPrinter *textPrinter);
bool16 __attribute__((long_call)) TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter);
bool16 __attribute__((long_call)) TextPrinterWait(struct TextPrinter *textPrinter);
void __attribute__((long_call)) DrawDownArrow(u8 windowId, u16 x, u16 y, u8 bgColor, bool8 drawArrow, u8 *counter, u8 *yCoordIndex);
u16 __attribute__((long_call)) RenderText(struct TextPrinter *textPrinter);
s32 (*GetFontWidthFunc(u8 glyphId))(u16, bool32);
s32 __attribute__((long_call)) GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing);
u8 __attribute__((long_call)) RenderTextHandleBold(u8 *pixels, u8 fontId, u8 *str, int a3, int a4, int a5, int a6, int a7);
u8 __attribute__((long_call)) DrawKeypadIcon(u8 windowId, u8 keypadIconId, u16 x, u16 y);
u8 __attribute__((long_call)) GetKeypadIconTileOffset(u8 keypadIconId);
u8 __attribute__((long_call)) GetKeypadIconWidth(u8 keypadIconId);
u8 __attribute__((long_call)) GetKeypadIconHeight(u8 keypadIconId);
u8 __attribute__((long_call)) GetFontAttribute(u8 fontId, u8 attributeId);
u8 __attribute__((long_call)) GetMenuCursorDimensionByFont(u8 fontId, u8 whichDimension);
void __attribute__((long_call)) DecompressGlyph_Small(u16 glyphId, bool32 isJapanese);
void __attribute__((long_call)) DecompressGlyph_Normal(u16 glyphId, bool32 isJapanese);
void __attribute__((long_call)) DecompressGlyph_Female(u16 glyphId, bool32 isJapanese);
s32 __attribute__((long_call)) GetGlyphWidth_Braille(u16 font_type, bool32 isJapanese);
u8 __attribute__((long_call)) CreateTextCursorSprite(u8 sheetId, u16 x, u16 y, u8 priority, u8 subpriority);
void __attribute__((long_call)) DestroyTextCursorSprite(u8 spriteId);

#endif // GUARD_TEXT_H
