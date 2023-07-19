#include "../includes/ex.h"

void process_data(int number) {
    // Throw error if number is negative
    if (number < 0) {
        throw std::runtime_error("The number is negative!\n");
    }
    std::cout << "The number is positive!\n";
}
void process_data(std::string str) {
    // Check if the string contains non-alphabet characters and if it does, throw error
    auto it = std::find_if(str.begin(), str.end(), [](char const &c) {return !std::isalpha(c);});
    if (it != str.end()) {
        throw std::runtime_error("The string includes non-alphabet characters!\n");
    }
    std::cout << "The string includes only alphabet characters!\n";
}