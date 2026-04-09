
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "trmm.h"

double A[20][20];
double B[20][30];

void init_array(int m, int n,
                double *alpha,
                double A[20][20],
                double B[20][30])
{
    int i, j;

    *alpha = (double(1.5));
    for (i = 0; i < m; i++) {
        for (j = 0; j < i; j++) {
            A[i][j] = (double)((i+j) % m)/m;
        }
        A[i][i] = (double(1.0));
        for (j = 0; j < n; j++) {
            B[i][j] = (double)((n+(i-j)) % n)/n;
        }
    }
}

void print_array(int m, int n, double B[20][30], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    fprintf(stderr, "begin dump: %s", "B");
    result << "==BEGIN DUMP_ARRAYS==\n";
    result << "begin dump: B";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i * m + j) % 20 == 0) {
                fprintf(stderr, "\n");
                result << "\n";
            }
            fprintf(stderr, "%0.6lf ", (float)B[i][j]);
            result << std::setw(8) << std::setprecision(6) << std::fixed << (float)B[i][j] << " ";
        }
    }

    fprintf(stderr, "\nend   dump: %s\n", "B");
    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "\nend   dump: B\n";
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
    
    init_array(m, n, &alpha, A, B);

    kernel_trmm(alpha, A, B);

    print_array(m, n, B, output_file);

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
