// clang++ -fsanitize=leak

#include <memory>

int main() {
  auto num = std::make_unique<int>();
  num.release();
}
