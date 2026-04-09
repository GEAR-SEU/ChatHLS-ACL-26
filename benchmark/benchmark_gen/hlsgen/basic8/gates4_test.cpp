#include "gates4.h"
#include <fstream>
#include <iostream>

int main() {
    in_t in;
    out_t out_and;
    out_t out_or;
    out_t out_xor;

    out_t out_and_exp;
    out_t out_or_exp;
    out_t out_xor_exp;

    bool pass = true;

    // Open result file
    std::ofstream fout("result.dat");

    // Test all 16 combinations of 4-bit input
    for (int i = 0; i < 16; ++i) {
        in = i;  // Assign input

        // Call the HLS function
        gates4(in, &out_and, &out_or, &out_xor);

        // Compute expected outputs
        out_and_exp = (in[0] & in[1] & in[2] & in[3]);
        out_or_exp = (in[0] | in[1] | in[2] | in[3]);
        out_xor_exp = (in[0] ^ in[1] ^ in[2] ^ in[3]);

        // Write result to file
        fout << "Input: " << in.to_uint()
             << ", AND: " << out_and.to_uint() << " (expected " << out_and_exp.to_uint() << ")"
             << ", OR: " << out_or.to_uint() << " (expected " << out_or_exp.to_uint() << ")"
             << ", XOR: " << out_xor.to_uint() << " (expected " << out_xor_exp.to_uint() << ")\n";

        // Verify outputs
        if (out_and != out_and_exp || out_or != out_or_exp || out_xor != out_xor_exp) {
            std::cout << "Mismatch at input " << in.to_uint() << std::endl;
            pass = false;
        }
    }

    fout.close();

    // Check if all tests passed
    if (pass) {
        std::cout << "Test passed!" << std::endl;
        return 0;
    } else {
        std::cout << "Test failed!" << std::endl;
        return 1;
    }
}
