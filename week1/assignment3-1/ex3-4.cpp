#include <iostream>

/* Write a program that declares a variable inside 
 * a block and prints its value inside and outside 
 * the block. Discuss with the students the scope 
 * of variables declared inside blocks.
 */

int main() {
    {
        int v{5};
        std::cout << "Inside the block: " << v << "\n";
    }

    // ERROR: v doesn't exist outside block:
    // std::cout << "Outside the block: " << v << "\n";

    return 0;
}