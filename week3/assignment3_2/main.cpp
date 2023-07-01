#include "includes/ex1.h"
#include "includes/ex2.h"
#include "includes/ex3.hpp"

int main() {    

    /* Exericse 1.
     * Test basic math functions.First write your unit tests and then 
     * create simple math functions like addition, subtraction, 
     * multiplication and division. Try and think about meaningful unit 
     * tests. Your program does not need a user interface now that you 
     * are using unit tests to check for functionality.
     * Remember error handling.*/

    double result1{addition(2.1, 1.8)};
    double result2{subtraction(3.0, 2.1)};
    double result3{multiplication(3.5, 3.5)};
    double result4{division(8.0, 1.2)};

    std::cout << "2.1 + 1.8 = " << result1 << "\n";
    std::cout << "3.0 - 2.1 = " << result2 << "\n";
    std::cout << "3.5 * 3.5 = " << result3 << "\n";
    std::cout << "8.0 / 1.2 = " << result4 << "\n";


    /* Exercise 2.
     * Write unit tests for a string utility program. Write unit tests 
     * that check if your program can correctly handle reversing a string,
     * a method to convert a string to uppercase, a method to convert 
     * a string to lowercase and a method to check if a string is a palindrome.
     */
    std::string modified_upper{convert_to_uppercase("hello")};
    std::cout << "'hello' to uppercase: " << modified_upper << "\n";
    std::string modified_lower{convert_to_lowercase("HELLO")};
    std::cout << "'HELLO' to lowercase: " << modified_lower << "\n";
    bool is_it{check_if_palindrome("saippuakauppias")};
    std::cout << "'saippuakauppias' is palindrome: " << is_it << "\n";


    /* Exercise 5. 
     * Add error handling to your banking system.
     */

    // Create example-customer and initialize it's member variables
    Customer example_customer = {"Test Person", "Test Street 1", 
                                 "+358 40 123 4567", {}};

    // Create Account-struct
    Account account = {300};

    // Connect customer to account (account_number serves also as 
    // a map key)
    example_customer.accounts[account_number] = account;

    // Connect customer to a bank (customer_number serves also as 
    // a map key)
    bank[customer_number] = example_customer;

    // User interface
    std::cout << "\n\nWelcome to the Elisa's Bank!\n"; 
    std::cout << "Please choose an action:\n";
    bool stay_in_loop = false;

    // Ask a user to choose an action (in the while loop) until 
    // the user chooses to quit the program
    while (true) {
        std::cout << "\n\n1: select a customer\n";
        std::cout << "2: create a new customer\n";
        std::cout << "3: exit\n";
        int selection{};
        std::cin >> selection;

        clear_failed_cin();  // if user input is not number

        switch (selection) {
            case 1:
                {
                stay_in_loop = true;  // Needed for exiting from next while-loop
                std::cout << "Enter the customer number: ";
                int cust_num{};
                std::cin >> cust_num;
                int customer_num{get_valid_customer_number(cust_num)};
                std::cout << "\n\nCustomer '" << bank[customer_num].name << "' chosen\n";

                while(stay_in_loop) {

                    std::cout << "\nPlease, choose an action:\n";
                    std::cout << "1: check balance\n";
                    std::cout << "2: deposit money\n";
                    std::cout << "3: withdraw money\n";
                    std::cout << "4: create a new account\n";
                    std::cout << "5: exit to previous menu\n\n";

                    int choice{};
                    std::cin >> choice;

                    clear_failed_cin();  // If user don't input number

                    switch (choice)
                    {
                    case 1:  // Check balance
                        {
                        // Ask user to input account number and get the number
                        int account_num_input{get_account_number_from_user()};
                        // Check account number is valid and it is in use
                        int valid_acc_num = check_account_number_is_valid(account_num_input, customer_num);
                        
                        std::cout << "\n\nAccount balance is " 
                        // From bank-map, find right customer with the customer number
                        // and then find right account with the account number and pick
                        // it's balance
                            << bank[customer_num].accounts[valid_acc_num].balance << " €\n";
                        }
                        break;

                    case 2:  // Deposit money
                        {
                        // Ask user to input account number and get the number
                        int account_num_input{get_account_number_from_user()};
                        // Check account number is valid and it is in use
                        int valid_acc_num = check_account_number_is_valid(account_num_input, customer_num);
                        std::cout << "Enter the amount you want to deposit: ";
                        double amount{};
                        std::cin >> amount;
                        // Check that user inputs valid number
                        double valid_amount{get_valid_input_value_type_for_deposit(amount)};

                        bank[customer_num] = deposit_money(bank[customer_num], valid_acc_num, valid_amount);
                        
                        std::cout << "\n\nAccount balance after deposit is " 
                                  << bank[customer_num].accounts[valid_acc_num].balance << " €\n";
                        }
                        break;

                    case 3:  // Withdraw money
                        {
                        // Ask user to input account number and get the number
                        int account_num_input{get_account_number_from_user()};
                        // Check account number is valid and it is in use
                        int valid_acc_num = check_account_number_is_valid(account_num_input, customer_num);
                        std::cout << "Enter the amount you want to withdraw: ";
                        double amount{};
                        std::cin >> amount;
                        double valid_amount{get_valid_withdrawal(bank[customer_num], valid_acc_num, amount)};
                        bank[customer_num] = withdraw_money(bank[customer_num], valid_acc_num, valid_amount);
                        std::cout << "\n\nAccount balance after withdrawal is " 
                                  << bank[customer_num].accounts[valid_acc_num].balance << " €\n";
                        } 
                        break;

                    case 4:  // Create a new account
                        {
                        std::cout << "Enter the amount you want to deposit: ";
                        double amount{};
                        std::cin >> amount;
                        double valid_amount{get_valid_input_value_type_for_deposit(amount)};
                        // Returns [1] a new account number
                        int new_acc_num{create_new_account(customer_num, valid_amount)};
                        std::cout << "A new account created with number " << new_acc_num 
                                  << " and with balance " << bank[customer_num].accounts[new_acc_num].balance << " €\n";
                        break;
                        }
                    case 5:
                        {
                        stay_in_loop = false;  // exit to the previous menu
                        break;
                        }
                    default:
                        {
                        std::cout << "Please select number from the options!\n\n";
                        break;
                        }
                    }
                } // second while-loop ends
                // Save the customer data to the csv-file when the action is done
                try
                {
                    save_customer_data("customer_data.csv", bank[customer_number]);
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }

                }
                break; // first menu's case 1 ends
            case 2:
                {
                clear_failed_cin();  // Just in case
                std::cout << "Name: ";
                std::string customer_name{};
                std::getline(std::cin >> std::ws, customer_name);

                std::cout << "Address: ";
                std::string customer_address{};
                std::getline(std::cin >> std::ws, customer_address);

                std::cout << "Phone number: ";
                std::string customer_phone_number{};
                std::getline(std::cin >> std::ws, customer_phone_number);

                std::cout << "Balance: ";
                std::string new_balance{};
                std::getline(std::cin >> std::ws, new_balance);
                
                // Returns [0] new account number and [1] customer number
                std::vector<int> numbers = create_new_customer(customer_name, customer_address, customer_phone_number, std::stod(new_balance));
                
                // Save data to the csv-file and catch possible exeptions
                try
                {
                    save_customer_data("customer_data.csv", bank[numbers[1]]);
                }
                catch(const std::exception& exept)
                {
                    std::cerr << exept.what() << '\n';
                }

                std::cout << "\nA new customer '" << customer_name << "' created" 
                          << " with customer number " << numbers[1] << "\n";
                std::cout << "And a new account created with account number " << numbers[0]
                          << " and with balance " << new_balance << "\n";
                break;
                }

            case 3:
                {
                std::cout << "\nGoodbye!\n\n";
                return 0;
                }

            default:
                {
                if ((selection < 0) || (selection > 3) || (!isdigit(static_cast<char>(selection)))) {
                    std::cout << "Please select number from the options!\n\n";
                }
                break;
                }

        }
    }
}