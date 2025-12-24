//
// i.MX6 SPDIF Register Definitions
// Auto-generated from reference manual
//

#pragma once

// SPDIF Base Addresses
#define SPDIF_BASE 0x02004000

// SPDIF Accessor Macros
#define SPDIF(reg) *(volatile unsigned int*)(SPDIF_BASE + (reg))

// SPDIF Register Offsets
#define SPDIF_SCR 0x0000
#define SPDIF_SIC 0x0010
#define SPDIF_SIE 0x000C
#define SPDIF_SIS 0x0010
#define SPDIF_SRCD 0x0004
#define SPDIF_SRCSH 0x001C
#define SPDIF_SRCSL 0x0020
#define SPDIF_SRFM 0x0044
#define SPDIF_SRL 0x0014
#define SPDIF_SRPC 0x0008
#define SPDIF_SRQ 0x0028
#define SPDIF_SRR 0x0018
#define SPDIF_SRU 0x0024
#define SPDIF_STC 0x0050
#define SPDIF_STCSCH 0x0034
#define SPDIF_STCSCL 0x0038
#define SPDIF_STL 0x002C
#define SPDIF_STR 0x0030

// SPDIF_SRCSL
#define SPDIF_SRCSL_R 3
#define SPDIF_SRCSL_R 2
#define SPDIF_SRCSL_R 1
#define SPDIF_SRCSL_R 0

// SPDIF_SRL
#define SPDIF_SRL_R 3
#define SPDIF_SRL_R 2
#define SPDIF_SRL_R 1
#define SPDIF_SRL_R 0

// SPDIF_SRR
#define SPDIF_SRR_R 3
#define SPDIF_SRR_R 2
#define SPDIF_SRR_R 1
#define SPDIF_SRR_R 0

// SPDIF_STC
#define SPDIF_STC_SYSCLK_DF_HIGH 23
#define SPDIF_STC_SYSCLK_DF_LOW 20
#define SPDIF_STC_SYSCLK_DF_HIGH 19
#define SPDIF_STC_SYSCLK_DF_LOW 11

// SPDIF_STCSCL
#define SPDIF_STCSCL_R 3
#define SPDIF_STCSCL_R 2
#define SPDIF_STCSCL_R 1
#define SPDIF_STCSCL_R 0

// SPDIF_STL
#define SPDIF_STL_R 3
#define SPDIF_STL_R 2
#define SPDIF_STL_R 1
#define SPDIF_STL_R 0

// SPDIF_STR
#define SPDIF_STR_R 3
#define SPDIF_STR_R 2
#define SPDIF_STR_R 1
#define SPDIF_STR_R 0

