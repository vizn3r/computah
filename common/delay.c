#include "delay.h"
#include "types.h"

void dummy_delay(uint64_t cycles) {
  for (uint64_t i = 0; i < cycles; i++)
    ;
}
