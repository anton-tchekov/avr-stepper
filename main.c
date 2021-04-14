#include "stepper.h"
#include <avr/io.h>

int main(void)
{
	uint8_t step, state = STEPPER_INIT;
	for(;;)
	{
		step = next_step(&state, FULL_STEP | FWD);
		PORTB &= 0xF0;
		PORTB |= step;
	}

	return 0;
}