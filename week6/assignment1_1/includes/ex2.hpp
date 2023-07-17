#ifndef EX2_HPP
#define EX2_HPP
#include <iostream>

enum class Order_state {
    in_stock,
    ordered,
    processing,
    shipping,
    delivered,
};

struct Order {
    int order_number;
    // Default state is "in_stock"
    Order_state state{Order_state::in_stock};
    void print_state();
    // Change the Order_state to next state e.g. in_stock -> ordered
    Order_state progress_order();
};

#endif