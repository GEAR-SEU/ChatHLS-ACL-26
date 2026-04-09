#include "ap_fixed.h"
#include "hls_math.h"

typedef ap_fixed<32,16> t_ap_fixed;


void gemm(  
		 t_ap_fixed alpha,
		 t_ap_fixed beta,
		 t_ap_fixed C[ 20 + 0][25 + 0],
		 t_ap_fixed A[ 20 + 0][30 + 0],
		 t_ap_fixed B[ 30 + 0][25 + 0])
{
  #pragma HLS top name=gemm

    const int ni = 20;
    const int nj = 25;
    const int nk = 30;

  int i, j, k;
L1:  for (i = 0; i < ni; i++) {
L2:    for (j = 0; j < nj; j++)
	C[i][j] *= beta;
L3:    for (k = 0; k < nk; k++) {
L4:       for (j = 0; j < nj; j++)
	  C[i][j] += alpha * A[i][k] * B[k][j];
    }
  }

}