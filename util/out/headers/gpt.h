//
// i.MX6 GPT Register Definitions
// Auto-generated from reference manual
//

#pragma once

// GPT Base Addresses
#define GPT_BASE 0x02098000

// GPT Accessor Macros
#define GPT(reg) *(volatile unsigned int*)(GPT_BASE + (reg))

// GPT Register Offsets
#define GPT_CNT 0x0024
#define GPT_CR 0x0000
#define GPT_ICR1 0x001C
#define GPT_ICR2 0x0020
#define GPT_IR 0x000C
#define GPT_OCR1 0x0010
#define GPT_OCR2 0x0014
#define GPT_OCR3 0x0018
#define GPT_PR 0x0004
#define GPT_SR 0x0008

// GPT_CNT
#define GPT_CNT_FO3 31

// GPT_IR
#define GPT_IR_ROVIE_HIGH 31
#define GPT_IR_ROVIE_LOW 6
#define GPT_IR_R 19
#define GPT_IR_R 18
#define GPT_IR_R 17
#define GPT_IR_R 16
#define GPT_IR_ROVIE 5
#define GPT_IR_IF2IE 4
#define GPT_IR_R 3
#define GPT_IR_R 2
#define GPT_IR_OF2 1
#define GPT_IR_OF1 0

// GPT_PR
#define GPT_PR_PRESCALER_HIGH 31
#define GPT_PR_PRESCALER_LOW 12

// GPT_SR
#define GPT_SR_ROV_HIGH 31
#define GPT_SR_ROV_LOW 6
#define GPT_SR_ROV 5
#define GPT_SR_IF2 4
#define GPT_SR_IF1 3
#define GPT_SR_OF3 2
#define GPT_SR_IF2 1

