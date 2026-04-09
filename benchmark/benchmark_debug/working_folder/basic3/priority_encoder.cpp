#include "priority_encoder.h"

// Function implementation: priority_encoder
// This function implements a 3-bit priority encoder.
// If none of the input bits are high (input is zero), output zero.
// The highest priority is given to the lowest bit (bit 0).
void priority_encoder(input_t in, output_t* pos) {
    // Check each bit starting from the highest priority (bit 0)
    if (in[0]) {
        *pos = 0;
    } else if (in[1]) {
        *pos = 1;
    } else if (in[2]) {
        *pos = 2;
    } else {
        *pos = 0; // If all bits are zero, output zero
    }
}
