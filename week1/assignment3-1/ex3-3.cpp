#include <iostream>

/* Create a program with two functions: main() and calculate(). 
 * Inside the calculate() function, declare a variable and 
 * assign a value to it. Print the value of the variable in both 
 * functions. Discuss with the students the difference between 
 * local and global scope.
*/

int g_number{};

void calculate() {
    g_number = 5;  
    int number{8};  // This local variable is only accessible in calculate-function
    std::cout << "This is printed from the calculate-function! " << g_number << "\n";
}

int main() {
    calculate();
    // OK, global variable is accessible in both functions
    std::cout << "This is printed from the main! " << g_number << "\n";

    /* std::cout << "This is printed from the main! " << number << "\n";
    ----> ERROR: number is calculate-function's local variable and doen't exist in main
    -function  
    */
     
    return 0;
}




