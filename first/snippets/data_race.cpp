#include <future>
#include <iostream>

int main() {
    int a = 0;
    auto future = std::async([&]{
        return a;
    });
    a = 5;
    std::cout << future.get() << std::endl;
}

