#ifndef _LFSR_H_
#define _LFSR_H_

#include <stdio.h>
#include "ap_int.h"

// Function declaration for the LFSR
void lfsr(bool reset, ap_uint<5> &q);

#endif // _LFSR_H_
