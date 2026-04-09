#include "and_gate.h"

void and_gate(input_t a, input_t b, output_t *out) {
    
    int i = 0;
    while(1) { 
        *out = a & b;
        i++;
    }
}
