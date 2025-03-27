#include "vector.cpp"

#include <iostream>

int main() {
    Vector<int> vector;
    for (int i = 0; i < 50; ++i) {
        vector.pushBack(i);
    }
    for (int i = 0; i < 20; ++i) {
        vector.removeElement(0);
    }
    for (int i = 0; i < vector.length(); ++i) {
        std::cout << vector[i] << '\n';
    }
    std::cout << "meow\n";
}