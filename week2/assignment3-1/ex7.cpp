#include <iostream>
#include <algorithm>
#include <vector>

/* Create a vector of pairs with repeating first elements. 
 * After sorting, check if the pairs with equal first 
 * elements maintain their relative order.*/


int main() {
    std::vector<std::pair <int, int>> vector_of_pairs{
        {45, 23}, {2, 154}, {16, 23}, {2, 49}, {2, 1}, {2, 13}};

    std::stable_sort(vector_of_pairs.begin(), vector_of_pairs.end());

    for (const auto& pair : vector_of_pairs) {
        std::cout << pair.first << " " << pair.second << "\n";
    }

    return 0;
}
