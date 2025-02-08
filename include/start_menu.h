#ifndef GUARD_START_MENU_H
#define GUARD_START_MENU_H

#include "global.h"

void __attribute__((long_call)) AppendToList(u8 *list, u8 *pos, u8 newEntry);
void __attribute__((long_call)) Task_StartMenuHandleInput(u8 taskId);
void __attribute__((long_call)) SetUpReturnToStartMenu(void);
void __attribute__((long_call)) ShowStartMenu(void);
void __attribute__((long_call)) Field_AskSaveTheGame(void);
void __attribute__((long_call)) CB2_SetUpSaveAfterLinkBattle(void);

#endif // GUARD_START_MENU_H
