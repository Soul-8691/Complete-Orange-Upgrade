#ifndef GUARD_PC_SCREEN_EFFECT_H
#define GUARD_PC_SCREEN_EFFECT_H

void __attribute__((long_call)) BeginPCScreenEffect_TurnOn(u16 xspeed, u16 yspeed, u8 priority);
void __attribute__((long_call)) BeginPCScreenEffect_TurnOff(u16 xspeed, u16 yspeed, u8 priority);
bool8 __attribute__((long_call)) IsPCScreenEffectRunning_TurnOff(void);
bool8 __attribute__((long_call)) IsPCScreenEffectRunning_TurnOn(void);

#endif //GUARD_PC_SCREEN_EFFECT_H
