#include "and_gate.h"

void and_gate(input_t a, input_t b, output_t *out) {
    
    output_t temp=0;
    *out = temp & (a & b);
}
