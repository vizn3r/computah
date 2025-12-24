//
// i.MX6 SATA Register Definitions
// Auto-generated from reference manual
//

#pragma once

// SATA Base Addresses
#define SATA_BASE 0x02200000

// SATA Accessor Macros
#define SATA(reg) *(volatile unsigned int*)(SATA_BASE + (reg))

// SATA Register Offsets
#define SATA_BISTAFR 0x00A0
#define SATA_BISTCR 0x00A4
#define SATA_BISTFCTR 0x00A8
#define SATA_BISTSR 0x00AC
#define SATA_CAP 0x0000
#define SATA_CAP2 0x0024
#define SATA_CCC_CTL 0x0014
#define SATA_CCC_PORTS 0x0018
#define SATA_GHC 0x0004
#define SATA_GPCR 0x00D0
#define SATA_GPSR 0x00D4
#define SATA_IS 0x0008
#define SATA_OOBR 0x00BC
#define SATA_P0CI 0x0138
#define SATA_P0CLB 0x0100
#define SATA_P0CMD 0x0118
#define SATA_P0DMACR 0x0170
#define SATA_P0FB 0x0108
#define SATA_P0IE 0x0114
#define SATA_P0IS 0x0110
#define SATA_P0PHYCR 0x0178
#define SATA_P0PHYSR 0x017C
#define SATA_P0SACT 0x0134
#define SATA_P0SCTL 0x012C
#define SATA_P0SERR 0x0130
#define SATA_P0SIG 0x0124
#define SATA_P0SNTF 0x013C
#define SATA_P0SSTS 0x0128
#define SATA_P0TFD 0x0120
#define SATA_PI 0x000C
#define SATA_TESTR 0x00F4
#define SATA_TIMER1MS 0x00E0
#define SATA_VERSIONR 0x00F8
#define SATA_VS 0x0010

