#include <iostream>

using CallbackType = void(*)();
static CallbackType s_callback = nullptr;

//never called:
void enable_destruction_sequence() {
    s_callback = []{
        std::cout << "calling rm -rf /..." << std::endl;
    };
}

int main() {
    s_callback();
}

