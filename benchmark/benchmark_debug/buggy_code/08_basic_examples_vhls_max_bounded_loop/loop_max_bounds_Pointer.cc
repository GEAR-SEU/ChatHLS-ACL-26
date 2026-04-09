#include "loop_max_bounds.h"

dout_t loop_max_bounds(din_t A[N], dsel_t width) {  

  dout_t out_accum=0;
  dsel_t *x = 0; 
  
  LOOP_X:for (*x=0; *x<N-1; (*x)++) {
    if (*x<width) {
      out_accum += A[*x];
    }
  }

  return out_accum;
}
