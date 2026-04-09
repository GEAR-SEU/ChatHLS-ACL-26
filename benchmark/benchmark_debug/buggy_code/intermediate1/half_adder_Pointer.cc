#include "half_adder.h"

void half_adder(bool a, bool b, bool *sum, bool *cout) {
    bool *dynamic_sum = new bool; 
    bool *dynamic_cout = new bool; 
    
    
    *dynamic_sum = a ^ b;    
    *dynamic_cout = a & b;   
    
    *sum = *dynamic_sum;
    *cout = *dynamic_cout;
    
    delete dynamic_sum; 
    delete dynamic_cout; 
}
