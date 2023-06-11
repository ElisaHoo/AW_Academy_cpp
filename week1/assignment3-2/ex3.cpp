#include <iostream>
#include <string>
#include <map>
#include <limits>

/* Update your ex2.cpp -program to handle more than one customer.
 The customer number for each created customer must be unique.*/

struct Account {
    int balance;
};

struct Customer {
    std::string name;
    std::string address;
    std::string phone;
    std::map<int, Account> accounts;
};

static int account_number{0};
static int customer_number{0};
std::map<int, Customer> bank;  //database to handle customers

int get_account_number();
void create_new_account(Customer& customer);
Customer withdraw_money(Customer customer, int acc_num);
Customer deposit_money(Customer& customer, int acc_num);
void create_new_customer();

int main() {
    // Create example-customer and initialize it's member variables
    Customer current_customer;
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
    std::cout << "Welcome to the Elisa's Bank!\n"; 
    std::cout << "Please choose an action:\n";
    bool stay_in_loop = false;

    // Ask a user to choose an action (in the while loop) until 
    // the user choose to quit the program
    while (true) {
        std::cout << "\n\n1: select a customer\n";
        std::cout << "2: create a new customer\n";
        std::cout << "3: exit\n";
        int selection{};
        std::cin >> selection;

        switch (selection) {
            case 1:
                {
                stay_in_loop = true;  // Needed for exiting from next while-loop
                std::cout << "Enter the customer number: ";
                int c_num{};
                std::cin >> c_num;
                //current_customer = bank[c_num];
                std::cout << "\n\nCustomer '" << bank[c_num].name << "' chosen\n";

                while(stay_in_loop) {

                    std::cout << "\n\nPlease, choose an action:\n";
                    std::cout << "1: check balance\n";
                    std::cout << "2: deposit money\n";
                    std::cout << "3: withdraw money\n";
                    std::cout << "4: create a new account\n";
                    std::cout << "5: exit to previous menu\n\n";

                    int choice{};
                    std::cin >> choice;

                    switch (choice)
                    {
                    case 1:  
                        {
                        int chosen_acc_num = get_account_number();
                        std::cout << "\n\nAccount balance is " 
                            << bank[c_num].accounts[chosen_acc_num].balance << " €\n";
                        }
                        break;
                    case 2:  
                        {
                        int chosen_acc_num = get_account_number();
                        bank[c_num] = deposit_money(bank[c_num], chosen_acc_num);
                        }
                        break;
                    case 3:  
                        {
                        int chosen_acc_num = get_account_number();
                        bank[c_num] = withdraw_money(bank[c_num], chosen_acc_num);
                        }
                        break;
                    case 4:
                        {
                        create_new_account(bank[c_num]);
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

                }
                break; // first menu's case 1 ends
            case 2:
                {
                create_new_customer();
                break;
                }
            
            default:
                std::cout << "\nGoodbye!\n\n";
                return 0;
        }
    }
}

// deposit money and update the new balance to the struct variable
Customer deposit_money(Customer& customer, int acc_num) {
    std::cout << "Enter the amount you want to deposit: ";
    int amount{};
    std::cin >> amount;
    customer.accounts[acc_num].balance += amount;
    std::cout << "\n\nAccount balance after deposit is " 
        << customer.accounts[acc_num].balance << " €\n";
    return customer;
                
}

// withdraw money and update the new balance to the struct variable
Customer withdraw_money(Customer customer, int acc_num) {
    std::cout << "Enter the amount you want to withdraw: ";
    double amount{};
    std::cin >> amount;
    std::cout << "\n\nAccount balance after withdrawal is " 
        << (customer.accounts[acc_num].balance -= amount) << " €\n";
    return customer;
    
}

int get_account_number() {
    std::cout << "Enter the account number: ";
    int acc_num{};
    std::cin >> acc_num;
    return acc_num;
}

void create_new_account(Customer& customer) {
    std::cout << "Enter the amount you want to deposit: ";
    int amount{};
    std::cin >> amount;
    // global static int account_number increases by 1
    customer.accounts[++account_number].balance = {amount};  
    std::cout << "A new account created with number " << account_number 
        << " and with balance " << customer.accounts[account_number].balance << " €\n";
}

void create_new_customer() {
    // Just for checking if there is "some rubbish in the cin" to avoid program act weirdly
    if (!std::cin) {   
        std::cin.clear();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    std::cout << "Name: ";
    std::string n{};
    std::getline(std::cin, n);

    std::cout << "Address: ";
    std::string a{};
    std::getline(std::cin, a);

    std::cout << "Phone number: ";
    std::string p{};
    std::getline(std::cin, p);

    std::cout << "Balance: ";
    int b{};
    std::cin >> b;

    // create customer
    Customer customer = {.name = n, .address = a, .phone = p, {}};

    // create account and connect it to the customer
    Account acc = {b};
    customer.accounts[++account_number] = acc;

    // Connect customer to the bank db
    bank[++customer_number] = customer;

    std::cout << "\nA new customer '" << customer.name << "' created" 
              << " with customer number " << customer_number << "\n";
    std::cout << "A new account created with account number " << account_number 
              << " and with balance " << b << "\n";
}