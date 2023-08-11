#ifndef EX_HPP
#define EX_HPP
#include <iostream>

// Template arguments are return type and it's arguments 
template <typename Return_type, typename... Args>
class Caller {
    public:
        using return_type = Return_type;
        // Caller = constructor, (*) = pointer to function, (Args... args) = parameters for function
        Caller(Return_type(*)(Args... args)) {}
        static const size_t arity{sizeof...(Args)};
    private:
};

int sum(int a, int b, int c) {
    return a + b + c;
}

void dummy_print(std::string world) {
    std::cout << "Hello " << world << "!\n";
} 

std::string return_name() {
    return "Maija";
}

template <typename T>
void print_details(T& func) {
    Caller caller(func);
    std::cout << "The return type of the function: " 
              << typeid(typename decltype(caller)::return_type).name() 
              << "\n";
    std::cout << "The argument count of the function: " << decltype(caller)::arity << "\n";
} 

#endif