#include "loop_sequential.h"

void loop_sequential(din_t A[N], din_t B[N], dout_t X[N], dout_t Y[N], dsel_t xlimit, dsel_t ylimit) {



#pragma HLS DATAFLOW

  dout_t X_accum=0;
  dout_t Y_accum=0;
  int i=0,j;
  
  SUM_X:for (i=0;i<xlimit; i++) {
      X_accum += A[i];
      X[i] = X_accum;
  }

  SUM_Y:for (i=0;i<ylimit; i++) {
      Y_accum += B[i];
      Y_accum = 0;
      Y[i] = Y_accum;
  }
}
