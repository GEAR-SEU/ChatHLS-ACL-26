
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "heat-3d.h"

double A[10][10][10];
double B[10][10][10];

void init_array(int n,
                double A[10][10][10],
                double B[10][10][10])
{
    int i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                A[i][j][k] = B[i][j][k] = (double) (i + j + (n-k))* 10 / (n);
}

void print_array(int n, double A[10][10][10], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    fprintf(stderr, "begin dump: %s", "A");
    result << "==BEGIN DUMP_ARRAYS==\n";
    result << "begin dump: A";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) {
                if ((i * n * n + j * n + k) % 20 == 0) {
                    fprintf(stderr, "\n");
                    result << "\n";
                }
                fprintf(stderr, "%0.6lf ", (float)A[i][j][k]);
                result << std::setw(8) << std::setprecision(6) << std::fixed << (float)A[i][j][k] << " ";
            }

    fprintf(stderr, "\nend   dump: %s\n", "A");
    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "\nend   dump: A\n";
    result << "==END   DUMP_ARRAYS==\n";

    result.close();
}

int main(int argc, char** argv)
{
    int n = 10;
    int tsteps = 20;

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
        } else if (arg == "-t" && i + 1 < argc) {
            tsteps = std::stoi(argv[++i]);
        }
    }

    init_array(n, A, B);

    heat_3d(A, B);

    print_array(n, A, output_file);

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
