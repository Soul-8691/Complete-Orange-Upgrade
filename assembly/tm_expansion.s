.text
.align 2
.thumb
.thumb_func
.global TMSlotsHack

TMSlotsHack:
ldr r0, ram
str r0, [r1, #0x18]
mov r0, #0x80
strb r0, [r1, #0x1c]
ldr r0, return
bx r0

.align
ram:.word 0x0203c0c8
return:.word 0x08099e74+1
