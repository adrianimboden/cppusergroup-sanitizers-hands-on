// clang++ -fsanitize=memory

#include <iostream>

int calc_area(const int &x, const int &y) { return x * y; }

int main() {
  int x = 4;
  int y;
  if (calc_area(x, y) > 5) {
    std::cout << "good" << std::endl;
  }
}
