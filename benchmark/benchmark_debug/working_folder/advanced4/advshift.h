#ifndef ADVSHIFT_H
#define ADVSHIFT_H

#include "ap_int.h"

// Function prototype for the advshift module
void advshift(bool load, bool ena, ap_uint<2> amount, ap_uint<64> data, ap_uint<64> *q);

#endif // ADVSHIFT_H
