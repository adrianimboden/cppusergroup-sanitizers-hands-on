#include <iostream>
#include <array>

int main() {
    int a = 3;
    std::array<int, 2> arr{{1,2}};
    for (size_t i = 0; i <= 2; ++i) {
        std::cout << arr[i] << std::endl;
    }
    (void)a;
}

