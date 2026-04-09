Objective:

Implement a High-Level Synthesis (HLS) function that models a NOR gate. The function should compute the NOR operation on two single-bit input signals and assign the result to the output signal.

Function Prototype:

<CPP>
void nor_gate(bit_t a, bit_t b, bit_t* out);
Requirements:

1. Include Necessary Headers:

Include the header file that provides the definition of bit_t. This data type represents a single-bit signal and is defined elsewhere (e.g., in nor.h).
Ensure any other necessary HLS libraries are included (e.g., ap_int.h for arbitrary precision integers).
2. Function Implementation:

Implement the function nor such that it performs the NOR operation on the inputs a and b, and assigns the result to the output pointer out.
The function should directly perform the NOR operation without any additional logic or processing.
Compute the NOR operation using bitwise operators.
Assignment should be done in a way that is synthesizable by HLS tools.
3. Coding Standards:

Clarity and Conciseness:
Write clean and concise code.
Use proper indentation and code formatting for readability.
Comments:
Include comments to explain the functionality of the code.
Comment on any non-obvious code sections for better understanding.
HLS Coding Conventions:
Ensure that the code is compatible with HLS synthesis tools.
Avoid using unsupported language constructs.
Task:

Provide the complete content of the nor.cpp file based on the above specifications.