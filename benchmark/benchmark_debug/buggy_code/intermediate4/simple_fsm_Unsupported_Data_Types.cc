#include "simple_fsm.h"







void simple_fsm(bool reset, bool in, bool* out) {
    
    static complex<double> state = {STATE_0, 0};  

    if (reset) {
        
        state = {STATE_0, 0};
    } else {
        
        if (in == false) {
            
            state = ~state; 
        }
        
    }

    
    if (state.real() == STATE_0) {
        *out = true; 
    } else {
        *out = false; 
    }
}
