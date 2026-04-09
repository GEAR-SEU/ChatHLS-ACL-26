#include "mux.h"

void mux(data_t a, data_t b, sel_t sel, data_t* out) {
    data_t* temp_ptr;
    if (sel == 0) {
        *temp_ptr = a;
    } else {
        *temp_ptr = b;
    }
    *out = *temp_ptr;
}
