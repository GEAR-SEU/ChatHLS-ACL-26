
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "nussinov.h"

char seq[60];
int table[60][60];

void init_array(int n, char seq[60], int table[60][60])
{
    for (int i = 0; i < n; i++) {
        seq[i] = (char)((i+1)%4);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            table[i][j] = 0;
}

void print_array(int n, int table[60][60], const std::string& filename)
{
    std::ofstream result(filename);
    
    if (!result.is_open()) {
        fprintf(stderr, "Error: Could not open file %s for writing\n", filename.c_str());
        exit(1);
    }

    fprintf(stderr, "==BEGIN DUMP_ARRAYS==\n");
    fprintf(stderr, "begin dump: %s", "table");
    result << "==BEGIN DUMP_ARRAYS==\n";
    result << "begin dump: table";

    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (t % 20 == 0) {
                fprintf(stderr, "\n");
                result << "\n";
            }
            fprintf(stderr, "%d ", table[i][j]);
            result << std::setw(3) << table[i][j] << " ";
            t++;
        }
    }

    fprintf(stderr, "\nend   dump: %s\n", "table");
    fprintf(stderr, "==END   DUMP_ARRAYS==\n");
    result << "\nend   dump: table\n";
    result << "==END   DUMP_ARRAYS==\n";

    result.close();
}

int main(int argc, char** argv)
{
    int n = 60;

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

    init_array(n, seq, table);

    kernel_nussinov(seq, table);

    print_array(n, table, output_file);

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
