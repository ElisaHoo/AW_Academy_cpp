#include <iostream>

/* Write a program that declares a variable inside a loop
 * and prints its value. Ask the students what will happen 
 * if they try to access the variable outside the loop.
 */

int main() {
    while (true) {
        // variable is available only in this while-loop
        std::string print_hello{"Hello world!"};
        std::cout << print_hello << "\n";
        break; 
    } // Variable's life cycle end here with this curly brace...
    // ...and it doesn't exist outside the loop anymore
    return 0;
}