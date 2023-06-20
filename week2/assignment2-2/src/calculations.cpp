#include "../includes/calculations.h"

void get_numbers(double& num1, double& num2) {
    std::cout << "Enter 1st integer: ";
    std::cin >> num1;
    if(!std::cin) { // User didn't input number -> cin fails
        std::cin.clear();  // clear cin's failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Please try again.\n";
            std::cout << "Enter 1st integer: ";
            std::cin >> num1;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    assert((typeid(num1) == typeid(double)) && "Input has to be number!\n"); 
    
    std::cout << "Enter 2nd integer: ";
    std::cin >> num2;
    if(!std::cin) { // User didn't input number -> cin fails
        std::cin.clear();  // clear cin's failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Please try again.\n";
            std::cout << "Enter 2st integer: ";
            std::cin >> num2;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    assert((typeid(num2) == typeid(double)) && "Input has to be number!\n"); 
}

void addition(double& num1, double& num2) {
    std::cout << "\nThe sum of the numbers is " << (num1 + num2) << "\n\n";
}

void subtraction(double& num1, double& num2) {
    std::cout << "\nThe difference between the numebers is " << (num1 - num2) << "\n\n";
}

void multiplication(double& num1, double& num2) {
    std::cout << "\nThe product of the numbers is " << (num1 * num2) << "\n\n";
}

void division(double& num1, double& num2) {
    std::cout << "\nThe quotient of the numbers is " << (num1 / num2) << "\n\n";
}