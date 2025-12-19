#pragma once

#include <lib/uart.h>

#ifdef DEBUG_PRINT
#define DPRINT(msg)                                                            \
  uart_print("DEBUG: ");                                                       \
  uart_print((const char *)(msg));
#else
#define DPRINT(msg) (void)0
#endif
