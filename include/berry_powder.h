#ifndef GUARD_BERRY_POWDER_H
#define GUARD_BERRY_POWDER_H

u32 __attribute__((long_call)) GetBerryPowder(void);
void __attribute__((long_call)) SetBerryPowder(u32 *powder, u32 amount);
void __attribute__((long_call)) ApplyNewEncryptionKeyToBerryPowder(u32 newKey);
bool8 __attribute__((long_call)) GiveBerryPowder(u32 amountToAdd);

#endif //GUARD_BERRY_POWDER_H
