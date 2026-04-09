#include "half_adder.h"

void half_adder(bool a, bool b, bool *sum, bool *cout) {
    
    *sum = a ^ (b << 2);    
    *cout = a & b;   
}
