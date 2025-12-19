#include "kernel.h"
#include "lib/uart.h"
#include <stdint.h>

void _start() {
  uart_print(" >> Entering kernel\n");
  kernel_main();
}

void kernel_main(void) {
  // sex
  uart_print("Hello from kernel!\n");
}
