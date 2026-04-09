
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "symm.h"

double C[20][30];
double A[20][20];
double B[20][30];

void init_array(int m, int n,
                double *alpha,
                double *beta,
                double C[20][30],
                double A[20][20],
                double B[20][30])
{
    int i, j;

    *alpha = (double(1.5));
    *beta = (double(1.2));
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            C[i][j] = (double) ((i+j) % 100) / m;
            B[i][j] = (double) ((n+i-j) % 100) / m;
        }
    for (i = 0; i < m; i++) {
        for (j = 0; j <=i; j++)
            A[i][j] = (double) ((i+j) % 100) / m;
        for (j = i+1; j < m; j++)
            A[i][j] = -999;
    }
}

void print_array(int m, int n, double C[20][30], const std::string& filename)
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

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i * m + j) % 20 == 0) {
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
    int m = 20;
    int n = 30;

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
        } else if (arg == "-m" && i + 1 < argc) {
            m = std::stoi(argv[++i]);
        } else if (arg == "-n" && i + 1 < argc) {
            n = std::stoi(argv[++i]);
        }
    }

    double alpha;
    double beta;
    
    init_array(m, n, &alpha, &beta, C, A, B);

    kernel_symm(alpha, beta, C, A, B);

    print_array(m, n, C, output_file);

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
