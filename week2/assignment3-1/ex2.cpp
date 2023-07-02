#include <iostream>
#include <algorithm>
#include <array>

/* Use std::sort with std::greater<int>() to sort an array 
 * of integers in descending order.*/

int main() {
    std::array<int, 10> numbers{6, 10, 3, 7, 5, 9, 1, 2, 8, 4};
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}