#ifndef EX3_HPP
#define EX3_HPP

#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <fstream>
#include <vector>

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
inline std::map<int, Customer> bank;  //database to handle customers

const int ERROR_CODE{1};

void clear_failed_cin();
int get_valid_customer_number(int customer_num);
bool customer_number_is_used(int customer_num);
int get_account_number_from_user();
bool account_number_is_used(int acc_num, int customer_num);
int check_account_number_is_valid(int acc_num, int customer_num);
double get_valid_input_value_type_for_deposit(double amount);
Customer deposit_money(Customer& customer, int acc_num, double amount);
int create_new_account(int customer_num, double amount_input);
double get_valid_withdrawal(Customer customer, int acc_num, double amount);
Customer withdraw_money(Customer customer, int acc_num, double amount);
std::vector<int> create_new_customer(std::string name, 
                         std::string address, 
                         std::string phone_number, 
                         double new_balance);
void save_customer_data(const std::string& filename, Customer &current_customer);

#endif