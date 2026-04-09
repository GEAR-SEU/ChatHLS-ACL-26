
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "mvt.h"

double A[40][40];
double x1[40];
double x2[40];
double y_1[40];
double y_2[40];

void init_array(int n,
                double x1[40],
                double x2[40],
                double y_1[40],
                double y_2[40],
                double A[40][40])
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        x1[i] = (double) (i % n) / n;
        x2[i] = (double) ((i + 1) % n) / n;
        y_1[i] = (double) ((i + 3) % n) / n;
        y_2[i] = (double) ((i + 4) % n) / n;
        for (j = 0; j < n; j++)
            A[i][j] = (double) (i*j % n) / n;
    }
}

void print_array(int n, double x1[40], double x2[40], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    result << "==BEGIN DUMP_ARRAYS==\n";

    fprintf(stderr, "begin dump: %s", "x1");
    result << "begin dump: x1";
    for (int i = 0; i < n; i++) {
        if (i % 20 == 0) {
            fprintf(stderr, "\n");
            result << "\n";
        }
        fprintf(stderr, "%0.6lf ", (float)x1[i]);
        result << std::setw(8) << std::setprecision(6) << std::fixed << (float)x1[i] << " ";
    }
    fprintf(stderr, "\nend   dump: %s\n", "x1");
    result << "\nend   dump: x1\n";

    fprintf(stderr, "begin dump: %s", "x2");
    result << "begin dump: x2";
    for (int i = 0; i < n; i++) {
        if (i % 20 == 0) {
            fprintf(stderr, "\n");
            result << "\n";
        }
        fprintf(stderr, "%0.6lf ", (float)x2[i]);
        result << std::setw(8) << std::setprecision(6) << std::fixed << (float)x2[i] << " ";
    }
    fprintf(stderr, "\nend   dump: %s\n", "x2");
    result << "\nend   dump: x2\n";

    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "==END   DUMP_ARRAYS==\n";

    result.close();
}

int main(int argc, char** argv)
{
    int n = 40;

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
        }
    }

    init_array(n, x1, x2, y_1, y_2, A);

    kernel_mvt(x1, x2, y_1, y_2, A);

    print_array(n, x1, x2, output_file);

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
