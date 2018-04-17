// clang++ -fsanitize=undefined

void foo(int &ref) { (void)ref; }

int main() {
  int *ptr = nullptr;
  foo(*ptr);
}
