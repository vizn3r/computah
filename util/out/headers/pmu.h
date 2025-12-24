//
// i.MX6 PMU Register Definitions
// Auto-generated from reference manual
//

#pragma once

// PMU Base Addresses
#define PMU_BASE 0x020C8110

// PMU Accessor Macros
#define PMU(reg) *(volatile unsigned int*)(PMU_BASE + (reg))

// PMU Register Offsets
#define PMU_MISC0 0x0040
#define PMU_MISC1 0x0050
#define PMU_MISC1_CLR 0x0058
#define PMU_MISC1_SET 0x0054
#define PMU_MISC1_TOG 0x005C
#define PMU_MISC2 0x0060
#define PMU_MISC2_CLR 0x0068
#define PMU_MISC2_SET 0x0064
#define PMU_MISC2_TOG 0x006C
#define PMU_REG_1P1 0x0000
#define PMU_REG_2P5 0x0020
#define PMU_REG_3P0 0x0010
#define PMU_REG_CORE 0x0030

