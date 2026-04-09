#include "priority_encoder.h"

void priority_encoder(input_t in, output_t* pos) {
    int i = 0;
    
    for (; ;) {
        if (in[i]) {
            *pos = i;
            break; 
        }
        i = (i + 1) % 3;
    }
}
