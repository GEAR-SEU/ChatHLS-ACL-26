#include "zerolow.h"
#include <cstdio>

#define N 20  // Number of simulation cycles

struct stats_t {
    int errors;
    int errortime;
    int errors_zero;
    int errortime_zero;
    int clocks;
};

int main() {
    stats_t stats1 = {0, -1, 0, -1, 0};

    bool zero_ref = false;  // Reference output is always LOW
    bool zero_dut;

    // Simulate clock cycles (both rising and falling edges)
    for (int time = 0; time < N; time++) {
        // Simulate rising edge
        stats1.clocks++;
        zerolow(&zero_dut);

        // Compare DUT output with reference output
        bool tb_match = (zero_ref == zero_dut);
        if (!tb_match) {
            if (stats1.errors == 0) stats1.errortime = time;
            stats1.errors++;
        }
        if (zero_ref != zero_dut) {
            if (stats1.errors_zero == 0) stats1.errortime_zero = time;
            stats1.errors_zero++;
        }

        // Simulate falling edge
        stats1.clocks++;
        zerolow(&zero_dut);

        // Compare DUT output with reference output
        tb_match = (zero_ref == zero_dut);
        if (!tb_match) {
            if (stats1.errors == 0) stats1.errortime = time;
            stats1.errors++;
        }
        if (zero_ref != zero_dut) {
            if (stats1.errors_zero == 0) stats1.errortime_zero = time;
            stats1.errors_zero++;
        }
    }

    // Final reporting
    if (stats1.errors_zero) {
        printf("Hint: Output 'zero' has %d mismatches. First mismatch occurred at time %d.\n",
               stats1.errors_zero, stats1.errortime_zero);
    } else {
        printf("Hint: Output 'zero' has no mismatches.\n");
    }

    printf("Hint: Total mismatched samples is %d out of %d samples\n", stats1.errors, stats1.clocks);
    printf("Simulation finished at %d cycles\n", stats1.clocks);
    printf("Mismatches: %d in %d samples\n", stats1.errors, stats1.clocks);

    return 0;
}
