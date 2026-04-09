Objective:
Implement a High-Level Synthesis (HLS) function that performs the addition of two 8-bit signed 2's complement numbers, a and b, to produce an 8-bit signed sum s. Also, compute whether a signed overflow has occurred during the addition.

Function Prototype:
```cpp
void signed_adder(din_t a, din_t b, dout_t* s, bool* overflow);
```