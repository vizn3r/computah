//
// i.MX6 EPIT Register Definitions
// Auto-generated from reference manual
//

#pragma once

// EPIT Base Addresses
#define EPIT1_BASE 0x020D0000
#define EPIT2_BASE 0x020D4000

// EPIT Accessor Macros
#define EPIT1(reg) *(volatile unsigned int*)(EPIT1_BASE + (reg))
#define EPIT2(reg) *(volatile unsigned int*)(EPIT2_BASE + (reg))

// EPIT Register Offsets
#define EPIT_CMPR 0x000C
#define EPIT_CNR 0x0010
#define EPIT_CR 0x0000
#define EPIT_LR 0x0008
#define EPIT_SR 0x0004

