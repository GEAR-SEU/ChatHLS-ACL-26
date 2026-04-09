#include "advshift.h"

void advshift(bool load, bool ena, ap_uint<2> amount, ap_uint<64> data, ap_uint<64> *q) {
    
    ap_uint<64>* reg_q = new ap_uint<64>;
    
    if (load) {
        
        reg_q[0] = data;
    } else if (ena) {
        
        switch (amount) {
            case 0:
                
                reg_q[0] = (reg_q[0] << 1);
                break;
            case 1:
                
                reg_q[0] = (reg_q[0] << 8);
                break;
            case 2:
                
                reg_q[0] = (reg_q[0] >> 1);
                break;
            case 3:
                
                reg_q[0] = (reg_q[0] >> 8);
                break;
            default:
                break;
        }
    }
    
    *q = reg_q[0];

    delete[] reg_q;
}
