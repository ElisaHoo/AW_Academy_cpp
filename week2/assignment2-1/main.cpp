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
    struct Food porridge{.name = "porridge", .prize = 1.95, .ingredients = {"water", "oatmeal", "salt"}};
    struct Food hamburger{.name = "hamburger", .prize = 5.90, .ingredients = {"bread", "cheese", "ground beef patty", "mayonnaise", "salad"}};
    struct Food beer{.name =  "beer", .prize = 6.50, .ingredients = {"barley malt", "yeast", "water"}};

    print_ingredients(porridge);
    
    std::vector<Food> menu = {porridge, hamburger, beer};
    print_menu(menu);
    
    Order order;
    bool ask_for_orders = true;
    while(ask_for_orders) {
        get_customer_order(menu, order);
        ask_for_orders = ask_if_makes_more_orders();
    }
    std::cout << "Thank you for your order! The total prize is " << order.total_prize << " euros\n";
    
    return 0;
}

