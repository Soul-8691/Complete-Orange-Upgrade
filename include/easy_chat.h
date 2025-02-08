#ifndef GUARD_EASY_CHAT_H
#define GUARD_EASY_CHAT_H

#include "global.h"
#include "constants/easy_chat.h"

#define NUM_ALPHABET_ROWS    4
#define NUM_ALPHABET_COLUMNS 7

struct EasyChatWordInfo
{
    const u8 *text;
    int alphabeticalOrder;
    int enabled;
};

typedef union
{
    const u16 *valueList;
    const struct EasyChatWordInfo *words;
} EasyChatGroupWordData;

struct EasyChatGroup
{
    EasyChatGroupWordData wordData;
    u16 numWords;
    u16 numEnabledWords;
};

struct EasyChatWordsByLetter
{
    const u16 *words;
    int numWords;
};

u8 __attribute__((long_call)) *CopyEasyChatWord(u8 *dest, u16 word);
u8 __attribute__((long_call)) *ConvertEasyChatWordsToString(u8 *dest, const u16 *src, u16 columns, u16 rows);
bool8 __attribute__((long_call)) EC_DoesEasyChatStringFitOnLine(const u16 *easyChatWords, u8 columns, u8 rows, u16 maxLength);
void __attribute__((long_call)) InitQuestionnaireWords(void);
void __attribute__((long_call)) InitEasyChatPhrases(void);
void __attribute__((long_call)) EnableRareWord(u8);
bool8 __attribute__((long_call)) InitEasyChatSelection(void);
void __attribute__((long_call)) DestroyEasyChatSelectionData(void);
u8 __attribute__((long_call)) GetSelectedGroupByIndex(u8);
void __attribute__((long_call)) GetUnlockedECWords(bool32 isAlphabetical, u16 groupId);
u16 __attribute__((long_call)) GetDisplayedWordByIndex(u16 index);
u16 __attribute__((long_call)) GetNumDisplayedWords(void);
const u8 *GetEasyChatWordGroupName(u8);
u8 __attribute__((long_call)) *CopyEasyChatWordPadded(u8 *, u16, u16);
void __attribute__((long_call)) DoEasyChatScreen(u8 type, u16 *words, MainCallback callback);
u8 __attribute__((long_call)) GetNumDisplayableGroups(void);
bool8 __attribute__((long_call)) InitEasyChatGraphicsWork(void);
bool8 __attribute__((long_call)) LoadEasyChatGraphics(void);
void __attribute__((long_call)) DestroyEasyChatGraphicsResources(void);
void __attribute__((long_call)) EasyChatInterfaceCommand_Setup(u16 id);
bool8 __attribute__((long_call)) EasyChatInterfaceCommand_Run(void);
u8 __attribute__((long_call)) GetEasyChatScreenFrameId(void);
const u8 *GetTitleText(void);
u16 __attribute__((long_call)) *GetEasyChatWordBuffer(void);
u8 __attribute__((long_call)) GetNumRows(void);
u8 __attribute__((long_call)) GetNumColumns(void);
u8 __attribute__((long_call)) GetMainCursorColumn(void);
u8 __attribute__((long_call)) GetMainCursorRow(void);
void __attribute__((long_call)) GetEasyChatInstructionsText(const u8 **str1, const u8 **str2);
void __attribute__((long_call)) GetEasyChatConfirmText(const u8 **str1, const u8 **str2);
void __attribute__((long_call)) GetEasyChatConfirmCancelText(const u8 **str1, const u8 **str2);
void __attribute__((long_call)) GetEasyChatConfirmDeletionText(const u8 **str1, const u8 **str2);
void __attribute__((long_call)) GetECSelectGroupCursorCoords(u8 *Xp, u8 *Yp);
bool8 __attribute__((long_call)) IsEasyChatAlphaMode(void);
u8 __attribute__((long_call)) GetECSelectGroupRowsAbove(void);
void __attribute__((long_call)) GetECSelectWordCursorCoords(s8 *arg0, s8 *arg1);
u8 __attribute__((long_call)) GetECSelectWordRowsAbove(void);
u8 __attribute__((long_call)) GetECSelectWordNumRows(void);
bool32 __attribute__((long_call)) ShouldDrawECUpArrow(void);
bool32 __attribute__((long_call)) ShouldDrawECDownArrow(void);

#endif // GUARD_EASY_CHAT_H
