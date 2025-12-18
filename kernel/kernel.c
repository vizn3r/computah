#include "kernel.h"
#include "lib/uart.h"
#include <stdint.h>

void _start() { kernel_main(); }

void kernel_main(void) {
  const char *msg = "Kernel start";

  uart_print(msg);
}
