#include "matrix.hpp"

#include <array>
#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T, const std::size_t width, const std::size_t height>
Matrix<T, width, height>::Matrix() {
    if (width <= 0 || height <= 0)
        throw std::invalid_argument("Invalid size...");
}

template <typename T, const std::size_t width, const std::size_t height>
Matrix<T, width, height>::Matrix(
    std::array<std::array<T, height>, width> init_array) {
    if (width <= 0 || height <= 0)
        throw std::invalid_argument("Invalid size...");
    array = init_array;
}

template <typename T, const std::size_t width, const std::size_t height>
std::ostream& operator<<(std::ostream& os, Matrix<T, width, height> matrix) {
    std::cout << width << ' ' << height << '\n';
    for (std::size_t i = 0; i < width; ++i) {
        for (std::size_t j = 0; j < height; ++j) {
            os << matrix.array[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}