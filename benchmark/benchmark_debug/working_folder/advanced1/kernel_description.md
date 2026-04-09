Create a signed_adder.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that performs the addition of two 8-bit signed 2's complement numbers, a and b, to produce an 8-bit signed sum s. Also, compute whether a signed overflow has occurred during the addition.

Function Prototype:
```cpp
void signed_adder(din_t a, din_t b, dout_t* s, bool* overflow);
```

Requirements:
    Include Necessary Headers:
        Include the header file that provides the definitions of din_t and dout_t. These data types represent 8-bit signed integers and are defined elsewhere (e.g., in signed_adder.h).
        Include any other necessary HLS-specific headers (e.g., ap_int.h) required for arbitrary precision integer types.

    Function Implementation:
        Implement the function signed_adder such that it performs the following operations:

            Addition:
                Calculate the sum s of the input values a and b.
            Overflow Detection:
                Determine if a signed overflow has occurred during the addition.
                Signed overflow occurs when the sign bits of a and b are the same, but the sign bit of the result s is different.
                Set the overflow flag to true if an overflow has occurred; otherwise, set it to false.
        Implementation Details:
            Use bitwise operations to extract the sign bits of a, b, and s.
            Ensure that the addition and overflow detection are performed according to the rules of 2's complement arithmetic.

    Coding Standards:
        Ensure that the code is clear, concise, and adheres to HLS coding conventions.
        Include necessary comments to explain the code for readability.
        Optimize the code for synthesis by minimizing unnecessary logic and following best practices.

Task:
Provide the complete content of the signed_adder.cpp file based on the above specifications.