#ifndef GUARD_SCRIPT_H
#define GUARD_SCRIPT_H

#include "global.h"

struct ScriptContext;

typedef bool8 (*ScrCmdFunc)(struct ScriptContext *);
typedef u8 Script[];

struct ScriptContext
{
    u8 stackDepth;
    u8 mode;
    u8 comparisonResult;
    u8 (*nativePtr)(void);
    const u8 *scriptPtr;
    const u8 *stack[20];
    ScrCmdFunc *cmdTable;
    ScrCmdFunc *cmdTableEnd;
    u32 data[4];
};

#define ScriptReadByte(ctx) (*(ctx->scriptPtr++))

void __attribute__((long_call)) InitScriptContext(struct ScriptContext *ctx, void *cmdTable, void *cmdTableEnd);
u8 __attribute__((long_call)) SetupBytecodeScript(struct ScriptContext *ctx, const u8 *ptr);
void __attribute__((long_call)) SetupNativeScript(struct ScriptContext *ctx, bool8 (*ptr)(void));
void __attribute__((long_call)) StopScript(struct ScriptContext *ctx);
bool8 __attribute__((long_call)) RunScriptCommand(struct ScriptContext *ctx);
void __attribute__((long_call)) ScriptJump(struct ScriptContext *ctx, const u8 *ptr);
void __attribute__((long_call)) ScriptCall(struct ScriptContext *ctx, const u8 *ptr);
void __attribute__((long_call)) ScriptReturn(struct ScriptContext *ctx);
u16 __attribute__((long_call)) ScriptReadHalfword(struct ScriptContext *ctx);
u32 __attribute__((long_call)) ScriptReadWord(struct ScriptContext *ctx);
void __attribute__((long_call)) LockPlayerFieldControls(void);
void __attribute__((long_call)) UnlockPlayerFieldControls(void);
bool8 __attribute__((long_call)) ArePlayerFieldControlsLocked(void);
void __attribute__((long_call)) ScriptContext_Init(void);
bool8 __attribute__((long_call)) ScriptContext_IsEnabled(void);
bool8 __attribute__((long_call)) ScriptContext_RunScript(void);
void __attribute__((long_call)) ScriptContext_SetupScript(const u8 *ptr);
void __attribute__((long_call)) ScriptContext_Stop(void);
void __attribute__((long_call)) ScriptContext_Enable(void);
void __attribute__((long_call)) RunScriptImmediately(const u8 *ptr);
void __attribute__((long_call)) RunOnLoadMapScript(void);
void __attribute__((long_call)) RunOnTransitionMapScript(void);
void __attribute__((long_call)) RunOnResumeMapScript(void);
void __attribute__((long_call)) RunOnReturnToFieldMapScript(void);
void __attribute__((long_call)) RunOnDiveWarpMapScript(void);
bool8 __attribute__((long_call)) TryRunOnFrameMapScript(void);
void __attribute__((long_call)) TryRunOnWarpIntoMapScript(void);
u32 __attribute__((long_call)) CalculateRamScriptChecksum(void);
void __attribute__((long_call)) ClearRamScript(void);
bool8 __attribute__((long_call)) InitRamScript(u8 *script, u16 scriptSize, u8 mapGroup, u8 mapNum, u8 objectId);
const u8 *GetRamScript(u8 objectId, const u8 *script);
bool32 __attribute__((long_call)) ValidateRamScript(void);
void __attribute__((long_call)) InitRamScript_NoObjectEvent(u8 * script, u16 scriptSize);
u8 __attribute__((long_call)) * GetSavedRamScriptIfValid(void);
void __attribute__((long_call)) RegisterQuestLogInput(u8 var);
void __attribute__((long_call)) ClearMsgBoxCancelableState(void);
void __attribute__((long_call)) SetQuestLogInputIsDpadFlag(void);
void __attribute__((long_call)) ClearQuestLogInput(void);
void __attribute__((long_call)) ClearQuestLogInputIsDpadFlag(void);
void __attribute__((long_call)) MsgSetSignpost(void);
void __attribute__((long_call)) MsgSetNotSignpost(void);
bool8 __attribute__((long_call)) IsMsgSignpost(void);
bool8 __attribute__((long_call)) IsQuestLogInputDpad(void);
u8 __attribute__((long_call)) GetRegisteredQuestLogInput(void);
void __attribute__((long_call)) ResetFacingNpcOrSignpostVars(void);
bool8 __attribute__((long_call)) CanWalkAwayToCancelMsgBox(void);
void __attribute__((long_call)) SetWalkingIntoSignVars(void);
bool8 __attribute__((long_call)) IsMsgBoxWalkawayDisabled(void);

extern const u8 *gRamScriptRetAddr;
extern u8 __attribute__((long_call)) gWalkAwayFromSignInhibitTimer;

#endif // GUARD_SCRIPT_H
