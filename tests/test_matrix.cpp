#include <array>
#include <iostream>

#include "../src/matrix.cpp"

int main() {
    std::array<std::array<int, 2>, 2> arr1{{{1, 2}, {2, 3}}};
    Matrix<int, 2, 2> x(arr1);
    std::array<std::array<int, 2>, 2> arr2{{{0, 2}, {3, 7}}};
    Matrix<int, 2, 2> y(arr2);
    // for (size_t i = 0; i < 2; ++i) {
    //     for (size_t j = 0; j < 2; ++j) {
    //         std::cout << x.array[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }
    // std::cout << x + y;
    std::cout << x * y;
    return 0;
}