#ifndef GUARD_FIELD_WEATHER_EFFECTS_H
#define GUARD_FIELD_WEATHER_EFFECTS_H

bool8 __attribute__((long_call)) Ash_Finish(void);
bool8 __attribute__((long_call)) Bubbles_Finish(void);
bool8 __attribute__((long_call)) Clouds_Finish(void);
bool8 __attribute__((long_call)) FogHorizontal_Finish(void);
bool8 __attribute__((long_call)) FogDiagonal_Finish(void);
bool8 __attribute__((long_call)) Rain_Finish(void);
bool8 __attribute__((long_call)) Thunderstorm_Finish(void);
bool8 __attribute__((long_call)) Sandstorm_Finish(void);
bool8 __attribute__((long_call)) Snow_Finish(void);
bool8 __attribute__((long_call)) Sunny_Finish(void);
bool8 __attribute__((long_call)) Drought_Finish(void);
bool8 __attribute__((long_call)) Shade_Finish(void);
void __attribute__((long_call)) Ash_InitAll(void);
void __attribute__((long_call)) Ash_InitVars(void);
void __attribute__((long_call)) Ash_Main(void);
void __attribute__((long_call)) Bubbles_InitAll(void);
void __attribute__((long_call)) Bubbles_InitVars(void);
void __attribute__((long_call)) Bubbles_Main(void);
void __attribute__((long_call)) Clouds_InitAll(void);
void __attribute__((long_call)) Clouds_InitVars(void);
void __attribute__((long_call)) Clouds_Main(void);
void __attribute__((long_call)) Drought_InitAll(void);
void __attribute__((long_call)) Drought_InitVars(void);
void __attribute__((long_call)) Drought_Main(void);
void __attribute__((long_call)) FogHorizontal_InitAll(void);
void __attribute__((long_call)) FogHorizontal_InitVars(void);
void __attribute__((long_call)) FogHorizontal_Main(void);
void __attribute__((long_call)) FogDiagonal_InitAll(void);
void __attribute__((long_call)) FogDiagonal_InitVars(void);
void __attribute__((long_call)) FogDiagonal_Main(void);
void __attribute__((long_call)) Rain_InitAll(void);
void __attribute__((long_call)) Rain_InitVars(void);
void __attribute__((long_call)) Rain_Main(void);
void __attribute__((long_call)) Thunderstorm_Main(void);
void __attribute__((long_call)) Sandstorm_InitAll(void);
void __attribute__((long_call)) Sandstorm_InitVars(void);
void __attribute__((long_call)) Sandstorm_Main(void);
void __attribute__((long_call)) Snow_InitAll(void);
void __attribute__((long_call)) Snow_InitVars(void);
void __attribute__((long_call)) Shade_InitAll(void);
void __attribute__((long_call)) Shade_InitVars(void);
void __attribute__((long_call)) Sunny_InitAll(void);
void __attribute__((long_call)) Sunny_InitVars(void);
void __attribute__((long_call)) Sunny_Main(void);
void __attribute__((long_call)) Shade_Main(void);
void __attribute__((long_call)) Snow_Main(void);
void __attribute__((long_call)) Thunderstorm_InitVars(void);
void __attribute__((long_call)) Thunderstorm_InitAll(void);
void __attribute__((long_call)) Downpour_InitVars(void);
void __attribute__((long_call)) Downpour_InitAll(void);

#endif //GUARD_FIELD_WEATHER_EFFECTS_H
