#include <iostream>
#include <vector>
#include <algorithm>

/* Create a function that will output the smallest and largest 
 * number in the list.*/

void output_the_largest_and_smallest(std::vector<int> v) {
    std::vector<int>::iterator min = std::min_element(v.begin(), v.end());
    std::vector<int>::iterator max = std::max_element(v.begin(), v.end());
    std::cout << "Min element has value " << *min
              << " and max element value " << *max 
              << "\n";
}

int main() {
    std::vector<int> v{3, 73, 8, 90, 100, 4, 88, -2, 5001, 62};
    output_the_largest_and_smallest(v);
    return 0;
}