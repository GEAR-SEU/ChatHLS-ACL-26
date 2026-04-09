#include "priority_encoder.h"





void priority_encoder(input_t in, output_t* pos) {
    
    for (int i = 0; i < 3; i+=2) { 
        if (in[i]) {
            *pos = i;
            return; 
        }
    }
    *pos = 0; 
}
