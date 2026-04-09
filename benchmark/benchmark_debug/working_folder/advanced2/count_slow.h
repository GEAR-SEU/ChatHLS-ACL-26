#ifndef _COUNT_SLOW_H_
#define _COUNT_SLOW_H_

#include <stdio.h>
#include "ap_int.h"

// Define data types for inputs and outputs
typedef ap_uint<1> in_bit_t;
typedef ap_uint<4> out_q_t;

// Function prototype for the decade counter
void count_slow(in_bit_t reset, in_bit_t slowena, out_q_t *q);

#endif
