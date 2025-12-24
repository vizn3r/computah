//
// i.MX6 GPIO Register Definitions
// Auto-generated from reference manual
//

#pragma once

// GPIO Base Addresses
#define GPIO1_BASE 0x0209C000
#define GPIO2_BASE 0x020A0000
#define GPIO3_BASE 0x020A4000
#define GPIO4_BASE 0x020A8000
#define GPIO5_BASE 0x020AC000
#define GPIO6_BASE 0x020B0000
#define GPIO7_BASE 0x020B4000

// GPIO Accessor Macros
#define GPIO1(reg) *(volatile unsigned int*)(GPIO1_BASE + (reg))
#define GPIO2(reg) *(volatile unsigned int*)(GPIO2_BASE + (reg))
#define GPIO3(reg) *(volatile unsigned int*)(GPIO3_BASE + (reg))
#define GPIO4(reg) *(volatile unsigned int*)(GPIO4_BASE + (reg))
#define GPIO5(reg) *(volatile unsigned int*)(GPIO5_BASE + (reg))
#define GPIO6(reg) *(volatile unsigned int*)(GPIO6_BASE + (reg))
#define GPIO7(reg) *(volatile unsigned int*)(GPIO7_BASE + (reg))

// GPIO Register Offsets
#define GPIO_DR 0x0000
#define GPIO_EDGE_SEL 0x001C
#define GPIO_GDIR 0x0004
#define GPIO_ICR1 0x000C
#define GPIO_ICR2 0x0010
#define GPIO_IMR 0x0014
#define GPIO_ISR 0x0018
#define GPIO_PSR 0x0008

