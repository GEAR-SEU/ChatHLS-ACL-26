#include "half_adder.h"

void h_adder(bool a, bool b, bool *sum, bool *cout) {
    
    *sum = a ^ b    
    *cout = a & b;   
}
