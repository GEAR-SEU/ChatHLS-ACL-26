Create a simple_fsm.cpp file with the following specifications:

Objective: 
Implement a High-Level Synthesis (HLS) function that implements a Moore state machine with two states (0 and 1), one input in, and one output out. The reset state is 0. The output is high in state 0. If in is low, the state changes.

Function Prototype:
```cpp
void simple_fsm(bool reset, bool in, bool* out);
```

Requirements:

Include Necessary Headers:
    Include the header file that provides the definitions of any necessary data types or constants. These may include standard types like bool or HLS-specific types if required.
    The header file should be named appropriately (e.g., simple_fsm.h) and should contain any necessary declarations.

Function Implementation:
    Implement the simple_fsm function such that it accurately represents the specified Moore state machine.
    State Machine Details:
        States:
            The FSM has two states: STATE_0 and STATE_1, which can be represented using an appropriate data type (e.g., ap_uint<1> or unsigned char).
        Reset Behavior:
            When the reset signal is true, the FSM should reset to STATE_0.
        State Transition Logic:
            If in is low (false), the FSM changes state (toggles between STATE_0 and STATE_1).
            If in is high (true), the FSM remains in the current state.
        Output Logic:
            The FSM is a Moore machine, so the output out depends only on the current state.
            When in STATE_0, the output out should be high (true).
            When in STATE_1, the output out should be low (false).
    Implementation Details:
        Use a static variable to maintain the state between function calls.
        Ensure that the function updates the state and output correctly based on the input parameters.
        Avoid any unnecessary logic or processing beyond the specified functionality.

Coding Standards:
    Ensure that the code is clear, concise, and adheres to HLS coding conventions.
    Include necessary comments to explain the code for readability.
    Use appropriate data types provided by the HLS libraries (e.g., ap_uint from ap_int.h if needed).
    Ensure the code is suitable for synthesis using HLS tools.

Task:
Provide the complete content of the simple_fsm.cpp file based on the above specifications.