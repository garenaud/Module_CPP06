#ifndef IDENTIFIER_HPP
#define IDENTIFIER_HPP

#include "Base.hpp"

class Identifier {
private:
    Identifier() {}  // Constructeur privé
    Identifier(const Identifier& other);
    Identifier& operator=(const Identifier& other);
public:
    static Base* generate();
    static void identify(Base* p);
    static void identify(Base& p);
};

#endif // IDENTIFIER_HPP
