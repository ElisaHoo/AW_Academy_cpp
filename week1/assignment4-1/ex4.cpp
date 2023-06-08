#include <iostream>
#define NDEBUG
#include <cassert>

/* Write a C++ program that performs division 
 * of two numbers. Implement a function called 
 * divide() that takes two integers as input and 
 * returns their division result. Use an assert 
 * statement to check that the second number 
 * (denominator) is not zero. If the assertion 
 * fails, display an error message indicating 
 * that division by zero is not allowed. Compile 
 * the program both with and without the NDEBUG 
 * macro defined and observe the behavior when 
 * the assertion fails in each case.*/

int divide(int num1, int num2) {
    return num1 / num2;
}

int main() {
    std::cout << "Please enter numbers for calculating division of two numbers\n" << "Number 1: ";
    int num1{};
    std::cin >> num1;
    std::cout << "Number 2: ";
    int num2;
    std::cin >> num2;

    assert((num2 != 0) && "Division by zero is not allowed");

    std::cout << "The result is " << divide(num1, num2) << "\n";

    return 0;
}