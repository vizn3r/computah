//
// i.MX6 ECSPI Register Definitions
// Auto-generated from reference manual
//

#pragma once

// ECSPI Base Addresses
#define ECSPI1_BASE 0x02008000
#define ECSPI2_BASE 0x0200C000
#define ECSPI3_BASE 0x02010000
#define ECSPI4_BASE 0x02014000
#define ECSPI5_BASE 0x02018000

// ECSPI Accessor Macros
#define ECSPI1(reg) *(volatile unsigned int*)(ECSPI1_BASE + (reg))
#define ECSPI2(reg) *(volatile unsigned int*)(ECSPI2_BASE + (reg))
#define ECSPI3(reg) *(volatile unsigned int*)(ECSPI3_BASE + (reg))
#define ECSPI4(reg) *(volatile unsigned int*)(ECSPI4_BASE + (reg))
#define ECSPI5(reg) *(volatile unsigned int*)(ECSPI5_BASE + (reg))

// ECSPI Register Offsets
#define ECSPI_CONFIGREG 0x000C
#define ECSPI_CONREG 0x0008
#define ECSPI_DMAREG 0x0014
#define ECSPI_INTREG 0x0010
#define ECSPI_MSGDATA 0x0040
#define ECSPI_PERIODREG 0x001C
#define ECSPI_RXDATA 0x0000
#define ECSPI_STATREG 0x0018
#define ECSPI_TESTREG 0x0020
#define ECSPI_TXDATA 0x0004

// ECSPI_STATREG
#define ECSPI_STATREG_TC 7
#define ECSPI_STATREG_RO 6
#define ECSPI_STATREG_RF 5
#define ECSPI_STATREG_RDR 4
#define ECSPI_STATREG_RR 3
#define ECSPI_STATREG_TF 2
#define ECSPI_STATREG_RO 1

