#include <iostream>

/* Write a program that declares a variable inside a namespace and 
 * another variable with the same name inside a function. Print the 
 * value of each variable and discuss with the students how scope 
 * resolution works in namespaces.
 */

namespace elisa {
    int number{5};  // variable inside namespace
}

int main() {
    int number{10};  // local variable inside a function

    std::cout << number << "\n";  // prints the local scope variable
    std::cout << elisa::number << "\n";  // prints the variable in namespace
}