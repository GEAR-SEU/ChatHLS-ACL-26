#include "and_gate.h"

void and_gate(input_t a, input_t b, output_t *out) {
    
    
    output_t* dynamic_out = new output_t;
    *dynamic_out = a & b;
    *out = *dynamic_out;
    delete dynamic_out;
}
