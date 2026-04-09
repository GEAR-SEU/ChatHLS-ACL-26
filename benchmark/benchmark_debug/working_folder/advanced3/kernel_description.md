Create an adv_fsm.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that implements a finite state machine (FSM) that recognizes the sequence 101 on the input signal x. The output signal z is asserted to 1 when the sequence 101 is detected.

Function Prototype:
```cpp
void adv_fsm(input_t reset, input_t x, output_t* z);
```

Requirements:
Include Necessary Headers:
Include the header file adv_fsm.h that provides the definitions of input_t and output_t. These data types represent single-bit signals and are defined elsewhere.

Function Implementation:
Implement the function adv_fsm such that it implements a finite state machine with the following specifications:

States:

The FSM has four states:
IDLE (state 0)
S1 (state 1)
S10 (state 2)
S101 (state 3)
Output Signal:

The output signal z is asserted to 1 when the FSM reaches the S101 state.

State Transition Logic:
When reset is active (1):
The FSM transitions to the IDLE state.
Otherwise:
If the present state is IDLE:
If x is 1, the next state is S1.
Else, the next state remains at IDLE.
If the present state is S1:
If x is 0, the next state is S10.
Else, the next state remains at IDLE.
If the present state is S10:
If x is 1, the next state is S101.
Else, the next state remains at IDLE.
If the present state is S101:
The next state is assigned to IDLE.
State Maintenance:

The FSM should maintain its state between function calls, simulating sequential hardware behavior.

Coding Standards:
Ensure that the code is clear, concise, and adheres to HLS coding conventions.
Include any necessary comments to explain the code for readability.
Use appropriate HLS pragmas if required to guide synthesis (e.g., interface specifications).

Task:
Provide the complete content of the adv_fsm.cpp file based on the above specifications.