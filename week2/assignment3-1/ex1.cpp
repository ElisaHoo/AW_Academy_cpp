#include <iostream>
#include <algorithm>
#include <array>

/* Write a program that sorts an array of integers 
 * in ascending order using std::sort*/

int main() {
    std::array<int, 10> numbers{6, 10, 3, 7, 5, 9, 1, 2, 8, 4};
    std::sort(numbers.begin(), numbers.end());

    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}