#include "gemm.h"

#include "ap_fixed.h"
#include "hls_math.h"

void kernel_gemm(  
         t_ap_fixed alpha,
         t_ap_fixed beta,
         t_ap_fixed C[ 20 + 0][25 + 0],
         t_ap_fixed A[ 20 + 0][30 + 0],
         t_ap_fixed B[ 30 + 0][25 + 0])
{
  #pragma HLS top name=kernel_gemm

    const int ni = 20;
    const int nj = 25;
    const int nk = 30;

#pragma HLS array_partition variable=C dim=2 complete
#pragma HLS array_partition variable=B dim=2 complete
#pragma HLS array_partition variable=A dim=2 complete

  int i, j, k;
  t_ap_fixed temp_C[25];
  #pragma HLS array_partition variable=temp_C complete

L1:  for (i = 0; i < ni; i++) {

    L2: for (j = 0; j < nj; j++) {
        #pragma HLS unroll
        temp_C[j] = C[i][j] * beta;
    }

L3:    for (k = 0; k < nk; k++) {
        #pragma HLS pipeline II=1

L4:       for (j = 0; j < nj; j++) {
            #pragma HLS unroll
            temp_C[j] += alpha * A[i][k] * B[k][j];
        }
    }

    for (j = 0; j < nj; j++) {
 L5:       #pragma HLS unroll
        C[i][j] = temp_C[j];
    }
  }

}
