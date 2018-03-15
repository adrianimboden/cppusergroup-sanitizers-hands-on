#include <iostream>
#include <functional>
#include <memory>
#include <vector>

struct Database {
    std::function<void()> table1ChangedCallback;
    
    void insertIntoTable1() {
        table1ChangedCallback();
    }
    
    void insertIntoTable2() {
        //...
    }
};



int main() {
    const auto ptrDatabase = std::make_shared<Database>();
    
    ptrDatabase->table1ChangedCallback = [=]{
        //...
        ptrDatabase->insertIntoTable2(/*...*/);
        //...
    };
    
    //...
}

