#ifndef GUARD_WEATHER_H
#define GUARD_WEATHER_H

#include "global.h"
#include "constants/field_weather.h"

#define TAG_WEATHER_START 0x1200
enum {
    GFXTAG_CLOUD = TAG_WEATHER_START,
    GFXTAG_FOG_H,
    GFXTAG_ASH,
    GFXTAG_FOG_D,
    GFXTAG_SANDSTORM,
    GFXTAG_BUBBLE,
    GFXTAG_RAIN,
};
enum {
    PALTAG_WEATHER = TAG_WEATHER_START,
};

struct Weather
{
    union
    {
        struct
        {
            struct Sprite *rainSprites[MAX_RAIN_SPRITES];
            struct Sprite *snowflakeSprites[101];
            struct Sprite *cloudSprites[NUM_CLOUD_SPRITES];
        } s1;
        struct
        {
            u8 filler0[0xA0];
            struct Sprite *fogHSprites[NUM_FOG_HORIZONTAL_SPRITES];
            struct Sprite *ashSprites[NUM_ASH_SPRITES];
            struct Sprite *fogDSprites[NUM_FOG_DIAGONAL_SPRITES];
            struct Sprite *sandstormSprites1[NUM_SANDSTORM_SPRITES];
            struct Sprite *sandstormSprites2[NUM_SWIRL_SANDSTORM_SPRITES];
        } s2;
    } sprites;
    u8 gammaShifts[19][32];
    u8 altGammaShifts[19][32];
    s8 gammaIndex;
    s8 gammaTargetIndex;
    u8 gammaStepDelay;
    u8 gammaStepFrameCounter;
    u16 fadeDestColor;
    u8 palProcessingState;
    u8 fadeScreenCounter;
    bool8 readyForInit;
    u8 taskId;
    u8 fadeInActive;
    u8 fadeInCounter;
    u16 initStep;
    u16 finishStep;
    u8 currWeather;
    u8 nextWeather;
    u8 weatherGfxLoaded;
    bool8 weatherChangeComplete;
    u8 weatherPicSpritePalIndex;
    u8 altGammaSpritePalIndex;
    u16 rainSpriteVisibleCounter;
    u8 curRainSpriteIndex;
    u8 targetRainSpriteCount;
    u8 rainSpriteCount;
    u8 rainSpriteVisibleDelay;
    u8 isDownpour;
    u8 rainStrength;
    bool8 cloudSpritesCreated;
    u16 snowflakeVisibleCounter;
    u16 snowflakeTimer;
    u8 snowflakeSpriteCount;
    u8 targetSnowflakeSpriteCount;
    u16 thunderDelay;
    u16 thunderCounter;
    bool8 thunderAllowEnd;
    bool8 thunderSkipShort;
    u8 thunderShortRetries;
    bool8 thunderTriggered;
    u16 fogHScrollPosX;
    u16 fogHScrollCounter;
    u16 fogHScrollOffset;
    u8 lightenedFogSpritePals[6];
    u8 lightenedFogSpritePalsCount;
    bool8 fogHSpritesCreated;
    u16 ashBaseSpritesX;
    u16 ashUnused;
    bool8 ashSpritesCreated;
    u32 sandstormXOffset;
    u32 sandstormYOffset;
    u8 filler_70C[2];
    u16 sandstormBaseSpritesX;
    u16 sandstormPosY;
    u16 sandstormWaveIndex;
    u16 sandstormWaveCounter;
    bool8 sandstormSpritesCreated;
    bool8 sandstormSwirlSpritesCreated;
    u16 fogDBaseSpritesX;
    u16 fogDPosY;
    u16 fogDScrollXCounter;
    u16 fogDScrollYCounter;
    u16 fogDXOffset;
    u16 fogDYOffset;
    bool8 fogDSpritesCreated;
    u16 bubblesDelayCounter;
    u16 bubblesDelayIndex;
    u16 bubblesCoordsIndex;
    u16 bubblesSpriteCount;
    bool8 bubblesSpritesCreated;
    u16 currBlendEVA;
    u16 currBlendEVB;
    u16 targetBlendEVA;
    u16 targetBlendEVB;
    u8 blendUpdateCounter;
    u8 blendFrameCounter;
    u8 blendDelay;
    s16 droughtBrightnessStage;
    s16 droughtLastBrightnessStage;
    s16 droughtTimer;
    s16 droughtState;
    u8 filler_744[0xD-4];
    s8 loadDroughtPalsIndex;
    u8 loadDroughtPalsOffset;
};

extern struct Weather *const gWeatherPtr;

void __attribute__((long_call)) FadeScreen(u8 mode, s8 delay);

void __attribute__((long_call)) SetSavedWeather(u32);
u8 __attribute__((long_call)) GetSav1Weather(void);

void __attribute__((long_call)) DoCurrentWeather(void);
void __attribute__((long_call)) SetSavedWeatherFromCurrMapHeader(void);
void __attribute__((long_call)) SlightlyDarkenPalsInWeather(u16 *, u16 *, u32);
void __attribute__((long_call)) PlayRainStoppingSoundEffect(void);
bool8 __attribute__((long_call)) IsWeatherNotFadingIn(void);
void __attribute__((long_call)) SetWeatherScreenFadeOut(void);
void __attribute__((long_call)) WeatherProcessingIdle(void);
u8 __attribute__((long_call)) GetCurrentWeather(void);
void __attribute__((long_call)) delay(u8, u8, u32);
void __attribute__((long_call)) UpdateSpritePaletteWithWeather(u8 palIdx);
void __attribute__((long_call)) ResetPreservedPalettesInWeather(void);
void __attribute__((long_call)) PreservePaletteInWeather(u8 palIdx);

void __attribute__((long_call)) SetNextWeather(u8 weather);
void __attribute__((long_call)) SetCurrentAndNextWeather(u8 weather);
void __attribute__((long_call)) Weather_SetBlendCoeffs(u8 eva, u8 evb);
void __attribute__((long_call)) Weather_SetTargetBlendCoeffs(u8 eva, u8 evb, int delay);
bool8 __attribute__((long_call)) Weather_UpdateBlend(void);
void __attribute__((long_call)) LoadCustomWeatherSpritePalette(const u16 *palette);
void __attribute__((long_call)) ResetDroughtWeatherPaletteLoading(void);
bool8 __attribute__((long_call)) LoadDroughtWeatherPalettes(void);
void __attribute__((long_call)) DroughtStateInit(void);
void __attribute__((long_call)) DroughtStateRun(void);
void __attribute__((long_call)) SetRainStrengthFromSoundEffect(u16 soundEffect);
void __attribute__((long_call)) WeatherShiftGammaIfPalStateIdle(s8 gammaIndex);
void __attribute__((long_call)) WeatherBeginGammaFade(u8 gammaIndex, u8 gammaTargetIndex, u8 gammaStepDelay);
void __attribute__((long_call)) ApplyWeatherGammaShiftToPal(u8 paletteIndex);
void __attribute__((long_call)) StartWeather(void);
void __attribute__((long_call)) ResumePausedWeather(void);
void __attribute__((long_call)) FadeSelectedPals(u8 mode, s8 delay, u32 selectedPalettes);

extern const u16 gCloudsWeatherPalette[];
extern const u16 gSandstormWeatherPalette[];
extern const u8 gWeatherFogDiagonalTiles[];
extern const u8 gWeatherFogHorizontalTiles[];
extern const u8 gWeatherCloudTiles[];
extern const u8 gWeatherSnow1Tiles[];
extern const u8 gWeatherSnow2Tiles[];
extern const u8 gWeatherBubbleTiles[];
extern const u8 gWeatherAshTiles[];
extern const u8 gWeatherRainTiles[];
extern const u8 gWeatherSandstormTiles[];

#endif // GUARD_WEATHER_H
