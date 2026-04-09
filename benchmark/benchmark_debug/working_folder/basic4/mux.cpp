#include "mux.h"

// Function implementation: mux
// This function implements a 2-to-1 multiplexer.
// When sel=0, it assigns 'a' to 'out'.
// When sel=1, it assigns 'b' to 'out'.
void mux(data_t a, data_t b, sel_t sel, data_t* out) {
    if (sel == 0) {
        *out = a;
    } else {
        *out = b;
    }
}
