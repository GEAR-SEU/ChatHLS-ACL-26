Objective:
Implement a High-Level Synthesis (HLS) function that performs a counter operation, counting from 1 to 12 with reset functionality. The counter should increment on each call and wrap around to 1 after reaching 12. It should also reset to 1 when the reset signal is asserted.

Function Prototype:
```cpp
void counter(bool reset, ap_uint<4>& q);
```