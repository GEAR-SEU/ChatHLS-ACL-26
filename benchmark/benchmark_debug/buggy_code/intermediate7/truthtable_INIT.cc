#include "truthtable.h"

void truthtable(input_t x3, input_t x2, input_t x1, output_t* f) {
    

    
    x1 = 0; 

    
    if ( (x3 == 0 && x2 == 0 && x1 == 0) ||
         (x3 == 0 && x2 == 0 && x1 == 1) ||
         (x3 == 0 && x2 == 1 && x1 == 1) ||
         (x3 == 1 && x2 == 1 && x1 == 0) ) {
        result = 1;
    } else {
        result = 0;
    }

    *f = result; 
}
