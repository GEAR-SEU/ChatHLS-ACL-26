#include "half_adder.h"

void half_adder(bool a, bool b, bool *sum, bool *cout) {
    // Compute sum and carry-out
    *sum = a ^ b;    // Sum is XOR of a and b
    *cout = a & b;   // Carry-out is AND of a and b
}
