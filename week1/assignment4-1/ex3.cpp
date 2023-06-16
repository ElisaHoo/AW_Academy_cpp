#include <iostream>
#define NDEBUG  // overrides assert (must be before #include <cassert>)
#include <cassert>

/* Write a C++ program that calculates the sum of 
 * two integers. Implement a function called sum() 
 * that takes two integers as input and returns their 
 * sum. Use an assert statement to check that the sum 
 * is positive. If the assertion fails, display an error 
 * message indicating that the sum is not positive. 
 * Compile the program with the NDEBUG macro defined and 
 * observe the behaviour when the assertion fails.*/

int sum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    std::cout << "Please enter numbers for calculating a sum of two numbers\n" << "Number 1: ";
    int num1{};
    std::cin >> num1;
    std::cout << "Number 2: ";
    int num2;
    std::cin >> num2;

    assert((sum(num1, num2) > 0) && "The sum of the numbers is negative");

    std::cout << "The result is " << sum(num1, num2) << "\n";

    return 0;
}