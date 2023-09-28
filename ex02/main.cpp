#include <iostream>
#include <ctime>
#include "Identifier.hpp"

int main() {
    std::srand(std::time(0));
    
    Base* ptr = Identifier::generate();
    Identifier::identify(ptr);
    Identifier::identify(*ptr);

    delete ptr;
    return 0;
}
