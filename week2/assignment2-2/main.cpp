
/* Exercise 1.
 * Create a calculator program that can do basic operations: 
 * Addition, subtraction, multiplication and division. In your 
 * program, create a user interface that asks for basic calculation 
 * operations. All calculations should be executed in a utility library.
 * Exercise 2.
 * Refactor your code so that you can add parameters when you call your 
 * calculator from the command line. for example the command 
 * "./calculator --sum 1 2" returns the correct calculation. You can use 
 * a third party library for this called cxxopts 
 * https://github.com/jarro2783/cxxoptsLinks to an external site..
 * Exercise 3.
 * Add asserts that makes sure that the the program runs only with 
 * correct input values.*/
#include "includes/calculations.h"

int main(int argc, char* argv[]) {
    // If user don't enter "extra" command line arguments, open 
    // program's UI
    if (argc < 2) {
        std::cout << "\n*** Calculator program ***\n";
        while (true) {
            // Ask user to choose operation
            std::cout << "Please choose an operation:\n";
            std::cout << "(1) addition\n";
            std::cout << "(2) subtraction\n";
            std::cout << "(3) multiplication\n";
            std::cout << "(4) division\n";
            std::cout << "(5) quit\n";

            // Pick the choice
            int choice{};
            std::cin >> choice;
            assert((choice > 0 && choice < 6) && "Operation has to be a number between 1 and 5!");

            // If choice is to quit, exit from the loop an don't go to 
            // ask numbers
            if (choice == 5) {
                break;
            }

            // Ask numbers from a user
            double num1{};
            double num2{};
            get_numbers(num1, num2);

            switch (choice)
            {
            case 1:
                {
                    addition(num1, num2);
                }
                break;
            case 2:
                {
                    subtraction(num1, num2);
                }
                break;
            case 3:
                {
                    multiplication(num1, num2);
                }
                break;
            case 4:
                {   
                    assert((num2 != 0) && "You can not divide by zero!");
                    division(num1, num2);
                }
                break;
            
            default:
                std::cout << "\nInvalid input! Please choose from numbers "
                             " 1-5.\n";
                break;
            }
        }
        std::cout << "\nGoodbye!\n";
        return 0;

    } else if (argc == 4) {
        // If argc == 4, perform calculation using command line arguments
        double num1{std::stod(argv[2])}; // Convert command line arguments to double
        double num2{std::stod(argv[3])};
        assert((num2 != 0) && "You can not divide by zero!");


        if (static_cast<std::string>(argv[1]) == "--sum") {
            addition(num1, num2);

        } else if (static_cast<std::string>(argv[1]) == "--difference") {
            subtraction(num1, num2);

        } else if (static_cast<std::string>(argv[1]) == "--product") {
            multiplication(num1, num2);

        } else if (static_cast<std::string>(argv[1]) == "--quotient") {
            division(num1, num2);
        }

    } else {
        // Prompt instructions, if the number of command line arguments 
        // isn't correct
        std::cout << "\nTo use calculator-program you have to input " 
                     "0 or 3 command line arguments after program path command.\n";
        std::cout << "For example './build/calculator --sum 1 2' will return sum of"
                     " 1 and 2 on the console.\n";
        std::cout << "You can use also '--difference', '--product', or '--quotient' "
                     "flags.\n";
        std::cout << "If don't use any extra command line arguments, the program's "
                     "user interface opens.\n";
    }
}