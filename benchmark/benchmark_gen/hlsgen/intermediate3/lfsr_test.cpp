#include "lfsr.h"
#include <iostream>

int main() {
    ap_uint<5> q;
    bool reset;
    int retval = 0;

    // Expected output values for each test, matching the Verilog testbench
    ap_uint<5> expected_q[17] = {
        1,   // Test 1: After reset, q should be 1
        1,   // Test 1a: q should remain 1 during reset
        16,  // Test 2
        24,  // Test 3
        28,  // Test 4
        14,  // Test 5
        23,  // Test 6
        27,  // Test 7
        13,  // Test 8
        6,   // Test 9
        19,  // Test 10
        9,   // Test 11
        20,  // Test 12
        10,  // Test 13
        5,   // Test 14
        2,   // Test 15
        1    // Test 16
    };

    // Simulate clock cycles and apply reset as per Verilog testbench
    for (int test_num = 0; test_num < 17; test_num++) {
        // Apply reset for the first two cycles
        if (test_num <= 1) {
            reset = true;
        } else {
            reset = false;
        }

        // Call the LFSR function to simulate one clock cycle
        lfsr(reset, q);

        // Verify the output against the expected value
        if (q != expected_q[test_num]) {
            std::cout << "Test " << test_num + 1 << " failed: Expected q = "
                      << expected_q[test_num] << ", Got q = " << q << std::endl;
            retval = 1;
            break;
        } else {
            std::cout << "Test " << test_num + 1 << " passed: q = " << q << std::endl;
        }
    }

    if (retval == 0) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return retval;
}
