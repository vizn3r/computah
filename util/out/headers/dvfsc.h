//
// i.MX6 DVFSC Register Definitions
// Auto-generated from reference manual
//

#pragma once

// DVFSC Base Addresses
#define DVFSC_BASE 0x020DC180

// DVFSC Accessor Macros
#define DVFSC(reg) *(volatile unsigned int*)(DVFSC_BASE + (reg))

// DVFSC Register Offsets
#define DVFSC_CNTR 0x0020
#define DVFSC_COUN 0x0004
#define DVFSC_DVFSEMAC 0x001C
#define DVFSC_DVFSGPBT 0x0018
#define DVFSC_DVFSGPC0 0x0010
#define DVFSC_DVFSGPC1 0x0014
#define DVFSC_DVFSLTR0_0 0x0024
#define DVFSC_DVFSLTR0_1 0x0028
#define DVFSC_DVFSLTR1_0 0x002C
#define DVFSC_DVFSLTR1_1 0x0030
#define DVFSC_DVFSPT0 0x0034
#define DVFSC_DVFSPT1 0x0038
#define DVFSC_DVFSPT2 0x003C
#define DVFSC_DVFSPT3 0x0040
#define DVFSC_DVFSSIG0 0x000C
#define DVFSC_SIG1 0x0008
#define DVFSC_THRS 0x0000

