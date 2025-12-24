//
// i.MX6 PGC Register Definitions
// Auto-generated from reference manual
//

#pragma once

// PGC Base Addresses
#define PGC_BASE 0x020DC260

// PGC Accessor Macros
#define PGC(reg) *(volatile unsigned int*)(PGC_BASE + (reg))

// PGC Register Offsets
#define PGC_CPU_CTRL 0x0040
#define PGC_CPU_PDNSCR 0x0048
#define PGC_CPU_PUPSCR 0x0044
#define PGC_CPU_SR 0x004C
#define PGC_GPU_CTRL 0x0000
#define PGC_GPU_PDNSCR 0x0008
#define PGC_GPU_PUPSCR 0x0004
#define PGC_GPU_SR 0x000C

// PGC_CPU_CTRL
#define PGC_CPU_CTRL_PSR_HIGH 31
#define PGC_CPU_CTRL_PSR_LOW 1
#define PGC_CPU_CTRL_R 19
#define PGC_CPU_CTRL_R 18
#define PGC_CPU_CTRL_R 17
#define PGC_CPU_CTRL_R 16
#define PGC_CPU_CTRL_R 3
#define PGC_CPU_CTRL_R 2
#define PGC_CPU_CTRL_R 1
#define PGC_CPU_CTRL_PSR 0

