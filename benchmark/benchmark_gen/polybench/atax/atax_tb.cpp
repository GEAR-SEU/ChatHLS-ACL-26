
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "atax.h"

double A[38][42];
double x[42];
double y[42];
double tmp[38];

void init_array(int m, int n, double A[38][42], double x[42])
{
    int i, j;
    double fn = (double)n;

    for (i = 0; i < n; i++)
        x[i] = (double(1.0)) + ((double(i)) / fn);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            A[i][j] = (double)(double(((i+j) % n))) / (double(5.0)*double(m));
}

void print_array(int n, double y[42], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    fprintf(stderr, "begin dump: %s", "y");
    result << "==BEGIN DUMP_ARRAYS==\n";
    result << "begin dump: y";
    
    for (int i = 0; i < n; i++) {
        if (i % 20 == 0) {
            fprintf(stderr, "\n");
            result << "\n";
        }
        fprintf(stderr, "%0.6lf ", (float)y[i]);
        result << std::setw(8) << std::setprecision(6) << std::fixed << (float)y[i] << " ";
    }
    
    fprintf(stderr, "\nend   dump: %s\n", "y");
    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "\nend   dump: y\n";
    result << "==END   DUMP_ARRAYS==\n";

    result.close();
}

int main(int argc, char** argv)
{
    int m = 38;
    int n = 42;

    // Default filenames
    std::string output_file = "./result.dat";
    std::string golden_file = "./tb_data_hls.txt";

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-o" && i + 1 < argc) {
            output_file = argv[++i];
        } else if (arg == "-g" && i + 1 < argc) {
            golden_file = argv[++i];
        }
    }

    init_array(m, n, A, x);

    kernel_atax(A, x, y, tmp);

    print_array(n, y, output_file);

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
