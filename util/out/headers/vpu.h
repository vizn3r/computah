//
// i.MX6 VPU Register Definitions
// Auto-generated from reference manual
//

#pragma once

// VPU Base Addresses
#define VPU_BASE 0x02040000

// VPU Accessor Macros
#define VPU(reg) *(volatile unsigned int*)(VPU_BASE + (reg))

// VPU Register Offsets
#define VPU_BitCodecBusy 0x0020
#define VPU_BitCurPc 0x0018
#define VPU_BitIntClear 0x000C
#define VPU_BitIntSts 0x0010
#define VPU_CodeDown 0x0004
#define VPU_CodeRun 0x0000
#define VPU_HostIntReq 0x0008

