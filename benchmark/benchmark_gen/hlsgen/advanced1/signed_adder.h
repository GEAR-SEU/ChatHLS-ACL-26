#ifndef _SIGNED_ADDER_H_
#define _SIGNED_ADDER_H_

#include <stdio.h>
#include "ap_int.h"

// Define input and output data types
typedef ap_int<8> din_t;    // 8-bit signed integer for inputs a and b
typedef ap_int<8> dout_t;   // 8-bit signed integer for output s
typedef bool overflow_t;    // Boolean for overflow flag

// Function prototype
void signed_adder(din_t a, din_t b, dout_t* s, overflow_t* overflow);

#endif
