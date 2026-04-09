#include "dff.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

struct stats_t {
    int errors = 0;
    int errortime = -1;
    int errors_q = 0;
    int errortime_q = -1;
    int clocks = 0;
};

int main() {
    stats_t stats1;

    const int N = 10;  // Number of simulation cycles
    const int TIMEOUT = 100;

    input_t clk = 0;
    input_t d;
    output_t q_ref = 0;
    output_t q_dut = 0;

    // Open VCD file for waveform dumping (simulated)
    std::ofstream vcdfile("wave.vcd");
    vcdfile << "$dumpvars\n";

    // Seed random number generator
    srand(0);

    // Simulation loop
    for (int time = 0; time < TIMEOUT; time++) {
        // Toggle clock every 5 time units
        if (time % 5 == 0) {
            clk = !clk;
        }

        // Generate random input 'd' on clock edges
        if (time % 5 == 0 || time % 5 == 2) {
            d = rand() % 2;
        }

        // Reference D Flip-Flop behavior
        if (clk) {  // Positive edge triggered
            q_ref = d;
        }

        // Device Under Test (DUT)
        dff(d, clk, &q_dut);

        // Log wave data to VCD file (simulated)
        vcdfile << "# " << time << "\n";
        vcdfile << "b" << clk << " clk\n";
        vcdfile << "b" << d << " d\n";
        vcdfile << "b" << q_ref << " q_ref\n";
        vcdfile << "b" << q_dut << " q_dut\n";

        // Verification
        bool tb_match = (q_ref == q_dut);

        stats1.clocks++;

        if (!tb_match) {
            if (stats1.errors == 0) stats1.errortime = time;
            stats1.errors++;
        }

        if (q_ref != q_dut) {
            if (stats1.errors_q == 0) stats1.errortime_q = time;
            stats1.errors_q++;
        }

        // Timeout check
        if (stats1.clocks >= N) {
            std::cout << "Simulation finished at " << time << " time units\n";
            break;
        }
    }

    // Final reporting
    if (stats1.errors_q) {
        std::cout << "Hint: Output 'q' has " << stats1.errors_q
                  << " mismatches. First mismatch occurred at time " << stats1.errortime_q << ".\n";
    } else {
        std::cout << "Hint: Output 'q' has no mismatches.\n";
    }

    std::cout << "Hint: Total mismatched samples is " << stats1.errors
              << " out of " << stats1.clocks << " samples\n";
    std::cout << "Mismatches: " << stats1.errors << " in " << stats1.clocks << " samples\n";

    vcdfile << "$end\n";
    vcdfile.close();
    return 0;
}
