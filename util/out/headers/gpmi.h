//
// i.MX6 GPMI Register Definitions
// Auto-generated from reference manual
//

#pragma once

// GPMI Base Addresses
#define GPMI_BASE 0x00112000

// GPMI Accessor Macros
#define GPMI(reg) *(volatile unsigned int*)(GPMI_BASE + (reg))

// GPMI Register Offsets
#define GPMI_AUXILIARY 0x0050
#define GPMI_COMPARE 0x0010
#define GPMI_CTRL0 0x0000
#define GPMI_CTRL0_CLR 0x0008
#define GPMI_CTRL0_SET 0x0004
#define GPMI_CTRL0_TOG 0x000C
#define GPMI_CTRL1 0x0060
#define GPMI_CTRL1_CLR 0x0068
#define GPMI_CTRL1_SET 0x0064
#define GPMI_CTRL1_TOG 0x006C
#define GPMI_DATA 0x00A0
#define GPMI_DEBUG 0x00C0
#define GPMI_DEBUG2 0x00E0
#define GPMI_DEBUG3 0x00F0
#define GPMI_ECCCOUNT 0x0030
#define GPMI_ECCCTRL 0x0020
#define GPMI_ECCCTRL_CLR 0x0028
#define GPMI_ECCCTRL_SET 0x0024
#define GPMI_ECCCTRL_TOG 0x002C
#define GPMI_PAYLOAD 0x0040
#define GPMI_READ_DDR_DLL_CTRL 0x0100
#define GPMI_READ_DDR_DLL_STS 0x0120
#define GPMI_STAT 0x00B0
#define GPMI_TIMING0 0x0070
#define GPMI_TIMING1 0x0080
#define GPMI_TIMING2 0x0090
#define GPMI_VERSION 0x00D0
#define GPMI_WRITE_DDR_DLL_CTRL 0x0110
#define GPMI_WRITE_DDR_DLL_STS 0x0130

