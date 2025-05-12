#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <cstddef>
template <typename T, const std::size_t width, const std::size_t height>
class Matrix {
   public:
    Matrix();
    Matrix(std::array<std::array<T, height>, width>);
    std::array<std::array<T, height>, width> array;
    void initialize_matrix(std::array<std::array<T, height>, width>);
    Matrix<T, width, height> operator+(Matrix<T, width, height>);
    Matrix<T, width, height> operator-(Matrix<T, width, height>);
    template <const std::size_t height2>
    Matrix<T, width, height> operator*(Matrix<T, height, height2>);
    Matrix<T, width, height> operator*(T scalar);
    T determinant();
};

#endif