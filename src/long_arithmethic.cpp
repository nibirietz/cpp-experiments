#include "long_arithmethic.hpp"
#include <iostream>

BigInteger::BigInteger(std::string number) {
    for (int i = number.size() - SIZE_OF_CHUNK; i >= -7; i -= 8) {
        if (i > 0) {
            int64_t chunk = std::stoi(number.substr(i, SIZE_OF_CHUNK));
            std::cout << chunk << '\n';
        }
        int64_t chunk = std::stoi(number.substr(0, SIZE_OF_CHUNK + i));
        std::cout << chunk << '\n';
    }
}
