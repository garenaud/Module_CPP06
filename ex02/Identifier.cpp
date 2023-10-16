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
        if (dynamic_cast<A*>(&p) != nullptr) {
            std::cout << "A\n";
        } else if (dynamic_cast<B*>(&p) != nullptr) {
            std::cout << "B\n";
        } else if (dynamic_cast<C*>(&p) != nullptr) {
            std::cout << "C\n";
        }
    } catch (...) {
        std::cout << "Unknown Type\n"; // Gestion de l'échec du cast
    }
}
