#include "left_rotate.h"
#include <iostream>

int main() {
    bool_t load;
    amount_t amount;
    data_t data;
    data_t out;

    int test_failed = 0;

    // Test 1: Load not enabled, data should not be loaded into 'out'
    data = 0xFF;
    load = 0;
    amount = 0;
    left_rotate(load, amount, data, out);
    if (out == data) {
        std::cout << "Test 1 failed: out == " << out.to_string(16) << std::endl;
        test_failed = 1;
    } else {
        std::cout << "Test 1 passed: load = " << load << ", amount = " << amount
                  << ", out = " << out.to_string(16) << std::endl;
    }

    // Test 2: Load enabled, data should be loaded into 'out'
    data = 0xAA;
    load = 1;
    amount = 0;
    left_rotate(load, amount, data, out);
    if (out != data) {
        std::cout << "Test 2 failed: out != " << data.to_string(16)
                  << ", out = " << out.to_string(16) << std::endl;
        test_failed = 1;
    } else {
        std::cout << "Test 2 passed: load = " << load << ", amount = " << amount
                  << ", out = " << out.to_string(16) << std::endl;
    }

    // Test 3: Load enabled with amount, but amount should not affect loading
    data = 0x01;
    load = 1;
    amount = 2;
    left_rotate(load, amount, data, out);
    if (out != data) {
        std::cout << "Test 3 failed: out != " << data.to_string(16)
                  << ", out = " << out.to_string(16) << std::endl;
        test_failed = 1;
    } else {
        std::cout << "Test 3 passed: load = " << load << ", amount = " << amount
                  << ", out = " << out.to_string(16) << std::endl;
    }

    // Subsequent tests: Shift and rotate operations
    load = 0; // Load disabled
    struct TestCase {
        amount_t amount;
        data_t expected_out;
    };

    TestCase test_cases[] = {
        {1, 0x02},
        {2, 0x08},
        {3, 0x40},
        {4, 0x04},
        {5, 0x80},
        {6, 0x20},
        {7, 0x10},
    };

    for (int i = 0; i < 7; ++i) {
        amount = test_cases[i].amount;
        left_rotate(load, amount, data, out);
        if (out != test_cases[i].expected_out) {
            std::cout << "Test " << i + 4 << " failed: out != "
                      << test_cases[i].expected_out.to_string(16)
                      << ", out = " << out.to_string(16) << std::endl;
            test_failed = 1;
        } else {
            std::cout << "Test " << i + 4 << " passed: load = " << load
                      << ", amount = " << amount << ", out = " << out.to_string(16)
                      << std::endl;
        }
    }

    if (test_failed) {
        std::cout << "Some tests failed." << std::endl;
        return 1;
    } else {
        std::cout << "All tests passed." << std::endl;
        return 0;
    }
}
