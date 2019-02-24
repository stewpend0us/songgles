#include "songgles.h"

void main(void)
{
	PD_DDR = (1 << 6);
	PD_CR1 = (1 << 6);
	PD_ODR = 0;
}
