#include "computez.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

struct stats_t {
    int errors = 0;
    int errortime = -1;
    int errors_z = 0;
    int errortime_z = -1;
    int clocks = 0;
};

int main() {
    stats_t stats1;

    const int N = 101;  // Number of simulation cycles

    input_t x;
    input_t y;
    output_t z_ref;
    output_t z_dut;

    std::ofstream wavefile("wave.txt");  // Simulating wave logging

    // Seed random number generator
    srand(0);

    // Simulation loop
    for (int clk = 0; clk < N; clk++) {
        // Generate random inputs (equivalent to Verilog's $random % 4)
        int rand_val = rand() % 4;
        x = rand_val & 1;
        y = (rand_val >> 1) & 1;

        // Reference model calculation
        z_ref = (x ^ y) & x;

        // Device Under Test (DUT)
        computez(x, y, &z_dut);

        // Log wave data
        wavefile << "Time: " << clk << ", x: " << x << ", y: " << y << ", z_ref: " << z_ref << ", z_dut: " << z_dut << std::endl;

        // Verification
        bool tb_match = (z_ref == z_dut);

        stats1.clocks++;

        if (!tb_match) {
            if (stats1.errors == 0) stats1.errortime = clk;
            stats1.errors++;
        }

        if (z_ref != z_dut) {
            if (stats1.errors_z == 0) stats1.errortime_z = clk;
            stats1.errors_z++;
        }
    }

    // Final reporting
    if (stats1.errors_z) {
        std::cout << "Hint: Output 'z' has " << stats1.errors_z
                  << " mismatches. First mismatch occurred at time " << stats1.errortime_z << ".\n";
    } else {
        std::cout << "Hint: Output 'z' has no mismatches.\n";
    }

    std::cout << "Hint: Total mismatched samples is " << stats1.errors
              << " out of " << stats1.clocks << " samples\n";
    std::cout << "Simulation finished at " << stats1.clocks << " cycles\n";
    std::cout << "Mismatches: " << stats1.errors << " in " << stats1.clocks << " samples\n";

    wavefile.close();
    return 0;
}
