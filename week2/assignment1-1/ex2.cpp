#include <iostream>
#include <array>
#include <algorithm>

/* Add a function that receives an std::array and a number, 
 * and checks whether the number is in the array. The function 
 * should return a boolean value.*/

bool is_number_in_array(std::array<int, 10> arr, int num) {
    auto exists = std::find(begin(arr), end(arr), num);
    return (exists != std::end(arr));
}

int main() {
    std::array arr{3, 73, 5, 90, 100, 4, 88, 2, 5001, 62};
    
    if (is_number_in_array(arr, 100)) {
        std::cout << "Number is in array!\n";
    } else {
        std::cout << "Number is not in the array!\n";
    }

    return 0;
}