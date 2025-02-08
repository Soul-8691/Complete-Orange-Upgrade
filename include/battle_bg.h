#ifndef GUARD_BATTLE_BG_H
#define GUARD_BATTLE_BG_H

#include "bg.h"

extern const struct BgTemplate gBattleBgTemplates[];

void __attribute__((long_call)) InitBattleBgsVideo(void);
void __attribute__((long_call)) DrawBattleEntryBackground(void);
void __attribute__((long_call)) InitLinkBattleVsScreen(u8 taskId);
void __attribute__((long_call)) LoadBattleMenuWindowGfx(void);
void __attribute__((long_call)) LoadBattleTextboxAndBackground(void);
void __attribute__((long_call)) BattleInitBgsAndWindows(void);
void __attribute__((long_call)) DrawMainBattleBackground(void);

#endif // GUARD_BATTLE_BG_H
