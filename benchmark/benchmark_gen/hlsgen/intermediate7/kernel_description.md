Create a truthtable.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that implements the logic function specified by the following truth table:

x3	x2	x1	f
0	0	0	1
0	0	1	1
0	1	0	0
0	1	1	1
1	0	0	0
1	0	1	0
1	1	0	1
1	1	1	0

Function Prototype:
```cpp
void truthtable(input_t x3, input_t x2, input_t x1, output_t* f);
```

Requirements:
    Include Necessary Headers:
        Include the header file that provides the definitions of input_t and output_t. These data types represent single-bit signals and are defined elsewhere (e.g., in truthtable.h).
    Function Implementation:
        Implement the function truthtable such that it computes the output f based on the inputs x3, x2, and x1, according to the provided truth table.
        The function should accurately reflect the logic specified in the truth table.
        Optimize the implementation by deriving a simplified Boolean expression if possible.

Coding Standards:
    Ensure that the code is clear, concise, and adheres to HLS coding conventions.
    Include any necessary comments to explain the code for readability.
    The implementation should be suitable for synthesis using HLS tools.

Task:
Provide the complete content of the truthtable.cpp file based on the above specifications.