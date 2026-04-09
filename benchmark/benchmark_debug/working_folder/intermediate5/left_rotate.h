#ifndef _LEFT_ROTATE_H_
#define _LEFT_ROTATE_H_

#include <stdio.h>
#include "ap_int.h"

// Define data types
typedef ap_uint<3> amount_t;
typedef ap_uint<8> data_t;
typedef ap_uint<1> bool_t; // For 'load' signal

void left_rotate(bool_t load, amount_t amount, data_t data, data_t &out);

#endif // _LEFT_ROTATE_H_
