Create an advshift.cpp file with the following specifications:

Objective:

Implement a High-Level Synthesis (HLS) function that builds a 64-bit arithmetic shift register with synchronous load. The shift register can shift both left and right by 1 or 8 bit positions, selected by the amount input.

Function Prototype:

```cpp
void advshift(bool load, bool ena, ap_uint<2> amount, ap_uint<64> data, ap_uint<64> *q);
```

Requirements:

Include Necessary Headers:

Include the header file that provides the definitions of ap_uint and any other necessary types (e.g., ap_int.h). These data types support arbitrary precision integers and are essential for HLS.
Function Implementation:

Implement the function advshift with the following behavior:

Shift Register Initialization:

Use a static variable to represent the 64-bit shift register (q) that retains its value between function calls, mimicking the behavior of a hardware register.
Synchronous Load:

If the load signal is high (true), load the input data into the shift register q.
Shift Operation:

If the ena signal is high (true) and load is low (false), perform a shift operation based on the amount input:
2'b00: Shift left by 1 bit.
2'b01: Shift left by 8 bits.
2'b10: Shift right by 1 bit.
2'b11: Shift right by 8 bits.
Output Assignment:

Assign the current value of the shift register to the output pointer q.

Coding Standards:

Ensure that the code is clear, concise, and adheres to HLS coding conventions.
Include necessary comments to explain the code for readability.
Avoid any additional logic or processing not specified in the requirements.

Task:

Provide the complete content of the advshift.cpp file based on the above specifications.