#include "covariance.h"

#include "ap_fixed.h"
#include "hls_math.h"

void kernel_covariance( 
		       t_ap_fixed float_n,
		       t_ap_fixed data[32][28],
		       t_ap_fixed cov[28][28],
		       t_ap_fixed mean[28])
{
  #pragma HLS top name=kernel_covariance

    const int n = 32;
    const int m = 28;

  int i, j, k;

  #pragma HLS ARRAY_PARTITION variable=mean complete dim=1
  #pragma HLS ARRAY_PARTITION variable=data cyclic factor=8 dim=1
  #pragma HLS ARRAY_PARTITION variable=data cyclic factor=7 dim=2
  #pragma HLS ARRAY_PARTITION variable=cov cyclic factor=7 dim=1

L1:  for (j = 0; j < m; j++)
    {
      #pragma HLS PIPELINE
      mean[j] = (t_ap_fixed)(0.0);
L2:      for (i = 0; i < n; i++)
        mean[j] += data[i][j];
      mean[j] /= float_n;
    }

L3:  for (i = 0; i < n; i++)
    {
      #pragma HLS PIPELINE
      #pragma HLS UNROLL
L4:      for (j = 0; j < m; j++)
        data[i][j] -= mean[j];
    }

L5:  for (i = 0; i < m; i++)
    {
      #pragma HLS PIPELINE
L6:      for (j = i; j < m; j++)
        {
          cov[i][j] = (t_ap_fixed)(0.0);
L7:          for (k = 0; k < n; k++)
            cov[i][j] += data[k][i] * data[k][j];
          cov[i][j] /= (float_n - (t_ap_fixed)(1.0));
          cov[j][i] = cov[i][j];
        }
    }

}
