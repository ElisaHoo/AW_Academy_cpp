#ifndef EX5_HPP
#define EX5_HPP
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <type_traits>

// Helper-function, to check that the elements in the containers are integers
template <typename T, typename... Ts>
bool elements_are_integers(T first, Ts... packs) {
    if constexpr(sizeof...(packs) > 0) {
        // Check if the elements contained in the "first"-container are integers
        if (std::is_integral_v<typename T::value_type>)
        {
            return elements_are_integers(packs...);
        }
        return false;
    }
    return true;
}

template <typename... Ts>
std::vector<int> concatenate_conts(Ts... packs) {
    if (!elements_are_integers(packs...)) {
        throw std::invalid_argument("Containers elements must be integers");
    }
    std::vector<int> combined_vec{};
    // Using fold expression to "loop through" the packs.
    // Insert all the elements of the packs to the newly created vector
    (combined_vec.insert(combined_vec.end(), std::begin(packs), std::end(packs)), ...);
    return combined_vec;
}

#endif