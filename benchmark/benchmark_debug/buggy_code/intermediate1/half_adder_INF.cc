#include "half_adder.h"

void half_adder(bool a, bool b, bool *sum, bool *cout) {
    
    for(int i = 0; ; i++) { 
        *sum = a ^ b;    
        *cout = a & b;   
    }
}
