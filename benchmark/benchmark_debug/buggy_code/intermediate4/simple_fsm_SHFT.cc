#include "simple_fsm.h"







void simple_fsm(bool reset, bool in, bool* out) {
    
    static ap_uint<1> state = STATE_0;

    if (reset) {
        
        state = STATE_0;
    } else {
        
        if (in == false) {
            
            state = state << 1; 
        }
        
    }

    
    if (state == STATE_0) {
        *out = true; 
    } else {
        *out = false; 
    }
}
