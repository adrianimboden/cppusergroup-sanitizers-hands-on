#include <iostream>
#include <set>

int main() {
    std::set<int> numbers{0, 1, 2, 3, 4, 6, 7};
    
    //remove even numbers
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        const auto number = *it;
        if ((number % 2) == 0) {
            numbers.erase(it);
        }
    }
    
    std::for_each(numbers.begin(), numbers.end(), [](auto number) {
        std::cout << number << "\n";
    });
}

