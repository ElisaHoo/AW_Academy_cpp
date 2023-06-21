#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <fstream>

struct Account {
    double balance;
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

const int ERROR_CODE{1};

void clear_failed_cin();
int get_account_number(Customer customer);
int get_valid_input_value_type_for_account_number();
int get_customer_number();
int get_valid_input_value_type_for_customer_number();
void create_new_account(Customer& customer);
Customer withdraw_money(Customer customer, int acc_num);
double get_valid_input_value_type_for_withdrawal();
Customer deposit_money(Customer& customer, int acc_num);
double get_valid_input_value_type_for_deposit();
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
                int customer_num{};
                customer_num = get_customer_number();
                
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
                        int chosen_acc_num{};
                        chosen_acc_num = get_account_number(bank[customer_num]);

                        std::cout << "\n\nAccount balance is " 
                        // From bank-map, find right customer with the customer number
                        // and then find right account with the account number and pick
                        // it's balance
                            << bank[customer_num].accounts[chosen_acc_num].balance << " €\n";
                        }
                        break;

                    case 2:  // Deposit money
                        {
                        int chosen_acc_num{};
                        chosen_acc_num = get_account_number(bank[customer_num]);
                        
                        bank[customer_num] = deposit_money(bank[customer_num], chosen_acc_num);
                        }
                        break;

                    case 3:  // Withdraw money
                        {
                        int chosen_acc_num{};
                        chosen_acc_num = get_account_number(bank[customer_num]);
                        
                        bank[customer_num] = withdraw_money(bank[customer_num], chosen_acc_num);
                        }
                        break;

                    case 4:  // Create a new account
                        {
                        create_new_account(bank[customer_num]);
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
                create_new_customer();
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

int get_customer_number() {
    int customer_num{get_valid_input_value_type_for_customer_number()};
    //Check that customer number is valid (=bank map includes customer number)
    if (bank.find(customer_num) == bank.end()) {
        std::cout << "The entered customer number is not in use! Please try again.\n";
        customer_num = get_customer_number();
    }
    std::cout << "\n\nCustomer '" << bank[customer_num].name << "' chosen\n";
    return customer_num;
}

int get_account_number(Customer customer) {
    int acc_num{get_valid_input_value_type_for_account_number()};
    //Check that account number is valid (=customer.accounts map includes customer number)
    if (customer.accounts.find(acc_num) == customer.accounts.end()) {
        std::cout << "The entered account number is not in use! Please try again.\n";
        acc_num = get_account_number(customer);
    }
    return acc_num;
}

// deposit money and update the new balance to the struct variable
Customer deposit_money(Customer& customer, int acc_num) {
    double amount{get_valid_input_value_type_for_deposit()}; // Makes sure user inputs number
    customer.accounts[acc_num].balance += amount;
    std::cout << "\n\nAccount balance after deposit is " 
        << customer.accounts[acc_num].balance << " €\n";
    return customer;           
}

// withdraw money and update the new balance to the struct variable
Customer withdraw_money(Customer customer, int acc_num) {
    double amount{get_valid_input_value_type_for_withdrawal()};  // Makes sure user inputs number
    // Check that there is enough money to the withdrawal and if not, keep
    // asking valid amount
    while (amount > customer.accounts[acc_num].balance) {
        std::cout << "\nInsufficient funds to the withdrawal! There are " 
                  << customer.accounts[acc_num].balance 
                  << " euros in your account. Please try again.\n";
        std::cout << "Enter the amount you want to withdraw: ";
        std::cin >> amount;
    }
    std::cout << "\n\nAccount balance after withdrawal is " 
        << (customer.accounts[acc_num].balance -= amount) << " €\n";
    return customer;
}

void create_new_account(Customer& current_customer) {
    double amount{get_valid_input_value_type_for_deposit()};
    // global static int account_number increases by 1
    current_customer.accounts[++account_number].balance = {amount};  
    std::cout << "A new account created with number " << account_number 
        << " and with balance " << current_customer.accounts[account_number].balance << " €\n";
}

void create_new_customer() {
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
    double new_balance{};
    std::cin >> new_balance;

    // create customer
    Customer customer = {.name = customer_name, .address = customer_address, .phone = customer_phone_number, {}};

    // create account and connect it to the customer
    Account acc = {new_balance};
    customer.accounts[++account_number] = acc;

    // Connect customer to the bank db
    bank[++customer_number] = customer;

    std::cout << "\nA new customer '" << customer.name << "' created" 
              << " with customer number " << customer_number << "\n";
    std::cout << "And a new account created with account number " << account_number 
              << " and with balance " << new_balance << "\n";
    
    // Save data to the csv-file
    try
    {
        save_customer_data("customer_data.csv", bank[customer_number]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   
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
        throw std::runtime_error("Couldn't open the file");
    }

}

void clear_failed_cin() {
    if(!std::cin) { // User didn't input number -> cin fails
        std::cin.clear();  // clear cin's failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}

int get_valid_input_value_type_for_customer_number() {
    std::cout << "Enter the customer number: ";
    int customer_num{};
    std::cin >> customer_num;
    if(!std::cin) { // User didn't input number -> cin fails
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Please try again.\n";
            std::cout << "Enter the customer number: ";
            std::cin >> customer_num;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    return customer_num;
}

int get_valid_input_value_type_for_account_number() {
    std::cout << "Enter the account number: ";
    int acc_num{};
    std::cin >> acc_num;
    if(!std::cin) { // User didn't input number -> cin fails
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Please try again.\n";
            std::cout << "Enter the account number: ";
            std::cin >> acc_num;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    return acc_num;
}

double get_valid_input_value_type_for_deposit() {
    std::cout << "Enter the amount you want to deposit: ";
    double amount{};
    std::cin >> amount;
    // User didn't input number -> cin fails  OR  amount is zero or negative
    if(!std::cin || amount <= 0) { 
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Please try again.\n";
            std::cout << "Enter the amount you want to deposit: ";
            std::cin >> amount;
            if(!std::cin || amount <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    return amount;
}

double get_valid_input_value_type_for_withdrawal() {
    std::cout << "Enter the amount you want to withdraw: ";
    double amount{};
    std::cin >> amount;
    // User didn't input number -> cin fails  OR  amount is zero or negative
    if(!std::cin || amount <= 0) {  
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Please try again.\n";
            std::cout << "Enter the amount you want to withdraw: ";
            std::cin >> amount;
            if(!std::cin || amount <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    return amount;
}