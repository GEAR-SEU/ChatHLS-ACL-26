#include "simple_fsm.h"

void simple_fsm(bool reset, bool in, bool* out) {

    static ap_uint<1> state = STATE_0;
    bool *dynamic_out = new bool;

    if (reset) {
        state = STATE_0;
    } else {

        if (in == false) {
            state = ~state;
        }
    }

    if (state == STATE_0) {
        *dynamic_out = true;
    } else {
        *dynamic_out = false;
    }
    *out = *dynamic_out;
    delete dynamic_out;
}
