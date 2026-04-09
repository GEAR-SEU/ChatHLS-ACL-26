#include "ap_fixed.h"

void vector_mul(ap_fixed<32,16> a[8], ap_fixed<32,16> b[8], ap_fixed<32,16> c[8]) {
    for (int i = 0; i < 8; ++i) {
        c[i] = a[i] * b[i];
    }
}
