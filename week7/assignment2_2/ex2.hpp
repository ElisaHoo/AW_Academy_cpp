#ifndef EX2_HPP
#define EX2_HPP
#include <iostream>
#include <cstdint>

template <size_t N>
class Ex2 {
    public:
        template <typename... Ts>
        Ex2(Ts... packs) {
        }
        size_t numb_of_args() {
                return amount;
        }
    private:
        constexpr static size_t amount{N};
};

// this is a *deduction guide*, which tells how the deduce the
// template parameters from the constructor
template <typename... Ts>
// When constructor is called, Ex2 -class template gets amount N
Ex2(Ts...) -> Ex2<sizeof...(Ts)>;

#endif