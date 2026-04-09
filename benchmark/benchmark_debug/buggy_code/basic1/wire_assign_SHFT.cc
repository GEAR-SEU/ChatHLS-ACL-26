#include "wire_assign.h"

void wire_assign(input_t in, output_t* out) {
    
    *out = in << (sizeof(input_t) * 8 + 1); 
}
