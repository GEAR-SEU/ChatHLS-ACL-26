#ifndef _NOR_GATE_H_
#define _NOR_GATE_H_

#include <stdio.h>
#include "ap_int.h"

// Define input and output types
typedef ap_uint<1> bit_t;  // Single-bit input/output

// Function prototype for the NOR gate
void nor_gate(bit_t a, bit_t b, bit_t* out);

#endif
