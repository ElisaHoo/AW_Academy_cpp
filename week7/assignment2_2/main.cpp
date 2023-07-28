/* Exercise 1.
 * Take a look at C function printf and especially its format specifiers 
 * (https://alvinalexander.com/programming/printf-format-cheat-sheet/)
 * Create a template function with a signature that is something like
 * template <typename Ts...>
 * void safe_printf(const std::string& fmt, Ts args...);
 * that checks that the arguments given to the printf are of correct type.  
 * (It is enough to handle some of them)
 * (printf is unfortunately still quite common in some C++ circles that refuse to leave 
 * the 90's behind.  There are multiple reasons to prefer cout (or std::print from C++23 forward), 
 * but this safe_printf used to be something a lot of people had to write to fix the bugs 
 * caused by incorrect printfs in the codebase.)
 * 
 * Exercise 2.
 * We can use either static_assert of requires (c++20) to force a certain number of parameters 
 * for a variadic function.  Create a class where the constructor takes any number of arguments 
 * and store that number in class template parameters or a constexpr static class member or 
 * a template parameter using default (or you can save the parameter pack itself if you want, 
 * but that is tricky, so consider it completely optional brain-teaser).
 * Create function to return the number of arguments the constructor was called with
 * 
 * (optional part)
 * Create an another function that requires, at compile-time, the exact number of arguments 
 * the constructor was called with 
 * This example can prove handy (especially with the optional part). 
   #include <cstdint>
   template <std::size_t N>
   struct Example {
     template <typename... Ts>
     Example(Ts...) {};
   };

   // this is a *deduction guide*, which tells how the deduce the
   // template parameters from the constructor
   template <typename... Ts>
   Example(Ts...) -> Example<sizeof...(Ts)>;

   int main() {
      Example(1, 2, 3, 4, 5); // this would be deduced as Example<5>
   }

 * (optional) Exercise 3.
 * We created a type for a 2D grid, think about ways this grid could be generalised to arbitrary 
 * dimenions using variadics.  You can try this out if you want to, but don't get discouraged if 
 * you don't get it to work. It's not the easiest thing to do. */

#include "ex1.hpp"
#include "ex2.hpp"

int main() {
    // EXERCISE 1
    std::string cow{"cow"};
    std::string moon{"moon"};
    safe_printf("The %s jumped over the %s, %i times", cow, moon, 2);
    safe_printf("The right answer to the question %i is %c", 3, 'b');
    safe_printf("%i divided by %i is %f", 3, 2, 1.5f);
    //safe_printf("The right answer to the question %e is %c", 3, 'b');  // FAILS
    //safe_printf("The right answer to the question %i is %c", 3.4, 'b');  // FAILS
    
    // EXERCISE 2
    Ex2 ex(1, 2, 3, 4, 5);
    std::cout << "Number of arguments is " << ex.numb_of_args() << "\n";

    return 0;
}

