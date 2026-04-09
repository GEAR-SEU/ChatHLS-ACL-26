Objective:
Implement a High-Level Synthesis (HLS) function that performs a shift left and rotate operation on an 8-bit data input. This function simulates a register that can load data and perform left shift and rotate operations based on control signals.

Function Prototype:
```cpp
void left_rotate(bool_t load, amount_t amount, data_t data, data_t &out);
```