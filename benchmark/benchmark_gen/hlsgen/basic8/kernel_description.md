Objective:
Implement a High-Level Synthesis (HLS) function that performs combinational logic operations on a 4-bit input. The function calculates the 4-input AND, OR, and XOR of the input bits.

Function Prototype:

<CPP>
void gates4(in_t in, out_t *out_and, out_t *out_or, out_t *out_xor);
Requirements:

1. Include Necessary Headers:

Include the header file that provides the definitions of in_t and out_t. These data types represent multi-bit and single-bit signals, respectively, and are defined elsewhere (e.g., in gates4.h).
Ensure that any other necessary HLS libraries (such as ap_int.h) are included if required.
2. Function Implementation:

Functionality:
Implement the function gates4 to perform the following operations on the 4-bit input in:
Calculate the logical AND of all bits in in and assign the result to *out_and.
Calculate the logical OR of all bits in in and assign the result to *out_or.
Calculate the logical XOR of all bits in in and assign the result to *out_xor.
Implementation Details:
Use bitwise operators to perform the calculations.
The function should be purely combinational with no state or sequential logic.
3. Coding Standards:

Readability:
Write clear and concise code.
Use appropriate indentation and spacing for readability.
Include comments to explain critical sections of the code.
Conventions:
Adhere to HLS coding conventions and best practices.
Use meaningful variable names.
Ensure that the code is synthesizable.
Task:

Provide the complete content of the gates4.cpp file based on the above specifications.