Objective:

Implement a High-Level Synthesis (HLS) function that builds a 64-bit arithmetic shift register with synchronous load. The shift register can shift both left and right by 1 or 8 bit positions, selected by the amount input.

Function Prototype:

```cpp
void advshift(bool load, bool ena, ap_uint<2> amount, ap_uint<64> data, ap_uint<64> *q);
```