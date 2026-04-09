#include "priority_encoder.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    input_t in;
    output_t pos;

    // Open the result file for writing
    std::ofstream result_file("result.dat");
    if (!result_file.is_open()) {
        std::cerr << "Error opening result.dat for writing" << std::endl;
        return 1;
    }

    // Test cases
    bool test_passed = true;

    // Test 1: in = 0;
    in = 0;
    priority_encoder(in, &pos);
    if (pos != 0) {
        result_file << "test 1 failed" << std::endl;
        test_passed = false;
    } else {
        result_file << "in = " << in.to_uint() << " , pos = " << pos.to_uint() << std::endl;
    }

    // Test 2: in = 1;
    in = 1;
    priority_encoder(in, &pos);
    if (pos != 0) {
        result_file << "test 2 failed" << std::endl;
        test_passed = false;
    } else {
        result_file << "in = " << in.to_string(2) << " , pos = " << pos.to_string(2) << std::endl;
    }

    // Test 3: in = 2;
    in = 2;
    priority_encoder(in, &pos);
    if (pos != 1) {
        result_file << "test 3 failed" << std::endl;
        test_passed = false;
    } else {
        result_file << "in = " << in.to_string(2) << " , pos = " << pos.to_string(2) << std::endl;
    }

    // Test 4: in = 3;
    in = 3;
    priority_encoder(in, &pos);
    if (pos != 0) {
        result_file << "test 4 failed" << std::endl;
        test_passed = false;
    } else {
        result_file << "in = " << in.to_string(2) << " , pos = " << pos.to_string(2) << std::endl;
    }

    // Test 5: in = 4;
    in = 4;
    priority_encoder(in, &pos);
    if (pos != 2) {
        result_file << "test 5 failed" << std::endl;
        test_passed = false;
    } else {
        result_file << "in = " << in.to_string(2) << " , pos = " << pos.to_string(2) << std::endl;
    }

    // Test 6: in = 5;
    in = 5;
    priority_encoder(in, &pos);
    if (pos != 0) {
        result_file << "test 6 failed" << std::endl;
        test_passed = false;
    } else {
        result_file << "in = " << in.to_string(2) << " , pos = " << pos.to_string(2) << std::endl;
    }

    // Test 7: in = 6;
    in = 6;
    priority_encoder(in, &pos);
    if (pos != 1) {
        result_file << "test 7 failed" << std::endl;
        test_passed = false;
    } else {
        result_file << "in = " << in.to_string(2) << " , pos = " << pos.to_string(2) << std::endl;
    }

    // Test 8: in = 7;
    in = 7;
    priority_encoder(in, &pos);
    if (pos != 0) {
        result_file << "test 8 failed" << std::endl;
        test_passed = false;
    } else {
        result_file << "in = " << in.to_string(2) << " , pos = " << pos.to_string(2) << std::endl;
    }

    if (test_passed) {
        result_file << "all tests passed" << std::endl;
    }

    result_file.close();

    // Compare the result with the golden output
    int retval = system("diff --brief -w result.dat result_golden.dat");
    if (retval != 0) {
        std::cout << "Test failed  !!!" << std::endl;
        retval = 1;
    } else {
        std::cout << "Test passed !" << std::endl;
    }

    return retval;
}
