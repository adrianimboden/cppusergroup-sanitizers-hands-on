#include <cstring>
#include <iostream>

int main() {
    char str[] = "once";
    strcpy(str, "twice");
    std::cout << str << std::endl;
}
