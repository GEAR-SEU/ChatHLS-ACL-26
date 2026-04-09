#include<stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 32
#define M 32
#define P 32

void matmul(int A[N][M], int B[M][P], int AB[N][P]) {
  row: for(int i = 0; i < N; ++i) {
    col: for(int j = 0; j < P; ++j) {
      int ABij = 0;
    product: for(int k = 0; k < M; ++k) {
        ABij += A[i][k] * B[k][j];
      }
      AB[i][j] = ABij;
    }
  }
}
