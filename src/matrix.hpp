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
};

#endif