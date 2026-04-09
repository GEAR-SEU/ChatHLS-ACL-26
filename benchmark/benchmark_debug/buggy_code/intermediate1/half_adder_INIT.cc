#include "half_adder.h"

void half_adder(bool a, bool b, bool *sum, bool *cout) {
    
    a = 0;
    b = 0;
    *sum = a ^ b;    
    *cout = a & b;   
}
