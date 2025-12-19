.global _start
_start:
  ldr sp, =0x42000000
  ldr r0, =0x01C28000
  ldr r1, =msg

loop:
  ldrb r2, [r1], #1
  cmp r2, #0
  beq hang
  strb r2, [r0]
  b loop

hang:
  b loader

msg:
  .asciz "Boot started:\n"

