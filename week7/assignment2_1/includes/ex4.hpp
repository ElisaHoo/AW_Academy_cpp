#ifndef EX4_HPP
#define EX4_HPP
#include <iostream>

struct Counter // Helper-type to count args
{
    Counter() {  // To increase counter
        counter++;
    }
    Counter(int i) {  // To reset counter
        counter = i;
    }
    static inline int counter;  
};

template <typename T, typename... Ts>
double product_times_arguments(T first, Ts... rest) { 
    static_assert((std::is_arithmetic<T>::value) 
            && "Arguments must be numbers");
    Counter argc; // Call the helper-type's constructor to increase counter
    if constexpr(sizeof...(rest) > 0) { 
        return first * product_times_arguments(rest...);
    }
    // 'first' = the product of the args, 'argc.counter' = number of arguments
    double result{static_cast<double>(first) * static_cast<double>(argc.counter)};
    Counter argc2(0);  // reset the counter for next use

    return result;
}

#endif