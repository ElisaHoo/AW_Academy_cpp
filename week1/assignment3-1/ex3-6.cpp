#include <iostream>

/* Write a program that declares a variable inside a function,
 * passes it as a parameter to another function, and modifies 
 * its value. Print the value of the variable before and after 
 * the function call. Discuss with the students how the lifetime 
 * of the variable is affected by passing it as a parameter.
 */
void calculate(int value);

int main() {
    int value{5};
    std::cout << "Before the function call: " << value << "\n";
    calculate(value);
    std::cout << "After the function call: " << value << "\n";  // value won't be modified
    return 0;
}

void calculate(int value) {
    value += 1;
}