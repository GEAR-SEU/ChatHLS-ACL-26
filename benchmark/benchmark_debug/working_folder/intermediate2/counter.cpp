#include "counter.h"

void counter(bool reset, ap_uint<4>& q) {
    // Static variable to hold the count value across function calls (represents the state)
    static ap_uint<4> count = 1;

    if (reset) {
        count = 1; // Reset count to 1 when reset is active
    } else {
        if (count == 12) {
            count = 1; // Wrap around to 1 after reaching 12
        } else {
            count = count + 1; // Increment count
        }
    }
    
    q = count; // Output the current count
}
