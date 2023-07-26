/* Exercise 1a.
Create a function with an integer template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
overload resolution.

Exercise 1b.
Create a function with an integer template parameters, that prints out the first integer
value, and then calls the function with remaining values.  Break the recursion using
if contexpr

Exercise 2.
Create a function that takes arbitrary number of arguments and returns the sum of the
arguments.  How should you handle errors (such as argument not being a number) here?

Exercise 3.
In exercise 7.1.1. we created a function to check if two types are the same.  Expand on this
to check if any number of types given are all the same.

Exercise 4.
Create a function that takes arbitrary number of arguments and return the product of the
arguments times the number of arguments.

Exercise 5.
Create a function that takes arbitrary number of containers as arguments and creates a
concatenated container.  (e.g. concatenate(std::vector{1, 2}, std::list{5, 8}) -> std::vector{1, 2, 5, 8};*/

#include "includes/ex1.hpp"
#include "includes/ex2.hpp"
#include "includes/ex3.hpp"
#include "includes/ex4.hpp"
#include "includes/ex5.hpp"

int main() {
    // EXERCISE 1a
    print_first_overload(23, 3, 6789, 0, 43, 1);

    // EXERCISE 1b
    print_first(1, 2, 3, 4, 5);

    // EXERCISE 2
    //float sum{sum_of_numbers(1, "cat", 3, 4, 5)};  // static_assert FAILS
    float sum{sum_of_numbers(1, 0, 0.11f, 3, 4, 5)};
    std::cout << "Sum of numbers is " << sum << "\n";

    // EXERCISE 3
    std::cout << std::boolalpha << types_are_equal(1, 2, 3, 4) << ", ";  // true
    std::string cat{"cat"};
    std::string dog{"dog"};
    std::cout << std::boolalpha << types_are_equal(cat, dog) << ", ";  //true
    std::cout << std::boolalpha << types_are_equal('t', 'r', cat) << ", ";  //false
    std::cout << std::boolalpha << types_are_equal(1, 2, 3, 4.5) << ", ";  // false
    std::cout << std::boolalpha << types_are_equal(-1.4, 5.978, 3590.77, 1) << "\n"; //false

    // EXERCISE 4
    double result1{product_times_arguments(1, 2, 0.1, 4)};
    double result2{product_times_arguments(1, 2, 3, 4)};
    double result{product_times_arguments(1, 2, 'g', 4)};
    std::cout << result1 << "\n"; // 3.2
    std::cout << result2 << "\n"; // 96

    // EXERCISE 5
    std::list<int> arr1{1, 2, 3};
    std::vector<int> arr2{9, 8};
    //std::vector<float> arr2{2.5, 5.4};  // Throws error
    // If container elements are strings,
    // the program breaks in the std library before throw 
    //std::vector<std::string> arr2{"Hello", "world!"};
    std::array<int, 2> arr3{40, 41};
    std::vector<int> vect{concatenate_conts(arr1, arr2, arr3)};
    for (auto& integ : vect) {
        std::cout << integ << " ";  // prints 1 2 3 9 8 40 41
    }
    std::cout << "\n";

    return 0;
}

