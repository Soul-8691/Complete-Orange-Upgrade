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
	gotonative LoadTrainerObjectScript
	end

LockFacing: .byte lock_facing, end_m
