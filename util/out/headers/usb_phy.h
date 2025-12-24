//
// i.MX6 USBPHY Register Definitions
// Auto-generated from reference manual
//

#pragma once

// USBPHY Base Addresses
#define USBPHY1_BASE 0x020C9000
#define USBPHY2_BASE 0x020CA000

// USBPHY Accessor Macros
#define USBPHY1(reg) *(volatile unsigned int*)(USBPHY1_BASE + (reg))
#define USBPHY2(reg) *(volatile unsigned int*)(USBPHY2_BASE + (reg))

// USBPHY Register Offsets
#define USBPHY_CTRL 0x0030
#define USBPHY_CTRL_CLR 0x0038
#define USBPHY_CTRL_SET 0x0034
#define USBPHY_CTRL_TOG 0x003C
#define USBPHY_DEBUG 0x0050
#define USBPHY_DEBUG0_STATUS 0x0060
#define USBPHY_DEBUG1 0x0070
#define USBPHY_DEBUG1_CLR 0x0078
#define USBPHY_DEBUG1_SET 0x0074
#define USBPHY_DEBUG1_TOG 0x007C
#define USBPHY_DEBUG_CLR 0x0058
#define USBPHY_DEBUG_SET 0x0054
#define USBPHY_DEBUG_TOG 0x005C
#define USBPHY_PWD 0x0000
#define USBPHY_PWD_CLR 0x0008
#define USBPHY_PWD_SET 0x0004
#define USBPHY_PWD_TOG 0x000C
#define USBPHY_RX 0x0020
#define USBPHY_RX_CLR 0x0028
#define USBPHY_RX_SET 0x0024
#define USBPHY_RX_TOG 0x002C
#define USBPHY_STATUS 0x0040
#define USBPHY_TX 0x0010
#define USBPHY_TX_CLR 0x0018
#define USBPHY_TX_SET 0x0014
#define USBPHY_TX_TOG 0x001C
#define USBPHY_VERSION 0x0080

