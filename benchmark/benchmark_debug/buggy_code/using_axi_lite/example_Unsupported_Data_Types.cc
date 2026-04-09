#include <stdio.h>
#include <complex>

void example(char* a, char* b, char* c) {
#pragma HLS INTERFACE s_axilite port = a bundle = BUS_A
#pragma HLS INTERFACE s_axilite port = b bundle = BUS_A
#pragma HLS INTERFACE s_axilite port = c bundle = BUS_A
#pragma HLS INTERFACE s_axilite port = return bundle = BUS_A

    std::complex<double> complex_result(*a, *b);
    *c += std::abs(complex_result);
}