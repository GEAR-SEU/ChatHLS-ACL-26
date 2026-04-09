#include "nor_gate.h"
#include <iostream>
#include <fstream>

int main() {
    bit_t a, b;
    bit_t out_dut;  // Output from Device Under Test (DUT)
    bit_t out_ref;  // Expected output (reference)
    bool pass = true;

    // Open result file to write the outputs
    std::ofstream result_file("result.dat");

    // Test all possible combinations of inputs a and b (00, 01, 10, 11)
    for (int i = 0; i < 4; ++i) {
        // Generate inputs
        a = (i >> 1) & 0x1;
        b = i & 0x1;

        // Compute expected output using reference model
        out_ref = ~(a | b);

        // Call the NOR function (DUT)
        nor_gate(a, b, &out_dut);

        // Write results to the result file
        result_file << "a: " << a.to_uint()
                    << ", b: " << b.to_uint()
                    << ", out: " << out_dut.to_uint()
                    << " (expected: " << out_ref.to_uint() << ")\n";

        // Check for mismatches
        if (out_dut != out_ref) {
            std::cout << "Mismatch at a=" << a.to_uint()
                      << ", b=" << b.to_uint()
                      << ": got " << out_dut.to_uint()
                      << ", expected " << out_ref.to_uint() << std::endl;
            pass = false;
        }
    }

    result_file.close();

    // Display test result
    if (pass) {
        std::cout << "Test passed!" << std::endl;
        return 0;  // Success
    } else {
        std::cout << "Test failed!" << std::endl;
        return 1;  // Failure
    }
}
