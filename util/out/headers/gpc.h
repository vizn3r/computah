//
// i.MX6 GPC Register Definitions
// Auto-generated from reference manual
//

#pragma once

// GPC Base Addresses
#define GPC_BASE 0x020DC000

// GPC Accessor Macros
#define GPC(reg) *(volatile unsigned int*)(GPC_BASE + (reg))

// GPC Register Offsets
#define GPC_CNTR 0x0000
#define GPC_IMR1 0x0008
#define GPC_IMR2 0x000C
#define GPC_IMR3 0x0010
#define GPC_IMR4 0x0014
#define GPC_ISR1 0x0018
#define GPC_ISR2 0x001C
#define GPC_ISR3 0x0020
#define GPC_ISR4 0x0024
#define GPC_PGR 0x0004

// GPC_PGR
#define GPC_PGR_DRCIC 31
#define GPC_PGR_DRCIC_HIGH 30
#define GPC_PGR_DRCIC_LOW 29
#define GPC_PGR_R 3
#define GPC_PGR_R 2
#define GPC_PGR_R 1
#define GPC_PGR_R 0

