#include "counter.h"

void counter(bool reset, ap_uint<4>& q) {
    
    static ap_uint<4> count = 1;

    if (reset) {
        count = 1; 
    } else {
        if (count == 12) {
            count = 1; 
        } else {
            count = pow(count, 1.5); 
        }
    }
    
    q = count; 
}
