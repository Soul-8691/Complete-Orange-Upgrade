#include "../include/global.h"
#include "../include/gflib.h"
#include "../include/decompress.h"
#include "../include/pokemon.h"
#include "../include/constants/flags.h"
#include "../include/menu.h"
#include "../include/event_data.h"
#include "../include/window.h"

#define MUGSHOT_PALETTE_NUM 13

extern const struct WindowTemplate __attribute__((long_call)) SetWindowTemplateFields(u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock);
extern u8 __attribute__((long_call)) sMugshotWindow;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

void DrawMugshotCore(void){
    struct WindowTemplate t;
    u16 windowId;
    extern struct CompressedSpriteSheet mugshots[];
    extern struct CompressedSpritePalette mugshotPals[];
    u8 x = gSpecialVar_0x8000;
    u8 y = gSpecialVar_0x8001;
    u8 width = gSpecialVar_0x8002;
    u8 height = gSpecialVar_0x8003;
    u16 mugshotIndex = gSpecialVar_0x8004;

    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    t = SetWindowTemplateFields(0, x, y, width, height, MUGSHOT_PALETTE_NUM, 0x40);
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadCompressedPalette(mugshotPals[mugshotIndex].data, BG_PLTT_ID(MUGSHOT_PALETTE_NUM), 0x20);
    CopyToWindowPixelBuffer(windowId, mugshots[mugshotIndex].data, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, width, height);
    CopyWindowToVram(windowId, 3);
}
