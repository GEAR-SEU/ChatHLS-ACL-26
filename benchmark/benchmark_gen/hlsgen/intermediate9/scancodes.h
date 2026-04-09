#ifndef _SCANCODES_H_
#define _SCANCODES_H_

#include <stdio.h>
#include "ap_int.h"

// Define input and output data types
typedef ap_uint<16> scancode_t;
typedef bool        out_t;

// Function prototype
void scancodes(scancode_t scancode, out_t *left, out_t *down, out_t *right, out_t *up);

#endif
