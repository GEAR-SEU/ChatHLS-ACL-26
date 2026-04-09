Create a left_rotate.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that performs a shift left and rotate operation on an 8-bit data input. This function simulates a register that can load data and perform left shift and rotate operations based on control signals.

Function Prototype:
```cpp
void left_rotate(bool_t load, amount_t amount, data_t data, data_t &out);
```

Requirements:
Include Necessary Headers:
    Include the header file left_rotate.h that provides the definitions of the data types:
        bool_t: Represents the load control signal (1-bit unsigned integer).
        amount_t: Represents the shift amount (3-bit unsigned integer).
        data_t: Represents the data inputs and outputs (8-bit unsigned integer).
    Include any other necessary headers for HLS, such as ap_int.h for arbitrary precision integer types.

Function Implementation:
Implement the function left_rotate with the following behavior:
    Load Operation:
        If the load signal is high (1), load the input data into an internal register.
    Shift Left and Rotate Operation:
        If the load signal is low (0), perform a shift left and rotate operation on the internal register out by the number of bits specified by amount.
        The rotation should bring the bits that overflow on the left back to the right side.
        For amount equal to 0, the output remains unchanged.
    State Preservation:
        Use a static variable or appropriate HLS constructs to maintain the state of the internal register between function calls, simulating a hardware register.

Coding Standards:
    Ensure the code is clear, concise, and adheres to HLS coding conventions.
    Include comments to explain the code and enhance readability.
    Avoid any unnecessary logic or processing beyond what is specified.

Task:
Provide the complete content of the left_rotate.cpp file based on the above specifications.