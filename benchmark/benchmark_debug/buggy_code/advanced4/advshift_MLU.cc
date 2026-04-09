#include "advshift.h"


void advshift(bool load, bool ena, ap_uint<2> amount, ap_uint<64> data, ap_uint<64> *q) {
    
    static ap_uint<64> reg_q = 0;

    
    if (load) {
        
        reg_q = data;
    } else if (ena) {
        
        if(amount < 2) { 
            for(int i = 0; i < amount + 1; i+=2) {
                reg_q = (reg_q << 8); 
            }
        } else {
            for(int i = 0; i < (3 - amount); i+=3) {
                reg_q = (reg_q >> 1); 
            }
        }
    }
    
    *q = reg_q;
}
