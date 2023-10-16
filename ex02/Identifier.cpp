#include <iostream>
#include <cstdlib>
#include "Identifier.hpp"
#include "DerivedClasses.hpp"

Base* Identifier::generate() {
    int random = std::rand() % 3;
    if (random == 0) return new A;
    if (random == 1) return new B;
    return new C;
}

void Identifier::identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr) std::cout << "A\n";
    else if (dynamic_cast<B*>(p) != nullptr) std::cout << "B\n";
    else if (dynamic_cast<C*>(p) != nullptr) std::cout << "C\n";
}

void Identifier::identify(Base& p) {
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "A\n";
    } catch (...) {
        try {
            static_cast<void>(dynamic_cast<B&>(p));
            std::cout << "B\n";
        } catch (...) {
            std::cout << "C\n";
        }
    }
}
