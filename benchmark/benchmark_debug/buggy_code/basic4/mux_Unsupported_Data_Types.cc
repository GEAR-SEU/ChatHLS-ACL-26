#include "mux.h"





void mux(data_t a, data_t b, sel sel, data_t* out) {
    if (sel == 0)
        *out = a;
    else
        *out = b;
}
