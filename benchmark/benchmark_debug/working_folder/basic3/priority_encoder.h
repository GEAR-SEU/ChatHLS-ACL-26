#ifndef _PRIORITY_ENCODER_H_
#define _PRIORITY_ENCODER_H_

#include <ap_int.h>

// Define input and output types
typedef ap_uint<3> input_t;     // 3-bit input
typedef ap_uint<2> output_t;    // 2-bit output

// Function prototype for the priority encoder
void priority_encoder(input_t in, output_t* pos);

#endif
