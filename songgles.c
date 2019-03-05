#include "songgles.h"

char state;

enum state { WAIT, CHIRP, LISTEN, BEEP, };

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
//	CLK_CKDIVR = 0x18; // probably don't need to do this
//	while ( !(CLK_SWCR & 0x08) ) {} // probably don't need to do this
	CLK_ICKR &= ~0x01; // disable high-speed internal RC
}

static void setup_TIM1()
{
	TIM1_PSCRH = 0;
	TIM1_PSCRL = 2;
	TIM1_ARRH = 0;
	TIM1_ARRL = 100;
	TIM1_CR1 |= 0x80; // use ARR preload registers
//	TIM1_IER |= 0x01; // enable interrupt
}

void tim1_update(void) __interrupt(11)
{
	PC_ODR ^= 0x40;
	PC_ODR ^= 0x08;
	TIM1_SR1 &= ~0x01;
}

void tim4_update(void) __interrupt(23)
{
	// overall timer gets hit once per second? ish?
	TIM2_IER &= ~0x01; // disable TIM2 interrupt

	PC_ODR |= 0x08; // start the chirp
	TIM1_IER |= 0x01; // enable TIM1 interrupt
}

int main(void)
{
	sim();
	setup_clock();
	setup_io();
	setup_TIM1();
	rim();

	TIM1_CR1 |= 0x01;

	state = WAIT;
	for(;;)
	{
		switch state
		{
			case WAIT:
				wfi();
				break;
			case CHIRP:
				break;
			case LISTEN:
				break;
			case BEEP:
				break;
		}
	}
}

	
