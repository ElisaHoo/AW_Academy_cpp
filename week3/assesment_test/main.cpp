#include "includes/transactions.h"

int main() {
    Transaction transaction_teppo = {.incomes = {23.50, 4.52}, .expenses = {1.40}};
    Transaction transaction_tiina = {.incomes = {}, .expenses = {}};
    User user_teppo = {.name = "Teppo Testeri", transaction_teppo};
    User user_tiina = {.name = "Tiina Testeri", transaction_tiina};

    std::map<int, User> user_db;  // database to handle users

    // Connect users to user database
    user_db[1] = user_teppo;
    user_db[2] = user_tiina;

    // User interface
    std::cout << "Personal finance management system for Tiina and Teppo\n\n"; 
    std::cout << "Please enter your user number";
    int user_num{};
    user_num = get_user_number(user_db);

    while (true) {
        std::cout << "\n(1) view transactions\n";
        std::cout << "(2) add income\n";
        std::cout << "(3) add expense\n";
        std::cout << "(4) view total expenses\n";
        std::cout << "(5) exit\n";
        int choice{};
        std::cin >> choice;

        clear_failed_cin();  // handles if user inputs alphabet etc invalid

        switch (choice)
        {
        case 1:
            {
                view_transactions(user_num, user_db);
            }
            break;

        case 2:
            {
                double income{get_amount()};
                user_db[user_num].transaction.incomes.push_back(income);
                std::cout << "Transaction done!\n";
            }
            break;
        
        case 3:
            {
                double expense{get_amount()};
                user_db[user_num].transaction.expenses.push_back(expense);
                std::cout << "Transaction done!\n";
            }
            break;

        case 4:
            {
                double total = calculate_total_expenses(std::vector<double>{user_db[user_num].transaction.expenses});
                std::cout << "Total expenses are: " << total << " €\n"; 
            }
            break;

        case 5:
            {
                std::cout << "\nGoodbye!\n\n";
                return 0;
            }
            
        default:
            {
                std::cout << "Please select number from the options!\n\n";
            }
            break;
        }
    }



    return 0;
}