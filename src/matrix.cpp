#include "matrix.hpp"

#include <iostream>
#include <stdexcept>

template <typename T>
Matrix<T>::Matrix(int w, int h) {
    if (w <= 0 || h <= 0) throw std::invalid_argument("Razmer...");
    width = w;
    height = h;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Matrix<T> matrix) {
    //
}