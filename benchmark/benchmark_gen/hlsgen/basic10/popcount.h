#ifndef _POPCOUNT_H_
#define _POPCOUNT_H_

#include "ap_int.h"

// Define input and output data types using arbitrary precision integers
typedef ap_uint<3> din_t;    // 3-bit unsigned integer for input
typedef ap_uint<2> dout_t;   // 2-bit unsigned integer for output

// Function prototype for the popcount module
void popcount(din_t in, dout_t* out);

#endif  // _POPCOUNT_H_
