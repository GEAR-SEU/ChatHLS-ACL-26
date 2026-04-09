Create an fsm.cpp file with the following specifications:
Objective:

Implement a High-Level Synthesis (HLS) function that models a Mealy finite-state machine (FSM) for a 2's complementer. The FSM should use one-hot encoding for states, implement an asynchronous active-high reset, and conform to the specified state transitions and outputs.

Function Prototype:

<CPP>
void fsm(logic x, logic areset, logic& z);
Requirements:

Include Necessary Headers:

Include the header file that provides the definition of the logic data type, representing single-bit signals (e.g., using ap_int.h).
Function Implementation:

Implement the FSM with the following characteristics:
States: A and B (one-hot encoded).
State Encoding: Use one-hot encoding for states.
Reset: Asynchronous active-high reset that sets the FSM to state A.
State Transitions:
State A:
On input x=0, stay in state A, output z=0.
On input x=1, transition to state B, output z=1.
State B:
On input x=0, stay in state B, output z=1.
On input x=1, stay in state B, output z=0.
Clocking: Assume all sequential logic is triggered on the positive edge of the clock.
The function should directly model the FSM behavior without any additional logic or processing.
Coding Standards:

Ensure that the code is clear, concise, and adheres to HLS coding conventions.
Include necessary comments to explain the code for readability.
Use appropriate HLS pragmas if needed (e.g., for reset behavior).
Task:

Provide the complete content of the fsm.cpp file based on the above specifications.