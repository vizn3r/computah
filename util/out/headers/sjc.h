//
// i.MX6 SJC Register Definitions
// Auto-generated from reference manual
//

#pragma once

// SJC Base Addresses
#define SJC_BASE 0x00000000

// SJC Accessor Macros
#define SJC(reg) *(volatile unsigned int*)(SJC_BASE + (reg))

// SJC Register Offsets
#define SJC_DCR 0x0004
#define SJC_GPCCR 0x0007
#define SJC_GPSSR 0x0003
#define SJC_GPUSR1 0x0000
#define SJC_GPUSR2 0x0001
#define SJC_GPUSR3 0x0002
#define SJC_SSR 0x0005

