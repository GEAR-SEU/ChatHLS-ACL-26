Create a mux.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that performs the function of a 2-to-1 multiplexer, where the output is selected from one of two inputs based on a selection signal.

Function Prototype:
```cpp
void mux(data_t a, data_t b, sel_t sel, data_t* out);
```

Requirements:
    Include Necessary Headers:
        Include the header file that provides the definitions of data_t and sel_t. These data types represent the input and output signals and the selection signal, and are defined elsewhere (e.g., in mux.h).

    Function Implementation:
        Implement the function mux such that it assigns the value of a or b to the output pointer out based on the selection signal sel.
            When sel == 0, assign a to out.
            When sel == 1, assign b to out.
        The function should directly perform this selection without any additional logic or processing.

    Coding Standards:
        Ensure that the code is clear, concise, and adheres to HLS coding conventions.
        Include any necessary comments to explain the code for readability.

Task:
Provide the complete content of the mux.cpp file based on the above specifications.