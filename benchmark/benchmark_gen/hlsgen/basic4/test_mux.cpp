#include "mux.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bitset>

int main() {
    data_t a = 0;
    data_t b = 0;
    sel_t sel;
    data_t out;

    int increment_a = 0;

    // Open the result file for writing
    std::ofstream result_file("result.dat");
    if (!result_file.is_open()) {
        std::cerr << "Error opening result.dat for writing" << std::endl;
        return 1;
    }

    // Loop until b reaches 15 (4'b1111)
    while (b < 16) {  // 16 is 4'b10000, so b goes from 0 to 15
        // Test with sel = 0
        sel = 0;
        mux(a, b, sel, &out);
        if (out != a) {
            result_file << "test failed" << std::endl;
            result_file.close();
            std::cout << "Test failed !!!" << std::endl;
            return 1;
        } else {
            result_file << "a = " << std::bitset<5>(a) << " , b = " << std::bitset<5>(b)
                        << ", sel = " << sel << ", out = " << std::bitset<5>(out) << std::endl;
        }

        // Test with sel = 1
        sel = 1;
        mux(a, b, sel, &out);
        if (out != b) {
            result_file << "test failed" << std::endl;
            result_file.close();
            std::cout << "Test failed !!!" << std::endl;
            return 1;
        } else {
            result_file << "a = " << std::bitset<5>(a) << " , b = " << std::bitset<5>(b)
                        << ", sel = " << sel << ", out = " << std::bitset<5>(out) << std::endl;
        }

        // Increment a and b alternately
        if (increment_a) {
            a = a + 1;
        } else {
            b = b + 1;
        }

        increment_a = !increment_a;
    }

    result_file << "all tests passed" << std::endl;
    result_file.close();

    // Compare the result with the golden output
    int retval = system("diff --brief -w result.dat result_golden.dat");
    if (retval != 0) {
        std::cout << "Test failed !!!" << std::endl;
        retval = 1;
    } else {
        std::cout << "Test passed !" << std::endl;
    }

    return retval;
}
