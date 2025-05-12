#include "matrix.hpp"

#include <array>
#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T, const std::size_t width, const std::size_t height>
Matrix<T, width, height>::Matrix() {
    if (width <= 0 || height <= 0)
        throw std::invalid_argument("Invalid size...");
    for (std::size_t i = 0; i < width; ++i) {
        for (std::size_t j = 0; j < height; ++j) {
            array[i][j] = 0;
        }
    }
}

template <typename T, const std::size_t width, const std::size_t height>
Matrix<T, width, height>::Matrix(
    std::array<std::array<T, height>, width> init_array) {
    if (width <= 0 || height <= 0)
        throw std::invalid_argument("Invalid size...");
    array = init_array;
}

template <typename T, const std::size_t width, const std::size_t height>
Matrix<T, width, height> Matrix<T, width, height>::operator+(
    Matrix<T, width, height> another_matrix) {
    Matrix<T, width, height> result_matrix;
    for (std::size_t i = 0; i < width; ++i) {
        for (std::size_t j = 0; j < height; ++j) {
            result_matrix.array[i][j] =
                array[i][j] + another_matrix.array[i][j];
        }
    }
    return result_matrix;
}
template <typename T, const std::size_t width, const std::size_t height>
template <const std::size_t height2>
Matrix<T, width, height> Matrix<T, width, height>::operator*(
    Matrix<T, height, height2> another_matrix) {
    Matrix<T, width, height2> result_matrix{};
    for (std::size_t i = 0; i < width; ++i) {
        for (std::size_t k = 0; k < height2; ++k) {
            for (std::size_t j = 0; j < height; ++j) {
                result_matrix.array[i][k] +=
                    array[i][j] * another_matrix.array[j][k];
            }
        }
    }
    return result_matrix;
}

template <typename T, const std::size_t width, const std::size_t height>
T Matrix<T, width, height>::determinant() {
    if constexpr (width != height) {
        return -1;
    } else if constexpr (width == 0) {
        return -1;
    } else if constexpr (width == 1) {
        return array[0][0];
    } else {
        T det = 0;
        for (std::size_t j = 0; j < height; ++j) {
            std::array<std::array<T, width - 1>, width - 1> sub_array;
            for (std::size_t i = 1; i < width; ++i) {
                std::array<T, width - 1> row;
                std::size_t is_j = 0;
                for (std::size_t k = 0; k < width; ++k) {
                    if (k == j) {
                        is_j = 1;
                        continue;
                    }
                    row[k - is_j] = array[i][k];
                }
                sub_array[i - 1] = row;
            }
            Matrix<T, width - 1, width - 1> sub_matrix(sub_array);
            if (j % 2 == 0) {
                det += (array[0][j] * sub_matrix.determinant());
            } else {
                det -= (array[0][j] * sub_matrix.determinant());
            }
        }

        return det;
    }
}
template <typename T, const std::size_t width, const std::size_t height>
std::ostream& operator<<(std::ostream& os, Matrix<T, width, height> matrix) {
    for (std::size_t i = 0; i < width; ++i) {
        for (std::size_t j = 0; j < height; ++j) {
            os << matrix.array[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}