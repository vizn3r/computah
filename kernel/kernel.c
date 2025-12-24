#include "kernel.h"

void _start(void) { kernel_main(); }

void kernel_main(void) {
  volatile unsigned int *uart = (unsigned int *)0x02020040;
  const char *msg = "Hello fucking world!";

  while (*msg) {
    *uart = *msg;
    ++msg;
  }
}
