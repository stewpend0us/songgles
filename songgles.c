#include "songgles.h"


static void setup_io()
{
	PC_ODR = 0x00; // output off
	PC_DDR = 0x48; // output on 3 and 6
	PC_CR1 = 0x48; // push pull on 3 and 6

	PD_ODR = 0x00; // output off
	PD_DDR = 0x48; // output on 3 and 6, input on 2 and 5
	PD_CR1 = 0x40; // open drain on 3, push pull on 6, floating on 2 and 5

	EXTI_CR1 |= 0x80; // falling edge for port D
}

static void setup_clock()
{
	CLK_SWCR |= 0x02; //set SWEN
	CLK_SWCR &= ~0x04; //0 SWIEN
	CLK_SWR = 0xB4; //HSE clock source
//	CLK_CKDIVR = 0x18; // probably don't need to do this
//	while ( !(CLK_SWCR & 0x08) ) {} // probably don't need to do this
	CLK_ICKR &= ~0x01; // disable high-speed internal clock
}

static void setup_TIM1()
{
	TIM1_PSCRH = 0;
	TIM1_PSCRL = 2;
//	TIM1_PSCRH = 0x8F;
//	TIM1_PSCRL = 0xFF;
	TIM1_ARRH = 0;
	TIM1_ARRL = 100;
	TIM1_CR1 |= 0x80; // use ARR preload registers
//	TIM1_IER |= 0x01; // enable interrupt
}

void tim4_update(void) __interrupt(23)
{
	// overall timer gets hit once per second? ish?
	TIM2_IER &= ~0x01; // disable TIM2 interrupt

	PC_ODR |= 0x08; // start the chirp
	TIM1_CR1 |= 0x01; // enable TIM1 counter
}

enum { CHIRP_START, CHIRPING, LISTEN_START, LISTENING, WAITING };
unsigned char chirps_remaining;
unsigned char state;

int main(void)
{
	__critical
	{
		setup_clock();
		setup_io();
		setup_TIM1();
	}


	for(;;)
	{
		switch ( state )
		{
			case CHIRP_START:
			{
				state = CHIRPING; // update state
				chirps_remaining = 16;
				PC_ODR |= 0x08; // start the chirp
				TIM1_CR1 |= 0x01; // enable TIM1 counter
				break;
			}
			case CHIRPING:
			{
				if ( TIM1_SR1 & 0x01 ) // TIM1 overflow
				{
					TIM1_SR1 &= ~0x01;
					if ( --chirps_remaining )
					{
					//	PD_ODR ^= 0x40;
						PC_ODR ^= 0x48;
					}
					else
					{
						TIM1_CR1 &= ~0x01; // disable TIM1 counter
					//	PD_ODR = 0x00;
						PC_ODR = 0x00;
						state = LISTEN_START;
					}
				}
				break;
			}
			case LISTEN_START:
			{
				state = LISTENING;
				break;
			}
			case LISTENING:
			{
				state = WAITING;
				break;
			}
			case WAITING:
			{
				wfi();
				break;
			}
		}
	}
}

	
