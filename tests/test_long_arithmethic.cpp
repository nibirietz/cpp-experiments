#include "../src/long_arithmethic.cpp"

int main() {
    BigInteger tst(std::string("9999999999999999"));
    std::cout << tst << '\n';
    BigInteger tst2(std::string("1"));
    std::cout << tst2 << '\n';
    std::cout << tst + tst2 << '\n';
    return 0;
}
