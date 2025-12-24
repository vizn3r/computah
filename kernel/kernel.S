.global _start

.section .rodata
msg:
  .asciz "Hello fuckking world!\n"

.section .text
_start:
  ldr sp, =0x1a000000
  ldr r0, =0x02020040
  ldr r1, =msg
loop:
  ldrb r2, [r1], #1
  cmp r2, #0
  beq hang
  strb r2, [r0]
  b loop

hang:
  b hang
