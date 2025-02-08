#ifndef GUARD_FIELD_MESSAGE_BOX_H
#define GUARD_FIELD_MESSAGE_BOX_H

#include "global.h"

enum {
    FIELD_MESSAGE_BOX_HIDDEN,
    FIELD_MESSAGE_BOX_UNUSED,
    FIELD_MESSAGE_BOX_NORMAL,
    FIELD_MESSAGE_BOX_AUTO_SCROLL,
};

bool8 __attribute__((long_call)) ShowFieldMessage(const u8 *message);
bool8 __attribute__((long_call)) ShowFieldAutoScrollMessage(const u8 *message);
void __attribute__((long_call)) HideFieldMessageBox(void);
bool8 __attribute__((long_call)) IsFieldMessageBoxHidden(void);
u8 __attribute__((long_call)) GetFieldMessageBoxType(void);
void __attribute__((long_call)) InitFieldMessageBox(void);

#endif // GUARD_FIELD_MESSAGE_BOX_H
