#include "../includes/ex.hpp"

Positive_integers::Positive_integers(int num) {
    if (num >= 0) {
        number = num;
    } else {
        throw std::invalid_argument("Invalid input! The number must be positive.");
    }
}

void Positive_integers::print_number() {
    std::cout << "You entered: " << number << "\n";
}

int Positive_integers::add(Positive_integers obj) {
    // Check overflow, and if it's true, return INT_MAX
    if ((obj.number + number) > max_number) {
        return max_number;
    }
    return (number + obj.number); 
}

int Positive_integers::subtract(Positive_integers obj) {
    // If subtraction is negative, return zero
    if (number - obj.number < 0) {
        return 0;
    }
    return (number - obj.number);
}

void Count_instances::print_count() {
    std::cout << "The number of instances is " << counter << "\n";
}

//int Count_instances::counter{0};  // Tarvitaan jos headerissä ei ole inlineä