#include "count_slow.h"
#include <stdio.h>

int main() {
    in_bit_t reset, slowena;
    out_q_t q;
    int failed = 0;

    // Initialize variables
    reset = 0;
    slowena = 0;
    q = 0;

    printf("Starting Testbench Simulation...\n");

    // Test 1: Check reset functionality
    reset = 1;
    slowena = 0;
    count_slow(reset, slowena, &q);
    if (q != 0) {
        printf("Test 1 failed: q != 0 after reset.\n");
        failed = 1;
        return failed;
    } else {
        printf("Test 1 passed: q = %d\n", q.to_uint());
    }

    // Test 2: Counter should stay at 0 when reset is active
    slowena = 1;
    count_slow(reset, slowena, &q);
    count_slow(reset, slowena, &q);
    if (q != 0) {
        printf("Test 2 failed: q != 0 when reset is active.\n");
        failed = 1;
        return failed;
    } else {
        printf("Test 2 passed: q = %d\n", q.to_uint());
    }

    // Deactivate reset to start counter
    reset = 0;
    slowena = 1;

    // Test 3 to 7: Counter increments from 1 to 5
    for (int i = 1; i <= 5; i++) {
        count_slow(reset, slowena, &q);
        if (q != i) {
            printf("Test %d failed: q != %d.\n", i + 2, i);
            failed = 1;
            return failed;
        } else {
            printf("Test %d passed: q = %d\n", i + 2, q.to_uint());
        }
    }

    // Test 8 and 9: Pause counter (slowena = 0)
    slowena = 0;
    count_slow(reset, slowena, &q);
    if (q != 5) {
        printf("Test 8 failed: q changed when slowena is 0.\n");
        failed = 1;
        return failed;
    } else {
        printf("Test 8 passed: q = %d\n", q.to_uint());
    }

    count_slow(reset, slowena, &q);
    if (q != 5) {
        printf("Test 9 failed: q changed when slowena is 0.\n");
        failed = 1;
        return failed;
    } else {
        printf("Test 9 passed: q = %d\n", q.to_uint());
    }

    // Resume counter
    slowena = 1;

    // Test 10 to 14: Counter increments from 6 to 0 (after wrapping at 9)
    int expected_values[] = {6, 7, 8, 9, 0};
    for (int i = 0; i < 5; i++) {
        count_slow(reset, slowena, &q);
        if (q != expected_values[i]) {
            printf("Test %d failed: q != %d.\n", i + 10, expected_values[i]);
            failed = 1;
            return failed;
        } else {
            printf("Test %d passed: q = %d\n", i + 10, q.to_uint());
        }
    }

    if (failed == 0) {
        printf("All tests passed successfully!\n");
    }

    return failed;
}
