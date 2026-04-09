
void kernel_syr2k(double alpha,double beta,double C[80][80],double A[80][60],double B[80][60])
{
  int i;
  int j;
  int k;
//BLAS PARAMS
//UPLO  = 'L'
//TRANS = 'N'
//A is NxM
//B is NxM
//C is NxN
  
  L1: for (i = 0; i < 80; i++) {
    L2: for (j = 0; j < 80; j++) {
      if (j <= i) {
        C[i][j] *= beta;
      }
    }

    L3: for (k = 0; k < 60; k++) {
      L4: for (j = 0; j < 80; j++) {
        if (j <= i) {
          C[i][j] += A[j][k] * alpha * B[i][k] + B[j][k] * alpha * A[i][k];
        }
      }
    }
  }
}
