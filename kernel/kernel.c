#include "kernel.h"
#include "lib/uart.h"
#include <stdint.h>

void _start() { kernel_main(); }

void kernel_main(void) { uart_print("Hello from kernel!"); }
