#ifndef EX1_HPP
#define EX1_HPP
#include <iostream>

// Overload the function for case that there is only one element left in the pack 
// and break the recursion
template <typename T>
int print_first_overload(T&& first) {
    std::cout << first << "\n";
    return 0;
}

template <typename T, typename... Ts>
// Get the first element from the parameter pack and print it
int print_first_overload(T&& first, Ts&&... rest) {
    std::cout << first << ", ";
    // call the function recursively again, give rest of the pack as argument
    return print_first_overload(rest...);
}

// EXERCISE 1b
template <typename T, typename... Ts>
void print_first(T&& first, Ts&&... rest) {
    std::cout << first;
    // Check if there are still stuff in the pack
    if constexpr(sizeof...(rest) > 0) {
        // Print , -sign and call the function recursively again,
        // give rest of the stuff as argument
        std::cout << ", ";
        print_first(rest...);
    } else {
        std::cout << "\n";
    }
}

#endif