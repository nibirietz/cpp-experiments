#ifndef LONG_ARITHMETHIC_HPP
#define LONG_ARITHMETHIC_HPP
#include <cstdint>
#include <string>
#include <vector>
const int SIZE_OF_CHUNK = 8;

class BigInteger {
  public:
    BigInteger(std::string number);

  private:
    std::vector<int64_t> array;
};

#endif
