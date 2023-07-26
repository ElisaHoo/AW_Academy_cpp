#ifndef EX3_HPP
#define EX3_HPP
#include <iostream>
#include <type_traits>
#include <concepts>

template <typename T, typename... Ts>
bool types_are_equal(T&&, Ts&&...) {
    // Using fold expressions, checks if the types in pack are
    // equal to the pack's first element's type
    if ((std::is_same_v<T, Ts> && ...)) {
        return true;
    }
    return false;
}
   
#endif