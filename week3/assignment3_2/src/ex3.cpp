#include "../includes/ex3.hpp"

int get_valid_customer_number(int customer_num) {
    // Check if user didn't input number -> cin fails OR inputted number is not in use
    if(!std::cin || !customer_number_is_used(customer_num)) { 
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input or the number is not in use! Please try again.\n";
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

bool customer_number_is_used(int customer_num) {
    //Check that customer number is used (=bank map includes customer number)
    return bank.find(customer_num) != bank.end();
}

int get_account_number_from_user() {
    std::cout << "Enter the account number: ";
    int acc_num{};
    std::cin >> acc_num;
    return acc_num;
}

int check_account_number_is_valid(int acc_num, int customer_num) {
    // User didn't input number -> cin fails OR account is not in use
    if(!std::cin || !account_number_is_used(acc_num, customer_num)) { 
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input or account number is not in use! Please try again.\n";
            std::cout << "Enter the account number: ";
            std::cin >> acc_num;
            if(!std::cin || !account_number_is_used(acc_num, customer_num)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    return acc_num;
}

bool account_number_is_used(int acc_num, int customer_num) {
    //Check that account number is valid (=customer.accounts map includes customer number)
    return bank[customer_num].accounts.find(acc_num) != bank[customer_num].accounts.end();
}

double get_valid_input_value_type_for_deposit(double amount) {
    // User didn't input number -> cin fails  OR  amount is zero or negative
    if(!std::cin || amount <= 0) { 
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Amount must be greater than zero.\n";
            std::cout << "Please enter the amount again: ";
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

Customer deposit_money(Customer& customer, int acc_num, double amount) {
    customer.accounts[acc_num].balance += amount;
    return customer;           
}

double get_valid_withdrawal(Customer customer, int acc_num, double amount) {
    // User didn't input number -> cin fails  OR  amount is zero or negative OR there is not enough money
    if(!std::cin || amount < 0 || amount > customer.accounts[acc_num].balance) {  
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Withdrawal must be positive and the account balance must "
                         "be sufficient for the withdrawal. Please try again.\n";
            std::cout << "There are " << customer.accounts[acc_num].balance 
                      << " euros in your account.\n";
            std::cout << "Enter the amount you want to withdraw: ";
            std::cin >> amount;
            if(!std::cin || amount < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    return amount;
}

// withdraw money and update the new balance to the struct variable
Customer withdraw_money(Customer customer, int acc_num, double amount) {
    customer.accounts[acc_num].balance -= amount;
    return customer;
}

int create_new_account(int customer_num, double amount) {
    // global static int account_number increases by 1
    bank[customer_num].accounts[++account_number].balance = {amount};
    return account_number;
}

std::vector<int> create_new_customer(std::string customer_name, std::string customer_address, std::string customer_phone_number, double new_balance) {
    // create customer
    Customer customer = {.name = customer_name, .address = customer_address, .phone = customer_phone_number, {}};

    int new_account_num{++account_number};
    int new_cust_num{++customer_number};

    // create account and connect it to the customer
    Account acc = {new_balance};
    customer.accounts[new_account_num] = acc;

    // Connect customer to the bank db
    bank[new_cust_num] = customer;

    std::vector<int> numbers{};
    numbers.push_back(new_account_num);
    numbers.push_back(new_cust_num);

    return numbers;
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
        std::cout << "\nSaving succeeded!\n";
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