//
// i.MX6 SRC Register Definitions
// Auto-generated from reference manual
//

#pragma once

// SRC Base Addresses
#define SRC_BASE 0x020D8000

// SRC Accessor Macros
#define SRC(reg) *(volatile unsigned int*)(SRC_BASE + (reg))

// SRC Register Offsets
#define SRC_GPR1 0x0020
#define SRC_GPR10 0x0044
#define SRC_GPR2 0x0024
#define SRC_GPR3 0x0028
#define SRC_GPR4 0x002C
#define SRC_GPR5 0x0030
#define SRC_GPR6 0x0034
#define SRC_GPR7 0x0038
#define SRC_GPR8 0x003C
#define SRC_GPR9 0x0040
#define SRC_SBMR1 0x0004
#define SRC_SBMR2 0x001C
#define SRC_SCR 0x0000
#define SRC_SIMR 0x0018
#define SRC_SISR 0x0014
#define SRC_SRSR 0x0008

