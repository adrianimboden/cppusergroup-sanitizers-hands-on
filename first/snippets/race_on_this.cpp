#include <iostream>
#include <thread>
#include <memory>

std::mutex callbackGuard;
std::function<void()> callback = nullptr;

void set_callback(std::function<void()> fn) {
    std::unique_lock guard{callbackGuard};
    callback = fn;
}

std::function<void()> get_callback() {
    std::unique_lock guard{callbackGuard};
    return callback;
}

class Foo {
public:
    Foo() {
        //register myself
        set_callback([this] {
            ++data;
        });
    }
    
    ~Foo() {
        //unregister myself
        set_callback(nullptr);
    }
            
private:
    std::atomic<int> data = 0;
};

int main() {
    std::atomic<bool> stop{false};
    std::atomic<bool> started{false};
    auto ptrFoo = std::make_unique<Foo>();
    
    std::thread secondThread{[&]{
        while (not stop) {
            if (const auto callback = get_callback()) {
                callback();
            }
            started = true;
        }
    }};
    
    while (not started) ;
    
    ptrFoo.reset();
    stop = true;
    secondThread.join();
}

