#ifndef GUARD_MAIL_DATA_H
#define GUARD_MAIL_DATA_H

#include "global.h"

void __attribute__((long_call)) ClearMailData(void);
void __attribute__((long_call)) ClearMailStruct(struct Mail *mail);
bool8 __attribute__((long_call)) MonHasMail(struct Pokemon *mon);
u8 __attribute__((long_call)) GiveMailToMon(struct Pokemon *mon, u16 itemId);
u16 __attribute__((long_call)) SpeciesToMailSpecies(u16 species, u32 personality);
u16 __attribute__((long_call)) MailSpeciesToSpecies(u16 mailSpecies, u16 *buffer);
u8 __attribute__((long_call)) GiveMailToMon2(struct Pokemon *mon, struct Mail *mail);
void __attribute__((long_call)) TakeMailFromMon(struct Pokemon *mon);
void __attribute__((long_call)) ClearMailItemId(u8 mailId);
u8 __attribute__((long_call)) TakeMailFromMon2(struct Pokemon *mon);
bool8 __attribute__((long_call)) ItemIsMail(u16 itemId);

#endif //GUARD_MAIL_DATA_H
