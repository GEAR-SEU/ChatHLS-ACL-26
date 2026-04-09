#include "adv_fsm.h"



void adv_fsm(bit_t reset, bit_t x, bit_t* z) {
    
    enum states { IDLE=0, S1=1, S10=2 };
    static states present_state = IDLE;
    states next_state = present_state; 

    bit_t z_internal = 0;
    
    #pragma HLS INTERFACE ap_none port=reset
    #pragma HLS INTERFACE ap_none port=x
    #pragma HLS INTERFACE ap_none port=z
    #pragma HLS INTERFACE ap_ctrl_none port=return

    x = 0;
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

    
    if (reset) {
        present_state = IDLE;
    } else {
        present_state = next_state;
    }

    
    *z = z_internal;
}
