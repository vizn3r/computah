//
// i.MX6 FLEXCAN Register Definitions
// Auto-generated from reference manual
//

#pragma once

// FLEXCAN Base Addresses
#define FLEXCAN1_BASE 0x02090000
#define FLEXCAN2_BASE 0x02094000

// FLEXCAN Accessor Macros
#define FLEXCAN1(reg) *(volatile unsigned int*)(FLEXCAN1_BASE + (reg))
#define FLEXCAN2(reg) *(volatile unsigned int*)(FLEXCAN2_BASE + (reg))

// FLEXCAN Register Offsets
#define FLEXCAN_CRCR 0x0044
#define FLEXCAN_CTRL1 0x0004
#define FLEXCAN_CTRL2 0x0034
#define FLEXCAN_ECR 0x001C
#define FLEXCAN_ESR1 0x0020
#define FLEXCAN_ESR2 0x0038
#define FLEXCAN_GFWR 0x09E0
#define FLEXCAN_IFLAG1 0x0030
#define FLEXCAN_IFLAG2 0x002C
#define FLEXCAN_IMASK1 0x0028
#define FLEXCAN_IMASK2 0x0024
#define FLEXCAN_MCR 0x0000
#define FLEXCAN_RX14MASK 0x0014
#define FLEXCAN_RX15MASK 0x0018
#define FLEXCAN_RXFGMASK 0x0048
#define FLEXCAN_RXFIR 0x004C
#define FLEXCAN_RXIMR0_RXIMR63 0x0880
#define FLEXCAN_RXMGMASK 0x0010
#define FLEXCAN_TIMER 0x0008

