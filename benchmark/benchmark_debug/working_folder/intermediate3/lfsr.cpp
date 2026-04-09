#include "lfsr.h"

// LFSR function implementing a 5-bit maximal-length Galois LFSR
// with taps at bit positions 5, 3, and 1.
void lfsr(bool reset, ap_uint<5> &q) {
    // Static variable to hold the current state between function calls
    static ap_uint<5> state = 1; // Initialize state to 1

    if (reset) {
        // Reset the LFSR state to 1
        state = 1;
    } else {
        // Calculate the feedback bit by XORing the tapped bits
        // Taps at positions 5, 3, and 1 correspond to bits 4, 2, and 0 in 0-based indexing
        bool feedback = state[4] ^ state[2] ^ state[0];

        // Shift the state to the right by 1 and insert the feedback bit at MSB
        state = (state >> 1) | (feedback << 4);
    }

    // Output the current state
    q = state;
}
