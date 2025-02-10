.text
.thumb
.align 2

.include "xse_commands.s"
.include "xse_defines.s"

.global EventScript_ObjectApproachPlayer
EventScript_ObjectApproachPlayer:
	lock
    applymovement LASTTALKED LockFacing
	special EndTrainerApproach
	waitstate
    call TrainerFaceFixScript
	gotonative LoadTrainerObjectScript
	end

LockFacing: .byte lock_facing, end_m

TrainerFaceFixScript:
	callasm TrainerFaceFix
	compare LASTRESULT 0xFFFF
	if equal _goto .LReturn
	switch LASTRESULT
	case DOWN, PlayerLookDown
	case UP, PlayerLookUp
	case LEFT, PlayerLookLeft
	case RIGHT, PlayerLookRight
.LReturn:
	return

PlayerLookDown:
	spriteface PLAYER DOWN
	return

PlayerLookUp:
	spriteface PLAYER UP
	return

PlayerLookLeft:
	spriteface PLAYER LEFT
	return

PlayerLookRight:
	spriteface PLAYER RIGHT
	return
