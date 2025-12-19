#pragma once

#include <types.h>

int init_mmc(void);
int mmc_send_cmd(uint32_t cmd_idx, uint32_t arg, uint32_t flags);
int mmc_init_card(void);

int mmc_read_block(uint32_t block_num, void *dest);
void mmc_read_blocks(uint32_t start_block, void *dest, uint32_t num_blocks);
