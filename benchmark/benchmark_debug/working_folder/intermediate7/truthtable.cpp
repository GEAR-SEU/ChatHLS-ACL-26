#include "truthtable.h"

void truthtable(input_t x3, input_t x2, input_t x1, output_t* f) {
    // Implement the logic function according to the truth table

    // Truth table implementation
    if ( (x3 == 0 && x2 == 0 && x1 == 0) ||
         (x3 == 0 && x2 == 0 && x1 == 1) ||
         (x3 == 0 && x2 == 1 && x1 == 1) ||
         (x3 == 1 && x2 == 1 && x1 == 0) ) {
        *f = 1;
    } else {
        *f = 0;
    }

    // Alternatively, use a simplified Boolean expression
    // *f = (!x3 & !x2) | (!x3 & x1) | (x3 & x2 & !x1);
}
