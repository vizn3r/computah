#include <lib/sd_mmc.h>
#include <lib/uart.h>

void loader(void) {
  uart_print("Loading kernel:\n");
  // do other shit
  uart_print(" >> Init SD card\n");

  init_mmc();
  if (mmc_init_card() == -1) {
    uart_print(" !!>> Couldn't initialize SD card\n");
  }

  uart_print(" << SD card initialized\n");
  uart_print(" >> Reading kernel\n");

  mmc_read_blocks(1024, (void *)0x40000000, 100);
  uart_print(" >> Jumping to kernel\n");

  void (*kernel_main)(void) = (void (*)(void))0x4000000;
  kernel_main();
}
