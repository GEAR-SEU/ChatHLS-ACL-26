#ifndef DFF_H
#define DFF_H

#include <stdio.h>
#include "ap_int.h"

// Define input and output types for single-bit signals
typedef bool input_t;
typedef bool output_t;

// Function prototype
void dff(input_t d, input_t clk, output_t* q);

#endif // DFF_H
