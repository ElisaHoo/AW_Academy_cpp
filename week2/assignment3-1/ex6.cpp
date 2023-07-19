#include <iostream>
#include <algorithm>
#include <vector>

/* Use std::partial_sort to find the top 5 elements from a vector of 
 * integers. The vector should have at least 20 elements.*/

int main() {
    std::vector<int> numbers{15, 7, 20, 5, 4, 2, 17, 8, 12, 14, 11, 9,
                             16, 10, 1, 13, 6, 18, 19, 3};
    
    std::partial_sort(numbers.begin(), numbers.begin() + 5, numbers.end());
    
    // Prints 1 2 3 4 5 20 17 15 12 14 ...and so on
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}