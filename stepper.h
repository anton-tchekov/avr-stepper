#ifndef __STEPPER_H__
#define __STEPPER_H__

#include <stdint.h>

#define STEPPER_INIT  0x80

#define HALF_STEP    0
#define FULL_STEP    1

#define BWD          0
#define FWD          2

uint8_t next_step(uint8_t *state, uint8_t param);

#endif /* __STEPPER_H__ */
