#include "../includes/transactions.h"

void clear_failed_cin() {
    if(!std::cin) { // User didn't input number -> cin fails
        std::cin.clear();  // clear cin's failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}

int get_user_number(std::map<int, User> user_db) {
    int user_num{get_valid_input_value_type_for_user_number()};
    //Check that user number is valid (=user_db -map includes user number)
    if (user_db.find(user_num) == user_db.end()) {
        std::cout << "The entered user number is not in use! Please try again.\n";
        user_num = get_user_number(user_db);
    }
    std::cout << "\n\nUser '" << user_db[user_num].name << "' chosen\n";
    return user_num;
}

int get_valid_input_value_type_for_user_number() {
    std::cout << "Enter the user number: ";
    int user_num{};
    std::cin >> user_num;
    if(!std::cin) { // User didn't input number -> cin fails
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Please try again.\n";
            std::cout << "Enter the user number: ";
            std::cin >> user_num;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }
    return user_num;
}

void view_transactions(int user_num, std::map<int, User> user_db) {
    std::cout << "\nIncomes are: \n";
    for (const auto inc: user_db[user_num].transaction.incomes) {
        std::cout << inc << "\n";
    }
    std::cout << "\n";
    std::cout << "Expenses are: \n";
    for (const auto exp: user_db[user_num].transaction.expenses) {
        std::cout << exp << "\n";
    }
}

double get_amount() {
    std::cout << "Enter the amount for transaction:";
    double amount{};
    std::cin >> amount;
    // User didn't input number -> cin fails  OR  amount is zero or negative
    if(!std::cin || amount <= 0) { 
        clear_failed_cin();
        while (true) {  // Keep asking valid input
            std::cout << "Invalid input! Please try again.\n";
            std::cout << "Enter the amount for transaction: ";
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

double calculate_total_expenses(std::vector<double> expenses) {
    double total = 0.0;
    for (const auto expense : expenses) {
        total += expense;
    }
    return total;
}

