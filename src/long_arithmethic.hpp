#ifndef LONG_ARITHMETHIC_HPP
#define LONG_ARITHMETHIC_HPP
#include <cstdint>
#include <ostream>
#include <string>
#include <vector>
const int SIZE_OF_CHUNK = 8;

class BigInteger {
  public:
    BigInteger();
    BigInteger(std::string number);
    friend std::ostream& operator<<(std::ostream& os, const BigInteger self);
    friend BigInteger operator+(const BigInteger first,
                                const BigInteger second);

  private:
    std::vector<int64_t> array;
};

#endif
