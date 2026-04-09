Create a half_adder.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that performs a half-adder operation, where the function adds two single-bit inputs and produces a sum and a carry-out.

Function Prototype:

```cpp
void half_adder(bool a, bool b, bool* sum, bool* cout);
```

Requirements:
    Include Necessary Headers:
        Include any essential headers required for the implementation.
        If necessary, include "ap_int.h" for arbitrary precision data types (though for single-bit operations, built-in types may suffice).

    Function Implementation:
        Implement the half_adder function to compute the sum and carry-out (cout) of the two input bits a and b.
        The sum should be the result of the bitwise XOR operation between a and b.
        The carry-out should be the result of the bitwise AND operation between a and b.

    Coding Standards:
        Ensure the code is clear, concise, and adheres to HLS coding conventions.
        Use meaningful variable names and proper indentation for readability.
        Include comments where necessary to explain the logic and flow of the code.

Task:
Provide the complete content of the half_adder.cpp file based on the above specifications.