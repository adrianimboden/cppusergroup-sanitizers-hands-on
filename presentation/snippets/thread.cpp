// clang++ -fsanitize=thread

#include <thread>

int main() {
  int a = 0;
  auto t1 = std::thread([&] { a = 1; });
  auto t2 = std::thread([&] { a = 2; });
  t1.join();
  t2.join();
}
