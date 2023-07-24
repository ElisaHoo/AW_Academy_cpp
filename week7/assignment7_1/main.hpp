#ifndef MAIN_HPP
#define MAIN_HPP
#include <iostream>
#include <type_traits>
#include <concepts>

// If the types are same (T, T), return true
template <typename T>
constexpr bool types_are_equal(T, T) {
    return true;
}

// If the types are not same (T, U). return false
template <typename T, typename U>
constexpr bool types_are_equal(T, U) {
    return false;
}

template <typename T>
constexpr bool can_decay() {
    // If "decayed T" is same as "not-decayed T", then T can not be decayed -> return false
    if (std::is_same_v<std::decay_t<T>, T>) {
        return false;
    }
    return true;
}

#endif