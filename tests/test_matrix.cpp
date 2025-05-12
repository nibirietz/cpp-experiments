#include <array>
#include <iostream>

#include "../src/matrix.cpp"

int main() {
    std::array<std::array<int, 2>, 2> arr{{{1, 2}, {2, 3}}};
    Matrix<int, 2, 2> x(arr);
    // for (size_t i = 0; i < 2; ++i) {
    //     for (size_t j = 0; j < 2; ++j) {
    //         std::cout << x.array[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }
    std::cout << x;
    return 0;
}