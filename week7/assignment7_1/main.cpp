/* Exercise 1
 * Create a constexpr function that checks if two types the same.  
 * (Hint:  You do not need any library functionality (i.e. headers) 
 * for this)
 * 
 * Exercise 2
 * Create a constexpr function that checks if a type can be decayed 
 * further. */

#include "main.hpp"

int main() {
    // EXERCISE 1
    std::cout << "Float and int are same type: " 
              << std::boolalpha << types_are_equal(12.4f, 34) << "\n";  // false
    std::cout << "Double and double are same type: " 
              << std::boolalpha << types_are_equal(2.5667, 0.123) << "\n";  // true

    // EXERCISE 2
    int num_int;  // Can not decay
    int * point;  // Can decay
    volatile int num_vol;  // Can decay

    std::cout << std::boolalpha << can_decay<decltype(num_int)>() << "\n";  // false
    std::cout << std::boolalpha << can_decay<decltype(num_vol)>() << "\n";  // true
    std::cout << std::boolalpha << can_decay<decltype(*point)>() << "\n";  // true
    std::cout << std::boolalpha << can_decay<std::string>() << "\n";  // false

    return 0;
}