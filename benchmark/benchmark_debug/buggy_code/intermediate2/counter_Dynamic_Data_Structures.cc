#include "counter.h"

void counter(bool reset, ap_uint<4>& q) {
    
    ap_uint<4>* count = new ap_uint<4>;

    if (reset) {
        *count = 1; 
    } else {
        if (*count == 12) {
            *count = 1; 
        } else {
            *count = *count + 1; 
        }
    }
    
    q = *count; 

    delete count; 
}
