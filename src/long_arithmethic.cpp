#include "long_arithmethic.hpp"
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

BigInteger::BigInteger(std::string number) {
    for (int i = number.size() - SIZE_OF_CHUNK; i >= -7; i -= 8) {
        int64_t chunk;
        if (i > 0) {
            chunk = std::stoi(number.substr(i, SIZE_OF_CHUNK));
        } else {
            chunk = std::stoi(number.substr(0, SIZE_OF_CHUNK + i));
        }
        array.push_back(chunk);
    }
}
BigInteger::BigInteger() { array.push_back(0); }

std::ostream& operator<<(std::ostream& os, const BigInteger self) {
    os << self.array[self.array.size() - 1];
    for (int i = 0; i < self.array.size() - 1; ++i) {
        std::string chunk =
            std::to_string(self.array[self.array.size() - i - 2]);
        for (int j = 0; j < 8 - chunk.size(); ++j) {
            os << '0';
        }
        os << chunk;
    }
    return os;
}

BigInteger operator+(const BigInteger first, const BigInteger second) {
    BigInteger result;
    for (int i = 0; i < std::max(first.array.size(), second.array.size());
         ++i) {
        int64_t chunk1;
        int64_t chunk2;
        if (i >= first.array.size())
            chunk1 = 0;
        else
            chunk1 = first.array[i];
        if (i >= second.array.size())
            chunk2 = 0;
        else
            chunk2 = second.array[i];
        if (i == result.array.size() - 1) {
            result.array[i] += chunk1 + chunk2;
        } else {
            result.array.push_back(chunk1 + chunk2);
        }
        if (std::abs(result.array[i]) > 9999999) {
            result.array.push_back(result.array[i] / 100000000);
            result.array[i] %= 100000000;
        }
    }
    return result;
}
