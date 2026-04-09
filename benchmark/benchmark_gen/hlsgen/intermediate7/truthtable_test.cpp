#include "truthtable.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    input_t x3, x2, x1;
    output_t f;
    int retval = 0;

    // Expected outputs for each input combination according to the truth table
    int expected_outputs[8] = {1, 1, 0, 1, 0, 0, 1, 0};

    std::ofstream result_file("result.dat");

    for (int i = 0; i < 8; i++) {
        x3 = (i >> 2) & 0x1;
        x2 = (i >> 1) & 0x1;
        x1 = i & 0x1;

        // Call the function under test
        truthtable(x3, x2, x1, &f);

        // Write result to file
        result_file << "x3=" << x3.to_int()
                    << ", x2=" << x2.to_int()
                    << ", x1=" << x1.to_int()
                    << ", f=" << f.to_int() << std::endl;

        // Check the output against expected value
        if (f != expected_outputs[i]) {
            std::cout << "Test " << i+1 << " failed" << std::endl;
            retval = 1;
            // Optionally, you can break here to stop after the first failure
        } else {
            std::cout << "x3=" << x3.to_int()
                      << ", x2=" << x2.to_int()
                      << ", x1=" << x1.to_int()
                      << ", f=" << f.to_int()
                      << " - Test passed" << std::endl;
        }
    }

    result_file.close();

    // Comparison with golden results (if available)
    // Assuming 'result.golden.dat' contains the expected output
    retval = system("diff --brief -w result.dat result_golden.dat");
    if (retval != 0) {
        std::cout << "Overall Test failed!!!" << std::endl;
        retval = 1;
    } else {
        std::cout << "Overall Test passed!" << std::endl;
    }

    return retval;
}
