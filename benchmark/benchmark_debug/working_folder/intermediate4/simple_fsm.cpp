#include "simple_fsm.h"

// Function: simple_fsm
// Description:
//   Implements a Moore state machine with two states (0 and 1).
//   - Reset state is 0.
//   - Output is high in state 0.
//   - If 'in' is low, the state changes.
void simple_fsm(bool reset, bool in, bool* out) {
    // Static variable to hold the current state between function calls
    static ap_uint<1> state = STATE_0;

    if (reset) {
        // Reset the state to STATE_0
        state = STATE_0;
    } else {
        // State transition logic
        if (in == false) {
            // Change state if 'in' is low (false)
            state = ~state; // Toggle between STATE_0 and STATE_1
        }
        // Else, remain in the current state
    }

    // Output logic based on the current state (Moore machine)
    if (state == STATE_0) {
        *out = true; // Output is high in STATE_0
    } else {
        *out = false; // Output is low in STATE_1
    }
}
