.text
.thumb
.align 2

.include "xse_commands.s"
.include "xse_defines.s"

.global EventScript_ObjectApproachPlayer
EventScript_ObjectApproachPlayer:
	lock
	special EndTrainerApproach
	waitstate
	gotonative LoadTrainerObjectScript
	end
