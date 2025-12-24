//
// i.MX6 AIPSTZ Register Definitions
// Auto-generated from reference manual
//

#pragma once

// AIPSTZ Base Addresses
#define AIPSTZ1_BASE 0x0207C000
#define AIPSTZ2_BASE 0x0217C000

// AIPSTZ Accessor Macros
#define AIPSTZ1(reg) *(volatile unsigned int*)(AIPSTZ1_BASE + (reg))
#define AIPSTZ2(reg) *(volatile unsigned int*)(AIPSTZ2_BASE + (reg))

// AIPSTZ Register Offsets
#define AIPSTZ_MPR 0x0000
#define AIPSTZ_OPACR 0x0040
#define AIPSTZ_OPACR1 0x0044
#define AIPSTZ_OPACR2 0x0048
#define AIPSTZ_OPACR3 0x004C
#define AIPSTZ_OPACR4 0x0050

