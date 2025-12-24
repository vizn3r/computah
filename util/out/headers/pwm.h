//
// i.MX6 PWM Register Definitions
// Auto-generated from reference manual
//

#pragma once

// PWM Base Addresses
#define PWM1_BASE 0x02080000
#define PWM2_BASE 0x02084000
#define PWM3_BASE 0x02088000
#define PWM4_BASE 0x0208C000

// PWM Accessor Macros
#define PWM1(reg) *(volatile unsigned int*)(PWM1_BASE + (reg))
#define PWM2(reg) *(volatile unsigned int*)(PWM2_BASE + (reg))
#define PWM3(reg) *(volatile unsigned int*)(PWM3_BASE + (reg))
#define PWM4(reg) *(volatile unsigned int*)(PWM4_BASE + (reg))

// PWM Register Offsets
#define PWM_PWMCNR 0x0014
#define PWM_PWMCR 0x0000
#define PWM_PWMIR 0x0008
#define PWM_PWMPR 0x0010
#define PWM_PWMSAR 0x000C
#define PWM_PWMSR 0x0004

// PWM_PWMCNR
#define PWM_PWMCNR_COUNT_HIGH 31
#define PWM_PWMCNR_COUNT_LOW 16

// PWM_PWMCR
#define PWM_PWMCR_FWM_HIGH 27
#define PWM_PWMCR_FWM_LOW 26
#define PWM_PWMCR_STOPEN 25
#define PWM_PWMCR_DOZEN 24
#define PWM_PWMCR_WAITEN 23
#define PWM_PWMCR_STOPEN 11
#define PWM_PWMCR_DOZEN 1

// PWM_PWMIR
#define PWM_PWMIR_R 19
#define PWM_PWMIR_R 18
#define PWM_PWMIR_R 17
#define PWM_PWMIR_R 16
#define PWM_PWMIR_ROV 4
#define PWM_PWMIR_FE 3
#define PWM_PWMIR_R 2
#define PWM_PWMIR_FE 1
#define PWM_PWMIR_FIFOAV 0

// PWM_PWMPR
#define PWM_PWMPR_PERIOD_HIGH 31
#define PWM_PWMPR_PERIOD_LOW 16

// PWM_PWMSAR
#define PWM_PWMSAR_SAMPLE_HIGH 31
#define PWM_PWMSAR_SAMPLE_LOW 16
#define PWM_PWMSAR_R 3
#define PWM_PWMSAR_R 2
#define PWM_PWMSAR_RIE 1
#define PWM_PWMSAR_FIE 0

// PWM_PWMSR
#define PWM_PWMSR_R 19
#define PWM_PWMSR_R 18
#define PWM_PWMSR_R 17
#define PWM_PWMSR_R 16
#define PWM_PWMSR_FWE 6
#define PWM_PWMSR_CMP 5
#define PWM_PWMSR_R 3
#define PWM_PWMSR_R 2
#define PWM_PWMSR_R 1
#define PWM_PWMSR_EN 0

