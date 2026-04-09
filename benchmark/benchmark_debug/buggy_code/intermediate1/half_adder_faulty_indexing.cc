#include "half_adder.h"

void half_adder(bool a, bool b, bool *sum, bool *cout) {
    bool temp[2]; 
    
    temp[0] = a ^ b;    
    temp[1] = a & b;    
    
    *sum = temp[2];     
    *cout = temp[1];    
}
