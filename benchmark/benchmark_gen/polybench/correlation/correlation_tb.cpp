
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "correlation.h"

double data[32][28];
double corr[28][28];
double mean[28];
double stddev[28];

void init_array(int m, int n, double *float_n, double data[32][28])
{
    int i, j;

    *float_n = double(32.0);

    for (i = 0; i < 32; i++)
        for (j = 0; j < 28; j++)
            data[i][j] = (double)(double(i*j)/double(28.0)) + double(i);
}

void print_array(int m, double corr[28][28], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    fprintf(stderr, "begin dump: %s", "corr");
    result << "==BEGIN DUMP_ARRAYS==\n";
    result << "begin dump: corr";

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if ((i * m + j) % 20 == 0) {
                fprintf(stderr, "\n");
                result << "\n";
            }
            fprintf(stderr, "%0.6lf ", (float)corr[i][j]);
            result << std::setw(8) << std::setprecision(6) << std::fixed << (float)corr[i][j] << " ";
        }
    }

    fprintf(stderr, "\nend   dump: %s\n", "corr");
    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "\nend   dump: corr\n";
    result << "==END   DUMP_ARRAYS==\n";

    result.close();
}

int main(int argc, char** argv)
{
    int n = 32;
    int m = 28;

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

    double float_n;
    
    init_array(m, n, &float_n, data);

    correlation(float_n, data, corr, mean, stddev);

    print_array(m, corr, output_file);

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
