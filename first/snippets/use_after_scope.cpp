#include <iostream>
#include <functional>

std::function<int()> foo(int a) {
    return [&]{
        return a + 6;
    };
}

int main() {
    auto fn = foo(6);
    std::cout << fn() << std::endl;
}

