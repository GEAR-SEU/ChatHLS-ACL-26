Objective: 
Implement a High-Level Synthesis (HLS) function that implements a Moore state machine with two states (0 and 1), one input in, and one output out. The reset state is 0. The output is high in state 0. If in is low, the state changes.

Function Prototype:
```cpp
void simple_fsm(bool reset, bool in, bool* out);
```