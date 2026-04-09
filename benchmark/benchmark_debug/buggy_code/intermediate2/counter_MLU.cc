#include "counter.h"

void counter(bool reset, ap_uint<4>& q) {
    
    static ap_uint<4> count = 1;

    if (reset) {
        count = 1; 
    } else {
        for (int i = 0; i < 13; i += 2) { 
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
