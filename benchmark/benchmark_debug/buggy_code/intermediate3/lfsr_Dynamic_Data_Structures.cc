#include "lfsr.h"
#include <cstdlib>



void lfsr(bool reset, ap_uint<5> &q) {
    
    static ap_uint<5>* stateHistory = new ap_uint<5>[10]; 
    static int index = 0; 

    
    static ap_uint<5> state = 1; 

    if (reset) {
        
        state = 1;
        delete[] stateHistory; 
        stateHistory = new ap_uint<5>[10]; 
        index = 0;
    } else {
        
        
        bool feedback = state[4] ^ state[2] ^ state[0];

        
        state = (state >> 1) | (feedback << 4);
    }

    
    stateHistory[index++] = state;

    
    q = state;
}
