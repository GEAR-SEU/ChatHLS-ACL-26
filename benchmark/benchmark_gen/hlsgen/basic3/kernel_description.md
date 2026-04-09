Create a priority_encoder.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that designs a 3-bit priority encoder. The function should accept a 3-bit input and output a 2-bit position value indicating the highest priority bit that is set to '1'. If none of the input bits are high (i.e., input is zero), output zero.

Function Prototype:
```cpp
void priority_encoder(input_t in, output_t* pos);
```

Requirements:
Include Necessary Headers:
    Include the header file that provides the definitions of input_t and output_t. These data types represent signals with specific bit widths and are defined elsewhere (e.g., in priority_encoder.h).

Function Implementation:
    Implement the function priority_encoder such that it examines the input value in and assigns the output pointer pos with the position of the highest priority bit that is set to '1'.

    The priority is defined as follows:
        The highest priority is given to the lowest bit (bit 0). If in[0] is '1', pos should be set to 0.
        If in[0] is '0' and in[1] is '1', pos should be set to 1.
        If in[0] and in[1] are '0' and in[2] is '1', pos should be set to 2.
        If all bits are '0', pos should be set to 0.

    The function should use straightforward conditional statements to determine the position.

Coding Standards:
    Ensure that the code is clear, concise, and adheres to HLS coding conventions.
    Include any necessary comments to explain the code for readability.

Task:
Provide the complete content of the priority_encoder.cpp file based on the above specifications.