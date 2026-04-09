#include "mux.h"





void mux(data_t a, data_t b, sel_t sel, data_t* out) {
    int i = 0;
    while(1) { 
        if (sel == 0) {
            *out = a;
        } else {
            *out = b;
        }
        i++;
    }
}
