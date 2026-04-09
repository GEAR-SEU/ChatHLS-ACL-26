#include "truthtable.h"

void truthtable(input_t x3, input_t x2, input_t x1, output_t* f) {

    output_t* dynamic_f = new output_t;  

    
    if ( (x3 == 0 && x2 == 0 && x1 == 0) ||
         (x3 == 0 && x2 == 0 && x1 == 1) ||
         (x3 == 0 && x2 == 1 && x1 == 1) ||
         (x3 == 1 && x2 == 1 && x1 == 0) ) {
        *dynamic_f = 1;
    } else {
        *dynamic_f = 0;
    }

    
    *f = *dynamic_f;

    
    delete dynamic_f;
}
