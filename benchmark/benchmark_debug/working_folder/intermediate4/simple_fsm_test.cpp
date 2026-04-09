#include "simple_fsm.h"
#include <iostream>

int main() {
    bool clk = false;
    bool reset;
    bool in;
    bool out;
    int retval = 0;

    // Stimulus inputs and expected outputs
    struct TestVector {
        bool reset;
        bool in;
        bool expected_out;
        const char* description;
    };

    TestVector tests[] = {
        // Test 1: Check reset
        {true,  0, true,  "Test 1: After reset, output should be high (state 0)"},
        // Test 2: Start FSM
        {false, 0, false, "Test 2: State changes to 1 when 'in' is low"},
        // Test 3
        {false, 0, true,  "Test 3: State changes to 0 when 'in' is low"},
        // Test 4
        {false, 1, true,  "Test 4: State remains in 0 when 'in' is high"},
        // Test 5
        {false, 0, false, "Test 5: State changes to 1 when 'in' is low"},
        // Test 6
        {false, 1, false, "Test 6: State remains in 1 when 'in' is high"},
        // Test 7: Check reset again
        {true,  1, true,  "Test 7: After reset, output should be high (state 0)"}
    };

    int num_tests = sizeof(tests) / sizeof(TestVector);

    for (int i = 0; i < num_tests; ++i) {
        reset = tests[i].reset;
        in = tests[i].in;

        // Call the FSM function to simulate one clock cycle
        simple_fsm(reset, in, &out);

        // Verify the output against the expected value
        if (out != tests[i].expected_out) {
            std::cout << tests[i].description << " - Failed" << std::endl;
            std::cout << "Expected out: " << tests[i].expected_out << ", Got: " << out << std::endl;
            retval = 1;
            break;
        } else {
            std::cout << tests[i].description << " - Passed" << std::endl;
            std::cout << "clk=" << clk << ", reset=" << reset << ", in=" << in << ", out=" << out << std::endl;
        }
    }

    if (retval == 0) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return retval;
}
