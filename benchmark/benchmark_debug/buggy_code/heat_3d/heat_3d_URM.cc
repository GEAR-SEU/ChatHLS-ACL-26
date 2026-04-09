#include "heat_3d.h"

#include "ap_fixed.h"
#include "hls_math.h"

void kernel_heat_3d(
              
              t_ap_fixed A[ 10 + 0][10 + 0][10 + 0],
              t_ap_fixed B[ 10 + 0][10 + 0][10 + 0])
{
  #pragma HLS top name=kernel_heat_3d
  #pragma HLS ARRAY_PARTITION variable=A complete
  #pragma HLS ARRAY_PARTITION variable=B complete

    const int n = 10;
    const int tsteps = 20;

  int t, i, j, k;

#pragma HLS unroll factor=3
L1:    for (t = 1; t <= 20; t++) {
L2:        for (i = 1; i < n-1; i++) {
L3:            for (j = 1; j < n-1; j++) {
L4:                for (k = 1; k < n-1; k++) {
#pragma HLS PIPELINE II=1
                    B[i][j][k] =   (t_ap_fixed(0.125)) * (A[i+1][j][k] - (t_ap_fixed(2.0)) * A[i][j][k] + A[i-1][j][k])
                                 + (t_ap_fixed(0.125)) * (A[i][j+1][k] - (t_ap_fixed(2.0)) * A[i][j][k] + A[i][j-1][k])
                                 + (t_ap_fixed(0.125)) * (A[i][j][k+1] - (t_ap_fixed(2.0)) * A[i][j][k] + A[i][j][k-1])
                                 + A[i][j][k];
                }
            }
        }
#pragma HLS unroll factor=4
L5:        for (i = 1; i < n-1; i++) {
L6:           for (j = 1; j < n-1; j++) {
L7:               for (k = 1; k < n-1; k++) {
#pragma HLS PIPELINE II=1
                   A[i][j][k] =   (t_ap_fixed(0.125)) * (B[i+1][j][k] - (t_ap_fixed(2.0)) * B[i][j][k] + B[i-1][j][k])
                                + (t_ap_fixed(0.125)) * (B[i][j+1][k] - (t_ap_fixed(2.0)) * B[i][j][k] + B[i][j-1][k])
                                + (t_ap_fixed(0.125)) * (B[i][j][k+1] - (t_ap_fixed(2.0)) * B[i][j][k] + B[i][j][k-1])
                                + B[i][j][k];
               }
           }
       }
    }

}
