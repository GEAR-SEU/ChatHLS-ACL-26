#ifndef _MUX_H_
#define _MUX_H_

#include <ap_int.h>

// Define input and output types
typedef ap_uint<5> data_t;    // 5-bit data type for inputs and output
typedef ap_uint<1> sel_t;     // 1-bit selection signal

// Function prototype for the 2-to-1 multiplexer
void mux(data_t a, data_t b, sel_t sel, data_t* out);

#endif
