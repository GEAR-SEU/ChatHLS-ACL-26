#include "popcount.h"
#include <iostream>
#include <cstdlib>   // For rand() function
#include <ctime>     // For seeding rand()
#include <cstring>   // For memset()

int main() {
    // Seed the random number generator

    din_t in;
    dout_t out;
    dout_t expected_out;

    int errors = 0;
    int total_tests = 0;

    // Test with all possible 3-bit inputs (0 to 7)
    for (int i = 0; i < 30; i++) {
        in = i;

        // Call the popcount function
        popcount(in, &out);

        // Compute expected output
        expected_out = (in[0] + in[1] + in[2]);

        // Compare the output with the expected value
        if (out != expected_out) {
            std::cout << "Mismatch at input " << in << ": Expected "
                      << expected_out << ", Got " << out << std::endl;
            errors++;
        }

        total_tests++;
    }
    // Display the test results
    if (errors == 0) {
        std::cout << "All " << total_tests << " tests passed successfully!" << std::endl;
    } else {
        std::cout << "Test failed with " << errors << " errors out of "
                  << total_tests << " tests." << std::endl;
        return 1;  // Return non-zero value to indicate failure
    }

    return 0;  // Return zero to indicate success
}
