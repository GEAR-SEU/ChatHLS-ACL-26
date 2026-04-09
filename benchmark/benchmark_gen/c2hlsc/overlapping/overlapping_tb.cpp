#include "overlapping.h"

static int test_epsilon[N];

int main() {
    int i;
    for (i = 0; i < N; i++) {
        test_epsilon[i] = i * 73 % 7 == 0;
    }
    double result;
    Overlapping(&result, test_epsilon);

    printf("result = %.0f\n", result);
}