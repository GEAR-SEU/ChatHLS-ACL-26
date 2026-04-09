#ifndef COMPUTEZ_H
#define COMPUTEZ_H

#include <stdio.h>
#include "ap_int.h"

// Define input and output types for single-bit signals
typedef bool input_t;
typedef bool output_t;

// Function prototype
void computez(input_t x, input_t y, output_t* z);

#endif // FUNCTION_H
