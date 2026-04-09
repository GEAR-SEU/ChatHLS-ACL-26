#include "signed_adder.h"
#include <iostream>
#include <fstream>

int main() {
    din_t a = 0;
    din_t b = 0;
    dout_t s;
    overflow_t overflow;

    int increment_a = 0;
    int retval = 0;

    std::ofstream result_file("result.dat");

    // Loop until b reaches its maximum positive value
    while (b != 126) {
        // Call the function under test
        signed_adder(a, b, &s, &overflow);

        // Expected values
        dout_t expected_s = a + b;
        overflow_t expected_overflow = ((a[7] == b[7]) && (s[7] != a[7]));

        // Check the results
        if (s != expected_s || overflow != expected_overflow) {
            std::cout << "Test failed" << std::endl;
            std::cout << "  a = " << (int)a << " , b = " << (int)b
                      << ", sum = " << (int)s << ", overflow = " << overflow << std::endl;
            retval = 1;
            break;
        } else {
            std::cout << "  a = " << (int)a << " , b = " << (int)b
                      << ", sum = " << (int)s << ", overflow = " << overflow << std::endl;
            result_file << "  a = " << (int)a << " , b = " << (int)b
                        << ", sum = " << (int)s << ", overflow = " << overflow << std::endl;
        }

        // Update a and b as per the Verilog testbench logic
        if (increment_a) {
            a = a + 1;
            if (a == 127) a = -128; // Wrap around if exceeding 8-bit signed integer range
        } else {
            b = b + 1;
            if (b == 127) b = -128; // Wrap around if exceeding 8-bit signed integer range
        }

        increment_a = !increment_a;
    }

    result_file.close();

    if (retval == 0) {
        std::cout << "All tests passed" << std::endl;
    } else {
        std::cout << "Some tests failed" << std::endl;
    }

    return retval;
}
