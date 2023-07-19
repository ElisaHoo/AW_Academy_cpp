#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <fstream>

/* Update your ex4.cpp -program to store account data in a file.*/

struct Account {
    int balance;
};

struct Customer {
    std::string name;
    std::string address;
    std::string phone;
    std::map<int, Account> accounts;
};

// Global variables for account and customer numbers & bank map
static int account_number{0};
static int customer_number{0};
std::map<int, Customer> bank;  //database to handle customers

int get_account_number();
void create_new_account(Customer& customer);
Customer withdraw_money(Customer customer, int acc_num);
Customer deposit_money(Customer& customer, int acc_num);
void create_new_customer();
void save_customer_data(const std::string& filename, Customer &current_customer);


int main() {
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
                        // From bank-map, find right customer with the customer number
                        // and then find right account with the account number and pick
                        // it's balance
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
                    // Save the customer data to the csv-file when the action is done
                    } save_customer_data("customer_data.csv", bank[c_num]);
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
    std::cout << "And a new account created with account number " << account_number 
              << " and with balance " << b << "\n";
    
    // Save data to the csv-file
    save_customer_data("customer_data.csv", bank[customer_number]);
}

void save_customer_data(const std::string& filename, Customer &current_customer) {
    std::ofstream customer_data_file(filename);  // Create and open a data file
    if (customer_data_file.is_open()) {
        customer_data_file << "1.Customer number, 2.Name, 3.Address, 4.Phone number, "
                              "5. Account number, 6.Balance\n";
        // Loop through the maps and write customer data to the file
        for (const auto& [customer_number, current_customer] : bank) {
            for (const auto& [account_number, account] : current_customer.accounts) {
                customer_data_file << "1." << customer_number << ", 2." << current_customer.name 
                << ", 3." << current_customer.address << ", 4." << current_customer.phone << ", 5." 
                << account_number << ", 6." << account.balance << "\n";
            }
        }
        customer_data_file.close();  // Close the file
        std::cout << "Saving succeeded!";
    } else {
        std::cout << "\n\nCouldn't open the file " << filename << "\n";
    }

}