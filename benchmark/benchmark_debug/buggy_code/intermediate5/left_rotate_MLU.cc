#include "left_rotate.h"

void left_rotate(bool_t load, amount_t amount, data_t data, data_t &out) {
    static data_t reg_out = 0; 

    if (load) {
        reg_out = data;
    } else {
        switch (amount) {
            case 0: 
                break;
            default: 
                for (int i = 0; i < 8; i+=2) { 
                    if (amount == i + 1) {
                        reg_out = (reg_out << (i + 1)) | (reg_out >> (8 - (i + 1)));
                        break;
                    }
                }
                break;
        }
    }
    out = reg_out;
}
