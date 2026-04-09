#include "mux.h"





void mux(data_t a, data_t b, sel_t sel, data_t* out) {
    if (sel == 0)
        out[1] = a;
    else
        out[2] = b;
}
