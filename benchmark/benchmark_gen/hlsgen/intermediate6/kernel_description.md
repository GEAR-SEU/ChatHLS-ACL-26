Create a ram.cpp file with the following specifications:

Objective:
Implement a High-Level Synthesis (HLS) function that simulates a RAM (Random Access Memory) module. The function should perform read and write operations based on a write enable signal (we). When we is high (1), the function writes data to the RAM at the specified address. When we is low (0), the function reads data from the RAM at the specified address.

Function Prototype:
```cpp
void ram(data_t data, addr_t addr, bool_t we, data_t& q);
```

Requirements:
Include Necessary Headers:
    Include the header file ram.h that provides the definitions of data_t, addr_t, and bool_t. These data types represent the data, address, and control signals, respectively.
        data_t: Data type for the data input/output (e.g., ap_uint<DATA_WIDTH>).
        addr_t: Data type for the address signal (e.g., ap_uint<ADDR_WIDTH>).
        bool_t: Data type for the write enable (we) signal (1-bit unsigned integer).
    Include any other necessary headers for HLS, such as ap_int.h for arbitrary precision integer types.
    
Function Implementation:
    Implement the function ram with the following behavior:
        Internal RAM Storage:
            Declare a static array to simulate the RAM storage. The size of the array should be 2^ADDR_WIDTH to cover all possible addresses.
            The static array should retain its values between function calls, emulating the behavior of a hardware RAM module.
        Write Operation:
            When the write enable signal we is high (1), write the input data to the RAM at the specified addr.
        Read Operation:
            Assign the value from the RAM at the specified addr to the output q.
            This should happen regardless of the state of we, ensuring that q always reflects the current value at the address addr.
        Sequential Behavior Simulation:
            Since hardware operations occur on clock edges, ensure that the function behaves as if operations are happening sequentially, mimicking clocked behavior.
    Avoid any unnecessary logic or processing beyond what is specified.

Coding Standards:
    Ensure the code is clear, concise, and adheres to HLS coding conventions.
    Include comments to explain the code and enhance readability.
    Use appropriate data types and ensure correct bit-widths to accurately model hardware behavior.
    
Task:
Provide the complete content of the ram.cpp file based on the above specifications.