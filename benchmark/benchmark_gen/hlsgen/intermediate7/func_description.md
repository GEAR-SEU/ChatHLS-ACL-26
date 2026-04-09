Objective:
Implement a High-Level Synthesis (HLS) function that implements the logic function specified by the following truth table:

x3	x2	x1	f
0	0	0	1
0	0	1	1
0	1	0	0
0	1	1	1
1	0	0	0
1	0	1	0
1	1	0	1
1	1	1	0

Function Prototype:
```cpp
void truthtable(input_t x3, input_t x2, input_t x1, output_t* f);
```