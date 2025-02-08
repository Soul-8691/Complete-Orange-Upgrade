#ifndef GUARD_FIELD_SCREEN_H
#define GUARD_FIELD_SCREEN_H

#include "global.h"

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
void __attribute__((long_call)) pal_fill_black(void);
void __attribute__((long_call)) UpdateWeatherPerDay(u16 days);

#endif //GUARD_FIELD_SCREEN_H
