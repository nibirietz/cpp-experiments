#include "../src/vector.cpp"

#include <iostream>

int main() {
    // Vector<int> vector;
    // for (int i = 0; i < 10; ++i) {
    //     vector.pushBack(i);
    // }
    // for (int i = 0; i < vector.length(); ++i) {
    // std::cout << vector[i] << '\n';
    // }
    // vector.insertElement(5, 10);
    // for (int i = 0; i < vector.length(); ++i) {
    // std::cout << vector[i] << '\n';
    // }
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vector<int> meow(arr);
}