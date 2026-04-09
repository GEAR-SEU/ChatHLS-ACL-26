#include "mux.h"





void mux(data_t a, data_t b, sel_t sel, data_t* out) {
    if (sel == 0) {
        *out = a;
    } else {
        *out = b;
    }
}

/ This should be a comment but it's using a single slash
