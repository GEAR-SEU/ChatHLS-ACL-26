Create a counter.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that performs a counter operation, counting from 1 to 12 with reset functionality. The counter should increment on each call and wrap around to 1 after reaching 12. It should also reset to 1 when the reset signal is asserted.

Function Prototype:
```cpp
void counter(bool reset, ap_uint<4>& q);
```

Requirements:
Include Necessary Headers:
    Header Files:
        Include ap_int.h to provide definitions for arbitrary-precision integer data types like ap_uint<4>.
        Include any other standard headers if necessary.

Function Implementation:
    Counter Logic:
        Use a static variable to maintain the state of the counter across function calls.
        When the reset signal is true, set the counter to 1.
        If the counter value reaches 12, the next increment should wrap the counter back to 1.
        On each function call, increment the counter unless the reset is active.

    Output Assignment:
        Assign the current value of the counter to the output parameter q.
    
Coding Standards:
    Clarity and Readability:
        Write clear and concise code with proper indentation.
        Include comments explaining key parts of the code for better understanding.
    HLS Coding Conventions:
        Use HLS-friendly constructs to ensure synthesis compatibility.
        Avoid dynamic memory allocation and recursive functions.
        
Task:
Provide the complete content of the counter.cpp file based on the above specifications.