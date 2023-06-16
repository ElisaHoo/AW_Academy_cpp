#ifndef PRINT_H
#define PRINT_H
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <iomanip>  // to use transform
#include <limits>

struct Food {
    std::string name;
    double price;
    std::vector<std::string> ingredients;
};

struct Order {
    std::vector<Food> customer_order;
    double total_price{0};
};

void print_ingredients(Food food);
Food input_new_food();
void add_food_to_menu(std::vector<Food>& menu, Food food);
void print_menu(std::vector<Food> menu);
void get_customer_order(std::vector<Food> menu, Order& order);
void print_order(Order& order);

#endif