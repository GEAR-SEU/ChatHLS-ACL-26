#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <string>
#include "3mm.h"

void init_array(int ni, int nj, int nk, int nl, int nm,
		t_ap_fixed A[ 16 + 0][20 + 0],
		t_ap_fixed B[ 20 + 0][18 + 0],
		t_ap_fixed C[ 18 + 0][24 + 0],
		t_ap_fixed D[ 24 + 0][22 + 0])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nk; j++)
      A[i][j] = (t_ap_fixed) ((i*j+1) % ni) / (5*ni);
  for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
      B[i][j] = (t_ap_fixed) ((i*(j+1)+2) % nj) / (5*nj);
  for (i = 0; i < nj; i++)
    for (j = 0; j < nm; j++)
      C[i][j] = (t_ap_fixed) (i*(j+3) % nl) / (5*nl);
  for (i = 0; i < nm; i++)
    for (j = 0; j < nl; j++)
      D[i][j] = (t_ap_fixed) ((i*(j+2)+2) % nk) / (5*nk);
}


void print_array(int ni, int nl, t_ap_fixed G[16][22], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    fprintf(stderr, "begin dump: %s", "G");
    result << "==BEGIN DUMP_ARRAYS==\n";
    result << "begin dump: G";
    
    for (int i = 0; i < ni; i++) {
        for (int j = 0; j < nl; j++) {
            if ((i * ni + j) % 20 == 0) {
                fprintf(stderr, "\n");
                result << "\n";
            }
            fprintf(stderr, "%0.6lf ", (float)G[i][j]);
            result << std::setw(8) << std::setprecision(6) << std::fixed << (float)G[i][j] << " ";
        }
    }
    
    fprintf(stderr, "\nend   dump: %s\n", "G");
    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "\nend   dump: G\n";
    result << "==END   DUMP_ARRAYS==\n";

    result.close();
}

int main(int argc, char** argv)
{
    int ni = 16, nj = 18, nk = 20, nl = 22, nm = 24;
    t_ap_fixed E[16][18], F[18][22], G[16][22];
    t_ap_fixed A[16][20], B[20][18], C[18][24], D[24][22];

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

    // Initialize arrays
    init_array(ni, nj, nk, nl, nm, A, B, C, D);

    // Call the kernel
    kernel_3mm(E, A, B, F, C, D, G);

    // Save the results and print to console
    print_array(ni, nl, G, output_file);

    // Compare the results file with the golden results
    std::string diff_command = "diff --brief -w " + output_file + " " + golden_file;
    int retval = system(diff_command.c_str());
    
    if (retval != 0) {
        fprintf(stderr, "Test failed  !!!\n"); 
        retval = 1;
    } else {
        fprintf(stderr, "Test passed !\n");
    }

    // Return 0 if the test passes
    return retval;
}