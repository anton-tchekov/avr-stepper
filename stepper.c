#include "stepper.h"

const uint8_t step_list[8] =
{
	0x0A, /* 1010 */
	0x08, /* 1000 */
	0x09, /* 1001 */
	0x01, /* 0001 */
	0x05, /* 0101 */
	0x04, /* 0100 */
	0x06, /* 0110 */
	0x02  /* 0010 */
};

uint8_t next_step(uint8_t *state, uint8_t param)
{
	uint8_t step, ret;
	step = *state;
	ret = step_list[step - 0x80];

	if(param & 1)
	{
		/* full step */
		if((param >> 1) & 1)
		{
			if(step % 2 == 0)
			{
				++step;
			}
			else
			{
				step += 2;
			}

			if(step == 0x88)
			{
				step = 0x80;
			}
		}
		else
		{
			if(step % 2 == 0)
			{
				--step;
			}
			else
			{
				step -= 2;
			}

			if(step == 0x7E)
			{
				step = 0x86;
			}
		}
	}
	else
	{
		/* half step */
		if((param >> 1) & 1)
		{
			if(++step == 0x88)
			{
				step = 0x80;
			}
		}
		else if(--step == 0x7F)
		{
			step = 0x86;
		}
	}

	*state = step;
	return ret;
}
