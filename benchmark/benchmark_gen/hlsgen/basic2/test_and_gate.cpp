#include "and_gate.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    input_t a, b;
    output_t out;

    // Open the result file for writing
    FILE *fp = fopen("result.dat", "w");
    if (fp == NULL) {
        printf("Error opening result.dat for writing\n");
        return 1;
    }

    // Test 1: a = 0; b = 0;
    a = 0; b = 0;
    and_gate(a, b, &out);
    if (out != 0) {
        fprintf(fp, "test 1 failed\n");
        fclose(fp);
        return 1;
    } else {
        fprintf(fp, "a = %d , b = %d, out = %d\n", (int)a, (int)b, (int)out);
    }

    // Test 2: a = 0; b = 1;
    a = 0; b = 1;
    and_gate(a, b, &out);
    if (out != 0) {
        fprintf(fp, "test 2 failed\n");
        fclose(fp);
        return 1;
    } else {
        fprintf(fp, "a = %d , b = %d, out = %d\n", (int)a, (int)b, (int)out);
    }

    // Test 3: a = 1; b = 0;
    a = 1; b = 0;
    and_gate(a, b, &out);
    if (out != 0) {
        fprintf(fp, "test 3 failed\n");
        fclose(fp);
        return 1;
    } else {
        fprintf(fp, "a = %d , b = %d, out = %d\n", (int)a, (int)b, (int)out);
    }

    // Test 4: a = 1; b = 1;
    a = 1; b = 1;
    and_gate(a, b, &out);
    if (out != 1) {
        fprintf(fp, "test 4 failed\n");
        fclose(fp);
        return 1;
    } else {
        fprintf(fp, "a = %d , b = %d, out = %d\n", (int)a, (int)b, (int)out);
    }

    fprintf(fp, "all tests passed\n");
    fclose(fp);

    // Compare the result with the golden output
    int retval = system("diff --brief -w result.dat result_golden.dat");
    if (retval != 0) {
        printf("Test failed  !!!\n");
        retval = 1;
    } else {
        printf("Test passed !\n");
    }

    return retval;
}
