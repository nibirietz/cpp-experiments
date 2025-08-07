#include <iostream>
#include <vector>

int main() {
    std::vector<int> x = {1, 2, 3, 4};
    std::vector<int>::iterator iter = x.begin();
    std::cout << *(iter + 3);
}