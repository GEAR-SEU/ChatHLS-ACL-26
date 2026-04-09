#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include "2mm.h"


double tmp[ 16 + 0][18 + 0];
double A[ 16 + 0][22 + 0];
double B[ 22 + 0][18 + 0];
double C[ 18 + 0][24 + 0];
double D[ 16 + 0][24 + 0];


void init_array(int ni, int nj, int nk, int nl,
		double *alpha,
		double *beta,
		double A[ 16 + 0][22 + 0],
		double B[ 22 + 0][18 + 0],
		double C[ 18 + 0][24 + 0],
		double D[ 16 + 0][24 + 0])
{
  int i, j;

  *alpha = (double(1.5));
  *beta = (double(1.2));
  for (i = 0; i < ni; i++)
    for (j = 0; j < nk; j++)
      A[i][j] = (double) ((i*j+1) % ni) / ni;
  for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
      B[i][j] = (double) (i*(j+1) % nj) / nj;
  for (i = 0; i < nj; i++)
    for (j = 0; j < nl; j++)
      C[i][j] = (double) ((i*(j+3)+1) % nl) / nl;
  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++)
      D[i][j] = (double) (i*(j+2) % nk) / nk;
}


// void print_array(int ni, int nl,
// 		 double D[ 16 + 0][24 + 0])
// {
//   int i, j;

//   fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
//   fprintf(stderr, "begin dump: %s", "D");
//   for (i = 0; i < ni; i++)
//     for (j = 0; j < nl; j++) {
// 	if ((i * ni + j) % 20 == 0) fprintf (stderr, "\n");
// 	fprintf (stderr, "%0.6lf ", (float)D[i][j]);
//     }
//   fprintf(stderr, "\nend   dump: %s\n", "D");
//   fprintf(stderr, "==END   DUMP_ARRAYS==\n");
// }

int print_array(int ni, int nl, double D[ 16 + 0][24 + 0]) {
    FILE *file;
    float expected_value;
    int mismatch_found = 0;

    // Open the reference file for reading
    file = fopen("./tb_data_hls.txt", "r");
    if (!file) {
        fprintf(stderr, "Error opening file tb_data.txt\n");
        return 1; // Return 1 if file can't be opened
    }
    // Skip the header lines
    char buffer[256];
    fgets(buffer, sizeof(buffer), file); // Skip "==BEGIN DUMP_ARRAYS=="
    fgets(buffer, sizeof(buffer), file); // Skip "begin dump: D"

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    fprintf(stderr, "begin dump: %s", "D");

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nl; j++) {
            if ((i * ni + j) % 20 == 0) fprintf(stderr, "\n");
            
            // Print current value
            fprintf(stderr, "%0.6lf ", (float)D[i][j]);

            // Read expected value from file
            if (fscanf(file, "%f", &expected_value) != 1) {
                fprintf(stderr, "\nError reading expected value from file\n");
                fclose(file);
                return 1; // Return 1 if reading fails
            }

            // Compare current value with expected value
            if (fabs ((float)D[i][j] - expected_value) > 0.000001) {
                mismatch_found = 1;
                //fprintf("Mismatch: %f != %f\n", (float)D[i][j], expected_value);
                fprintf(stderr, "\n Mismatch: %f != %f \n", (float)D[i][j], expected_value);
            }
        }
    }
    fgets(buffer, sizeof(buffer), file); // Skip "end dump: D"
    fgets(buffer, sizeof(buffer), file); // Skip "==END DUMP_ARRAYS=="

    fprintf(stderr, "\nend   dump: %s\n", "D");
    fprintf(stderr, "==END   DUMP_ARRAYS==\n");

    fclose(file);
    return mismatch_found ? 1 : 0; // Return 1 if mismatch found, otherwise return 0
}

int main(int argc, char** argv)
{

  int ni = 16;
  int nj = 18;
  int nk = 22;
  int nl = 24;


  double alpha;
  double beta;
  
  
  init_array (ni, nj, nk, nl, &alpha, &beta,
	      A,
	      B,
	      C,
	      D);


  kernel_2mm (
	      alpha, beta,
	      tmp,
	      A,
	      B,
	      C,
	      D);


  return print_array(ni, nl, D);


  //return 0;
}