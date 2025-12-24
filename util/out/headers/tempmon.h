//
// i.MX6 TEMPMON Register Definitions
// Auto-generated from reference manual
//

#pragma once

// TEMPMON Base Addresses
#define TEMPMON_BASE 0x020C8180

// TEMPMON Accessor Macros
#define TEMPMON(reg) *(volatile unsigned int*)(TEMPMON_BASE + (reg))

// TEMPMON Register Offsets
#define TEMPMON_TEMPSENSE0 0x0000
#define TEMPMON_TEMPSENSE0_CLR 0x0008
#define TEMPMON_TEMPSENSE0_SET 0x0004
#define TEMPMON_TEMPSENSE0_TOG 0x000C
#define TEMPMON_TEMPSENSE1 0x0010
#define TEMPMON_TEMPSENSE1_CLR 0x0018
#define TEMPMON_TEMPSENSE1_SET 0x0014
#define TEMPMON_TEMPSENSE1_TOG 0x001C

