#include "advshift.h"


void advshift(bool load, bool ena, ap_uint<2> amount, ap_uint<64> data, ap_uint<64> *q) {
    
    static ap_uint<64> reg_q = 0;

    
    if (load) {
        
        reg_q = data;
    } else if (ena) {
        
        switch (amount) {
            case 0:
                
                reg_q = (reg_q << 1);
                break;
            case 1:
                
                reg_q = (reg_q << 8);
                break;
            case 2:
                
                reg_q = (reg_q >> 1);
                break;
            case 3:
                
                reg_q = (reg_q >> 8);
                break;
            default:
                
                reg_q = undefined_variable;
                break;
        }
    }
    
    *q = reg_q;
}
