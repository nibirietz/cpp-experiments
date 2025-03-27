#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>

const int STANDARD_VECTOR_SIZE = 10;
const int STANDARD_MEMORY_MULTIPLIER = 2;

template <typename T> class Vector {
  private:
    int size;
    int len;
    void reallocate();

  public:
    T *array;
    Vector();
    void pushBack(T value);
    void removeElement(int index);
    int length() { return len; }

    T operator[](int index) {
        if (array == nullptr) {
            throw std::invalid_argument("");
        }
        if (index < 0 || index >= len)
            throw std::invalid_argument("Invalid index.");
        return array[index];
    }
};

#endif
