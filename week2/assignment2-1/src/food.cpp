#include "../includes/food.h"

void print_ingredients(Food food) {
    std::cout << "Ingredients of the " << food.name << " are:\n";
    for (int i = 0; i < food.ingredients.size(); ++i) {
        std::cout << "- " << food.ingredients[i] << "\n";
    } 
    std::cout << "\n";
}

Food input_new_food() {
    Food new_food;
    std::cout << "Enter name: ";
    std::getline(std::cin >> std::ws, new_food.name);
    std::cout << "Enter price: ";
    std::cin >> new_food.price;
    std::string ingr{};

    // Ask for ingredients until user says no
    while (true) {
        std::cout << "Enter ingredient: ";
        std::getline(std::cin >> std::ws, ingr);
        new_food.ingredients.push_back(ingr);
        std::cout << "Do you want to add another ingredient? (y/n) ";
        char c{};
        std::cin >> c;
        if (c == 'y') {
            continue;
        } else if (c == 'n') {
            return new_food;
        } else {
            std::cout << "Invalid input!\n";
            break;
        }
    }
}

void add_food_to_menu(std::vector<Food>& menu, Food food) {
    menu.push_back(food);
}

void print_menu(std::vector<Food> menu) {
    std::cout << "\n** Restaurant menu **\n";
    for (int i = 0; i < menu.size(); ++i) {
        std::cout << "- " << menu[i].name <<"\n";
    }
    std::cout << "\n";
}

void get_customer_order(std::vector<Food> menu, Order& order) {
    std::cout << "\nWhat would you like to order?\n";
    std::string choice{};
    std::getline(std::cin >> std::ws, choice);
    // Convert user input to lowercase to accept input regardless of case
    std::transform(choice.cbegin(), choice.cend(), choice.begin(), 
                   [](unsigned char c) {return std::tolower(c);});
    // Loop through the menu to pick up the order and prize
    for (int i = 0; i < menu.size(); ++i) {
        std::transform(menu[i].name.cbegin(), menu[i].name.cend(), menu[i].name.begin(), [](unsigned char c) {return std::tolower(c);});
        if (choice == menu[i].name){
            order.customer_order.push_back({menu[i]});
            order.total_price += menu[i].price;
            std::cout << "\nThank you!\n\n";
            return;
        }
    }
    // Prompt user if the food was not found from the menu
    std::cout << "\nSorry, but it is not on our menu\n";
}

void print_order(Order& order) {
    // If customer order includes something, loop through it and print the value
    if (order.customer_order.size() > 0) {
        std::cout << "\nYour order includes:\n";
        for (int i = 0; i < order.customer_order.size(); ++i) {
            std::cout << "- " << order.customer_order[i].name <<"\n";
        }
        std::cout << "The total prize for the order is " << order.total_price << " euros\n";
        std::cout << "\n";
        return;
    }
    std::cout << "\nYou have order nothing yet\n";
}
    