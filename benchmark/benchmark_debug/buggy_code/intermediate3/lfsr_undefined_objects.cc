#include "lfsr.h"



void lfsr(bool reset, ap_uint<5> &q) {
    
    static ap_uint<5> state = 1; 

    if (reset) {
        
        state = 1;
    } else {
        
        
        bool feedback = state[4] ^ state[2] ^ state[0];

        
        state = (state_current >> 1) | (feedback << 4);
    }

    
    q = state;
}
