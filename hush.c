#include "stm8l.h"

void main(void)
{
	int d;
	PD_DDR = 0xff;
	PD_CR1 = 0xff;
	while(1)
	{
		PD_ODR = 0x00;
		for( d=0; d<29000; d++ )
		{
		}
	}
}
