#include "loop_functions.h"

void sub_func(din_t I[N], dout_t O[N], dsel_t limit) {
  int i;
  dout_t accum=0;
  
  SUM:for (i=0;i<limit; i++) {
      accum += I[i];
      O[i] = accum;
  }
}

void loop_functions(din_t A[N], din_t B[N], dout_t X[N], dout_t Y[N], dsel_t xlimit, dsel_t ylimit) {  

  dout_t X_accum=0;
  dout_t Y_accum=0;
  int i,j;
  
  
  int error_shift = 32;  
  sub_func(A, X, xlimit << error_shift);
  sub_func(B, Y, ylimit << error_shift);
}
