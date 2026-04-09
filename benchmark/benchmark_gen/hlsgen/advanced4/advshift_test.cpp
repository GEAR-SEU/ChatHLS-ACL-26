#include "advshift.h"
#include <iostream>

int main() {
    // Variables
    bool load, ena;
    ap_uint<2> amount;
    ap_uint<64> data;
    ap_uint<64> q;

    // Initialize variables
    data = 0xFFFFFFFFFFFFFFFFULL;
    q = 0;

    // Test 1: Load not enabled, should not load
    load = 0;
    ena = 0;
    amount = 0;
    advshift(load, ena, amount, data, &q);
    if (q == 0xFFFFFFFFFFFFFFFFULL) {
        std::cout << "Test 1 failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test 1 passed: load=" << load << ", amount=" << amount << ", ena=" << ena << ", q=" << std::hex << q << std::endl;
    }

    // Test 2: Enable load
    load = 1;
    ena = 0;
    amount = 0;
    advshift(load, ena, amount, data, &q);
    if (q != 0xFFFFFFFFFFFFFFFFULL) {
        std::cout << "Test 2 failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test 2 passed: load=" << load << ", amount=" << amount << ", ena=" << ena << ", q=" << std::hex << q << std::endl;
    }

    // Test 3: Check load override
    load = 1;
    ena = 0;
    amount = 2;
    advshift(load, ena, amount, data, &q);
    if (q != 0xFFFFFFFFFFFFFFFFULL) {
        std::cout << "Test 3 failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test 3 passed: load=" << load << ", amount=" << amount << ", ena=" << ena << ", q=" << std::hex << q << std::endl;
    }

    // Test 4: Enable not active, should not shift
    load = 0;
    ena = 0;
    amount = 0;
    advshift(load, ena, amount, data, &q);
    if (q == 0xFFFFFFFFFFFFFFFEULL) {
        std::cout << "Test 4 failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test 4 passed: load=" << load << ", amount=" << amount << ", ena=" << ena << ", q=" << std::hex << q << std::endl;
    }

    // Test 5: Enable shift left by 1 bit
    load = 0;
    ena = 1;
    amount = 0;
    advshift(load, ena, amount, data, &q);
    if (q != 0xFFFFFFFFFFFFFFFEULL) {
        std::cout << "Test 5 failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test 5 passed: load=" << load << ", amount=" << amount << ", ena=" << ena << ", q=" << std::hex << q << std::endl;
    }

    // Test 6: Enable shift left by 8 bits
    load = 0;
    ena = 1;
    amount = 1;
    advshift(load, ena, amount, data, &q);
    if (q != 0xFFFFFFFFFFFFFE00ULL) {
        std::cout << "Test 6 failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test 6 passed: load=" << load << ", amount=" << amount << ", ena=" << ena << ", q=" << std::hex << q << std::endl;
    }

    // Test 7: Enable shift right by 1 bit
    load = 0;
    ena = 1;
    amount = 2;
    advshift(load, ena, amount, data, &q);
    if (q != 0x7FFFFFFFFFFFFF00ULL) {
        std::cout << "Test 7 failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test 7 passed: load=" << load << ", amount=" << amount << ", ena=" << ena << ", q=" << std::hex << q << std::endl;
    }

    // Test 8: Enable shift right by 8 bits
    load = 0;
    ena = 1;
    amount = 3;
    advshift(load, ena, amount, data, &q);
    if (q != 0x007FFFFFFFFFFFFFULL) {
        std::cout << "Test 8 failed" << std::endl;
        return 1;
    } else {
        std::cout << "Test 8 passed: load=" << load << ", amount=" << amount << ", ena=" << ena << ", q=" << std::hex << q << std::endl;
    }

    std::cout << "All tests passed" << std::endl;
    return 0;
}
