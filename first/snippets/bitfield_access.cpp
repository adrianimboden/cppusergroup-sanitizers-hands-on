#include <iostream>
#include <future>

struct SuperDense {
    int a: 3;
    int b: 3;
    
    std::mutex guardA;
    std::mutex guardB;
};

int main() {
    SuperDense obj;
    auto fut1 = std::async([&]{
        std::unique_lock lock{obj.guardA};
        obj.a = 2;
    });
    auto fut2 = std::async([&]{
        std::unique_lock lock{obj.guardB};
        obj.b = 3;
    });
    fut1.get();
    fut2.get();
    std::cerr << "a=" << obj.a << ", b=" << obj.b << std::endl;
}

