#include "bicg.h"

#include "ap_fixed.h"
#include "hls_math.h"

void kernel_bicg( 
    		 t_ap_fixed A[42][38],
    		 t_ap_fixed s[38],
    		 t_ap_fixed q[42],
    		 t_ap_fixed p[38],
    		 t_ap_fixed r[42])
{
  #pragma HLS top name=kernel_bicg

  #pragma HLS ARRAY_PARTITION variable=s complete dim=1
  #pragma HLS ARRAY_PARTITION variable=p complete dim=1
  #pragma HLS ARRAY_PARTITION variable=A cyclic factor=5 dim=2 

  const int n = 42;
  const int m = 38;

  int i, j;

  L1: for (i = 0; i < m; i++)
    {
      #pragma HLS PIPELINE II=1
      s[i] = 0;
    }

  L2: for (i = 0; i < n; i++)
    {
      q[i] = (t_ap_fixed(0.0));
      L3: for (j = 0; j < m; j++)
        {
          #pragma HLS PIPELINE II=1
    	  s[j] = s[j] + r[i] * A[i][j];
    	  q[i] = q[i] + A[i][j] * p[j];
        }
    }
}
