#include "includes/food.h"
#include <string>

/* You are in a buzzing startup company that is building a ordering
 * system for a restaurant.
 * Exercise 1:
 * Set up your program and create the first set of data. To start, 
 * your menu ordering program should have a struct called Food. The 
 * members for the struct should contain the name, price and ingredients. 
 * Your program needs to be able to print out all of the attributes. 
 * Divide the program into multiple source and header files as needed.
 * Test your program by creating a food item and printing out its 
 * ingredients in the main.cpp file. Use CMake to build your program.
 * Exercise 2:
 * Add a menu to the program. Add a menu to the program. At this stage, 
 * you should be able to add foods into the menu and print out the menu 
 * for the customer.
 * Exercise 3:
 * The program needs to handle orders. Add a new feature where the 
 * customer can pick a food from the menu and add it to the order. 
 * The order should also contain information of the total price.
 * Exercise 4:
 * In your main.cpp, create a loop that allows a customer to add as 
 * many items as they want to their order from the menu. They should be 
 * able to view the menu and their current order at any time.*/

int main() {
    struct Food porridge{.name = "porridge", .price = 1.95, .ingredients = {"water", "oatmeal", "salt"}};
    
    print_ingredients(porridge);

    std::vector<Food> menu{porridge};

    std::cout << "Add new food to menu\n";
    // Ask to add another food until user says no
    while (true) {
        add_food_to_menu(menu, input_new_food());
        std::cout << "Do you want to add another food? (y/n) ";
        char c{};
        std::cin >> c;
        if (c == 'y') {
            continue;
        } else if (c == 'n') {
            break;
        } else {
            std::cout << "Invalid input!\n";
            break;
        }
    }
    
    Order order;
    
    // Goes to loop where customer can choose action: make an order, 
    // check an order or view the menu
    while(true) {
        std::cout << "\nPlease choose an action:\n";
        std::cout << "(1) Make an order\n";
        std::cout << "(2) View the order\n";
        std::cout << "(3) View the menu\n";
        std::cout << "(4) Quit\n";
        
        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            {
                get_customer_order(menu, order);
            }
            break;
        case 2:
            {
                print_order(order);
            }
            break;
        case 3:
            {
                print_menu(menu);
            }
            break;
        case 4:
            {
                std::cout << "The total prize for the order is " << order.total_price << " euros\n";
                std::cout << "Thank you for visiting and please come again!\n";
                return 0;
            }
            break;
        default:
            std::cout << "Invalid action, please choose from the numbers 1-4!";
            break;
        }
    }

    return 0;
}
