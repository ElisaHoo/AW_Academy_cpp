#include "../includes/ex1.h"

double addition(double num1, double num2) {
    return (num1 + num2);
}

double subtraction(double num1, double num2) {
    return (num1 - num2);
}

double multiplication(double num1, double num2) {
    return (num1 * num2);
}

double division(double num1, double num2) {
    if (num2 == 0) {
        throw std::runtime_error("You can not divide by zero!\n");
    }
    return (num1 / num2);
}