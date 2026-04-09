void kernel_symm(double alpha,double beta,double C[60][80],double A[60][60],double B[60][80])
{
  int i;
  int j;
  int k;

  L1: for (i = 0; i < 60; i++) {
    L2: for (j = 0; j < 80; j++) {
      double temp2 = ((double )0);
      L3: for (k = 0; k < 60; k++) {
        if (k < i) {
          C[k][j] += alpha * B[i][j] * A[i][k];
          temp2 += B[k][j] * A[i][k];
        }
      }
      C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2;
    }
  }
}
