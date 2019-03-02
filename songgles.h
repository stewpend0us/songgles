
#define PA_ODR *(unsigned char*)0x5000
#define PA_IDR *(unsigned char*)0x5001
#define PA_DDR *(unsigned char*)0x5002
#define PA_CR1 *(unsigned char*)0x5003
#define PA_CR2 *(unsigned char*)0x5004
#define PB_ODR *(unsigned char*)0x5005
#define PB_IDR *(unsigned char*)0x5006
#define PB_DDR *(unsigned char*)0x5007
#define PB_CR1 *(unsigned char*)0x5008
#define PB_CR2 *(unsigned char*)0x5009
#define PC_ODR *(unsigned char*)0x500A
#define PC_IDR *(unsigned char*)0x500B
#define PC_DDR *(unsigned char*)0x500C
#define PC_CR1 *(unsigned char*)0x500D
#define PC_CR2 *(unsigned char*)0x500E
#define PD_ODR *(unsigned char*)0x500F
#define PD_IDR *(unsigned char*)0x5010
#define PD_DDR *(unsigned char*)0x5011
#define PD_CR1 *(unsigned char*)0x5012
#define PD_CR2 *(unsigned char*)0x5013
#define PE_ODR *(unsigned char*)0x5014
#define PE_IDR *(unsigned char*)0x5015
#define PE_DDR *(unsigned char*)0x5016
#define PE_CR1 *(unsigned char*)0x5017
#define PE_CR2 *(unsigned char*)0x5018
#define PF_ODR *(unsigned char*)0x5019
#define PF_IDR *(unsigned char*)0x501A
#define PF_DDR *(unsigned char*)0x501B
#define PF_CR1 *(unsigned char*)0x501C
#define PF_CR2 *(unsigned char*)0x501D
/*
 */
#define EXTI_CR1 *(unsigned char*)0X50A0
#define EXTI_CR2 *(unsigned char*)0X50A1
/*
 */
#define CLK_ICKR *(unsigned char*)0X50C0
#define CLK_ECKR *(unsigned char*)0X50C1
/**/
#define CLK_CMSR *(unsigned char*)0X50C3
#define CLK_SWR *(unsigned char*)0X50C4
#define CLK_SWCR *(unsigned char*)0X50C5
#define CLK_CKDIVR *(unsigned char*)0X50C6
#define CLK_PCKENR1 *(unsigned char*)0X50C7
#define CLK_CSSR *(unsigned char*)0X50C8
#define CLK_CCOR *(unsigned char*)0X50C9
#define CLK_PCKENR2 *(unsigned char*)0X50CA
/**/
#define CLK_HSITRIMR *(unsigned char*)0X50CC
#define CLK_SWIMCCR *(unsigned char*)0X50CD
/*
 */
#define BEEP_CSR *(unsigned char*)0X50F3
/*
 */
#define TIM1_CR1 *(unsigned char*)0x5250
#define TIM1_CR2 *(unsigned char*)0x5251
#define TIM1_SMCR *(unsigned char*)0x5252
#define TIM1_ETR *(unsigned char*)0x5253
#define TIM1_IER *(unsigned char*)0x5254
#define TIM1_SR1 *(unsigned char*)0x5255
#define TIM1_SR2 *(unsigned char*)0x5256
#define TIM1_EGR *(unsigned char*)0x5257
#define TIM1_CCMR1 *(unsigned char*)0x5258
#define TIM1_CCMR2 *(unsigned char*)0x5259
#define TIM1_CCMR3 *(unsigned char*)0x525A
#define TIM1_CCMR4 *(unsigned char*)0x525B
#define TIM1_CCER1 *(unsigned char*)0x525C
#define TIM1_CCER2 *(unsigned char*)0x525D
#define TIM1_CNTRH *(unsigned char*)0x525E
#define TIM1_CNTRL *(unsigned char*)0x525F
#define TIM1_PSCRH *(unsigned char*)0x5260
#define TIM1_PSCRL *(unsigned char*)0x5261
#define TIM1_ARRH *(unsigned char*)0x5262
#define TIM1_ARRL *(unsigned char*)0x5263
#define TIM1_RCR *(unsigned char*)0x5264
#define TIM1_CCR1H *(unsigned char*)0x5265
#define TIM1_CCR1L *(unsigned char*)0x5266
#define TIM1_CCR2H *(unsigned char*)0x5267
#define TIM1_CCR2L *(unsigned char*)0x5268
#define TIM1_CCR3H *(unsigned char*)0x5269
#define TIM1_CCR3L *(unsigned char*)0x526A
#define TIM1_CCR4H *(unsigned char*)0x526B
#define TIM1_CCR4L *(unsigned char*)0x526C
#define TIM1_BKR *(unsigned char*)0x526D
#define TIM1_DTR *(unsigned char*)0x526E
#define TIM1_OISR *(unsigned char*)0x526F
/*
 */
#define TIM2_CR1 *(unsigned char*)0x5200
/*
 */
#define TIM2_IER *(unsigned char*)0x5203
#define TIM2_SR1 *(unsigned char*)0x5204
#define TIM2_SR2 *(unsigned char*)0x5205
#define TIM2_EGR *(unsigned char*)0x5206
#define TIM2_CCMR1 *(unsigned char*)0x5207
#define TIM2_CCMR2 *(unsigned char*)0x5208
#define TIM2_CCMR3 *(unsigned char*)0x5209
#define TIM2_CCER1 *(unsigned char*)0x520A
#define TIM2_CCER2 *(unsigned char*)0x520B
#define TIM2_CNTRH *(unsigned char*)0x520C
#define TIM2_CNTRL *(unsigned char*)0x520D
#define TIM2_PSCR *(unsigned char*)0x520E
#define TIM2_ARRH *(unsigned char*)0x520F
#define TIM2_ARRL *(unsigned char*)0x5210
#define TIM2_CCR1H *(unsigned char*)0x5211
#define TIM2_CCR1L *(unsigned char*)0x5212
#define TIM2_CCR2H *(unsigned char*)0x5213
#define TIM2_CCR2L *(unsigned char*)0x5214
#define TIM2_CCR3H *(unsigned char*)0x5215
#define TIM2_CCR3L *(unsigned char*)0x5216
/*
 */
#define TIM4_CR1 *(unsigned char*)0x5240
/*
 */
#define TIM4_IER *(unsigned char*)0x5243
#define TIM4_SR *(unsigned char*)0x5244
#define TIM4_EGR *(unsigned char*)0x5245
#define TIM4_CNTR *(unsigned char*)0x5246
#define TIM4_PSCR *(unsigned char*)0x5247
#define TIM4_ARR *(unsigned char*)0x5248

#define sim() do{__asm__("sim");}while(0)
#define rim() do{__asm__("rim");}while(0)
#define wfi() do{__asm__("wfi");}while(0)
