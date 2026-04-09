#include "gesummv.h"
#include "ap_fixed.h"
#include "hls_math.h"

void kernel_gesummv(
                    t_ap_fixed alpha,
                    t_ap_fixed beta,
                    t_ap_fixed A[30][30],
                    t_ap_fixed B[30][30],
                    t_ap_fixed tmp[30],
                    t_ap_fixed x[30],
                    t_ap_fixed y[30])
{
  #pragma HLS top name=kernel_gesummv

    const int n = 30;

    int i, j;

    #pragma HLS ARRAY_PARTITION variable=x complete dim=1

    #pragma HLS PIPELINE II=1 
    L1:  for (i = 0; i < n; i++)
    {
             #pragma HLS pipeline II=1
        t_ap_fixed sum_tmp = 0;
        t_ap_fixed sum_y = 0;

        #pragma HLS PIPELINE II=1 
        L2:      for (j = 0; j < n; j++)
        {
                #pragma HLS PIPELINE II=1 
            sum_tmp += A[i][j] * x[j];
            sum_y += B[i][j] * x[j];
        }

        tmp[i] = sum_tmp;
        y[i] = alpha * sum_tmp + beta * sum_y;
    }
}
