#include <iostream>
#include <cmath>  // to use sqrt()
#define NDEBUG
#include <cassert>

/* Write a C++ program that calculates the square 
 * root of a given number. Implement a function 
 * called square_root() that takes a non-negative 
 * floating-point number as input and returns its 
 * square root. Use an assert statement to check 
 * that the input number is non-negative. If the 
 * assertion fails, display an error message 
 * indicating that the square root is not defined 
 * for negative numbers. Compile the program both 
 * with and without the NDEBUG macro defined and 
 * observe the behaviour when the assertion fails 
 * in each case.*/

float calculate_square_root(float number) {
    return sqrt(number);
}

int main() {
    std::cout << "Please enter a number for calculating a square root: ";
    int number{};
    std::cin >> number;

    assert((number > 0) && "The square root is not defined for negative numbers");

    std::cout << "The result is " << calculate_square_root(number) << "\n";

    return 0;
}