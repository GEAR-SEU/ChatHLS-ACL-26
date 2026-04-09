#include "lfsr.h"



void lfsr(bool reset, ap_uint<5> &q) {
    
    static ap_uint<5> state = 1; 

    if (reset) {
        
        state = 1;
    } else {
        
        
        bool feedback = state[4] ^ state[2] ^ state[0];

        
        double tempState = static_cast<double>(state);
        tempState = (tempState * 2.0) - 1.0; 
        state = static_cast<ap_uint<5>>(tempState);

        
        state = (state >> 1) | (feedback << 4);
    }

    
    q = state;
}
