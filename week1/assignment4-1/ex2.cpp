#include <iostream>
#include <cassert>
#include <string>

/* Write a C++ program that calculates the factorial of
 * a given number. Implement a function called factorial()
 * that takes an integer as input and returns its factorial.
 * Use an assert statement to check that the input number
 * is non-negative. If the assertion fails, display 
 * an error message indicating that the factorial is not 
 * defined for negative numbers. Test your program with 
 * various input values, including both positive and negative 
 * numbers.*/

int calculate_factorial(int number) {
    int factorial{1};
    for (number; number >= 1; number--) {
        factorial *= number; 
    }
    return factorial;
}

int main() {
    std::cout << "Please enter an interger for calculating it's factorial: ";
    int number{};
    std::cin >> number;

    assert((number >= 0) && "Please give non-negative number, factorial is not defined for negative numbers");

    std::cout << "The factorial number of " << number << " is " << calculate_factorial(number) << "\n"; 

    return 0;
}