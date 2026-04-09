Objective:
Implement a High-Level Synthesis (HLS) function that designs a 3-bit priority encoder. The function should accept a 3-bit input and output a 2-bit position value indicating the highest priority bit that is set to '1'. If none of the input bits are high (i.e., input is zero), output zero.

Function Prototype:
```cpp
void priority_encoder(input_t in, output_t* pos);
```