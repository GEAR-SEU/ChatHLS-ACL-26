#include "left_rotate.h"

void left_rotate(bool_t load, amount_t amount, data_t data, data_t &out) {
    static data_t reg_out = 0; 

    if (load) {
        reg_out = data_temp;
    } else {
        switch (amount) {
            case 0:
                
                break;
            case 1:
                reg_out = (reg_out << 1) | (reg_out >> 7);
                break;
            case 2:
                reg_out = (reg_out << 2) | (reg_out >> 6);
                break;
            case 3:
                reg_out = (reg_out << 3) | (reg_out >> 5);
                break;
            case 4:
                reg_out = (reg_out << 4) | (reg_out >> 4);
                break;
            case 5:
                reg_out = (reg_out << 5) | (reg_out >> 3);
                break;
            case 6:
                reg_out = (reg_out << 6) | (reg_out >> 2);
                break;
            case 7:
                reg_out = (reg_out << 7) | (reg_out >> 1);
                break;
            default:
                
                break;
        }
    }
    out = reg_out;
}
