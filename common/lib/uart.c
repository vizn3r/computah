#include "uart.h"
#include <stdint.h>

void uart_print(const char *msg) {
  volatile uint32_t *uart = (volatile uint32_t *)0x01C28000;

  while (*msg) {
    *uart = *msg;
    msg++;
  }
}
