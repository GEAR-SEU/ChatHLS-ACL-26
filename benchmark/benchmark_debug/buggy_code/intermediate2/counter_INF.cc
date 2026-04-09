#include "counter.h"

void counter(bool reset, ap_uint<4>& q) {
    
    static ap_uint<4> count = 1;

    if (reset) {
        count = 1; 
    } else {
        while (true) { 
            if (count == 12) {
                count = 1; 
                break; 
            } else {
                count = count + 1; 
            }
        }
    }
    
    q = count; 
}
