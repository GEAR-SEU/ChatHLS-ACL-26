#include "ap_fixed.h"
#include "hls_math.h"

typedef ap_fixed<32,16> t_ap_fixed;


void covariance( 
		       t_ap_fixed float_n,
		       t_ap_fixed data[ 32 + 0][28 + 0],
		       t_ap_fixed cov[ 28 + 0][28 + 0],
		       t_ap_fixed mean[ 28 + 0])
{
  #pragma HLS top name=covariance

    const int n = 32;
    const int m = 28;

  int i, j, k;

L1:  for (j = 0; j < m; j++)
    {
      mean[j] = (t_ap_fixed(0.0));
L2:      for (i = 0; i < n; i++)
        mean[j] += data[i][j];
      mean[j] /= float_n;
    }

L3:  for (i = 0; i < n; i++)
L4:    for (j = 0; j < m; j++)
      data[i][j] -= mean[j];

L5:  for (i = 0; i < m; i++)
L6:    for (j = i; j < m; j++)
      {
        cov[i][j] = (t_ap_fixed(0.0));
L7:        for (k = 0; k < n; k++)
	  cov[i][j] += data[k][i] * data[k][j];
        cov[i][j] /= (float_n - (t_ap_fixed(1.0)));
        cov[j][i] = cov[i][j];
      }

}
