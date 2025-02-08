#ifndef GUARD_PALETTE_H
#define GUARD_PALETTE_H

#include "global.h"

#define gPaletteFade_selectedPalettes (gPaletteFade.multipurpose1) // normal and fast fade
#define gPaletteFade_blendCnt         (gPaletteFade.multipurpose1) // hardware fade
#define gPaletteFade_delay            (gPaletteFade.multipurpose2) // normal and hardware fade
#define gPaletteFade_submode          (gPaletteFade.multipurpose2) // fast fade

#define PLTT_BUFFER_SIZE (PLTT_SIZE / sizeof(u16))

#define PALETTE_FADE_STATUS_DELAY 2
#define PALETTE_FADE_STATUS_ACTIVE 1
#define PALETTE_FADE_STATUS_DONE 0
#define PALETTE_FADE_STATUS_LOADING 0xFF

#define PALETTES_BG      0x0000FFFF
#define PALETTES_OBJECTS 0xFFFF0000
#define PALETTES_ALL     (PALETTES_BG | PALETTES_OBJECTS)

#define PLTT_ID(n) ((n) * 16)
#define BG_PLTT_OFFSET 0x000
#define OBJ_PLTT_OFFSET 0x100
#define BG_PLTT_ID(n) (BG_PLTT_OFFSET + PLTT_ID(n))
#define OBJ_PLTT_ID(n) (OBJ_PLTT_OFFSET + PLTT_ID(n))
#define OBJ_PLTT_ID2(n) (PLTT_ID((n) + 16))

enum
{
    FAST_FADE_IN_FROM_WHITE,
    FAST_FADE_OUT_TO_WHITE,
    FAST_FADE_IN_FROM_BLACK,
    FAST_FADE_OUT_TO_BLACK,
};

struct PaletteFadeControl
{
    u32 multipurpose1;
    u8 delayCounter:6;
    u16 y:5; // blend coefficient
    u16 targetY:5; // target blend coefficient
    u16 blendColor:15;
    u16 active:1;
    u16 multipurpose2:6;
    u16 yDec:1; // whether blend coefficient is decreasing
    u16 bufferTransferDisabled:1;
    u16 mode:2;
    u16 shouldResetBlendRegisters:1;
    u16 hardwareFadeFinishing:1;
    u16 softwareFadeFinishingCounter:5;
    u16 softwareFadeFinishing:1;
    u16 objPaletteToggle:1;
    u8 deltaY:4; // rate of change of blend coefficient
    u32 unused;
};

extern struct PaletteFadeControl gPaletteFade;
extern u32 __attribute__((long_call)) gPlttBufferTransferPending;
extern u16 __attribute__((long_call)) gPlttBufferUnfaded[PLTT_BUFFER_SIZE];
extern u16 __attribute__((long_call)) gPlttBufferFaded[PLTT_BUFFER_SIZE];

void __attribute__((long_call)) LoadCompressedPalette(const u32 *src, u16 offset, u16 size);
void __attribute__((long_call)) LoadPalette(const void *src, u16 offset, u16 size);
void __attribute__((long_call)) FillPalette(u16 value, u16 offset, u16 size);
void __attribute__((long_call)) TransferPlttBuffer(void);
u8 __attribute__((long_call)) UpdatePaletteFade(void);
void __attribute__((long_call)) ResetPaletteFade(void);
void __attribute__((long_call)) ReadPlttIntoBuffers(void);
bool8 __attribute__((long_call)) BeginNormalPaletteFade(u32 selectedPalettes, s8 delay, u8 startY, u8 targetY, u16 blendColor);
void __attribute__((long_call)) ResetPaletteFadeControl(void);
void __attribute__((long_call)) InvertPlttBuffer(u32 selectedPalettes);
void __attribute__((long_call)) TintPlttBuffer(u32 selectedPalettes, s8 r, s8 g, s8 b);
void __attribute__((long_call)) UnfadePlttBuffer(u32 selectedPalettes);
void __attribute__((long_call)) BeginFastPaletteFade(u8 submode);
void __attribute__((long_call)) BeginHardwarePaletteFade(u8 blendCnt, u8 delay, u8 y, u8 targetY, u8 shouldResetBlendRegisters);
void __attribute__((long_call)) BlendPalettes(u32 selectedPalettes, u8 coeff, u16 color);
void __attribute__((long_call)) BlendPalettesUnfaded(u32 selectedPalettes, u8 coeff, u16 color);
void __attribute__((long_call)) TintPalette_GrayScale(u16 *palette, u16 count);
void __attribute__((long_call)) TintPalette_GrayScale2(u16 *palette, u16 count);
void __attribute__((long_call)) TintPalette_SepiaTone(u16 *palette, u16 count);
void __attribute__((long_call)) TintPalette_CustomTone(u16 *palette, u16 count, u16 rTone, u16 gTone, u16 bTone);
void __attribute__((long_call)) PaletteStruct_ResetById(u16 id);
void __attribute__((long_call)) CopyPaletteInvertedTint(const u16 *src, u16 *dst, u16 count, u8 tone);
void __attribute__((long_call)) BlendPalettesGradually(u32 selectedPalettes, s8 delay, u8 coeff, u8 coeffTarget, u16 color, u8 priority, u8 id);
bool32 __attribute__((long_call)) IsBlendPalettesGraduallyTaskActive(u8 var);
void __attribute__((long_call)) DestroyBlendPalettesGraduallyTask(void);

static inline void SetBackdropFromColor(u16 color)
{
  FillPalette(color, 0, PLTT_SIZEOF(1));
}

static inline void SetBackdropFromPalette(const u16 *palette)
{
  LoadPalette(palette, 0, PLTT_SIZEOF(1));
}

#endif // GUARD_PALETTE_H
