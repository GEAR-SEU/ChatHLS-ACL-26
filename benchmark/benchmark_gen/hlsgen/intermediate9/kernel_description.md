Objective:

Create a hardware module suitable for High-Level Synthesis (HLS) that processes scancode inputs from a PS/2 keyboard and sets corresponding output signals for arrow key presses.

Function Prototype:
<CPP>
void scancodes(scancode_t scancode, out_t* left, out_t* down, out_t* right, out_t* up);

Requirements:

Initialization:

Before processing, initialize all output signals (left, down, right, up) to false.
Scancode Processing:

Use combinational logic (such as a switch statement or if-else blocks) to compare the input scancode against the specified scancode mappings for the arrow keys.
Set the corresponding output signal to true if a match is found.
Scancode Mappings:

Scancode (ap_uint<16> value)	Corresponding Output Signal
0xE06B	Set left to true
0xE072	Set down to true
0xE074	Set right to true
0xE075	Set up to true
Any other value	All outputs remain false
Function Behavior:

The module should directly assign output signals based on the input scancode without any additional logic or processing.
Ensure that only the output corresponding to the input scancode is set to true, and the others remain false.
Coding Standards:

HLS Optimization:

Ensure that the code is synthesizable with HLS tools like Xilinx Vivado HLS or Intel HLS Compiler.
Use appropriate HLS pragmas if necessary to optimize for area, latency, or throughput.
Data Types:

Utilize fixed-size data types suitable for hardware synthesis:
Use ap_uint<16> for 16-bit unsigned integers.
Use bool for single-bit signals.
Clarity and Readability:

Write clean and readable code with proper indentation.
Include comments to explain the code logic where necessary.
Coding Conventions:

Follow standard HLS coding conventions and best practices.
Use descriptive names for signals and variables.
Optional Testbench:

Include a testbench module to verify the functionality of the scancodes module.
The testbench should:
Apply various scancode inputs to the scancodes module.
Monitor and display the output signals (left, down, right, up).
Verify that the outputs match the expected results for each test case.
Task:

Implementation:

Provide the complete implementation of the scancodes module in a source file suitable for HLS synthesis.
Include any necessary headers (e.g., ap_int.h for arbitrary-precision integer types).
Ensure that the code is free of syntax errors and ready for synthesis.