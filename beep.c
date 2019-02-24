#include "songgles.h"

void main(void)
{
	int d, e = 1;
	PD_DDR = (1 << 6); // output mode
	PD_CR1 = (1 << 6); // push-pull
	OFF_PD6();
	while(1)
	{
		if (e > 30)
			e = 1;
		for( d=0; d<29000; d++ )
			if ( d%e == 0 )
				TOGGLE_PD6();
		OFF_PD6();
		for( d=0; d<29000; d++)
		{}
		e++;
	}
}
