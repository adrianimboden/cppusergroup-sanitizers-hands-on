// clang++ -fsanitize=address

void foo(int *out) { *out = 5; }

int main() { foo(nullptr); }
