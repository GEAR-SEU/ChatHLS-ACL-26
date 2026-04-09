#include "counter.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    bool reset;
    ap_uint<4> q;

    std::ofstream result_file("result.dat");

    // Initialize reset
    reset = true;

    // Simulate 20 clock cycles
    for (int cycle = 0; cycle < 20; ++cycle) {
        // Manage reset signal based on the test scenario
        if (cycle == 2) {
            reset = false; // Release reset after two cycles
        } else if (cycle == 17) {
            reset = false; // Ensure reset is inactive before re-asserting
        } else if (cycle == 18) {
            reset = true;  // Assert reset at cycle 18
        } else if (cycle == 19) {
            reset = false; // Release reset at cycle 19
        }

        // Call the counter function (simulating one clock cycle)
        counter(reset, q);

        // Write the output to the result file
        result_file << q.to_uint() << std::endl;
    }

    result_file.close();

    // Compare the generated results with the golden results
    int retval = system("diff --brief -w result.dat result_golden.dat");

    if (retval != 0) {
        std::cout << "Test failed  !!!" << std::endl; 
        retval = 1;
    } else {
        std::cout << "Test passed !" << std::endl;
    }

    return retval;
}
