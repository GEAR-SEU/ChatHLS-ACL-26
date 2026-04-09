Create a popcount.cpp file with the following specifications:

Objective:

Implement a High-Level Synthesis (HLS) function that performs a population count. The function counts the number of '1's in a 3-bit input vector and outputs the count.

Function Prototype:

<CPP>
void popcount(din_t in, dout_t* out);
Requirements:

Include Necessary Headers:

Include the header file that provides the definitions of din_t and dout_t. These data types represent the 3-bit input and 2-bit output signals, respectively, and are defined elsewhere (e.g., in popcount.h).
Function Implementation:

Implement the function popcount such that it counts the number of '1's in the input value in and assigns the result to the output pointer out.
The function should directly compute the sum of the bits of the input in[2:0] without any additional logic or processing.
Coding Standards:

Ensure that the code is clear, concise, and adheres to HLS coding conventions.
Include any necessary comments to explain the code for readability.
Task:

Provide the complete content of the popcount.cpp file based on the above specifications.