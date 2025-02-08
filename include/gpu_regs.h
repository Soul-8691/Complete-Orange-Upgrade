#ifndef GUARD_GPU_REGS_H
#define GUARD_GPU_REGS_H

#include "global.h"

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void __attribute__((long_call)) InitGpuRegManager(void);
void __attribute__((long_call)) CopyBufferedValuesToGpuRegs(void);
void __attribute__((long_call)) SetGpuReg(u8 regOffset, u16 value);
void __attribute__((long_call)) SetGpuReg_ForcedBlank(u8 regOffset, u16 value);
u16 __attribute__((long_call)) GetGpuReg(u8 regOffset);
void __attribute__((long_call)) SetGpuRegBits(u8 regOffset, u16 mask);
void __attribute__((long_call)) ClearGpuRegBits(u8 regOffset, u16 mask);
void __attribute__((long_call)) EnableInterrupts(u16 mask);
void __attribute__((long_call)) DisableInterrupts(u16 mask);

#endif //GUARD_GPU_REGS_H
