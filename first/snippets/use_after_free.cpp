#include <iostream>
#include <functional>
#include <memory>
#include <vector>

class Foo {
public:
    int getActive() {
        return *pCurrentlyActiveCase;
    }
    
    void toggle() {
        if (pCurrentlyActiveCase == &caseA) {
            pCurrentlyActiveCase = &caseB;
        } else {
            pCurrentlyActiveCase = &caseA;
        }
    }
    
private:
    int* pCurrentlyActiveCase = &caseA;
    int caseA = 1;
    int caseB = 2;
};



int main() {
    std::vector<Foo> elements;
    for (size_t i = 0; i < 100; ++i) {
        elements.push_back(Foo{});
    }
    std::cerr << elements[0].getActive() << std::endl;
}

