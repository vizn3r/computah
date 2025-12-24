//
// i.MX6 WDOG Register Definitions
// Auto-generated from reference manual
//

#pragma once

// WDOG Base Addresses
#define WDOG1_BASE 0x020BC000
#define WDOG2_BASE 0x020C0000

// WDOG Accessor Macros
#define WDOG1(reg) *(volatile unsigned int*)(WDOG1_BASE + (reg))
#define WDOG2(reg) *(volatile unsigned int*)(WDOG2_BASE + (reg))

// WDOG Register Offsets
#define WDOG_WCR 0x0000
#define WDOG_WICR 0x0006
#define WDOG_WMCR 0x0008
#define WDOG_WRSR 0x0004
#define WDOG_WSR 0x0002

