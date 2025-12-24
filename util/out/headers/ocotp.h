//
// i.MX6 OCOTP Register Definitions
// Auto-generated from reference manual
//

#pragma once

// OCOTP Base Addresses
#define OCOTP_BASE 0x021BC000

// OCOTP Accessor Macros
#define OCOTP(reg) *(volatile unsigned int*)(OCOTP_BASE + (reg))

// OCOTP Register Offsets
#define OCOTP_ANA0 0x04D0
#define OCOTP_ANA1 0x04E0
#define OCOTP_ANA2 0x04F0
#define OCOTP_CFG0 0x0410
#define OCOTP_CFG1 0x0420
#define OCOTP_CFG2 0x0430
#define OCOTP_CFG3 0x0440
#define OCOTP_CFG4 0x0450
#define OCOTP_CFG5 0x0460
#define OCOTP_CFG6 0x0470
#define OCOTP_CTRL 0x0000
#define OCOTP_CTRL_CLR 0x0008
#define OCOTP_CTRL_SET 0x0004
#define OCOTP_CTRL_TOG 0x000C
#define OCOTP_DATA 0x0020
#define OCOTP_FIELD_RETURN 0x06E0
#define OCOTP_GP1 0x0660
#define OCOTP_GP2 0x0670
#define OCOTP_HSJC_RESP1 0x0610
#define OCOTP_LOCK 0x0400
#define OCOTP_MAC0 0x0620
#define OCOTP_MAC1 0x0630
#define OCOTP_MEM0 0x0480
#define OCOTP_MEM1 0x0490
#define OCOTP_MEM2 0x04A0
#define OCOTP_MEM3 0x04B0
#define OCOTP_MEM4 0x04C0
#define OCOTP_MISC_CONF 0x06D0
#define OCOTP_READ_CTRL 0x0030
#define OCOTP_READ_FUSE_DATA 0x0040
#define OCOTP_RESP0 0x0600
#define OCOTP_SCS 0x0060
#define OCOTP_SCS_CLR 0x0068
#define OCOTP_SCS_SET 0x0064
#define OCOTP_SCS_TOG 0x006C
#define OCOTP_SRK0 0x0580
#define OCOTP_SRK1 0x0590
#define OCOTP_SRK2 0x05A0
#define OCOTP_SRK3 0x05B0
#define OCOTP_SRK4 0x05C0
#define OCOTP_SRK5 0x05D0
#define OCOTP_SRK6 0x05E0
#define OCOTP_SRK7 0x05F0
#define OCOTP_SRK_REVOKE 0x06F0
#define OCOTP_SW_STICKY 0x0050
#define OCOTP_TIMING 0x0010
#define OCOTP_VERSION 0x0090

