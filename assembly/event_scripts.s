.align 2
.thumb

.include "xse_commands.s"
.include "xse_defines.s"

.global EventScript_UseFlash

EventScript_UseFlash:
	lockall
	bufferpartypokemon 0x0 0x8004
	bufferattack 0x1 0x94
	setflag 0x806
	msgbox 0x81BDFD7 MSG_NORMAL
	checksound
	sound 0xC8
	animateflash 0x0
	setflashradius 0x0
	releaseall
	end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global EventScript_UseSurf

EventScript_UseSurf:
	bufferpartypokemon 0x0 0x8004
	bufferattack 0x1 57
	msgbox 0x81A556E MSG_YESNO
	compare LASTRESULT NO
	if equal _goto EventScript_SurfEnd
	lockall
	msgbox 0x81BDFD7 MSG_KEEPOPEN
	setanimation 0x0 0x8004
	doanimation 0x9
	goto EventScript_SurfEnd

EventScript_SurfEnd:
	releaseall
	end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global EventScript_WaterDyedBlue

EventScript_WaterDyedBlue:
	msgbox gText_WaterDyed MSG_NORMAL
	end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global EventScript_UseWaterfall

EventScript_UseWaterfall:
	bufferpartypokemon 0x0 0x8004
	bufferattack 0x1 127
	msgbox 0x81BE33F MSG_YESNO
	compare LASTRESULT NO
	if equal _goto EventScript_WaterfallEnd
	lockall
	msgbox 0x81BDFD7 MSG_KEEPOPEN
	setanimation 0x0 0x8004
	doanimation 0x2B
	goto EventScript_WaterfallEnd

EventScript_WaterfallEnd:
	releaseall
	end

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

.global EventScript_WallOfWater

EventScript_WallOfWater:
	msgbox 0x81BE30A MSG_NORMAL
	end
