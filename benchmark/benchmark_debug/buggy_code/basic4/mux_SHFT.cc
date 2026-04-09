#include "mux.h"





void mux(data_t a, data_t b, sel_t sel, data_t* out) {
    if (sel == 0) {
        *out = a << (sizeof(data_t)*8); 
    } else {
        *out = b;
    }
}
