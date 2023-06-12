#include <iostream>
#include <vector>

/*Create a program that will ask the user for the size of a vector.*/

int main() {
    std::cout << "Please enter the size of a vector: ";
    int size{};
    std::cin >> size;
    std::vector<int> my_vector;
    for(int i = 1; i < size+1; i++) {
        my_vector.push_back(i);
        std::cout << my_vector[i-1] << " ";
    }
    std::cout << "\n";

    return 0;
}