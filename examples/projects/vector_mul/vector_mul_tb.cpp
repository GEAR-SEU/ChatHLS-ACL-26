#include "ap_fixed.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

void vector_mul(ap_fixed<32,16> a[8], ap_fixed<32,16> b[8], ap_fixed<32,16> c[8]);

int main() {
    ap_fixed<32,16> a[8];
    ap_fixed<32,16> b[8];
    ap_fixed<32,16> c[8];
    for (int i = 0; i < 8; ++i) {
        a[i] = i + 1;
        b[i] = 2 * i;
        c[i] = 0;
    }
    vector_mul(a, b, c);
    for (int i = 0; i < 8; ++i) {
        float expected = static_cast<float>(a[i] * b[i]);
        float actual = static_cast<float>(c[i]);
        if (std::fabs(expected - actual) > 1e-3f) {
            std::cerr << "Mismatch at " << i << std::endl;
            return EXIT_FAILURE;
        }
    }
    std::cout << "Test passed" << std::endl;
    return EXIT_SUCCESS;
}
