#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <iostream>
#include <map>
#include <vector>
#include <limits>
#include <numeric>

struct Transaction {
    //double incomes;
    //double expenses;
    std::vector<double> incomes;
    std::vector<double> expenses;
};

struct User {
    std::string name;
    Transaction transaction;
};

void clear_failed_cin();
int get_user_number(std::map<int, User> user_db);
int get_valid_input_value_type_for_user_number();
void view_transactions(int user_num, std::map<int, User> user_db);
double get_amount();
double calculate_total_expenses(std::vector<double> expenses);

#endif