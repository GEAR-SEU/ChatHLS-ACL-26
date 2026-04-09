
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "gemm.h"

double C[20][25];
double A[20][30];
double B[30][25];

void init_array(int ni, int nj, int nk,
                double *alpha,
                double *beta,
                double C[20][25],
                double A[20][30],
                double B[30][25])
{
    int i, j;

    *alpha = (double(1.5));
    *beta = (double(1.2));
    for (i = 0; i < ni; i++)
        for (j = 0; j < nj; j++)
            C[i][j] = (double) ((i*j+1) % ni) / ni;
    for (i = 0; i < ni; i++)
        for (j = 0; j < nk; j++)
            A[i][j] = (double) (i*(j+1) % nk) / nk;
    for (i = 0; i < nk; i++)
        for (j = 0; j < nj; j++)
            B[i][j] = (double) (i*(j+2) % nj) / nj;
}

void print_array(int ni, int nj, double C[20][25], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    fprintf(stderr, "begin dump: %s", "C");
    result << "==BEGIN DUMP_ARRAYS==\n";
    result << "begin dump: C";

    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nj; j++) {
            if ((i * ni + j) % 20 == 0) {
                fprintf(stderr, "\n");
                result << "\n";
            }
            fprintf(stderr, "%0.6lf ", (float)C[i][j]);
            result << std::setw(8) << std::setprecision(6) << std::fixed << (float)C[i][j] << " ";
        }
    }

    fprintf(stderr, "\nend   dump: %s\n", "C");
    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "\nend   dump: C\n";
    result << "==END   DUMP_ARRAYS==\n";

    result.close();
}

int main(int argc, char** argv)
{
    int ni = 20;
    int nj = 25;
    int nk = 30;

    // Default filenames
    std::string output_file = "result.dat";
    std::string golden_file = "tb_data_hls.txt";

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-o" && i + 1 < argc) {
            output_file = argv[++i];
        } else if (arg == "-g" && i + 1 < argc) {
            golden_file = argv[++i];
        }
    }

    double alpha;
    double beta;
    
    init_array(ni, nj, nk, &alpha, &beta, C, A, B);

    kernel_gemm(alpha, beta, C, A, B);

    print_array(ni, nj, C, output_file);

    // Compare the results file with the golden results
    std::string diff_command = "diff --brief -w " + output_file + " " + golden_file;
    int retval = system(diff_command.c_str());
    
    if (retval != 0) {
        fprintf(stderr, "Test failed !!!\n"); 
        retval = 1;
    } else {
        fprintf(stderr, "Test passed !\n");
    }

    return retval;
}
