#include "wire_assign.h"

void wire_assign(input_t in, output_t* out) {
    
    output_t* dynamic_out = new output_t;
    *dynamic_out = in;
    *out = *dynamic_out;
    delete dynamic_out;
}
