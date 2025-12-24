//
// i.MX6 SSI Register Definitions
// Auto-generated from reference manual
//

#pragma once

// SSI Base Addresses
#define SSI1_BASE 0x02028000
#define SSI2_BASE 0x0202C000
#define SSI3_BASE 0x02030000

// SSI Accessor Macros
#define SSI1(reg) *(volatile unsigned int*)(SSI1_BASE + (reg))
#define SSI2(reg) *(volatile unsigned int*)(SSI2_BASE + (reg))
#define SSI3(reg) *(volatile unsigned int*)(SSI3_BASE + (reg))

// SSI Register Offsets
#define SSI_SACADD 0x003C
#define SSI_SACCDIS 0x0058
#define SSI_SACCEN 0x0054
#define SSI_SACCST 0x0050
#define SSI_SACDAT 0x0040
#define SSI_SACNT 0x0038
#define SSI_SATAG 0x0044
#define SSI_SCR 0x0010
#define SSI_SFCSR 0x002C
#define SSI_SIER 0x0018
#define SSI_SISR 0x0014
#define SSI_SRCCR 0x0028
#define SSI_SRCR 0x0020
#define SSI_SRMSK 0x004C
#define SSI_SRX0 0x0008
#define SSI_SRX1 0x000C
#define SSI_STCCR 0x0024
#define SSI_STCR 0x001C
#define SSI_STMSK 0x0048
#define SSI_STX0 0x0000
#define SSI_STX1 0x0004

// SSI_SACADD
#define SSI_SACADD_SACADD_HIGH 31
#define SSI_SACADD_SACADD_LOW 19
#define SSI_SACADD_SACDAT_HIGH 31
#define SSI_SACADD_SACDAT_LOW 20
#define SSI_SACADD_R 3
#define SSI_SACADD_R 2
#define SSI_SACADD_AC97EN 1
#define SSI_SACADD_AC97EN 0

// SSI_SACCEN
#define SSI_SACCEN_SACCEN_HIGH 31
#define SSI_SACCEN_SACCEN_LOW 10
#define SSI_SACCEN_R 3
#define SSI_SACCEN_R 2
#define SSI_SACCEN_R 1
#define SSI_SACCEN_R 0

// SSI_SACNT
#define SSI_SACNT_FRDIV_HIGH 31
#define SSI_SACNT_FRDIV_LOW 11
#define SSI_SACNT_FRDIV_HIGH 10
#define SSI_SACNT_FRDIV_LOW 5
#define SSI_SACNT_WR 4
#define SSI_SACNT_RD 3
#define SSI_SACNT_TIF 2
#define SSI_SACNT_RD 1

// SSI_SATAG
#define SSI_SATAG_SATAG_HIGH 31
#define SSI_SATAG_SATAG_LOW 16
#define SSI_SATAG_R 3
#define SSI_SATAG_R 2
#define SSI_SATAG_R 1
#define SSI_SATAG_R 0

// SSI_SCR
#define SSI_SCR_SYNC_TX_FS_HIGH 31
#define SSI_SCR_SYNC_TX_FS_LOW 13
#define SSI_SCR_SYNC_TX_FS 12
#define SSI_SCR_RFR_CLK_DIS 11
#define SSI_SCR_RFR_CLK_DIS 1

// SSI_SFCSR
#define SSI_SFCSR_DIV2_HIGH 31
#define SSI_SFCSR_DIV2_LOW 19
#define SSI_SFCSR_DIV2 18
#define SSI_SFCSR_PSR 17
#define SSI_SFCSR_WL3_WL0_HIGH 16
#define SSI_SFCSR_WL3_WL0_LOW 13
#define SSI_SFCSR_DC4_DC0_HIGH 12
#define SSI_SFCSR_DC4_DC0_LOW 8

// SSI_SIER
#define SSI_SIER_RFRCIE_HIGH 31
#define SSI_SIER_RFRCIE_LOW 25
#define SSI_SIER_RFRCIE 24
#define SSI_SIER_TFRCIE 23
#define SSI_SIER_TFRCIE 1

// SSI_SISR
#define SSI_SISR_RE 2
#define SSI_SISR_TE 1
#define SSI_SISR_SSIEN 0

// SSI_SRCR
#define SSI_SRCR_RXEXT_HIGH 31
#define SSI_SRCR_RXEXT_LOW 11
#define SSI_SRCR_RXEXT 10
#define SSI_SRCR_RXBIT0 9
#define SSI_SRCR_RFEN1 8
#define SSI_SRCR_RXBIT0 1

// SSI_SRMSK
#define SSI_SRMSK_SACCST_HIGH 31
#define SSI_SRMSK_SACCST_LOW 10
#define SSI_SRMSK_R 3
#define SSI_SRMSK_R 2
#define SSI_SRMSK_R 1
#define SSI_SRMSK_R 0

// SSI_STCR
#define SSI_STCR_TXBIT0_HIGH 31
#define SSI_STCR_TXBIT0_LOW 10
#define SSI_STCR_TXBIT0 9
#define SSI_STCR_TFEN1 8
#define SSI_STCR_TFEN1 1

