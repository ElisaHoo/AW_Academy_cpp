#ifndef EX_HPP
#define EX_HPP
#include <iostream>
#include <limits>

class Positive_integers {
    public:
        int number{0};
        Positive_integers() = default; 
        Positive_integers(int num);
        void print_number();
        int add(Positive_integers obj);
        int subtract(Positive_integers obj);
        int max_number{std::numeric_limits<int>::max()};
};

class Count_instances {
    public:
        static inline int counter;
        Count_instances() {
            counter++;
            print_count();
        }
        ~Count_instances() {
            // If instance's lifetime ends, decrement counter
            counter--;
        }
        void print_count();
};

#endif