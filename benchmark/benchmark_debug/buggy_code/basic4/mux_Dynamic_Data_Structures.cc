#include "mux.h"





void mux(data_t a, data_t b, sel_t sel, data_t* out) {
    data_t* dynamic_data = new data_t; 
    if (sel == 0) {
        *dynamic_data = a;
    } else {
        *dynamic_data = b;
    }
    *out = *dynamic_data;
    delete dynamic_data; 
}
