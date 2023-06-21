#include <iostream>

/* 1. Write a program that performs a division operation. 
 * The user should input two numbers. the program should catch and 
 * handle the possibility of a division by zero error. */
#include "../includes/ex.h"

float division(float num1, float num2) {
    if (num2 == 0) {
        // If num2 is zero, keep asking user to input 2nd number again
        while (true) {
            std::cout << "You can not divide by zero!\n";
            std::cout << "Please give 2nd number again:";
            std::cin >> num2;
            if (num2 == 0) {
                continue;
            } else {
                break;
            }
        }
    }
    // When num2 is != 0, return the calculation
    return (num1 / num2);
}