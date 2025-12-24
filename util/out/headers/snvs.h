//
// i.MX6 SNVS Register Definitions
// Auto-generated from reference manual
//

#pragma once

// SNVS Base Addresses
#define SNVS_BASE 0x020CC000

// SNVS Accessor Macros
#define SNVS(reg) *(volatile unsigned int*)(SNVS_BASE + (reg))

// SNVS Register Offsets
#define SNVS_HPCOMR 0x0004
#define SNVS_HPCR 0x0008
#define SNVS_HPLR 0x0000
#define SNVS_HPRTCLR 0x0028
#define SNVS_HPRTCMR 0x0024
#define SNVS_HPSR 0x0014
#define SNVS_HPTALR 0x0030
#define SNVS_HPTAMR 0x002C
#define SNVS_HPVIDR1 0x0BF8
#define SNVS_HPVIDR2 0x0BFC
#define SNVS_LPCR 0x0038
#define SNVS_LPGPR 0x0068
#define SNVS_LPLR 0x0034
#define SNVS_LPSMCLR 0x0060
#define SNVS_LPSMCMR 0x005C
#define SNVS_LPSR 0x004C

// SNVS_HPCR
#define SNVS_HPCR_R 19
#define SNVS_HPCR_R 18
#define SNVS_HPCR_R 17
#define SNVS_HPCR_R 16
#define SNVS_HPCR_R 3
#define SNVS_HPCR_R 2
#define SNVS_HPCR_R 1
#define SNVS_HPCR_R 0

// SNVS_HPLR
#define SNVS_HPLR_GPR_SL 6
#define SNVS_HPLR_GPR_SL 5

// SNVS_HPTALR
#define SNVS_HPTALR_R 19
#define SNVS_HPTALR_R 18
#define SNVS_HPTALR_R 17
#define SNVS_HPTALR_R 16
#define SNVS_HPTALR_R 3
#define SNVS_HPTALR_R 2
#define SNVS_HPTALR_R 1
#define SNVS_HPTALR_R 0

// SNVS_HPTAMR
#define SNVS_HPTAMR_HPTA_HIGH 31
#define SNVS_HPTAMR_HPTA_LOW 15
#define SNVS_HPTAMR_R 3
#define SNVS_HPTAMR_R 2
#define SNVS_HPTAMR_R 1
#define SNVS_HPTAMR_R 0

// SNVS_LPCR
#define SNVS_LPCR_PK_OVERRIDE_HIGH 31
#define SNVS_LPCR_PK_OVERRIDE_LOW 24
#define SNVS_LPCR_PK_OVERRIDE 23
#define SNVS_LPCR_PK_EN 22
#define SNVS_LPCR_ON_TIME_HIGH 21
#define SNVS_LPCR_ON_TIME_LOW 20

// SNVS_LPGPR
#define SNVS_LPGPR_R 3
#define SNVS_LPGPR_R 2
#define SNVS_LPGPR_R 1
#define SNVS_LPGPR_R 0

