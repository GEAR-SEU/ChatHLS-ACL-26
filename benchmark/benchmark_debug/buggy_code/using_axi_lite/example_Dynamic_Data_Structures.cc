#include <stdio.h>
#include <vector>

void example(char* a, char* b, char* c) {
#pragma HLS INTERFACE s_axilite port = a bundle = BUS_A
#pragma HLS INTERFACE s_axilite port = b bundle = BUS_A
#pragma HLS INTERFACE s_axilite port = c bundle = BUS_A
#pragma HLS INTERFACE s_axilite port = return bundle = BUS_A
    std::vector<char> d;
    *c += *a + *b;
}
