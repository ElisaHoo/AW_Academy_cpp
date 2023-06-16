#include <iostream>

/*Create a program that declares a variable inside a function 
 * and modifies its value inside an if statement. Print the 
 * value of the variable before and after the if statement. 
 * Discuss with the students the concept of scope and how it 
 * affects variable modifications.*/

int main() {
    int value{5};
    // Prints 5
    std::cout << "Before if-statement: " << value << "\n";
    if (true) {
        value += 1;
    }
    // Prints 6
    std::cout << "After if-statement: " << value << "\n";

    return 0;
}