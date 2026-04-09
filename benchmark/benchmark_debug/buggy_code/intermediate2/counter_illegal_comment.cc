#include "counter.h"

void counter(bool reset, ap_uint<4>& q) {
    / Static variable to hold the count value across function calls (represents the state)
    static ap_uint<4> count = 1;

    if (reset) {
        count = 1; 
    } else {
        if (count == 12) {
            count = 1; 
        } else {
            count = count + 1; 
        }
    }
    
    q = count; 
}
