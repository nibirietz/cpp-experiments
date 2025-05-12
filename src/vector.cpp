#include "vector.hpp"

#include <stdlib.h>

#include <stdexcept>

template <typename T>
Vector<T>::Vector() {
    size = STANDARD_VECTOR_SIZE;
    len = 0;
    array = (T *)(malloc(sizeof(T) * STANDARD_VECTOR_SIZE));
}

template <typename T>
Vector<T>::Vector(T arr[]) {
    len = sizeof(arr) / sizeof(T);
    reallocate();
    for (int i = 0; i < size; ++i) {
        array[i] = arr[i];
    }
}

template <typename T>
void Vector<T>::reallocate() {
    array = (T *)realloc(array, STANDARD_MEMORY_MULTIPLIER * sizeof(T) *
                                    STANDARD_VECTOR_SIZE * size);
    size *= STANDARD_MEMORY_MULTIPLIER;
}

template <typename T>
void Vector<T>::pushBack(T value) {
    if (len >= size) {
        reallocate();
    }
    array[len] = value;
    ++len;
}

template <typename T>
void Vector<T>::removeElement(int index) {
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
        size /= STANDARD_MEMORY_MULTIPLIER;
    }
}

template <typename T>
void Vector<T>::insertElement(int index, T value) {
    if (index < 0 || index >= len) {
        throw std::invalid_argument("Invalid index.");
    }
    if (len >= size) {
        reallocate();
    }
    for (int i = index; i < len; ++i) {
        array[len + index - i] = array[len + index - i - 1];
    }
    array[index] = value;
    ++len;
}

template <typename T>
T Vector<T>::operator[](int index) {
    if (array == nullptr) {
        throw std::invalid_argument("Invalid index.");
    }
    if (index < 0 || index >= len) {
        throw std::invalid_argument("Invalid index.");
    }

    return array[index];
}

template <typename T>
T Vector<T>::searchElement(T value) {
    for (int i = 0; i < len; ++i) {
        if (array[i] == value) return i;
    }

    return -1;
}