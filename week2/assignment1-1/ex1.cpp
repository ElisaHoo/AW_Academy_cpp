#include <iostream>
#include <array>

/* Create an array with 10 random numbers in it. Your program 
 * should also be able to output the elements in the array.*/

int main() {
    std::array arr{3, 73, 5, 90, 100, 4, 88, 2, 5001, 62};
    for (const auto& i: arr) {
        std::cout << i << " ";
    }

    return 0;
}