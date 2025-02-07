.text
.align 2
.thumb
.thumb_func
.global pocket_size_limiters

.equ freeRAM, 0x0203c0c8
.equ NumMainPocketItems, 100
.equ NumKeyItems, 100
.equ NumPokeballs, 50
.equ NumTMs, 100
.equ NumBerries, 100

MainPocket:
    ldr r0, .MainPocketRAM        @start of expanded item data
    str r0, [r1]        @store new RAM pocket data address into DMA memory
    mov r0, #0x4B            @75 main pocket items
    strb r0, [r1, #0x4]
    
KeyItems:
    ldr r0, =(freeRAM + (4*NumMainPocketItems))
    str r0, [r1, #0x8]
    mov r0, #NumKeyItems
    strb r0, [r1, #0xC]
    
PokeballsPocket:
    ldr r0, =(freeRAM + (4*NumMainPocketItems) + (4*NumKeyItems))
    str r0, [r1, #0x10]
    mov r0, #NumPokeballs
    strb r0, [r1, #0x14]    @store limiter
    
TMsPocket:
    ldr r0, =(freeRAM + (4*NumMainPocketItems) + (4*NumKeyItems) + (4*NumPokeballs))
    str r0, [r1, #0x18]
    mov r0, #NumTMs
    strb r0, [r1, #0x1C]    @store 128 into TM pocket limiter
    
BerriesPocket:
    ldr r0, =(freeRAM + (4*NumMainPocketItems) + (4*NumKeyItems) + (4*NumPokeballs) + (4*NumTMs))
    str r0, [r1, #0x20]
    add r1, #0x24
    mov r0, #NumBerries
    strb r0, [r1]
    bx lr
    

.align 2
.MainPocketRAM:    .word freeRAM
