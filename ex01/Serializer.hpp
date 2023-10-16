#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>  // pour uintptr_t

struct Data {
    int a;
    float b;
    // Ajoutez d'autres membres si nécessaire
};

class Serializer {
private:
    Serializer() {}  // Constructeur privé
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
