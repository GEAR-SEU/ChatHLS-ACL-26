#ifndef _SIMPLE_FSM_H_
#define _SIMPLE_FSM_H_

#include <stdio.h>
#include "ap_int.h"

// State definitions
#define STATE_0 0
#define STATE_1 1

// Function prototype
void simple_fsm(bool reset, bool in, bool* out);

#endif // _SIMPLE_FSM_H_
