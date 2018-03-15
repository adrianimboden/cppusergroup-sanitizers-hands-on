#include <iostream>

int foo(int& a) {
    return a;
}

int main() {
    int a;
    if (foo(a)) {
        std::cout << "true";
    } else {
        std::cout << "false";
    }
}

