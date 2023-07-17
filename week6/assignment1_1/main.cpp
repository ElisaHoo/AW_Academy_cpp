/* 
 * Exercise 1:
 * Create a header file that contains definition for enum class 
 * "status", and add a success status, and couple of error statuses
 * Create a function that returns a status code at random
 * Create a program to call the function and handle the status using 
 * `switch`-statement
 * Exercise 2:
 * We are going to implement a simple state machine.  A state machine 
 * is pretty simple concept with a lot of complicated explanations, 
 * but let's keep it simple here.
 * We create a state machine to track a status of an order 
 * (e.g. from an online store).  The order should be tracked from 
 * ordered to delivered.  (Make up the intermediate states)
 * Create a type to track the state for the machine.  Use `enum class`
 * Create a type for the orders (this is our state machine).  
 * Add a member functions to print the current status and to advance 
 * the status of the order. Create a program that runs through 
 * the different states and prints and advances through them.
 */

#include "includes/ex1.hpp"
#include "includes/ex2.hpp"

int main() {
    // EXERCISE 1

    // Create Status-type variable with random content
    Status status{return_random_status()};

    switch (status)
    {
        case Status::success: {
            std::cout << "Status is success!\n";
            break;
        }
        case Status::runtime_error:{
            std::cout << "Status is runtime error!\n";
            break;
        }
        case Status::syntax_error: {
            std::cout << "Status is syntax error!\n";
            break;
        }
        case Status::mystical_error: {
            std::cout << "Status is mystical error!\n";
            break;
        }
    }


    // EXERCISE 2
    Order order1{1};
    order1.print_state();
    order1.progress_order();
    order1.print_state();
    order1.progress_order();
    order1.print_state();
    order1.progress_order();
    order1.print_state();
    order1.progress_order();
    order1.print_state();
    order1.progress_order();
    order1.print_state();
    Order order2{2};
    order2.print_state();
    order2.progress_order();
    order2.print_state();

    return 0;
}