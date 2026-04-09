#include "ap_fixed.h"
#include "hls_math.h"

typedef ap_fixed<32,16> t_ap_fixed;


void bicg( 
		 t_ap_fixed A[ 42 + 0][38 + 0],
		 t_ap_fixed s[ 38 + 0],
		 t_ap_fixed q[ 42 + 0],
		 t_ap_fixed p[ 38 + 0],
		 t_ap_fixed r[ 42 + 0])
{
  #pragma HLS top name=bicg

    const int n = 42;
    const int m = 38;

  int i, j;

  L1: for (i = 0; i < m; i++)
    s[i] = 0;
  L2: for (i = 0; i < n; i++)
    {
      q[i] = (t_ap_fixed(0.0));
      L3: for (j = 0; j < m; j++)
	{
	  s[j] = s[j] + r[i] * A[i][j];
	  q[i] = q[i] + A[i][j] * p[j];
	}
    }
}
