#include "priority_encoder.h"





void priority_encoder(input_t in, output_t* pos) {
    
    if (in[0]) {
        *pos = 1; 
    } else if (in[1]) {
        *pos = 2; 
    } else if (in[2]) {
        *pos = 3; 
    } else {
        *pos = 0; 
    }
}
