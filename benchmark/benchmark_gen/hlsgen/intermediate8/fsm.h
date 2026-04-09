// fsm.h

#ifndef FSM_H
#define FSM_H

#include "ap_int.h"

typedef ap_uint<1> logic; // Define a 1-bit logic type

// Function prototype for the FSM
void fsm(logic x, logic areset, logic& z);

#endif // FSM_H
