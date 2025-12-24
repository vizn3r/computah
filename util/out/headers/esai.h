//
// i.MX6 ESAI Register Definitions
// Auto-generated from reference manual
//

#pragma once

// ESAI Base Addresses
#define ESAI_BASE 0x02024000

// ESAI Accessor Macros
#define ESAI(reg) *(volatile unsigned int*)(ESAI_BASE + (reg))

// ESAI Register Offsets
#define ESAI_ECR 0x0008
#define ESAI_ERDR 0x0004
#define ESAI_ESR 0x000C
#define ESAI_ETDR 0x0000
#define ESAI_PCRC 0x00FC
#define ESAI_PRRC 0x00F8
#define ESAI_RCCR 0x00E0
#define ESAI_RCR 0x00DC
#define ESAI_RFCR 0x0018
#define ESAI_RFSR 0x001C
#define ESAI_RSMA 0x00EC
#define ESAI_RSMB 0x00F0
#define ESAI_RX0 0x00A0
#define ESAI_RX1 0x00A4
#define ESAI_RX2 0x00A8
#define ESAI_RX3 0x00AC
#define ESAI_SAICR 0x00D0
#define ESAI_SAISR 0x00CC
#define ESAI_TCCR 0x00D8
#define ESAI_TCR 0x00D4
#define ESAI_TFCR 0x0010
#define ESAI_TFSR 0x0014
#define ESAI_TSMA 0x00E4
#define ESAI_TSMB 0x00E8
#define ESAI_TSR 0x0098
#define ESAI_TX0 0x0080
#define ESAI_TX1 0x0084
#define ESAI_TX2 0x0088
#define ESAI_TX3 0x008C
#define ESAI_TX4 0x0090
#define ESAI_TX5 0x0094

// ESAI_ERDR
#define ESAI_ERDR_R 19
#define ESAI_ERDR_R 18
#define ESAI_ERDR_R 17
#define ESAI_ERDR_R 16
#define ESAI_ERDR_R 3
#define ESAI_ERDR_R 2
#define ESAI_ERDR_R 1
#define ESAI_ERDR_R 0

// ESAI_ESR
#define ESAI_ESR_ETI 19
#define ESAI_ESR_ETO 18
#define ESAI_ESR_ERI 17
#define ESAI_ESR_ERO 16
#define ESAI_ESR_R 3
#define ESAI_ESR_R 2
#define ESAI_ESR_ETO 1
#define ESAI_ESR_ESAIEN 0

// ESAI_PCRC
#define ESAI_PCRC_R 3
#define ESAI_PCRC_R 2
#define ESAI_PCRC_R 1
#define ESAI_PCRC_R 0

// ESAI_TSR
#define ESAI_TSR_R 3
#define ESAI_TSR_R 2
#define ESAI_TSR_R 1
#define ESAI_TSR_R 0

