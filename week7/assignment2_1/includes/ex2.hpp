#ifndef EX2_HPP
#define EX2_HPP
#include <iostream>
#include <type_traits>
#include <cassert>
 
template <typename T, typename... Ts>
float sum_of_numbers(T first, Ts... rest) {
    static_assert((std::is_arithmetic<T>::value) 
            && "Arguments must be numbers");
    // 'first' is the first number in the pack and also holds the
    // sum accumulated so far
    if constexpr(sizeof...(rest) > 0) {
        // Call the function recursively and give the sum and rest of
        // the pack as arguments
        return first + sum_of_numbers(rest...);
    }
    // When the pack is empty, return the sum
    return first;
}

#endif