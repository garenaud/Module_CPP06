#include <iostream>
#include "Serializer.hpp"

int main() {
    Data originalData;
    originalData.a = 42;
    originalData.b = 3.14;

    uintptr_t raw = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(raw);

    if (deserializedData == &originalData) {
        std::cout << "La sérialisation et la désérialisation ont réussi." << std::endl;
    } else {
        std::cout << "Échec de la sérialisation/désérialisation." << std::endl;
    }

    return 0;
}
