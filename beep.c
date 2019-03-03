#include "songgles.h"

static inline void setup_io()
{
	PC_ODR = 0x00; // output off
	PC_DDR = 0x48; // output on 3 and 6
	PC_CR1 = 0x48; // push pull on 3 and 6

	PD_ODR = 0x00; // output off
	PD_DDR = 0x48; // output on 3 and 6, input on 2 and 5
	PD_CR1 = 0x40; // open drain on 3, push pull on 6, floating on 2 and 5

	EXTI_CR1 |= 0x80; // falling edge for port D
}

static inline void setup_clock()
{
	CLK_SWCR |= 0x02; //set SWEN
	CLK_SWCR &= ~0x04; //0 SWIEN
	CLK_SWR = 0xB4; //HSE clock source
	//TODO
	CLK_CKDIVR = 0x18; // probably don't need to do this
	while ( !(CLK_SWCR & 0x08) ) {} // probably don't need to do this
	CLK_ICKR &= ~0x01; // disable high-speed internal RC
}

static void setup_TIM1()
{
	TIM1_PSCRH = 0xFF;
	TIM1_PSCRL = 0xFF;
	TIM1_ARRH = 0x00;
	TIM1_ARRL = 0xFF;
	TIM1_CR1 |= 0x80;
	TIM1_IER |= 0x01;
}

void tim1_overflow(void) __interrupt(11)
{
	PD_ODR ^= 0x40;
	TIM1_SR1 &= ~0x01;
}

int main(void)
{
//	int d;
	sim();
	setup_clock();
	setup_io();
	setup_TIM1();
	rim();

	TIM1_CR1 |= 0x01;

	int d, e = 1;
	for(;;)
	{
	}
}
