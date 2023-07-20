#ifndef EX2_HPP
#define EX2_HPP
#include <iostream>
#include <limits>

class Positive_integer {
    public:
        Positive_integer() = default; 
        Positive_integer(int num);
        void print_number() const;
        int add(Positive_integer obj);
        int subtract(Positive_integer obj);
        friend Positive_integer multiply(const Positive_integer& posi1, const Positive_integer& posi2);
        
    private:
        int number{0};
        const static int max_number{std::numeric_limits<int>::max()};
};

#endif