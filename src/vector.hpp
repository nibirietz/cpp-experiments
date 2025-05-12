#ifndef VECTOR_H
#define VECTOR_H

const int STANDARD_VECTOR_SIZE = 16;
const int STANDARD_MEMORY_MULTIPLIER = 2;

template <typename T>
class Vector {
   private:
    int size;
    int len;
    void reallocate();
    T* array;

   public:
    Vector();
    Vector(T arr[]);
    void pushBack(T value);
    void removeElement(int index);
    int length() { return len; }
    void insertElement(int index, T value);
    T searchElement(T value);
    T operator[](int index);
};

#endif
