#ifndef _GATES4_H_
#define _GATES4_H_

#include <stdio.h>
#include "ap_int.h"

typedef ap_uint<4> in_t;   // 4-bit input
typedef ap_uint<1> out_t;  // 1-bit outputs

void gates4(in_t in, out_t *out_and, out_t *out_or, out_t *out_xor);

#endif
