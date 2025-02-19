#ifndef GUARD_STRING_UTIL_H
#define GUARD_STRING_UTIL_H

#include "global.h"

enum StringConvertMode
{
    STR_CONV_MODE_LEFT_ALIGN,
    STR_CONV_MODE_RIGHT_ALIGN,
    STR_CONV_MODE_LEADING_ZEROS
};

u8* __attribute__((long_call)) StringCopy(u8* dest, const u8 *src);
u8* __attribute__((long_call)) StringCopy10(u8 *dest, const u8 *src);
u8* __attribute__((long_call)) StringCopyN(u8 *dest, const u8 *src, u8 n);
u8* __attribute__((long_call)) StringAppend(u8 *dest, const u8 *src);
u16 __attribute__((long_call)) StringLength(const u8 *str);
u8* __attribute__((long_call)) ConvertIntToDecimalStringN(u8 *dest, s32 value, enum StringConvertMode mode, u8 n);
u8* __attribute__((long_call)) StringExpandPlaceholders(u8 *dest, const u8 *src);
s32 __attribute__((long_call)) StringCompare(const u8 *str1, const u8 *str2);
s32 __attribute__((long_call)) StringCompareN(const u8 *str1, const u8 *str2, u32 n);
u8* __attribute__((long_call)) StringAppendN(u8 *dest, const u8 *src, u8 n);
u8* __attribute__((long_call)) StringCopyPadded(u8 *dest, const u8 *src, u8 c, u16 n);

// u8 *StringCopy_Nickname(u8 *dest, const u8 *src);
// u8 *StringGet_Nickname(u8 *str);
// u8 *StringCopy_PlayerName(u8 *dest, const u8 *src);
// u8 *StringCopy(u8 *dest, const u8 *src);
// u8 *StringAppend(u8 *dest, const u8 *src);
// u8 *StringCopyN(u8 *dest, const u8 *src, u8 n);
// u8 *StringAppendN(u8 *dest, const u8 *src, u8 n);
// u16 StringLength(const u8 *str);
// s32 StringCompare(const u8 *str1, const u8 *str2);
// s32 StringCompareN(const u8 *str1, const u8 *str2, u32 n);
// bool8 IsStringLengthAtLeast(const u8 *str, s32 n);
// u8 *ConvertIntToDecimalStringN(u8 *dest, s32 value, enum StringConvertMode mode, u8 n);
// u8 *ConvertUIntToDecimalStringN(u8 *dest, u32 value, enum StringConvertMode mode, u8 n);
// u8 *ConvertIntToHexStringN(u8 *dest, s32 value, enum StringConvertMode mode, u8 n);
// u8 *StringExpandPlaceholders(u8 *dest, const u8 *src);
// u8 *StringBraille(u8 *dest, const u8 *src);
// u8 *GetExpandedPlaceholder(u32 id);
// u8 *StringFill(u8 *dest, u8 c, u16 n);
// u8 *StringCopyPadded(u8 *dest, const u8 *src, u8 c, u16 n);
// u8 *StringFillWithTerminator(u8 *dest, u16 n);
// u8 *StringCopyN_Multibyte(u8 *dest, const u8 *src, u32 n);
// u32 StringLength_Multibyte(const u8 *str);
// u8 *WriteColorChangeControlCode(u8 *dest, u32 colorType, u8 color);
// bool32 IsStringJapanese(u8 *str);
// u8 GetExtCtrlCodeLength(u8 code);
// s32 StringCompareWithoutExtCtrlCodes(const u8 *str1, const u8 *str2);
// void ConvertInternationalString(u8 *s, u8 language);
// void StripExtCtrlCodes(u8 *str);

#endif // GUARD_STRING_UTIL_H
