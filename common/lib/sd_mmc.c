#include "sd_mmc.h"
// #define DEBUG_PRINT
#include <debug.h>
#include <delay.h>
#include <reg/ccu.h>
#include <reg/sd_mmc.h>
#include <types.h>

void mmc_update_clk(void) {
  uint32_t cmd = (1 << SD_CMDR_CMD_LOAD) | (1 << SD_CMDR_WAIT_PRE_OVER) |
                 (1 << SD_CMDR_PRG_CLK); // PRG_CLK bit

  SD_MMC0(SD_CMDR) = cmd;

  // wait for command
  while (SD_MMC0(SD_CMDR) & (1 << SD_CMDR_CMD_LOAD))
    ;

  // clear interrupt status
  uint32_t val = SD_MMC0(SD_RISR);
  SD_MMC0(SD_RISR) = val;
}

void mmc_set_clk_400hkz(void) {
  // 24MHz / (2 * 30) = 400kHz
  // N divider = 0 (means divide by 2^0 = 1)
  // M divider = 30 (actual divider is M, so M=30)
  uint32_t val = (1 << SDMMC0_CLK_REG_SCLK_GATING) |
                 (0 << SDMMC0_CLK_REG_CLK_SRC_SEL_LOW) |
                 (0 << SDMMC0_CLK_REG_CLK_DIV_RATIO_N_LOW) |
                 (29 << SDMMC0_CLK_REG_CLK_DIV_RATIO_M_LOW);

  CCU(SDMMC0_CLK_REG) = val;
}

int mmc_send_cmd(uint32_t cmd_idx, uint32_t arg, uint32_t flags) {
  // write argument first
  SD_MMC0(SD_CAGR) = arg;

  // build command value
  uint32_t cmd =
      (1 << SD_CMDR_CMD_LOAD) | (cmd_idx << SD_CMDR_CMD_IDX_LOW) | flags;

  // send command
  SD_MMC0(SD_CMDR) = cmd;

  // wait for command to complete
  while (SD_MMC0(SD_CMDR) & (1 << SD_CMDR_CMD_LOAD))
    ;

  // check for errors
  uint32_t rint = SD_MMC0(SD_RISR);
  SD_MMC0(SD_RISR) = rint;

  // TODO: check error bits in rint

  return 0;
}

int mmc_init_card(void) {
  uint32_t flags = (1 << SD_CMDR_SEND_INIT_SEQ);
  mmc_send_cmd(0, 0, flags);
  dummy_delay(1000);

  flags = (1 << SD_CMDR_RESP_RCV);
  mmc_send_cmd(8, 0x000001AA, flags);

  uint32_t resp = SD_MMC0(SD_RESP0);

  int retries = 1000;
  while (retries--) {
    mmc_send_cmd(55, 0, flags);
    mmc_send_cmd(41, 0x40FF8000, flags);

    resp = SD_MMC0(SD_RESP0);
    if (resp & 0x80000000) {
      break; // Card is ready
    }
    dummy_delay(1000);
  }

  if (retries == 0) {
    return -1;
  }

  // ADD THESE:
  // CMD2: ALL_SEND_CID - get card identification
  flags = (1 << SD_CMDR_RESP_RCV) | (1 << SD_CMDR_LONG_RESP);
  mmc_send_cmd(2, 0, flags);

  // CMD3: SEND_RELATIVE_ADDR - get card address
  flags = (1 << SD_CMDR_RESP_RCV);
  mmc_send_cmd(3, 0, flags);

  uint32_t rca = SD_MMC0(SD_RESP0) & 0xFFFF0000; // Get RCA from response

  // CMD7: SELECT_CARD - put card in transfer state
  mmc_send_cmd(7, rca, flags);

  return 0;
}

int mmc_read_block(uint32_t block_num, void *dest) {
  DPRINT("   [block start]\n");

  SD_MMC0(SD_BKSR) = 512;
  SD_MMC0(SD_BYCR) = 512;

  uint32_t flags = (1 << SD_CMDR_RESP_RCV) | (1 << SD_CMDR_DATA_TRANS) |
                   (1 << SD_CMDR_WAIT_PRE_OVER);

  DPRINT("   [cmd]\n");
  mmc_send_cmd(17, block_num, flags);

  // Check response and status immediately after CMD17
  uint32_t rint = SD_MMC0(SD_RISR);
  // uint32_t resp = SD_MMC0(SD_RESP0);
  // uint32_t status = SD_MMC0(SD_STAR);

  if (rint & 0xBFC2) { // Error bits
    DPRINT("   [cmd error!]\n");
    return -1;
  }

  DPRINT("   [cmd ok]\n");

  DPRINT("   [fifo]\n");
  uint32_t *buf = (uint32_t *)dest;
  for (int i = 0; i < 512 / 4; i++) {
    while (SD_MMC0(SD_STAR) & (1 << SD_STAR_FIFO_EMPTY))
      ;
    buf[i] = SD_MMC0(SD_FIFO);
  }

  DPRINT("   [wait]\n");
  while (!(SD_MMC0(SD_RISR) & (1 << 3)))
    ;

  SD_MMC0(SD_RISR) = 0xFFFFFFFF;
  DPRINT("   [done]\n");
  return 0;
}

void mmc_read_blocks(uint32_t start_block, void *dest, uint32_t num_blocks) {
  uint8_t *ptr = (uint8_t *)dest;
  for (uint32_t i = 0; i < num_blocks; i++) {
    mmc_read_block(start_block + i, ptr);
    ptr += 512;
  }
}

int init_mmc(void) {
  // reset
  SD_MMC0(SD_GCTL) = SD_GCTL_RESET;
  dummy_delay(10000);

  SD_MMC0(SD_GCTL) |= (1 << SD_GCTL_FIFO_AC_MOD);

  // clk setup
  // disable clk
  unsigned int rval = SD_MMC0(SD_CKCR);
  rval &= ~(1 << SD_CKCR_CCLK_ENB);
  SD_MMC0(SD_CKCR) = rval;
  mmc_update_clk();

  mmc_set_clk_400hkz();

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
