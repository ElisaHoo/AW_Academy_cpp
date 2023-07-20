#include "../includes/ex2.hpp"

Positive_integer::Positive_integer(int num) {
    if (num >= 0) {
        number = num;
    } else {
        throw std::invalid_argument("Invalid input! The number must be positive.");
    }
}

void Positive_integer::print_number() const{
    std::cout << number << "\n";
}

int Positive_integer::add(Positive_integer obj) {
    // Check overflow, and if it's true, return INT_MAX
    if ((obj.number + number) > max_number) {
        return max_number;
    }
    return (number + obj.number); 
}

int Positive_integer::subtract(Positive_integer obj) {
    // If subtraction is negative, return zero
    if (number - obj.number < 0) {
        return 0;
    }
    return (number - obj.number);
}

Positive_integer multiply(const Positive_integer& posi1, const Positive_integer& posi2) {
    if ((posi1.number * posi2.number) > posi1.max_number) {
        return posi1.max_number;
    }
    return (posi1.number * posi2.number); 
}