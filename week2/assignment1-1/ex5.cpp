#include <iostream>
#include <vector>

/*Create a program that will ask the user for the size of a vector.*/

int main() {
    std::cout << "Please enter the size of a vector: ";
    int size{};
    std::cin >> size;
    std::vector<int> my_vector(size);
    for(int i = 1; i < size+1; ++i) {
        my_vector[i] = i;
        std::cout << my_vector[i] << " ";
    }
    std::cout << "\n";

    return 0;
}