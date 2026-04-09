#include "adv_fsm.h"
#include <iostream>

#define PERIOD 20
#define TOTAL_CYCLES 7

int main() {
    bit_t clk = 0;
    bit_t reset = 0;
    bit_t x = 0;
    bit_t z = 0;

    int failed = 0;

    // Test vectors (corresponding to the Verilog testbench)
    struct test_vector {
        bit_t reset;
        bit_t x;
        bit_t expected_z;
        const char* test_name;
    } test_vectors[TOTAL_CYCLES] = {
        {1, 0, 0, "Test 1"}, // Reset active
        {0, 0, 0, "Test 2"}, // State IDLE, x=0
        {0, 1, 0, "Test 3"}, // Transition to S1, x=1
        {0, 0, 0, "Test 4"}, // Transition to S10, x=0
        {0, 1, 1, "Test 5"}, // Transition to S101, x=1, z=1
        {0, 1, 0, "Test 6"}, // Back to S1, x=1
        // Additional cycles can be added if needed
    };

    std::cout << "Starting Testbench Simulation..." << std::endl;

    for (int i = 0; i < TOTAL_CYCLES; ++i) {
        // Apply inputs
        reset = test_vectors[i].reset;
        x = test_vectors[i].x;

        // Call the FSM function (simulate rising edge of clock)
        adv_fsm(reset, x, &z);

        // Check output
        if (z != test_vectors[i].expected_z) {
            std::cout << test_vectors[i].test_name << " failed: x=" << x << ", z=" << z << std::endl;
            failed = 1;
            break;
        } else {
            std::cout << test_vectors[i].test_name << " passed: x=" << x << ", z=" << z << std::endl;
        }
    }

    if (!failed) {
        std::cout << "All tests passed successfully!" << std::endl;
    }

    return failed;
}
