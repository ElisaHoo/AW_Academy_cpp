/* Exercise 1
 * Create a type for positive integers with following requirements
 * - Default-initialises to 0
 * - Initialising with a negative number reports an error to the user 
 *   and cleans up correctly (printing is not a valid way to report 
 *   errors to the user)
 * - Can be copied (e.g. a = b assignment works, where a and b are 
 *   instances of the type)
 * - Has a member function to print the contents 
 * 
 * Exercise 2
 * Create functions to add and substract our ex1. positive integers 
 * from each other. The integers should saturate at 0 and the maximum 
 * value (so they do not overflow, e.g. 42 - 51 = 0) 
 * (optional) Add overloads to your add and substract functions so they 
 * work with normal integer values too.
 * 
 * Exercise 3
 * Create a class that counts how many instances of it exist.  
 * Do not use global variables.  Create a function to print the count.*/

#include "includes/ex.hpp"

int main () {
    // EXERCISE 1
    Positive_integers pos_int;
    pos_int.print_number();  // Prints default value 0
    //Positive_integers neg_int(-2);  // Throws error about wrong input
    Positive_integers pos_int2(355);
    pos_int2.print_number();  // Prints 355
    pos_int2.number = 52;
    Positive_integers pos_int3;
    pos_int3 = pos_int2;
    pos_int3.print_number();  // Prints 52

    // EXERCISE 2
    Positive_integers pos_int4(150);
    int sum{pos_int3.add(pos_int4)};
    std::cout << "52 + 150 = " << sum << "\n";
    int subtr_zero{pos_int3.subtract(pos_int4)};
    std::cout << "52 - 150 = " << subtr_zero << "\n"; // This is zero
    int subtr{pos_int4.subtract(pos_int3)};
    std::cout << "150 - 52 = " << subtr << "\n";
    
    // EXERCISE 3
    Count_instances inst1_1;
    Count_instances inst1_2;
    {
        // Note that this instance's lifetime ends after the loop
        Count_instances inst2_1;
    }
    Count_instances inst1_3;  // Count is still 3

    return 0;
}