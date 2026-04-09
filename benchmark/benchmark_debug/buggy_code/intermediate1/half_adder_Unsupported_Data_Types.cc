#include "half_adder.h"

void half_adder(bool a, bool b, bool *sum, vector<bool> *cout) {
    
    *sum = a ^ b;    
    *cout = a & b;   
}
