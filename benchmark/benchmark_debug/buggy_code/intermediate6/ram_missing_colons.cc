#include "ram.h"


#define RAM_SIZE (1 << ADDR_WIDTH)


void ram(data_t data, addr_t addr, bool_t we, data_t& q) {
    
    static data_t ram[RAM_SIZE]

    
    if (we) {
        ram[addr] = data;
    }
    
    q = ram[addr];
}
