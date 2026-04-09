Objective:
Implement a High-Level Synthesis (HLS) function that simulates a RAM (Random Access Memory) module. The function should perform read and write operations based on a write enable signal (we). When we is high (1), the function writes data to the RAM at the specified address. When we is low (0), the function reads data from the RAM at the specified address.

Function Prototype:
```cpp
void ram(data_t data, addr_t addr, bool_t we, data_t& q);
```