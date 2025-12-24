//
// i.MX6 PCIE Register Definitions
// Auto-generated from reference manual
//

#pragma once

// PCIE Base Addresses
#define PCIE_BASE 0x00000000

// PCIE Accessor Macros
#define PCIE(reg) *(volatile unsigned int*)(PCIE_BASE + (reg))

// PCIE Register Offsets
#define PCIE_PHY_DEBUG 0x0002
#define PCIE_PHY_IDCODE_HI 0x0001
#define PCIE_PHY_IDCODE_LO 0x0000
#define PCIE_PHY_RTUNE_DEBUG 0x0003

