#include "ram.h"

// RAM size
#define RAM_SIZE (1 << ADDR_WIDTH)

// RAM function implementing the RAM module behavior
void ram(data_t data, addr_t addr, bool_t we, data_t& q) {
    // Static RAM array to maintain state between function calls
    static data_t ram[RAM_SIZE];

    // Write operation on positive clock edge (simulated by function call)
    if (we) {
        ram[addr] = data;
    }
    // Read operation
    q = ram[addr];
}
