//
// i.MX6 MLB Register Definitions
// Auto-generated from reference manual
//

#pragma once

// MLB Base Addresses
#define MLB_BASE 0x0218C000

// MLB Accessor Macros
#define MLB(reg) *(volatile unsigned int*)(MLB_BASE + (reg))

// MLB Register Offsets
#define MLB_ACMR0 0x03D8
#define MLB_ACMR1 0x03DC
#define MLB_ACSR0 0x03D0
#define MLB_ACSR1 0x03D4
#define MLB_ACTL 0x03C0
#define MLB_HCBR0 0x0098
#define MLB_HCBR1 0x009C
#define MLB_HCER0 0x0090
#define MLB_HCER1 0x0094
#define MLB_HCMR0 0x0088
#define MLB_HCMR1 0x008C
#define MLB_HCTL 0x0080
#define MLB_MADR 0x00E4
#define MLB_MCTL 0x00E0
#define MLB_MDAT0 0x00C0
#define MLB_MDAT1 0x00C4
#define MLB_MDAT2 0x00C8
#define MLB_MDAT3 0x00CC
#define MLB_MDWE0 0x00D0
#define MLB_MDWE1 0x00D4
#define MLB_MDWE2 0x00D8
#define MLB_MDWE3 0x00DC
#define MLB_MIEN 0x002C
#define MLB_MLBC0 0x0000
#define MLB_MLBC1 0x003C
#define MLB_MLBPC2 0x000D
#define MLB_MS0 0x000C
#define MLB_MS1 0x0014
#define MLB_MSD 0x0024
#define MLB_MSS 0x0020

