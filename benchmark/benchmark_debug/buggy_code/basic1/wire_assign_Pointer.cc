#include "wire_assign.h"

void wire_assign(input_t in, output_t* out) {
    output_t *temp;
    *temp = in;
    *out = *temp;
}
