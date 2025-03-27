#include "vector.hpp"
#include <stdexcept>
#include <stdlib.h>

template <typename T> Vector<T>::Vector() {
    size = STANDARD_VECTOR_SIZE;
    len = 0;
    array = (T *)(malloc(sizeof(T) * STANDARD_VECTOR_SIZE));
}

template <typename T> void Vector<T>::reallocate() {
    array = (T *)realloc(array, STANDARD_MEMORY_MULTIPLIER * sizeof(T) *
                                    STANDARD_VECTOR_SIZE * size);
    size *= STANDARD_MEMORY_MULTIPLIER;
}

template <typename T> void Vector<T>::pushBack(T value) {
    if (len >= size) {
        reallocate();
    }
    array[len] = value;
    ++len;
}

template <typename T> void Vector<T>::removeElement(int index) {
    if (index < 0 || index >= len) {
        throw std::invalid_argument("Invalid index.");
    }
    for (int i = index; i < len - 1; ++i) {
        array[i] = array[i + 1];
    }
    --len;
    if (len < size / STANDARD_MEMORY_MULTIPLIER) {
        array = (T *)realloc(array, sizeof(T) * STANDARD_VECTOR_SIZE * size /
                                        STANDARD_MEMORY_MULTIPLIER);
        size /= 2;
    }
}