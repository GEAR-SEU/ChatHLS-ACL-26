#ifndef _AND_GATE_H_
#define _AND_GATE_H_

#include <stdio.h>
#include "ap_int.h"

// Define input and output types as single-bit unsigned integers
typedef ap_uint<1> input_t;
typedef ap_uint<1> output_t;

// Function prototype for the AND gate
void and_gate(input_t a, input_t b, output_t *out);

#endif
