Objective:
Implement a High-Level Synthesis (HLS) function that models a Mealy finite-state machine (FSM) for a 2's complementer. The FSM should use one-hot encoding for states, implement an asynchronous active-high reset, and conform to the specified state transitions and outputs.

Function Prototype:
```cpp
void fsm(logic x, logic areset, logic& z);
```