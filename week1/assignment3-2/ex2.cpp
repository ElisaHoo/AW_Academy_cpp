#include <iostream>
#include <string>
#include <map>

/* Update your ex1.cpp -program so that the user can add more accounts. 
 * The account number needs to be unique.*/

struct Account {
    int balance;
};

struct Customer {
    std::string name;
    std::string address;
    std::string phone;
    int customer_number;
    std::map<int, Account> accounts;
};

static int account_number{0};

int get_account_number();
void create_new_account(Customer &customer);

int main() {
    // Get the customer information
    std::cout << "Welcome to the Elisa's Bank!\n" << "Please enter your information\n";

    std::cout << "Name: ";
    std::string n{};
    std::getline(std::cin, n);  // getline for inputting strings with spaces

    std::cout << "Address: ";
    std::string a{};
    std::getline(std::cin, a);

    std::cout << "Phone number: ";
    std::string p{};
    std::getline(std::cin, p);

    // Create a Customer-struct and initialize member variables
    struct Customer customer = {.name = n, .address = a, .phone = p, .customer_number = 111};
    // Create a Account-struct
    Account account = {200};
    customer.accounts[account_number] = account;  // Connect customer to account (account_number serves also as a map key)

    std::cout << "\n\nNew account created with number " << account_number << "!\n";

    // Ask a user to choose an action (in the while loop) until the user choose to quit the program
    while(true) {
        std::cout << "\n\nPlease, choose an action:\n";
        std::cout << "1: check balance\n";
        std::cout << "2: deposit money\n";
        std::cout << "3: withdraw money\n";
        std::cout << "4: create a new account\n";
        std::cout <<"5: exit\n\n";

        int choice{};
        std::cin >> choice;

        switch (choice)
        {
        case 1:  // check balance
            {
                int chosen_acc_num = get_account_number();
                std::cout << "\n\nYour account balance is " << customer.accounts[chosen_acc_num].balance << " €\n";
            }
            break;
        case 2:  // deposit money and update the new balance to the struct variable
            {
                int chosen_acc_num = get_account_number();
                std::cout << "Enter the amount you want to deposit: ";
                double amount{};
                std::cin >> amount;
                std::cout << "\n\nYour account balance after deposit is " << (customer.accounts[chosen_acc_num].balance += amount) << " €\n";
            }
            break;
        case 3:  // withdraw money and update the new balance to the struct variable
            {
                int chosen_acc_num = get_account_number();
                std::cout << "Enter the amount you want to withdraw: ";
                double amount{};
                std::cin >> amount;
                // Check if there is enough money for withdrawal
                if (amount > account.balance) {
                    std::cout << "\n\nYour account balance after withdrawal is " << (customer.accounts[chosen_acc_num].balance -= amount) << " €\n";
                } else {
                    std::cout << "\n\nThere is not enough balance for withdrawal!" 
                                 " The balace is now " << customer.accounts[chosen_acc_num].balance << " €\n";
                }   
            }
            break;
        case 4:
            create_new_account(customer);
            break;

        case 5:
            std::cout << "Thank you for visiting and welcome again!\n\n";
            return 0;  // exit the program

        default:
            std::cout << "Please select number from the options!\n\n";
            break;
        }
    }
}

int get_account_number() {
    std::cout << "Enter the account number: ";
    int acc_num{};
    std::cin >> acc_num;
    return acc_num;
}

void create_new_account(Customer &customer) {
    std::cout << "Enter the amount you want to deposit: ";
    int amount{};
    std::cin >> amount;
    customer.accounts[++account_number].balance = {amount};  // global static int account_number increases by 1
    std::cout << "A new account created with number " << account_number << " and with balance " << customer.accounts[account_number].balance << " €\n\n";
}