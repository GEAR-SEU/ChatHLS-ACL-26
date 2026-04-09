#include "adv_fsm.h"

/*
 * Function: adv_fsm
 * -----------------
 * Implements a finite state machine that recognizes the sequence 101.
 *
 * Parameters:
 *   reset - Synchronous reset signal (active high).
 *   x     - Input signal.
 *   z     - Output signal, asserted when the sequence 101 is detected.
 */

void adv_fsm(bit_t reset, bit_t x, bit_t* z) {
    // State encoding
    enum states { IDLE=0, S1=1, S10=2 };
    static states present_state = IDLE;
    states next_state = present_state; // Initialize to current state

    // Output signal initialization
    bit_t z_internal = 0;

    // HLS interface pragmas
    #pragma HLS INTERFACE ap_none port=reset
    #pragma HLS INTERFACE ap_none port=x
    #pragma HLS INTERFACE ap_none port=z
    #pragma HLS INTERFACE ap_ctrl_none port=return

    // Next state logic and output logic
    switch (present_state) {
        case IDLE:
            if (x == 1) {
                next_state = S1;
            } else {
                next_state = IDLE;
            }
            z_internal = 0;
            break;

        case S1:
            if (x == 0) {
                next_state = S10;
            } else {
                next_state = IDLE;
            }
            z_internal = 0;
            break;

        case S10:
            if (x == 1) {
                // Sequence 101 detected
                next_state = IDLE;
                z_internal = 1;
            } else {
                next_state = IDLE;
                z_internal = 0;
            }
            break;

        default:
            next_state = IDLE;
            z_internal = 0;
            break;
    }

    // State update logic
    if (reset) {
        present_state = IDLE;
    } else {
        present_state = next_state;
    }

    // Assign output
    *z = z_internal;
}
