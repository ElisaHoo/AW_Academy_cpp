/* Exercise 1
 * Create a namespace and a type in the global namespace.  
 * Create a function in the namespace and a static member 
 * function for the type.  Try using them from the global
 * namespace.
 * 
 * Exercise 2
 * Create a 3D vector type (e.g. a type with x, y and z values) 
 * in your own namespace. Then overload the << operator so you 
 * can use that type directly with std::cout
 * Think about in what namespace the overload should be located 
 * (try it out, it might be a bit surprising).
 * 
 * Exercise 3
 * Overload +, -, += and -= operators for your vector type to 
 * handle vector addition and substraction, pay attention to 
 * const-ness of your variables/parameters.*/


#include "includes/ex.hpp"

int main() {
   // EXERCISE 1
   Space::hello();
   Ship::hello();

   // EXERCISE 2
   Space::Space_location loc;
   std::cout << loc;  // prints 3 8 2

   // EXERCISE 3
   Space::Space_location loc2;
   Space::Space_location loc3{loc + loc2};
   std::cout << loc3; // prints 6 16 4
   std::cout << loc3 - loc2;  // prints 3 8 2
   std::cout << loc2 - loc3;  // prints -3 -8 -2


   return 0;
}