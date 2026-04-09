#include "wire_assign.h"
#include <cstdlib>
#include <iostream>

int main() {
    output_t out = false;
    wire_assign(true, &out);
    if (!out) {
        std::cerr << "Test failed" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Test passed" << std::endl;
    return EXIT_SUCCESS;
}
