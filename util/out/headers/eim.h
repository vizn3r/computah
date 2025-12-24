//
// i.MX6 EIM Register Definitions
// Auto-generated from reference manual
//

#pragma once

// EIM Base Addresses
#define EIM_BASE 0x021B8000

// EIM Accessor Macros
#define EIM(reg) *(volatile unsigned int*)(EIM_BASE + (reg))

// EIM Register Offsets
#define EIM_CS0GCR1 0x0000
#define EIM_CS0GCR2 0x0004
#define EIM_CS0RCR1 0x0008
#define EIM_CS0RCR2 0x000C
#define EIM_CS0WCR1 0x0010
#define EIM_CS0WCR2 0x0014
#define EIM_CS1GCR1 0x0018
#define EIM_CS1GCR2 0x001C
#define EIM_CS1RCR1 0x0020
#define EIM_CS1RCR2 0x0024
#define EIM_CS1WCR1 0x0028
#define EIM_CS1WCR2 0x002C
#define EIM_CS2GCR1 0x0030
#define EIM_CS2GCR2 0x0034
#define EIM_CS2RCR1 0x0038
#define EIM_CS2RCR2 0x003C
#define EIM_CS2WCR1 0x0040
#define EIM_CS2WCR2 0x0044
#define EIM_CS3GCR1 0x0048
#define EIM_CS3GCR2 0x004C
#define EIM_CS3RCR1 0x0050
#define EIM_CS3RCR2 0x0054
#define EIM_CS3WCR1 0x0058
#define EIM_CS3WCR2 0x005C
#define EIM_EAR 0x0098
#define EIM_WCR 0x0090
#define EIM_WIAR 0x0094

// EIM_WCR
#define EIM_WCR_WDOG_LIMIT_HIGH 31
#define EIM_WCR_WDOG_LIMIT_LOW 11
#define EIM_WCR_WDOG_EN 11
#define EIM_WCR_WDOG_LIMIT_HIGH 10
#define EIM_WCR_WDOG_LIMIT_LOW 9
#define EIM_WCR_WDOG_EN 8
#define EIM_WCR_INTPOL_HIGH 7
#define EIM_WCR_INTPOL_LOW 6
#define EIM_WCR_INTPOL 5
#define EIM_WCR_INTEN 4
#define EIM_WCR_INTEN 1

// EIM_WIAR
#define EIM_WIAR_R 19
#define EIM_WIAR_R 18
#define EIM_WIAR_R 17
#define EIM_WIAR_R 16
#define EIM_WIAR_BCM 11
#define EIM_WIAR_GBCD 3
#define EIM_WIAR_GBCD_HIGH 2
#define EIM_WIAR_GBCD_LOW 1
#define EIM_WIAR_R 2
#define EIM_WIAR_R 1
#define EIM_WIAR_BCM 0

