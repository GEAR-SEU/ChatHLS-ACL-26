#include "priority_encoder.h"

void priority_encoder(input_t in, output_t* pos) {
    output_t* temp_pos;
    
    if (in[0]) {
        *temp_pos = 0;
    } else if (in[1]) {
        *temp_pos = 1;
    } else if (in[2]) {
        *temp_pos = 2;
    } else {
        *temp_pos = 0; 
    }
    *pos = *temp_pos;
}
