#ifndef _RAM_H_
#define _RAM_H_

#include <stdio.h>
#include "ap_int.h"

// Parameter definitions
#define ADDR_WIDTH 6
#define DATA_WIDTH 8

// Type definitions
typedef ap_uint<DATA_WIDTH> data_t;
typedef ap_uint<ADDR_WIDTH> addr_t;
typedef ap_uint<1>          bool_t; // For 'we' signal

// Function prototype
void ram(data_t data, addr_t addr, bool_t we, data_t& q);

#endif // _RAM_H_
