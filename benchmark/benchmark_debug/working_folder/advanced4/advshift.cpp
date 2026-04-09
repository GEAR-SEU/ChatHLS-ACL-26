#include "advshift.h"

// Advshift function implementation
void advshift(bool load, bool ena, ap_uint<2> amount, ap_uint<64> data, ap_uint<64> *q) {
    // Static variable to hold the shift register value between function calls
    static ap_uint<64> reg_q = 0;

    // Synchronous logic emulation
    if (load) {
        // Load data into the shift register
        reg_q = data;
    } else if (ena) {
        // Shift operation based on the amount
        switch (amount) {
            case 0:
                // Shift left by 1 bit
                reg_q = (reg_q << 1);
                break;
            case 1:
                // Shift left by 8 bits
                reg_q = (reg_q << 8);
                break;
            case 2:
                // Shift right by 1 bit
                reg_q = (reg_q >> 1);
                break;
            case 3:
                // Shift right by 8 bits
                reg_q = (reg_q >> 8);
                break;
            default:
                break;
        }
    }
    // Output the current value of the shift register
    *q = reg_q;
}
