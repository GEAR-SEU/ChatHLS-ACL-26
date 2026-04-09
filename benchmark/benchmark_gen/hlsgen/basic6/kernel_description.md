Create a computez.cpp file with the following specifications:

Objective:

Implement a High-Level Synthesis (HLS) function that performs a specific boolean operation, where the output is computed based on the inputs using the formula: z = (x ^ y) & x.

Function Prototype:

<CPP>
void computez(input_t x, input_t y, output_t* z);
Requirements:

1. Include Necessary Headers:

Include the header file that provides the definitions of input_t and output_t. These data types represent single-bit signals and are defined elsewhere (e.g., in computez.h).
Include any other standard headers required for HLS projects.
2. Function Implementation:

Implement the function that it computes the output z based on the inputs x and y using the boolean expression z = (x ^ y) & x.
The function should directly perform the computation without any additional logic or processing.
1. Coding Standards:

Ensure that the code is clear, concise, and adheres to HLS coding conventions.
Use appropriate data types for single-bit signals (e.g., bool or ap_uint<1>).
Include necessary comments to explain the code for readability.
Task:

Provide the complete content of the computez.cpp file based on the above specifications.