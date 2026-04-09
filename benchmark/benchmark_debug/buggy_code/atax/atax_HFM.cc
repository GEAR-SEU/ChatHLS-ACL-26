
#include "hls_math.h"  

void kernel_atax( 
         t_ap_fixed A[38][42],
         t_ap_fixed x[42],
         t_ap_fixed y[42],
         t_ap_fixed tmp[38])
{
#pragma HLS top name=kernel_atax

#pragma HLS array_partition variable=x cyclic factor=7 dim=1
#pragma HLS array_partition variable=A cyclic factor=7 dim=2

    const int m = 38;
    const int n = 42;

    int i, j;

    L1: for (i = 0; i < n; i++)
    #pragma HLS pipeline
        y[i] = 0;

    L2: for (i = 0; i < m; i++)
    {
    #pragma HLS pipeline
        t_ap_fixed tmp_acc = 0;

        L3: for (j = 0; j < n; j++)
        #pragma HLS unroll factor=7
            tmp_acc += A[i][j] * x[j];

        tmp[i] = tmp_acc;

        L4: for (j = 0; j < n; j++)
        #pragma HLS pipeline
            y[j] += A[i][j] * tmp_acc;
    }
}
