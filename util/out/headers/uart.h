//
// i.MX6 UART Register Definitions
// Auto-generated from reference manual
//

#pragma once

// UART Base Addresses
#define UART1_BASE 0x02020000
#define UART2_BASE 0x021E8000
#define UART3_BASE 0x021EC000
#define UART4_BASE 0x021F0000
#define UART5_BASE 0x021F4000

// UART Accessor Macros
#define UART1(reg) *(volatile unsigned int *)(UART1_BASE + (reg))
#define UART2(reg) *(volatile unsigned int *)(UART2_BASE + (reg))
#define UART3(reg) *(volatile unsigned int *)(UART3_BASE + (reg))
#define UART4(reg) *(volatile unsigned int *)(UART4_BASE + (reg))
#define UART5(reg) *(volatile unsigned int *)(UART5_BASE + (reg))

// UART Register Offsets
#define UART_ONEMS 0x00B0
#define UART_UBIR 0x00A4
#define UART_UBMR 0x00A8
#define UART_UBRC 0x00AC
#define UART_UCR1 0x0080
#define UART_UCR2 0x0084
#define UART_UCR3 0x0088
#define UART_UCR4 0x008C
#define UART_UESC 0x009C
#define UART_UFCR 0x0090
#define UART_UMCR 0x00B8
#define UART_URXD 0x0000
#define UART_USR1 0x0094
#define UART_USR2 0x0098
#define UART_UTIM 0x00A0
#define UART_UTS 0x00B4
#define UART_UTXD 0x0040

// UART_ONEMS
#define UART_ONEMS_ONEMS_HIGH 31
#define UART_ONEMS_ONEMS_LOW 24

// UART_UBMR
#define UART_UBMR_MOD_HIGH 31
#define UART_UBMR_MOD_LOW 16

// UART_UESC
#define UART_UESC_RTSF 4
#define UART_UESC_TXDC 3
#define UART_UESC_BRCD 2
#define UART_UESC_RTSF 1
#define UART_UESC_RDR 0

// UART_UFCR
#define UART_UFCR_TRDY 13
#define UART_UFCR_RTSD 12
#define UART_UFCR_ESCF 11
#define UART_UFCR_FRAMERR 10
#define UART_UFCR_RRDY 9
#define UART_UFCR_AGTIM 8
#define UART_UFCR_DTRD 7
#define UART_UFCR_RXDS 6
#define UART_UFCR_TRDY 1

// UART_UMCR
#define UART_UMCR_TXEMPTY_HIGH 8
#define UART_UMCR_TXEMPTY_LOW 7
#define UART_UMCR_TXEMPTY 6
#define UART_UMCR_RXEMPTY 5
#define UART_UMCR_TXFULL 4
#define UART_UMCR_RXFULL 3
#define UART_UMCR_SOFTRST_HIGH 2
#define UART_UMCR_SOFTRST_LOW 1
#define UART_UMCR_RXEMPTY 1
#define UART_UMCR_SOFTRST 0

// UART_URXD
#define UART_URXD_CHARRDY_HIGH 31
#define UART_URXD_CHARRDY_LOW 16
#define UART_URXD_CHARRDY 15

// UART_UTIM
#define UART_UTIM_TIM_HIGH 31
#define UART_UTIM_TIM_LOW 12

// UART_UTS
#define UART_UTS_FRCPERR_HIGH 31
#define UART_UTS_FRCPERR_LOW 14
#define UART_UTS_FRCPERR 13
#define UART_UTS_LOOP 12
#define UART_UTS_DBGEN 11
#define UART_UTS_LOOPIR 10
#define UART_UTS_RXDBG 9
#define UART_UTS_LOOP 1

// UART_UTXD
#define UART_UTXD_TX_DATA_HIGH 15
#define UART_UTXD_TX_DATA_LOW 8
