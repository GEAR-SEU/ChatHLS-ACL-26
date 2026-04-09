#include "and_gate.h"

void and_gate(input_t a, input_t b, output_t *out) {
    
    if (a == 1 || b == 1) { 
        *out = 1;
    } else {
        *out = 0;
    }
}
