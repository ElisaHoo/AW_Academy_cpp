#include <iostream>
#include <string>

/* Write a banking program that will manage the information 
 * of a single users bank account. The bank stores the following 
 * information. name, address, telephone number and customer number.
 * The program will have a text based user interface for each action. 
 * The user can add or withdraw money, see their account balance, 
 * or quit the program.*/

struct Account {
    double balance;

    // constructor, account's default balance is 0.0
    Account() {
        balance = 0.0;
    }
};

struct Customer {
    std::string name;
    std::string address;
    std::string phone;
    int customer_number;
};

int main() {

    // Get the customer information
    std::cout << "Welcome to the banking program\n" << "Please enter your information\n";

    std::cout << "Name: ";
    std::string n{};
    std::getline(std::cin, n);  // getline for inputting strings with spaces

    std::cout << "Address: ";
    std::string a{};
    std::getline(std::cin, a);

    std::cout << "Phone number: ";
    std::string p{};
    std::getline(std::cin, p);

    // Create a Customer struct and initialize variables (random int for the customer number)
    struct Customer customer = {.name = n, .address = a, .phone = p, .customer_number = std::rand()};

    Account account;  // Create Account struct

    std::cout << "\n";

    // Ask user to choose the action in the while loop until user choose to quit the program
    while(true) {
        std::cout << "Please, choose action:\n";
        std::cout << "1: check balance\n" << "2: deposit money\n" << "3: withdraw money\n" << "4: exit the program\n\n";
        int number{};
        std::cin >> number;

        switch (number)
        {
        case 1:  // check balance
            {
                std::cout << "Your account balance is " << account.balance << " €\n\n";
            }
            break;
        case 2:  // deposit money and update the new balance to the struct variable
            {
                std::cout << "Enter the amount you want to deposit: ";
                double amount{};
                std::cin >> amount;
                std::cout << "Your account balance after deposit is " << (account.balance += amount) << " €\n\n";
            }
            break;
        case 3:  // withdraw money and update the new balance to the struct variable
            {
                std::cout << "Enter the amount you want to withdraw: ";
                double amount{};
                std::cin >> amount;
                // Check if there is enough money for withdrawal
                if (amount <= account.balance) {
                    std::cout << "Your account balance after withdraw is " << (account.balance -= amount) << " €\n\n";
                } else {
                    std::cout << "The account balance is not enough for withdrawal!\n\n";
                }   
            }
            break;
        case 4:
            std::cout << "Thank you for visiting and welcome again!\n";
            return 0;  // exit the program

        default:
            std::cout << "Please select number from the options!\n\n";
            break;
        }
    }
}

