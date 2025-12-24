//
// i.MX6 DCIC Register Definitions
// Auto-generated from reference manual
//

#pragma once

// DCIC Base Addresses
#define DCIC1_BASE 0x020E4000
#define DCIC2_BASE 0x020E8000

// DCIC Accessor Macros
#define DCIC1(reg) *(volatile unsigned int*)(DCIC1_BASE + (reg))
#define DCIC2(reg) *(volatile unsigned int*)(DCIC2_BASE + (reg))

// DCIC Register Offsets
#define DCIC_DCICC 0x0000
#define DCIC_DCICIC 0x0004
#define DCIC_DCICRC 0x0010
#define DCIC_DCICRCS 0x001C
#define DCIC_DCICRRS 0x0018
#define DCIC_DCICRS 0x0014
#define DCIC_DCICS 0x0008

// DCIC_DCICC
#define DCIC_DCICC_CLK_POL_HIGH 31
#define DCIC_DCICC_CLK_POL_LOW 8
#define DCIC_DCICC_CLK_POL 7
#define DCIC_DCICC_VSYNC_POL 6
#define DCIC_DCICC_VSYNC_POL 1

// DCIC_DCICIC
#define DCIC_DCICIC_EXT_SIG_EN_HIGH 31
#define DCIC_DCICIC_EXT_SIG_EN_LOW 17
#define DCIC_DCICIC_R 19
#define DCIC_DCICIC_R 18
#define DCIC_DCICIC_R 17
#define DCIC_DCICIC_R 16
#define DCIC_DCICIC_HSYNC_POL 5
#define DCIC_DCICIC_DE_POL 4
#define DCIC_DCICIC_IC_EN_HIGH 3
#define DCIC_DCICIC_IC_EN_LOW 1
#define DCIC_DCICIC_R 3
#define DCIC_DCICIC_R 2
#define DCIC_DCICIC_HSYNC_POL 1
#define DCIC_DCICIC_IC_EN 0

// DCIC_DCICS
#define DCIC_DCICS_R 19
#define DCIC_DCICS_R 18
#define DCIC_DCICS_R 17
#define DCIC_DCICS_R 16
#define DCIC_DCICS_FREEZE_MASK_HIGH 15
#define DCIC_DCICS_FREEZE_MASK_LOW 4
#define DCIC_DCICS_FREEZE_MASK 3
#define DCIC_DCICS_FI_MASK 2
#define DCIC_DCICS_FI_MASK 1
#define DCIC_DCICS_EI_MASK 0

