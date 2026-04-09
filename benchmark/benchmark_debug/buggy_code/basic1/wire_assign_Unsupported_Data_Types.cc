#include "wire_assign.h"

struct ComplexType {
    double real;
    double imag;
};

void wire_assign(ComplexType in, ComplexType* out) {
    
    out->real = in.real;
    out->imag = in.imag;
}
