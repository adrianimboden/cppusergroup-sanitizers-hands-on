#include <iostream>
#include <array>

struct Data {
    uint8_t foo;
    uint8_t bar; //<- change to uint16_t
};

int main() {
    Data a;
    Data b;
    
    a = {1, 2};
    b = {1, 2};
    
    if (memcmp(&a, &b, sizeof(Data)) == 0) {
        std::cerr << "equal" << std::endl;
    } else {
        std::cerr << "not equal" << std::endl;
    }
}

