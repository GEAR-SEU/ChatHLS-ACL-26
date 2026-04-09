
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "syr2k.h"

double C[30][30];
double A[30][20];
double B[30][20];

void init_array(int n, int m,
                double *alpha,
                double *beta,
                double C[30][30],
                double A[30][20],
                double B[30][20])
{
    int i, j;

    *alpha = (double(1.5));
    *beta = (double(1.2));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            A[i][j] = (double) ((i*j+1)%n) / n;
            B[i][j] = (double) ((i*j+2)%m) / m;
        }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            C[i][j] = (double) ((i*j+3)%n) / m;
        }
}

void print_array(int n, double C[30][30], const std::string& filename)
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i * n + j) % 20 == 0) {
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
    int n = 30;
    int m = 20;

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
        } else if (arg == "-n" && i + 1 < argc) {
            n = std::stoi(argv[++i]);
        } else if (arg == "-m" && i + 1 < argc) {
            m = std::stoi(argv[++i]);
        }
    }

    double alpha;
    double beta;
    
    init_array(n, m, &alpha, &beta, C, A, B);

    kernel_syr2k(alpha, beta, C, A, B);

    print_array(n, C, output_file);

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
