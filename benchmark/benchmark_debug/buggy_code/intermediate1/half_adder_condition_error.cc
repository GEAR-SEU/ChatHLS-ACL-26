#include "half_adder.h"

void half_adder(bool a, bool b, bool *sum, bool *cout) {
    *sum = a ^ b;
    if(a=1 && b=1)
        *cout = a & b;
}
