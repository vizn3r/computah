//
// i.MX6 KPP Register Definitions
// Auto-generated from reference manual
//

#pragma once

// KPP Base Addresses
#define KPP_BASE 0x020B8000

// KPP Accessor Macros
#define KPP(reg) *(volatile unsigned int*)(KPP_BASE + (reg))

// KPP Register Offsets
#define KPP_KDDR 0x0004
#define KPP_KPCR 0x0000
#define KPP_KPDR 0x0006
#define KPP_KPSR 0x0002

