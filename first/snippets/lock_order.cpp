#include <iostream>
#include <mutex>

int num = 0;
std::mutex guardA;
std::mutex guardB;

int foo() {
    std::unique_lock lock1{guardA};
    std::unique_lock lock2{guardB};
    return num;
}

int bar() {
    std::unique_lock lock1{guardB};
    std::unique_lock lock2{guardA};
    return num;
}

int main() {
    std::cout << "foo=" << foo() << ", bar=" << bar() << std::endl;
}

