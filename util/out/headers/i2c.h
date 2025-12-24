//
// i.MX6 I2C Register Definitions
// Auto-generated from reference manual
//

#pragma once

// I2C Base Addresses
#define I2C1_BASE 0x021A0000
#define I2C2_BASE 0x021A4000
#define I2C3_BASE 0x021A8000

// I2C Accessor Macros
#define I2C1(reg) *(volatile unsigned int*)(I2C1_BASE + (reg))
#define I2C2(reg) *(volatile unsigned int*)(I2C2_BASE + (reg))
#define I2C3(reg) *(volatile unsigned int*)(I2C3_BASE + (reg))

// I2C Register Offsets
#define I2C_I2CR 0x0008
#define I2C_I2DR 0x0010
#define I2C_I2SR 0x000C
#define I2C_IADR 0x0000
#define I2C_IFDR 0x0004

// I2C_I2CR
#define I2C_I2CR_IEN_HIGH 15
#define I2C_I2CR_IEN_LOW 8
#define I2C_I2CR_IEN 7
#define I2C_I2CR_IIEN 6
#define I2C_I2CR_MSTA 5
#define I2C_I2CR_IIEN 1

// I2C_I2DR
#define I2C_I2DR_DATA_HIGH 15
#define I2C_I2DR_DATA_LOW 8
#define I2C_I2DR_DATA 1
#define I2C_I2DR_RXAK 0

// I2C_I2SR
#define I2C_I2SR_MTX 4
#define I2C_I2SR_TXAK 3
#define I2C_I2SR_RSTA 2
#define I2C_I2SR_MTX 1
#define I2C_I2SR_ICF 0

// I2C_IADR
#define I2C_IADR_ADR_HIGH 15
#define I2C_IADR_ADR_LOW 8
#define I2C_IADR_ADR_HIGH 7
#define I2C_IADR_ADR_LOW 1

