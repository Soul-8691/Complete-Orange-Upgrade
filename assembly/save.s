.text
.thumb
.align 2

.include "asm_defines.s"

.pool
@0x806FC84 with r0
LinkBattleSaveHook:
	bl SaveDataAfterLinkBattle
	ldr r1, =0x806FCE6 | 1
	bx r1

.pool
@0x805415E with r0
LinkTradeSaveHook:
	bl SaveDataAfterLinkTrade
	ldr r1, =gMain
	mov r2, #0x87
	lsl r2, #0x3
	add r1, r2
	mov r2, #0x0
	ldr r3, =0x8054170 | 1
	bx r3

.pool
@0x8054A60 with r0
NewGameSaveClearHook:
	push {r4-r6, lr}
	mov r6, r8
	push {r6}
	sub sp, sp, #0x8
	bl NewGameWipeNewSaveData
	ldr r0, =0x8054A68 | 1
	bx r0
