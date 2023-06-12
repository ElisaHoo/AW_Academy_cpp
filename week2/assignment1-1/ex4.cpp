#include <iostream>
#include <vector>
#include <numeric>


/* Create a  program that that prints out the product 
 * of all elements in an array*/

void multiply_elements(std::vector<int> vect) {
    int multi{std::accumulate(vect.begin(), vect.end(), 1, std::multiplies<int>())};
    std::cout << "The multiplication is " << multi << "\n";
}

int main() {
    std::vector<int> vect{2, 4, 8, 3, 5};

    multiply_elements(vect);
    
    return 0;
}