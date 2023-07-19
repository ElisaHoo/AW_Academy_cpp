#include "../includes/ex2.hpp"

void Order::print_state() {
    switch (state)
    {
        case Order_state::in_stock: {
            std::cout << "The state of the order number " 
                    << order_number << " is 'in stock'.\n";
            break;
        }
        case Order_state::ordered: {
            std::cout << "The state of the order number " 
                    << order_number << " is 'ordered'.\n";
            break;
        }
        case Order_state::processing: {
            std::cout << "The state of the order number " 
                    << order_number << " is 'processing'.\n";
            break;
        }
        case Order_state::shipping: {
            std::cout << "The state of the order number " 
                    << order_number << " is 'shipping'.\n";
            break;
        }
        case Order_state::delivered: {
            std::cout << "The state of the order number " 
                    << order_number << " is 'delivered'.\n";
            break;
        }
    }
}

Order_state Order::progress_order() {
    if (state == Order_state::in_stock) {
        state = Order_state::ordered;
        return state;

    } else if (state == Order_state::ordered) {
        state = Order_state::processing;
        return state;

    } else if (state == Order_state::processing) {
        state = Order_state::shipping;
        return state;

    } else if (state == Order_state::shipping) {
        state = Order_state::delivered;
        return state;

    } else {
        state = Order_state::delivered;
        return state;
    }
}