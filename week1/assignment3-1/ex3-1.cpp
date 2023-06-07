#include <iostream>
#include <string>

/* Write a program that declares a variable inside a function 
 * and prints its value. Discuss with the students where the 
 * variable can be accessed and explain the concept of local scope.
 */

void print_value();

int main() {
    print_value();
    return 0;
}

void print_value() {
    // Variable "hello" is available only inside this function
    std::string hello{"Hello world! <3"};
    std::cout << hello << "\n";
}  // local variable's accessibility ends with this curly brace