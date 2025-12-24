//
// i.MX6 CCM Register Definitions
// Auto-generated from reference manual
//

#pragma once

// CCM Base Addresses
#define CCM_BASE 0x020C4000

// CCM Accessor Macros
#define CCM(reg) *(volatile unsigned int*)(CCM_BASE + (reg))

// CCM Register Offsets
#define CCM_CACRR 0x0010
#define CCM_CBCDR 0x0014
#define CCM_CBCMR 0x0018
#define CCM_CCDR 0x0004
#define CCM_CCGR0 0x0068
#define CCM_CCGR1 0x006C
#define CCM_CCGR2 0x0070
#define CCM_CCGR3 0x0074
#define CCM_CCGR4 0x0078
#define CCM_CCGR5 0x007C
#define CCM_CCGR6 0x0080
#define CCM_CCOSR 0x0060
#define CCM_CCR 0x0000
#define CCM_CCSR 0x000C
#define CCM_CDCDR 0x0030
#define CCM_CDHIPR 0x0048
#define CCM_CGPR 0x0064
#define CCM_CHSCCDR 0x0034
#define CCM_CIMR 0x005C
#define CCM_CISR 0x0058
#define CCM_CLPCR 0x0054
#define CCM_CMEOR 0x0088
#define CCM_CS1CDR 0x0028
#define CCM_CS2CDR 0x002C
#define CCM_CSCDR1 0x0024
#define CCM_CSCDR2 0x0038
#define CCM_CSCDR3 0x003C
#define CCM_CSCMR1 0x001C
#define CCM_CSCMR2 0x0020
#define CCM_CSR 0x0008

// CCM_CACRR
#define CCM_CACRR_R 3
#define CCM_CACRR_R 2
#define CCM_CACRR_R 1
#define CCM_CACRR_R 0

// CCM_CBCDR
#define CCM_CBCDR_R 19
#define CCM_CBCDR_R 18
#define CCM_CBCDR_R 17
#define CCM_CBCDR_R 16
#define CCM_CBCDR_R 3
#define CCM_CBCDR_R 2
#define CCM_CBCDR_R 1
#define CCM_CBCDR_R 0

// CCM_CCDR
#define CCM_CCDR_R 19
#define CCM_CCDR_R 18
#define CCM_CCDR_R 17
#define CCM_CCDR_R 16
#define CCM_CCDR_R 3
#define CCM_CCDR_R 2
#define CCM_CCDR_R 1
#define CCM_CCDR_W 0

// CCM_CCOSR
#define CCM_CCOSR_CLKO2_SEL 111
#define CCM_CCOSR_CLKO2_EN_HIGH 31
#define CCM_CCOSR_CLKO2_EN_LOW 25
#define CCM_CCOSR_CLKO2_EN 24
#define CCM_CCOSR_CLKO2_DIV_HIGH 23
#define CCM_CCOSR_CLKO2_DIV_LOW 21
#define CCM_CCOSR_CLKO2_SEL_HIGH 20
#define CCM_CCOSR_CLKO2_SEL_LOW 16
#define CCM_CCOSR_R 19
#define CCM_CCOSR_R 18
#define CCM_CCOSR_R 17
#define CCM_CCOSR_R 16
#define CCM_CCOSR_R 3
#define CCM_CCOSR_R 2
#define CCM_CCOSR_R 1
#define CCM_CCOSR_CLKO2_EN 0

// CCM_CCSR
#define CCM_CCSR_R 19
#define CCM_CCSR_R 18
#define CCM_CCSR_R 17
#define CCM_CCSR_R 16
#define CCM_CCSR_REF_EN_B_HIGH 3
#define CCM_CCSR_REF_EN_B_LOW 1
#define CCM_CCSR_R 3
#define CCM_CCSR_R 2
#define CCM_CCSR_R 1
#define CCM_CCSR_REF_EN_B 0

// CCM_CDCDR
#define CCM_CDCDR_R 19
#define CCM_CDCDR_R 18
#define CCM_CDCDR_R 17
#define CCM_CDCDR_R 16
#define CCM_CDCDR_R 3
#define CCM_CDCDR_R 2
#define CCM_CDCDR_R 1
#define CCM_CDCDR_R 0

// CCM_CGPR
#define CCM_CGPR_INT_MEM_CLK__HIGH 31
#define CCM_CGPR_INT_MEM_CLK__LOW 18
#define CCM_CGPR_INT_MEM_CLK_ 17
#define CCM_CGPR_FPL 16
#define CCM_CGPR_FPL 1

// CCM_CHSCCDR
#define CCM_CHSCCDR_R 3
#define CCM_CHSCCDR_R 2
#define CCM_CHSCCDR_R 1
#define CCM_CHSCCDR_R 0

// CCM_CIMR
#define CCM_CIMR_R 19
#define CCM_CIMR_R 18
#define CCM_CIMR_R 17
#define CCM_CIMR_R 16
#define CCM_CIMR_W 1

// CCM_CISR
#define CCM_CISR_R 19
#define CCM_CISR_R 18
#define CCM_CISR_R 17
#define CCM_CISR_R 16
#define CCM_CISR_W 0

// CCM_CLPCR
#define CCM_CLPCR_R 19
#define CCM_CLPCR_R 18
#define CCM_CLPCR_R 17
#define CCM_CLPCR_R 16
#define CCM_CLPCR_R 3
#define CCM_CLPCR_R 2
#define CCM_CLPCR_R 1
#define CCM_CLPCR_W 0

// CCM_CMEOR
#define CCM_CMEOR_R 19
#define CCM_CMEOR_R 18
#define CCM_CMEOR_R 17
#define CCM_CMEOR_R 16
#define CCM_CMEOR_CG3_HIGH 7
#define CCM_CMEOR_CG3_LOW 6
#define CCM_CMEOR_CG2_HIGH 5
#define CCM_CMEOR_CG2_LOW 4
#define CCM_CMEOR_CG1_HIGH 3
#define CCM_CMEOR_CG1_LOW 2
#define CCM_CMEOR_R 3
#define CCM_CMEOR_R 2
#define CCM_CMEOR_W 1
#define CCM_CMEOR_R 0

// CCM_CS1CDR
#define CCM_CS1CDR_R 19
#define CCM_CS1CDR_R 18
#define CCM_CS1CDR_R 17
#define CCM_CS1CDR_R 16
#define CCM_CS1CDR_R 3
#define CCM_CS1CDR_R 2
#define CCM_CS1CDR_R 1
#define CCM_CS1CDR_W 0

// CCM_CS2CDR
#define CCM_CS2CDR_R 19
#define CCM_CS2CDR_R 18
#define CCM_CS2CDR_R 17
#define CCM_CS2CDR_R 16
#define CCM_CS2CDR_R 3
#define CCM_CS2CDR_R 2
#define CCM_CS2CDR_R 1
#define CCM_CS2CDR_W 0

// CCM_CSR
#define CCM_CSR_R 19
#define CCM_CSR_R 18
#define CCM_CSR_R 17
#define CCM_CSR_R 16
#define CCM_CSR_R 3
#define CCM_CSR_R 2
#define CCM_CSR_R 1
#define CCM_CSR_W 0

