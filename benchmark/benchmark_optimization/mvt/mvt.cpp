#include "ap_fixed.h"
#include "hls_math.h"

typedef ap_fixed<32,16> t_ap_fixed;


void mvt(
		t_ap_fixed x1[ 40 + 0],
		t_ap_fixed x2[ 40 + 0],
		t_ap_fixed y_1[ 40 + 0],
		t_ap_fixed y_2[ 40 + 0],
		t_ap_fixed A[ 40 + 0][40 + 0])
{
  #pragma HLS top name=mvt

    const int n = 40;

  int i, j;

  L1: for (i = 0; i < n; i++) {
    L2: for (j = 0; j < n; j++) {
      x1[i] = x1[i] + A[i][j] * y_1[j];
    }
  }

  L3: for (i = 0; i < n; i++) {
    L4: for (j = 0; j < n; j++) {
      x2[i] = x2[i] + A[j][i] * y_2[j];
    }
  }

}