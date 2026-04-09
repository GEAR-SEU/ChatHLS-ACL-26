#include "signed_adder.h"

void signed_adder(din_t a, din_t b, dout_t* s, overflow_t* overflow) {
    
    dout_t *dynamic_sum = new dout_t;  

    *dynamic_sum = a + b;
    *s = *dynamic_sum;

    bool a_sign = a[7];
    bool b_sign = b[7];
    bool s_sign = (*s)[7];
    
    *overflow = ( (a_sign == b_sign) && (s_sign != a_sign) );

    delete dynamic_sum;  
}
