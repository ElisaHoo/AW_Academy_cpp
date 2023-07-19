#include "includes/ex.h"

int main() {
    /* Exercise 1.
     * Write a program that performs a division operation. 
     * The user should input two numbers. the program should catch and 
     * handle the possibility of a division by zero error. */
    std::cout << "Input two numbers to perform division operation\n";
    std::cout << "1st number: ";
    float num1{};
    std::cin >> num1;
    std::cout << "2nd number: ";
    float num2{};
    std::cin >> num2;
    float result = division(num1, num2);
    std::cout << "The result is " << result << "\n";

    /* Exercise 2. 
     * Write a program that reads in a list of integers and finds 
     * the maximum value. Return an error code if the list is empty.*/
    std::vector<int> numbers{}; 
    if (find_maximum_value(numbers) == ERROR_CODE) {
        std::cout << "The vector is empty!\n";
    } else {
        std::cout << "The maximum value is " << find_maximum_value(numbers) 
                  << "\n";
    }

    /* Exercise 3.
     *  Create a program that will print out a list of names. The user 
     * can choose a person in the list by inputting the user index and 
     * their name gets printed out. If the user tries to choose a user 
     * that is outside of the index, throw an appropriate exception. */
    std::vector<std::string> names{"Liisa", "Maija", "Kari", "Seppo"};
    try
    {
        choose_name(names);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     
    /* Exercise 4. Overload a function called process_data(). One version 
     * should accept an integer and the other a string. If the integer is 
     * negative or the string contains any non-alphabet characters, throw 
     * an exception.*/
    try
    {
        process_data("Hello!");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    /* Exercise 5. 
     * Add error handling to your banking system.*/
    

    return 0;
}