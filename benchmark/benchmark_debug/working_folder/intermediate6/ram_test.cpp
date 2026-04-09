#include "ram.h"
#include <iostream>

int main() {
    data_t data;
    addr_t addr;
    bool_t we;
    data_t q;

    int test_failed = 0;

    // Test 1: Write to ram[0]
    data = 0xAB;
    addr = 0;
    we = 1;
    ram(data, addr, we, q);
    if (q != 0xAB) {
        std::cout << "Test 1 failed: q != 0xAB, q = 0x" << std::hex << q.to_uint() << std::endl;
        test_failed = 1;
    } else {
        std::cout << "Test 1 passed: q = 0x" << std::hex << q.to_uint() << std::endl;
    }

    // Test 2: Write to ram[20]
    data = 0x77;
    addr = 20;
    we = 1;
    ram(data, addr, we, q);
    if (q != 0x77) {
        std::cout << "Test 2 failed: q != 0x77, q = 0x" << std::hex << q.to_uint() << std::endl;
        test_failed = 1;
    } else {
        std::cout << "Test 2 passed: q = 0x" << std::hex << q.to_uint() << std::endl;
    }

    // Test 3: Read ram[0]
    data = 0x77; // Data is irrelevant when we = 0
    addr = 0;
    we = 0;
    ram(data, addr, we, q);
    if (q != 0xAB) {
        std::cout << "Test 3 failed: q != 0xAB, q = 0x" << std::hex << q.to_uint() << std::endl;
        test_failed = 1;
    } else {
        std::cout << "Test 3 passed: q = 0x" << std::hex << q.to_uint() << std::endl;
    }

    // Test 4: Read ram[20]
    data = 0x12; // Data is irrelevant when we = 0
    addr = 20;
    we = 0;
    ram(data, addr, we, q);
    if (q != 0x77) {
        std::cout << "Test 4 failed: q != 0x77, q = 0x" << std::hex << q.to_uint() << std::endl;
        test_failed = 1;
    } else {
        std::cout << "Test 4 passed: q = 0x" << std::hex << q.to_uint() << std::endl;
    }

    if (test_failed) {
        std::cout << "Some tests failed." << std::endl;
        return 1;
    } else {
        std::cout << "All tests passed." << std::endl;
        return 0;
    }
}
