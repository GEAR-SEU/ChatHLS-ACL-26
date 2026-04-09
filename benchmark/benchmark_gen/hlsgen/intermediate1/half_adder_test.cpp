#include "half_adder.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    bool a = 0;
    bool b = 0;
    bool sum, cout;
    int retval = 0;

    // Open the result file for writing
    std::ofstream result_file("result.dat");
    if (!result_file.is_open()) {
        std::cerr << "Error opening result.dat for writing" << std::endl;
        return 1;
    }

    // Test case 1: a=0, b=0
    a = 0; b = 0;
    half_adder(a, b, &sum, &cout);
    if (cout != 0 || sum != 0) {
        result_file << "test failed" << std::endl;
        result_file.close();
        std::cout << "Test failed !!!" << std::endl;
        return 1;
    } else {
        result_file << "a=" << (int)a << ", b=" << (int)b << ", cout=" << (int)cout << ", sum=" << (int)sum << std::endl;
    }

    // Test case 2: a=0, b=1
    a = 0; b = 1;
    half_adder(a, b, &sum, &cout);
    if (cout != 0 || sum != 1) {
        result_file << "test failed" << std::endl;
        result_file.close();
        std::cout << "Test failed !!!" << std::endl;
        return 1;
    } else {
        result_file << "a=" << (int)a << ", b=" << (int)b << ", cout=" << (int)cout << ", sum=" << (int)sum << std::endl;
    }

    // Test case 3: a=1, b=0
    a = 1; b = 0;
    half_adder(a, b, &sum, &cout);
    if (cout != 0 || sum != 1) {
        result_file << "test failed" << std::endl;
        result_file.close();
        std::cout << "Test failed !!!" << std::endl;
        return 1;
    } else {
        result_file << "a=" << (int)a << ", b=" << (int)b << ", cout=" << (int)cout << ", sum=" << (int)sum << std::endl;
    }

    // Test case 4: a=1, b=1
    a = 1; b = 1;
    half_adder(a, b, &sum, &cout);
    if (cout != 1 || sum != 0) {
        result_file << "test failed" << std::endl;
        result_file.close();
        std::cout << "Test failed !!!" << std::endl;
        return 1;
    } else {
        result_file << "a=" << (int)a << ", b=" << (int)b << ", cout=" << (int)cout << ", sum=" << (int)sum << std::endl;
    }

    // All tests passed
    result_file << "All tests passed" << std::endl;
    result_file.close();

    // Compare the result with the golden output
    retval = system("diff --brief -w result.dat result_golden.dat");
    if (retval != 0) {
        std::cout << "Test failed !!!" << std::endl;
        retval = 1;
    } else {
        std::cout << "Test passed !" << std::endl;
    }

    return retval;
}
