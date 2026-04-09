#include "signed_adder.h"

void signed_adder(din_t a, din_t b, dout_t* s, overflow_t* overflow) {
    // Compute the sum
    *s = a + b;

    // Extract the sign bits
    bool a_sign = a[7];
    bool b_sign = b[7];
    bool s_sign = (*s)[7];

    // Compute overflow: occurs when the sign of a and b are the same
    // but the sign of the sum is different
    *overflow = ( (a_sign == b_sign) && (s_sign != a_sign) );
}
