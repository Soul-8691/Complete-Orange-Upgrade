#ifndef GUARD_RENEWABLE_HIDDEN_ITEMS_H
#define GUARD_RENEWABLE_HIDDEN_ITEMS_H

void __attribute__((long_call)) IncrementRenewableHiddenItemStepCounter(void);
void __attribute__((long_call)) TryRegenerateRenewableHiddenItems(void);
void __attribute__((long_call)) SetAllRenewableItemFlags(void);

#endif //GUARD_RENEWABLE_HIDDEN_ITEMS_H
