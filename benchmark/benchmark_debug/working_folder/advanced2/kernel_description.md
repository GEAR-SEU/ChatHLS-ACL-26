Create a count_slow.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that builds a decade counter counting from 0 through 9, inclusive, with a period of 10. The counter should:
    Increment its value from 0 to 9 when enabled.
    Reset to 0 synchronously when the reset signal is active.
    Pause counting when the enable signal (slowena) is inactive.
    Maintain its state between function calls, simulating sequential hardware behavior.

Function Prototype:
```cpp
void count_slow(input_t reset, input_t slowena, output_t* q);
```

Requirements:
    Include Necessary Headers:
        Include the header file count_slow.h that provides the definitions of input_t and output_t. These data types represent the input and output signals of appropriate bit widths and are defined elsewhere.

    Function Implementation:
        Implement the function count_slow such that it:
            Uses a static variable to maintain the counter state between function calls.
            Increments the counter from 0 to 9 when slowena is high.
            Resets the counter to 0 when reset is high.
            Pauses counting when slowena is low, retaining the current count value.
            Wraps around to 0 after reaching 9.
        The function should directly perform these operations without any additional logic or processing.

    Coding Standards:
        Ensure that the code is clear, concise, and adheres to HLS coding conventions.
        Include necessary comments to explain the code for readability and maintainability.
        Use appropriate HLS pragmas if required to guide synthesis (e.g., interface specifications).

Task:
Provide the complete content of the count_slow.cpp file based on the above specifications.