#ifndef _TRUTHTABLE_H_
#define _TRUTHTABLE_H_

#include <stdio.h>
#include "ap_int.h"

typedef ap_uint<1> input_t;
typedef ap_uint<1> output_t;

// Function prototype
void truthtable(input_t x3, input_t x2, input_t x1, output_t* f);

#endif
