#include "mux.h"

void mux(data_t a, data_t b, sel_t sel, data_t* out) {
    a=0;
    b=0;
    sel=0;
    if (sel == 0) {
        *out = temp; 
    } else {
        *out = b;
    }
}
