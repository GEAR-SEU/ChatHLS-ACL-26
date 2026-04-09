#include "mvt.h"
#include "ap_fixed.h"
#include "hls_math.h"

void kernel_mvt(
                t_ap_fixed x1[40],
                t_ap_fixed x2[40],
                t_ap_fixed y_1[40],
                t_ap_fixed y_2[40],
                t_ap_fixed A[40][40])
{
  #pragma HLS top name=kernel_mvt
  #pragma HLS array_partition variable=y_1 complete
  #pragma HLS array_partition variable=y_2 complete
  const int n = 40;
  int i, j;

  L1: for (i = 0; i < n; i++) {
    t_ap_fixed temp = x1[i];
    L2: for (j = 0; j < n; j++) {
      #pragma HLS pipeline
      #pragma HLS DATAFLOW
      temp += A[i][j] * y_1[j];
    }
    x1[i] = temp;
  }
  L3: for (i = 0; i < n; i++) {
    t_ap_fixed temp = x2[i];
    L4: for (j = 0; j < n; j++) {
      #pragma HLS pipeline
      temp += A[j][i] * y_2[j];
    }
    x2[i] = temp;
  }
}
