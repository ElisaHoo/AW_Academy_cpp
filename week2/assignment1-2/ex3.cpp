#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

/* Create a vector with 10 random elements in it. 
 * Rotate elements to the right by 3 positions 
 * with std::rotate.*/
void rotate_numbers(std::vector<int> v) {
    std::cout << "Before rotate left:\t";
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    std::cout << "After rotate left:\t";
    std::rotate(v.begin(), v.begin() + 3, v.end());
    for( int num : v) {
        std::cout << num << " ";
    }
    std::cout << "\n";

}

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 100 + 1);
    }
    rotate_numbers(v);    
    return 0;
}