#include "sd_mmc.h"
#include <reg/sd_mmc.h>
#include <types.h>

void mmc_update_clk(void) {
  uint32_t cmd = (1 << SD_CMDR_CMD_LOAD) | (1 << SD_CMDR_WAIT_PRE_OVER) |
                 (1 << 21); // PRG_CLK bit

  SD_MMC0(SD_CMDR) = cmd;

  // wait for command
  while (SD_MMC0(SD_CMDR) & (1 << SD_CMDR_CMD_LOAD))
    ;

  // clear interrupt status
  uint32_t val = SD_MMC0(SD_RISR);
  SD_MMC0(SD_RISR) = val;
}

int init_mmc(void) {
  // reset
  SD_MMC0(SD_GCTL) = SD_GCTL_RESET;

  // clk setup
  // disable clk
  unsigned int rval = SD_MMC0(SD_CKCR);
  rval &= ~(1 << SD_CKCR_CCLK_ENB);
  SD_MMC0(SD_CKCR) = rval;
  mmc_update_clk();

  // TODO: configure CCU for clock source (24MHz or 400kHz)

  // clear internal divider
  rval = SD_MMC0(SD_CKCR);
  rval &= ~((0xFF << SD_CKCR_CCLK_DIV_LOW)); // clear bits 7:0
  SD_MMC0(SD_CKCR) = rval;

  // re-enable clock
  rval |= (1 << SD_CKCR_CCLK_ENB);
  SD_MMC0(SD_CKCR) = rval;
  mmc_update_clk();

  // set 1-bit bus width
  SD_MMC0(SD_BWDR) = 0; // 0 = 1-bit

  return 0;
}
