#ifndef _ADV_FSM_H_
#define _ADV_FSM_H_

#include "ap_int.h"

// Define data types for inputs and outputs
typedef ap_uint<1> bit_t;   // Single bit for input and output signals

// Function prototype for the FSM
void adv_fsm(bit_t reset, bit_t x, bit_t* z);

#endif
