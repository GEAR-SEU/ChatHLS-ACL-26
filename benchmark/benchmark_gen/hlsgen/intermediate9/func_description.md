Objective:
Create a hardware module suitable for High-Level Synthesis (HLS) that processes scancode inputs from a PS/2 keyboard and sets corresponding output signals for arrow key presses.

Function Prototype:
```cpp
void scancodes(scancode_t scancode, out_t* left, out_t* down, out_t* right, out_t* up);
```