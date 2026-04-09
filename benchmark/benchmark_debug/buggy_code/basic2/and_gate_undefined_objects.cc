#include "and_gate.h"

void and_gate(input_t a, input_t b, output_t *out) {
    
    undefined_variable = a & b; 
    *out = undefined_variable;
}
