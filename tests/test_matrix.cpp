#include <array>
#include <iostream>

#include "../src/matrix.cpp"

int main() {
    std::array<std::array<int, 2>, 2> arr1{{{1, 2}, {2, 3}}};
    Matrix<int, 2, 2> x(arr1);
    std::array<std::array<int, 2>, 2> arr2{{{0, 2}, {3, 7}}};
    Matrix<int, 2, 2> y(arr2);
    std::cout << x.determinant() << ' ';
    std::cout << y.determinant() << ' ';
    std::array<std::array<int, 3>, 3> arr3 = {
        {{1, 2, 3}, {0, 2, 7}, {0, 0, 1}}};
    Matrix<int, 3, 3> z(arr3);
    std::cout << z.determinant() << '\n';
    std::cout << 2 * x << '\n' << x * 2;
    return 0;
}