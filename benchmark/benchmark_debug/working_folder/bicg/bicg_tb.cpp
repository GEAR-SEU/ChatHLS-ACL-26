
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "bicg.h"

t_ap_fixed A[42][38];
t_ap_fixed s[38];
t_ap_fixed q[42];
t_ap_fixed p[38];
t_ap_fixed r[42];

void init_array(int m, int n, t_ap_fixed A[42][38], t_ap_fixed r[42], t_ap_fixed p[38])
{
    int i, j;

    for (i = 0; i < m; i++)
        p[i] = (t_ap_fixed)(i % m) / m;
    for (i = 0; i < n; i++) {
        r[i] = (t_ap_fixed)(i % n) / n;
        for (j = 0; j < m; j++)
            A[i][j] = (t_ap_fixed) (i*(j+1) % n)/n;
    }
}

void print_array(int m, int n, t_ap_fixed s[38], t_ap_fixed q[42], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    result << "==BEGIN DUMP_ARRAYS==\n";

    fprintf(stderr, "begin dump: %s", "s");
    result << "begin dump: s";
    for (int i = 0; i < m; i++) {
        if (i % 20 == 0) {
            fprintf(stderr, "\n");
            result << "\n";
        }
        fprintf(stderr, "%0.6lf ", (float)s[i]);
        result << std::setw(8) << std::setprecision(6) << std::fixed << (float)s[i] << " ";
    }
    fprintf(stderr, "\nend   dump: %s\n", "s");
    result << "\nend   dump: s\n";

    fprintf(stderr, "begin dump: %s", "q");
    result << "begin dump: q";
    for (int i = 0; i < n; i++) {
        if (i % 20 == 0) {
            fprintf(stderr, "\n");
            result << "\n";
        }
        fprintf(stderr, "%0.6lf ", (float)q[i]);
        result << std::setw(8) << std::setprecision(6) << std::fixed << (float)q[i] << " ";
    }
    fprintf(stderr, "\nend   dump: %s\n", "q");
    result << "\nend   dump: q\n";

    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "==END   DUMP_ARRAYS==\n";

    result.close();
}

int main(int argc, char** argv)
{
    int n = 42;
    int m = 38;

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

    init_array(m, n, A, r, p);

    kernel_bicg(A, s, q, p, r);

    print_array(m, n, s, q, output_file);

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
