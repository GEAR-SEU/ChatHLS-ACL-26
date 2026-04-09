#include "scancodes.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    scancode_t scancode;
    out_t left;
    out_t down;
    out_t right;
    out_t up;

    int retval = 0;
    std::ofstream fp("result.dat");

    // Fixed test scancodes (as per the Verilog testbench)
    scancode_t test_scancodes[] = {
        0x0000,
        0x0001,
        0xE075, // Up arrow
        0xE06B, // Left arrow
        0xE06C, // Not mapped
        0xE072, // Down arrow
        0xE074, // Right arrow
        0xE076, // Not mapped
        0xFFFF  // Not mapped
    };

    const int N_fixed = sizeof(test_scancodes) / sizeof(scancode_t);

    // Test fixed scancodes
    for (int i = 0; i < N_fixed; ++i) {
        scancode = test_scancodes[i];
        scancodes(scancode, &left, &down, &right, &up);

        fp << "Scancode: 0x" << std::hex << scancode.to_uint()
           << " | Left: "  << left
           << " Down: "    << down
           << " Right: "   << right
           << " Up: "      << up << std::endl;

        // Expected outputs
        out_t exp_left  = 0;
        out_t exp_down  = 0;
        out_t exp_right = 0;
        out_t exp_up    = 0;

        switch (scancode.to_uint()) {
            case 0xE06B:
                exp_left = 1;
                break;
            case 0xE072:
                exp_down = 1;
                break;
            case 0xE074:
                exp_right = 1;
                break;
            case 0xE075:
                exp_up = 1;
                break;
            default:
                // No action needed
                break;
        }

        // Compare outputs
        if (left != exp_left || down != exp_down || right != exp_right || up != exp_up) {
            std::cout << "Mismatch at scancode 0x" << std::hex << scancode.to_uint() << std::endl;
            retval = 1;
        }
    }

    // Random testing
    const int N_random = 100; // Number of random test cases
    for (int i = 0; i < N_random; ++i) {
        scancode = rand() % 0x10000; // Generate a random 16-bit scancode

        scancodes(scancode, &left, &down, &right, &up);

        // Expected outputs
        out_t exp_left  = 0;
        out_t exp_down  = 0;
        out_t exp_right = 0;
        out_t exp_up    = 0;

        switch (scancode.to_uint()) {
            case 0xE06B:
                exp_left = 1;
                break;
            case 0xE072:
                exp_down = 1;
                break;
            case 0xE074:
                exp_right = 1;
                break;
            case 0xE075:
                exp_up = 1;
                break;
            default:
                // No action needed
                break;
        }

        // Compare outputs
        if (left != exp_left || down != exp_down || right != exp_right || up != exp_up) {
            std::cout << "Mismatch at scancode 0x" << std::hex << scancode.to_uint() << std::endl;
            retval = 1;
        }
    }

    fp.close();

    if (retval == 0) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }

    return retval;
}
