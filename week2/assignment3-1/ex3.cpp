#include <iostream>
#include <algorithm>
#include <vector>

/* Create a vector of floating-point numbers and sort it. 
 * Experiment with different sizes of vectors and number ranges*/

int main() {
    std::vector<float> numbers{6.7, -10.1, 3.44, 7.0, 0.4, 9.23, 1.01, 2.38, 8.0, 4.55};
    std::vector<float> numbers1{4002.1, 0.00001, 434.0044, 1000000.9999, -0.000456};
    
    std::sort(numbers.begin(), numbers.end());
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    std::sort(numbers1.begin(), numbers1.end());
    for (const auto& number : numbers1) {
        std::cout << number << " ";
    }
    std::cout << "\n";

    return 0;
}