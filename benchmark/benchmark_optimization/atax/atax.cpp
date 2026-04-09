#include "ap_fixed.h"
#include "hls_math.h"

typedef ap_fixed<32,16> t_ap_fixed;

void atax( 
		 t_ap_fixed A[ 38 + 0][42 + 0],
		 t_ap_fixed x[ 42 + 0],
		 t_ap_fixed y[ 42 + 0],
		 t_ap_fixed tmp[ 38 + 0])
{
  #pragma HLS top name=atax

    const int m = 38;
    const int n = 42;

  int i, j;

L1:  for (i = 0; i < n; i++)
      y[i] = 0;
      
L2:  for (i = 0; i < m; i++)
      {
        tmp[i] = (t_ap_fixed(0.0));
L3:      for (j = 0; j < n; j++)
	        tmp[i] = tmp[i] + A[i][j] * x[j];
L4:      for (j = 0; j < n; j++)
	        y[j] = y[j] + A[i][j] * tmp[i];
      } 
}