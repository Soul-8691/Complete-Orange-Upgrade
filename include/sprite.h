#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

#include "global.h"

#define MAX_SPRITES 64
#define SPRITE_NONE 0xFF
#define TAG_NONE 0xFFFF

// Given to SetSpriteMatrixAnchor to skip anchoring one of the coords.
#define NO_ANCHOR 0x800

struct SpriteSheet
{
    const void *data;  // Raw uncompressed pixel data
    u16 size;
    u16 tag;
};

struct CompressedSpriteSheet
{
    const u32 *data;  // LZ77 compressed pixel data
    u16 size;        // Uncompressed size of pixel data
    u16 tag;
};

struct SpriteFrameImage
{
    const void *data;
    u16 size;
};

#define obj_frame_tiles(ptr) {.data = (u8 *)ptr, .size = sizeof ptr}
#define overworld_frame(ptr, width, height, frame) {.data = (u8 *)ptr + (width * height * frame * 64)/2, .size = (width * height * 64)/2}

struct SpritePalette
{
    const u16 *data;  // Raw uncompressed palette data
    u16 tag;
};

struct CompressedSpritePalette
{
    const u32 *data;  // LZ77 compressed palette data
    u16 tag;
};

struct AnimFrameCmd
{
    // If the sprite has an array of images, this is the array index.
    // If the sprite has a sheet, this is the tile offset.
    u32 imageValue:16;

    u32 duration:6;
    u32 hFlip:1;
    u32 vFlip:1;
};

struct AnimLoopCmd
{
    u32 type:16;
    u32 count:6;
};

struct AnimJumpCmd
{
    u32 type:16;
    u32 target:6;
};

// The first halfword of this union specifies the type of command.
// If it -2, then it is a jump command. If it is -1, then it is the end of the script.
// Otherwise, it is the imageValue for a frame command.
union AnimCmd
{
    s16 type;
    struct AnimFrameCmd frame;
    struct AnimLoopCmd loop;
    struct AnimJumpCmd jump;
};

#define ANIMCMD_FRAME(...) \
    {.frame = {__VA_ARGS__}}
#define ANIMCMD_LOOP(_count) \
    {.loop = {.type = -3, .count = _count}}
#define ANIMCMD_JUMP(_target) \
    {.jump = {.type = -2, .target = _target}}
#define ANIMCMD_END \
    {.type = -1}

struct AffineAnimFrameCmd
{
    s16 xScale;
    s16 yScale;
    u8 rotation;
    u8 duration;
};

struct AffineAnimLoopCmd
{
    s16 type;
    s16 count;
};

struct AffineAnimJumpCmd
{
    s16 type;
    u16 target;
};

struct AffineAnimEndCmdAlt
{
    s16 type;
    u16 val;
};

union AffineAnimCmd
{
    s16 type;
    struct AffineAnimFrameCmd frame;
    struct AffineAnimLoopCmd loop;
    struct AffineAnimJumpCmd jump;
    struct AffineAnimEndCmdAlt end;
};

#define AFFINEANIMCMDTYPE_LOOP 0x7FFD
#define AFFINEANIMCMDTYPE_JUMP 0x7FFE
#define AFFINEANIMCMDTYPE_END  0x7FFF

#define AFFINEANIMCMD_FRAME(_xScale, _yScale, _rotation, _duration) \
    {.frame = {.xScale = _xScale, .yScale = _yScale, .rotation = _rotation, .duration = _duration}}
#define AFFINEANIMCMD_LOOP(_count) \
    {.loop = {.type = AFFINEANIMCMDTYPE_LOOP, .count = _count}}
#define AFFINEANIMCMD_JUMP(_target) \
    {.jump = {.type = AFFINEANIMCMDTYPE_JUMP, .target = _target}}
#define AFFINEANIMCMD_END \
    {.type = AFFINEANIMCMDTYPE_END}
#define AFFINEANIMCMD_LOOP(_count) \
    {.loop = {.type = AFFINEANIMCMDTYPE_LOOP, .count = _count}}
#define AFFINEANIMCMD_JUMP(_target) \
    {.jump = {.type = AFFINEANIMCMDTYPE_JUMP, .target = _target}}
#define AFFINEANIMCMD_END_ALT(_val) \
    {.end = {.type = AFFINEANIMCMDTYPE_END, .val = _val}}

struct AffineAnimState
{
    u8 animNum;
    u8 animCmdIndex;
    u8 delayCounter;
    u8 loopCounter;
    s16 xScale;
    s16 yScale;
    u16 rotation;
};

enum
{
    SUBSPRITES_OFF,
    SUBSPRITES_ON,
    SUBSPRITES_IGNORE_PRIORITY, // on but priority is ignored
};

struct Subsprite
{
    s8 x; // was u16 in R/S
    s8 y; // was u16 in R/S
    u16 shape:2;
    u16 size:2;
    u16 tileOffset:10;
    u16 priority:2;
};

struct SubspriteTable
{
    u8 subspriteCount;
    const struct Subsprite *subsprites;
};

struct Sprite;

typedef void (*SpriteCallback)(struct Sprite *);

struct SpriteTemplate
{
    u16 tileTag;
    u16 paletteTag;
    const struct OamData *oam;
    const union AnimCmd *const *anims;
    const struct SpriteFrameImage *images;
    const union AffineAnimCmd *const *affineAnims;
    SpriteCallback callback;
};

struct Sprite
{
    /*0x00*/ struct OamData oam;
    /*0x08*/ const union AnimCmd *const *anims;
    /*0x0C*/ const struct SpriteFrameImage *images;
    /*0x10*/ const union AffineAnimCmd *const *affineAnims;
    /*0x14*/ const struct SpriteTemplate *template;
    /*0x18*/ const struct SubspriteTable *subspriteTables;
    /*0x1C*/ SpriteCallback callback;

    /*0x20*/ s16 x, y;
    /*0x24*/ s16 x2, y2;
    /*0x28*/ s8 centerToCornerVecX;
    /*0x29*/ s8 centerToCornerVecY;

    /*0x2A*/ u8 animNum;
    /*0x2B*/ u8 animCmdIndex;
    /*0x2C*/ u8 animDelayCounter:6;
             u8 animPaused:1;
             u8 affineAnimPaused:1;
    /*0x2D*/ u8 animLoopCounter;

    // general purpose data fields
    /*0x2E*/ s16 data[8];

    /*0x3E*/ u16 inUse:1;               //1
             u16 coordOffsetEnabled:1;  //2
             u16 invisible:1;           //4
             u16 flags_3:1;             //8
             u16 flags_4:1;             //0x10
             u16 flags_5:1;             //0x20
             u16 flags_6:1;             //0x40
             u16 flags_7:1;             //0x80
    /*0x3F*/ u16 hFlip:1;               //1
             u16 vFlip:1;               //2
             u16 animBeginning:1;       //4
             u16 affineAnimBeginning:1; //8
             u16 animEnded:1;           //0x10
             u16 affineAnimEnded:1;     //0x20
             u16 usingSheet:1;          //0x40
             u16 anchored:1;            //0x80

    /*0x40*/ u16 sheetTileStart;

    /*0x42*/ u8 subspriteTableNum:6;
             u8 subspriteMode:2;

    /*0x43*/ u8 subpriority;
};

struct OamMatrix
{
    s16 a;
    s16 b;
    s16 c;
    s16 d;
};

extern const struct OamData gDummyOamData;
extern const union AnimCmd *const gDummySpriteAnimTable[];
extern const union AffineAnimCmd *const gDummySpriteAffineAnimTable[];
extern s16 __attribute__((long_call)) gSpriteCoordOffsetX;
extern s16 __attribute__((long_call)) gSpriteCoordOffsetY;
extern const struct SpriteTemplate gDummySpriteTemplate;
extern struct Sprite gSprites[];
extern struct OamMatrix gOamMatrices[];
extern bool8 __attribute__((long_call)) gAffineAnimsDisabled;
extern u16 __attribute__((long_call)) gReservedSpriteTileCount;

void __attribute__((long_call)) ResetSpriteData(void);
void __attribute__((long_call)) AnimateSprites(void);
void __attribute__((long_call)) BuildOamBuffer(void);
u8 __attribute__((long_call)) CreateSprite(const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority);
u8 __attribute__((long_call)) CreateSpriteAtEnd(const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority);
u8 __attribute__((long_call)) CreateInvisibleSprite(void (*callback)(struct Sprite *));
u8 __attribute__((long_call)) CreateSpriteAndAnimate(const struct SpriteTemplate *template, s16 x, s16 y, u8 subpriority);
void __attribute__((long_call)) DestroySprite(struct Sprite *sprite);
void __attribute__((long_call)) ResetOamRange(u8 a, u8 b);
void __attribute__((long_call)) LoadOam(void);
void __attribute__((long_call)) SetOamMatrix(u8 matrixNum, u16 a, u16 b, u16 c, u16 d);
void __attribute__((long_call)) CalcCenterToCornerVec(struct Sprite *sprite, u8 shape, u8 size, u8 affineMode);
void __attribute__((long_call)) SpriteCallbackDummy(struct Sprite *sprite);
void __attribute__((long_call)) ProcessSpriteCopyRequests(void);
void __attribute__((long_call)) RequestSpriteCopy(const u8 *src, u8 *dest, u16 size);
void __attribute__((long_call)) FreeSpriteTiles(struct Sprite *sprite);
void __attribute__((long_call)) FreeSpritePalette(struct Sprite *sprite);
void __attribute__((long_call)) FreeSpriteOamMatrix(struct Sprite *sprite);
void __attribute__((long_call)) DestroySpriteAndFreeResources(struct Sprite *sprite);
void __attribute__((long_call)) AnimateSprite(struct Sprite *sprite);
void __attribute__((long_call)) StartSpriteAnim(struct Sprite *sprite, u8 animNum);
void __attribute__((long_call)) StartSpriteAnimIfDifferent(struct Sprite *sprite, u8 animNum);
void __attribute__((long_call)) SeekSpriteAnim(struct Sprite *sprite, u8 animCmdIndex);
void __attribute__((long_call)) StartSpriteAffineAnim(struct Sprite *sprite, u8 animNum);
void __attribute__((long_call)) StartSpriteAffineAnimIfDifferent(struct Sprite *sprite, u8 animNum);
void __attribute__((long_call)) ChangeSpriteAffineAnim(struct Sprite *sprite, u8 animNum);
void __attribute__((long_call)) ChangeSpriteAffineAnimIfDifferent(struct Sprite *sprite, u8 animNum);
void __attribute__((long_call)) SetSpriteSheetFrameTileNum(struct Sprite *sprite);
u8 __attribute__((long_call)) AllocOamMatrix(void);
void __attribute__((long_call)) FreeOamMatrix(u8 matrixNum);
void __attribute__((long_call)) InitSpriteAffineAnim(struct Sprite *sprite);
void __attribute__((long_call)) SetOamMatrixRotationScaling(u8 matrixNum, s16 xScale, s16 yScale, u16 rotation);
u16 __attribute__((long_call)) LoadSpriteSheet(const struct SpriteSheet *sheet);
void __attribute__((long_call)) LoadSpriteSheets(const struct SpriteSheet *sheets);
u16 __attribute__((long_call)) AllocTilesForSpriteSheet(struct SpriteSheet *sheet);
void __attribute__((long_call)) AllocTilesForSpriteSheets(struct SpriteSheet *sheets);
void __attribute__((long_call)) FreeSpriteTilesByTag(u16 tag);
void __attribute__((long_call)) FreeSpriteTileRanges(void);
u16 __attribute__((long_call)) GetSpriteTileStartByTag(u16 tag);
u16 __attribute__((long_call)) GetSpriteTileTagByTileStart(u16 start);
void __attribute__((long_call)) RequestSpriteSheetCopy(const struct SpriteSheet *sheet);
u16 __attribute__((long_call)) LoadSpriteSheetDeferred(const struct SpriteSheet *sheet);
void __attribute__((long_call)) FreeAllSpritePalettes(void);
u8 __attribute__((long_call)) LoadSpritePalette(const struct SpritePalette *palette);
void __attribute__((long_call)) LoadSpritePalettes(const struct SpritePalette *palettes);
u8 __attribute__((long_call)) AllocSpritePalette(u16 tag);
u8 __attribute__((long_call)) IndexOfSpritePaletteTag(u16 tag);
u16 __attribute__((long_call)) GetSpritePaletteTagByPaletteNum(u8 paletteNum);
void __attribute__((long_call)) FreeSpritePaletteByTag(u16 tag);
void __attribute__((long_call)) SetSubspriteTables(struct Sprite *sprite, const struct SubspriteTable *subspriteTables);
bool8 __attribute__((long_call)) AddSpriteToOamBuffer(struct Sprite *object, u8 *oamIndex);
bool8 __attribute__((long_call)) AddSubspritesToOamBuffer(struct Sprite *sprite, struct OamData *destOam, u8 *oamIndex);
void __attribute__((long_call)) CopyToSprites(u8 *src);
void __attribute__((long_call)) CopyFromSprites(u8 *dest);
u8 __attribute__((long_call)) SpriteTileAllocBitmapOp(u16 bit, u8 op);
void __attribute__((long_call)) ClearSpriteCopyRequests(void);
void __attribute__((long_call)) ResetAffineAnimData(void);
void __attribute__((long_call)) FreeSpriteTilesIfNotUsingSheet(struct Sprite *sprite);
s16 __attribute__((long_call)) AllocSpriteTiles(u16 tileCount);
void __attribute__((long_call)) SetSpriteMatrixAnchor(struct Sprite* sprite, s16 xmod, s16 ymod);

#endif //GUARD_SPRITE_H
