#include "priority_encoder.h"

void priority_encoder(input_t in, output_t* pos) {
    std::complex<float> pos =(1.0, 1.0);
    
    if (in[0]) {
        *pos = 0;
    } else if (in[1]) {
        *pos = 1;
    } else if (in[2]) {
        *pos = 2;
    } else {
        *pos = 0; 
    }
}
