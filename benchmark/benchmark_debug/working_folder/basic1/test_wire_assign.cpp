#include "wire_assign.h"
#include <iostream>

int main() {
    input_t in;
    output_t out;
    int retval = 0;

    // Duration for each test case (not used in HLS C++ but included for completeness)
    const int period = 2;

    // Test 1: in = 0
    in = 0;
    wire_assign(in, &out);
    if (out != 0) {
        std::cout << "Test 1 failed" << std::endl;
        return 1;
    } else {
        std::cout << "in = " << in.to_uint() << " , out = " << out.to_uint() << std::endl;
    }

    // Test 2: in = 1
    in = 1;
    wire_assign(in, &out);
    if (out != 1) {
        std::cout << "Test 2 failed" << std::endl;
        return 1;
    } else {
        std::cout << "in = " << in.to_uint() << " , out = " << out.to_uint() << std::endl;
    }

    // Test 3: in = 0
    in = 0;
    wire_assign(in, &out);
    if (out != 0) {
        std::cout << "Test 3 failed" << std::endl;
        return 1;
    } else {
        std::cout << "in = " << in.to_uint() << " , out = " << out.to_uint() << std::endl;
    }

    std::cout << "All tests passed" << std::endl;
    return 0;
}
