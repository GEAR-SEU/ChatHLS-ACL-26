Create a dff.cpp file with the following specifications:

Objective:

Implement a High-Level Synthesis (HLS) function that models a positive-edge triggered D flip-flop. The output q should capture the input d on the rising edge of the clock clk.

Function Prototype:

<CPP>
void dff(input_t d, input_t clk, output_t* q);
Requirements:

1. Include Necessary Headers:

Include the header file that provides the definitions of input_t and output_t. These data types represent single-bit signals and are defined elsewhere (e.g., in dff.h).
Include any other standard headers required for HLS projects.
2. Function Implementation:

Implement the function dff such that it simulates a positive-edge triggered D flip-flop.

The function should perform the following:

Detect the rising edge of the clock signal clk (i.e., when clk transitions from 0 to 1).
On the rising edge of clk, assign the value of d to the output q.
Use appropriate HLS constructs or mechanisms to maintain the state of the flip-flop between function calls (e.g., static variables).

Ensure that the function models sequential logic behavior accurately.

3. Coding Standards:

Ensure that the code is clear, concise, and adheres to HLS coding conventions.
Include any necessary comments to explain the code for readability.
Use meaningful variable names and follow consistent formatting.
Task:

Provide the complete content of the dff.cpp file based on the above specifications.