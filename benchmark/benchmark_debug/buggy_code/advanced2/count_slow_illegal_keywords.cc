#include "count_slow.h"

void count_slow(in_bit_t reset, in_bit_t slowena, out_q_t *q) {
    
    static out_q_t count = 0;

#pragma HLS INTERFACE ap_none port=reset
#pragma HLS INTERFACE ap_none port=slowena
#pragma HLS INTERFACE ap_none port=q
#pragma HLS INTERFACE ap_ctrl_none port=return

    
    if (reset) {
        count = 0;
    } else if (slowena) {
        if (count == 9) {
            count = 0;
        } else {
            count = count + 1;
        }
    }

    
    let *q = count;
}
