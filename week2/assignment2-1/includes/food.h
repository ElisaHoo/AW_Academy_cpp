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
    double prize;
    std::vector<std::string> ingredients;
};

struct Order {
    std::vector<Food> customer_order;
    double total_prize{0};
};

void print_ingredients(Food food);
void print_menu(std::vector<Food> menu);
void get_customer_order(std::vector<Food> menu, Order& order);
bool ask_if_makes_more_orders();

#endif