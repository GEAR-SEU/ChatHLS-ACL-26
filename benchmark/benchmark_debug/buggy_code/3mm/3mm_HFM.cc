


#include "hls_math.h"

void kernel_3mm(    
        t_ap_fixed E[16][18],
        t_ap_fixed A[16][20],
        t_ap_fixed B[20][18],
        t_ap_fixed F[18][22],
        t_ap_fixed C[18][24],
        t_ap_fixed D[24][22],
        t_ap_fixed G[16][22])
{
  #pragma HLS top name=kernel_3mm

    const int ni = 16;
    const int nj = 18;
    const int nk = 20;
    const int nl = 22;
    const int nm = 24;

  int i, j, k;

  #pragma HLS array_partition variable=A complete dim=2
  #pragma HLS array_partition variable=B complete dim=1

  L1: for (i = 0; i < ni; i++)
  {
    L2: for (j = 0; j < nj; j++)
    {
        E[i][j] = (t_ap_fixed)(0.0);
        #pragma HLS pipeline II=1
        L3: for (k = 0; k < nk; ++k)
        {
          E[i][j] += A[i][k] * B[k][j];
        }
    }
  }

  #pragma HLS array_partition variable=C complete dim=2
  #pragma HLS array_partition variable=D complete dim=1

  L4: for (i = 0; i < nj; i++)
  {
    L5: for (j = 0; j < nl; j++)
    {
        F[i][j] = (t_ap_fixed)(0.0);
        #pragma HLS pipeline II=1
        L6: for (k = 0; k < nm; ++k)
        {
          F[i][j] += C[i][k] * D[k][j];
        }
    }
  }

  #pragma HLS array_partition variable=E complete dim=2
  #pragma HLS array_partition variable=F complete dim=1

  L7: for (i = 0; i < ni; i++)
  {
    L8: for (j = 0; j < nl; j++)
    {
        G[i][j] = (t_ap_fixed)(0.0);
        #pragma HLS pipeline II=1
        L9: for (k = 0; k < nj; ++k)
        {
          G[i][j] += E[i][k] * F[k][j];
        }
    }
  }

}
