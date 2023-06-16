#include <iostream>
#include <algorithm>
#include <array>

/* Create a function that will output the smallest and largest 
 * number in the array.*/

void output_the_largest_and_smallest(std::array<int, 5> arr) {

    const auto [min, max] = std::minmax_element(begin(arr), end(arr));
    std::cout << "Min element has value " << *min
              << " and max element value " << *max
              << "\n";
}

int main() {
    std::array<int, 5> arr = { 2, 5, 90, -1, 71 };
    output_the_largest_and_smallest(arr);
    return 0;
}