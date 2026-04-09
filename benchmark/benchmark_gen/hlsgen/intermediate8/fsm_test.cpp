// test_fsm.cpp

#include <iostream>
#include <fstream>
#include "fsm.h"

int main() {
    logic x;
    logic areset;
    logic z;

    // Simulation parameters
    const int cycles = 20; // Number of cycles to simulate
    int errors = 0;

    // Input and expected output arrays
    logic x_values[cycles];
    logic areset_values[cycles];
    logic z_expected;
    int expected_state = 1; // Start in State A

    // Initialize input sequences
    areset_values[0] = 1; // Assert reset
    x_values[0] = 0;

    areset_values[1] = 0; // Deassert reset
    x_values[1] = 1;

    areset_values[2] = 0;
    x_values[2] = 0;

    areset_values[3] = 0;
    x_values[3] = 1;

    areset_values[4] = 0;
    x_values[4] = 1;

    areset_values[5] = 0;
    x_values[5] = 0;

    areset_values[6] = 0;
    x_values[6] = 1;

    areset_values[7] = 0;
    x_values[7] = 0;

    areset_values[8] = 0;
    x_values[8] = 0;

    // Generate random inputs for the remaining cycles
    for (int i = 9; i < cycles; i++) {
        areset_values[i] = 0;
        x_values[i] = rand() % 2;
    }

    // Open result file
    std::ofstream result("result.dat");
    if (!result.is_open()) {
        std::cerr << "Failed to open result.dat" << std::endl;
        return 1;
    }

    // Simulation loop
    for (int i = 0; i < cycles; i++) {
        x = x_values[i];
        areset = areset_values[i];

        // Call the FSM function
        fsm(x, areset, z);

        // Compute expected output (Mealy machine)
        if (areset == 1) {
            expected_state = 1; // Reset to State A
            z_expected = 0;
        } else {
            if (expected_state == 1) { // State A
                z_expected = x;
                if (x == 1)
                    expected_state = 2; // Transition to State B
            } else if (expected_state == 2) { // State B
                z_expected = (~x) & 0x1;
                // Remain in State B
            } else {
                expected_state = 1; // Default to State A
                z_expected = 0;
            }
        }

        // Write results to file
        result << "Cycle " << i << ": areset=" << areset.to_uint()
               << " x=" << x.to_uint() << " z=" << z.to_uint()
               << " expected_z=" << z_expected.to_uint() << std::endl;

        // Check for mismatches
        if (z != z_expected) {
            errors++;
            std::cout << "Mismatch at cycle " << i << ": expected z="
                      << z_expected.to_uint() << ", got z=" << z.to_uint() << std::endl;
        }
    }

    result.close();

    // Report test outcome
    if (errors > 0) {
        std::cout << "Test failed with " << errors << " errors!" << std::endl;
    } else {
        std::cout << "Test passed!" << std::endl;
    }

    return errors;
}
