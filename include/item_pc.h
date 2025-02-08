#ifndef GUARD_ITEM_PC_H
#define GUARD_ITEM_PC_H

void __attribute__((long_call)) ItemPc_Init(u8 kind, MainCallback callback);
void __attribute__((long_call)) ItemPc_SetInitializedFlag(bool8 flag);

#endif //GUARD_ITEM_PC_H
