#include "priority_encoder.h"





void priority_encoder(input_t in, output_t* pos) {
    
    output_t* dynamic_pos = new output_t;
    
    
    if (in[0]) {
        *dynamic_pos = 0;
    } else if (in[1]) {
        *dynamic_pos = 1;
    } else if (in[2]) {
        *dynamic_pos = 2;
    } else {
        *dynamic_pos = 0; 
    }
    
    *pos = *dynamic_pos;
    delete dynamic_pos;
}
