.text
.align 2
.thumb
.thumb_func
.global JPANSaveblock

JPANSaveblock:
    ldr   r1, [r4, #0]
    mov   r3, #255
    lsl   r3, r3, #4
    add   r3, r3, r1
    ldrh  r0, [r3, #4]
    cmp   r0, #0
    beq   A00022
    cmp   r0, #4
    beq   A00028
    cmp   r0, #13
    beq   A00030
A00016:
    cmp   r5, #13
    ble   A00054
    mov   r0, #1
    pop   {r3}
    mov   r8, r3
    pop   {r4-r7, pc}
A00022:
    mov   r1, #204
    ldr   r2, A00048  @ = 0x0203C0C8
    b     A00036
A00028:
    mov   r1, #150
    lsl   r1, r1, #2
    ldr   r2, A0004C  @ = 0x0203C320
    b     A00036
A00030:
    mov   r1, #186
    lsl   r1, r1, #4
    ldr   r2, A00050  @ = 0x0203CEC0
A00036:
    sub   r3, r3, #4
    ldr   r0, [r3, #0]
    str   r0, [r2, #0]
    sub   r2, r2, #4
    sub   r1, r1, #4
    cmp   r1, #0
    bne   A00036
    b     A00016
A00054:
    ldr   r0, A00058  @ = 0x080D9E71
    bx    r0

.align
A00048:
    .word 0x0203C0C8
A0004C:
    .word 0x0203C320
A00050:
    .word 0x0203CEC0
A00058:
    .word 0x080D9E71

.global JPANSaveblock2

JPANSaveblock2:
    mov   r7, #255
    lsl   r7, r7, #4
    add   r7, r1, r7
    strh  r0, [r7, #6]
    ldrh  r6, [r7, #4]
    cmp   r6, #0
    beq   A00080
    cmp   r6, #4
    beq   A00086
    cmp   r6, #13
    beq   A0008E
    nop
A00078:
    ldr   r0, A0007C  @ = 0x080D9923
    bx    r0
A00080:
    mov   r3, #204
    ldr   r2, A000A4  @ = 0x0203C0C8
    b     A00094
A00086:
    mov   r3, #150
    lsl   r3, r3, #2
    ldr   r2, A000A8  @ = 0x0203C320
    b     A00094
A0008E:
    mov   r3, #186
    lsl   r3, r3, #4
    ldr   r2, A000AC  @ = 0x0203CEC0
A00094:
    sub   r7, r7, #4
    ldr   r0, [r2, #0]
    str   r0, [r7, #0]
    sub   r2, r2, #4
    sub   r3, r3, #4
    cmp   r3, #0
    bne   A00094
    b     A00078

.align
A0007C:
    .word 0x080D9923
A000A4:
    .word 0x0203C0C8
A000A8:
    .word 0x0203C320
A000AC:
    .word 0x0203CEC0
