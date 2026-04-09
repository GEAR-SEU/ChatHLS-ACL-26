#ifndef _WIRE_ASSIGN_H_
#define _WIRE_ASSIGN_H_

#include "ap_int.h"

// Define data types for input and output signals
typedef ap_uint<1> input_t;
typedef ap_uint<1> output_t;

// Function prototype
void wire_assign(input_t in, output_t* out);

#endif
